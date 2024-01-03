#include "defs.h"


void initRoom(int id, char *name, RoomType **room){
  // Allocate memory for the room
  *room = (RoomType *)malloc(sizeof(RoomType));

  if (*room != NULL){
    // Initialize the room data
    (*room)->id = id;
    // make sure the name is not too long with strncpy
    strncpy((*room)->name, name, MAX_STR);
    
    // Initialize the ghost list of the room
    initGhostList(&((*room)->ghosts));
  }
}

void initRoomArray(RoomArrayType *arr){
  // Initialize the array size to 0
  arr->size = 0;
}

void addRoom(RoomArrayType *arr, RoomType *r){

  // if the array is not full
  if (arr->size < MAX_ROOMS){
    // add the room to the array
    arr->elements[arr->size] = r;
    // increment the size
    arr->size++;
  }
  else{
    printf("Error: The room array is full\n");
  }

}

void cleanupRoomArray(RoomArrayType *arr){

  // for each room in the array
  for (int i = 0; i < arr->size; i++){
    // cleanup the ghost list and data
    cleanupGhostList(&(arr->elements[i]->ghosts));
    cleanupGhostData(&(arr->elements[i]->ghosts));

    // free the room
    free(arr->elements[i]);
    arr->elements[i] = NULL;

  }
  // reset the size to 0
  initRoomArray(arr);
}

void printRooms(const RoomArrayType *arr){
  printf("Rooms:\n");

  for (int i = 0; i < arr->size; i++){
    // print the room id and name
    printf("  %d: %s\n", arr->elements[i]->id, arr->elements[i]->name);

    // print the ghosts in the room
    printf("Ghosts:\n");
    printGhostList(&(arr->elements[i]->ghosts));

    printf("\n");
  }
}