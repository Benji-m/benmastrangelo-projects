#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define C_TRUE     1
#define C_FALSE    0
 
#define MAX_ARR  128
#define MAX_STR   32
#define MAX_ROOMS 30
  
#define NEXT_ROOM_ID    9001
#define NEXT_GHOST_ID  810310
 
typedef enum GhostType { POLTERGEIST, WRAITH, PHANTOM, BULLIES, OTHER } GhostEnumType;
 
/* These rename the structures that we'll be creating. It's an alternative to the format we've seen previously. */
typedef   struct Building   BuildingType; 
typedef   struct Ghost      GhostType;
typedef   struct GhostList  GhostListType;
typedef   struct Node       NodeType;
typedef   struct Room       RoomType;
typedef   struct RoomArray  RoomArrayType;


// A singly linked list meant to hold NodeType elements which point to GhostTypes. It must have both a head and a tail.
struct GhostList {
  NodeType* head;
  NodeType* tail;
};

struct Room {
  int     id;
  char    name[MAX_STR];
  struct  GhostList ghosts;
};
 
struct Ghost {
  int           id;
  GhostEnumType ghostType;
  struct Room   *room;
  float         likelihood;
};

struct RoomArray {
 RoomType* elements[MAX_ARR]; // static array of pointers to RoomType
  int size; // current number of rooms in the elements array
};
 
// The NodeType works with the GhostListType structure to implement a singly linked list of GhostType data.
struct Node {
  GhostType* ghost;
  struct Node* next;
 
};

// The BuildingType structure holds the data for the entire building, including the rooms and ghosts.
struct Building {
  GhostListType* ghosts;
  RoomArrayType* rooms;
};


// Function prototypes

void printMenu(int*);
void loadBuildingData(struct Building*);
void initGhostList(GhostListType *list);
void initGhost(int id, GhostEnumType type, RoomType *room, float likelihood, GhostType **ghost);
void addGhost(GhostListType *list, GhostType *ghost);
void cleanupGhostData(GhostListType *list);
void cleanupGhostList(GhostListType *list);
void printGhost(const GhostType *ghost);
void printGhostList(const GhostListType *list);
void addGhostByLikelihood(GhostListType *list, GhostType *ghost);
void printByLikelihood(const GhostListType *origList, int endsOnly);
void initRoom(int id, char *name, RoomType **room);
void initRoomArray(RoomArrayType *arr);
void addRoom(RoomArrayType *arr, RoomType *r);
void cleanupRoomArray(RoomArrayType *arr);
void printRooms(const RoomArrayType *arr);
void initBuilding(BuildingType *b);
void cleanupBuilding(BuildingType *b);