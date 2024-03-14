
const server = require('http').createServer(handler)
const io = require('socket.io')(server)
const fs = require('fs') 
const url = require('url'); 
const PORT = process.env.PORT || 3000 

const ROOT_DIR = 'html' 

const MIME_TYPES = {
  'css': 'text/css',
  'gif': 'image/gif',
  'htm': 'text/html',
  'html': 'text/html',
  'ico': 'image/x-icon',
  'jpeg': 'image/jpeg',
  'jpg': 'image/jpeg',
  'js': 'application/javascript',
  'json': 'application/json',
  'png': 'image/png',
  'svg': 'image/svg+xml',
  'txt': 'text/plain'
}

function get_mime(filename) {
  for (let ext in MIME_TYPES) {
    if (filename.indexOf(ext, filename.length - ext.length) !== -1) {
      return MIME_TYPES[ext]
    }
  }
  return MIME_TYPES['txt']
}

server.listen(PORT) 

function handler(request, response) {
  let urlObj = url.parse(request.url, true, false)
  console.log('\n============================')
  console.log("PATHNAME: " + urlObj.pathname)
  console.log("REQUEST: " + ROOT_DIR + urlObj.pathname)
  console.log("METHOD: " + request.method)

  let filePath = ROOT_DIR + urlObj.pathname
  if (urlObj.pathname === '/') filePath = ROOT_DIR + '/index.html'

  fs.readFile(filePath, function(err, data) {
    if (err) {
      console.log('ERROR: ' + JSON.stringify(err))
      response.writeHead(404);
      response.end(JSON.stringify(err))
      return
    }
    response.writeHead(200, {
      'Content-Type': get_mime(filePath)
    })
    response.end(data)
  })

}

//Socket Server
const registeredUsers = new Map();
io.on('connection', function(socket) {
  console.log("socket id: " +socket.id);
  socket.on('register', (data)=>{
    dataObj = JSON.parse(data);
  
    if(!registeredUsers.has(dataObj.username)){
      let returnObj = {}

      returnObj.text = dataObj.username + " is registered and connected to the CHAT SERVER"
      returnObj.sender = dataObj.username
      returnObj.private = dataObj.private
      registeredUsers.set(dataObj.username, socket.id)
      console.log(registeredUsers)
      socket.emit('regAck',JSON.stringify(returnObj))
    }
  })

  socket.on('clientPublicSays', function(data) {
    console.log("Public chat message")
    console.log('RECEIVED: ' + data)
    dataObj = JSON.parse(data);
    let returnObj = {}
    returnObj.text = dataObj.username +": " +dataObj.text
    returnObj.sender = dataObj.username
    returnObj.private = dataObj.private
    if(registeredUsers.has(dataObj.username)){
      for (const socketID of registeredUsers.values()){
        io.to(socketID).emit('serverSays',JSON.stringify(returnObj))
      }
    }
  })

  socket.on('clientPrivateSays', function(data) {
    console.log("Private chat message")
    console.log('RECEIVED: ' + data)
    dataObj = JSON.parse(data);
    
    let returnObj = {}
    returnObj.text = dataObj.username +": " +dataObj.text
    returnObj.sender = dataObj.username
    returnObj.private = dataObj.private
    dataObj.private.push(dataObj.username)
    if(registeredUsers.has(dataObj.username)){
      for(reciever of dataObj.private){
        if (registeredUsers.has(reciever.trim())){
          io.to(registeredUsers.get(reciever.trim())).emit('serverSays', JSON.stringify(returnObj))
         }
      }
    }
  })
})

console.log(`Server Running at port ${PORT}  CNTL-C to quit`)
console.log(`To Test:`)
console.log(`Open several browsers to: http://localhost:3000/chatClient.html`)
