#include "defs.h"

void initGhostList(GhostListType *list){
// Initialize the head and tail pointers to NULL
    list->head = NULL;
    list->tail = NULL;
}

void initGhost(int id, GhostEnumType type, RoomType *room, float likelihood, GhostType **ghost){
    // Allocate memory for the ghost
    *ghost = (GhostType *)malloc(sizeof(GhostType));
    
    // Initialize the ghost data
    if (*ghost != NULL){
        (*ghost)->id = id;
        (*ghost)->ghostType = type;
        (*ghost)->room = room;
        (*ghost)->likelihood = likelihood;
    }
}

void addGhost(GhostListType *list, GhostType *ghost){

    // Allocate memory for a new node
    NodeType *newNode = (NodeType *)malloc(sizeof(NodeType));

    if (newNode != NULL){
        
        // Initialize the node data
        newNode->ghost = ghost;
        newNode->next = NULL;

        // if list is empty set head and tail to newNode
        if (list->head == NULL){
            list->head = newNode;
            list->tail = newNode;
        }
        // if list is not empty set tail to newNode
        else{
            list->tail->next = newNode;
            list->tail = newNode;
        }
    }
}

void cleanupGhostData(GhostListType *list) {
    NodeType *currentNode = list->head;

    while (currentNode != NULL) {
        // Deallocate the ghost data
        free(currentNode->ghost);
        currentNode->ghost = NULL; // Set the pointer to NULL after deallocating

        // Move to the next node
        currentNode = currentNode->next;
    }
}

void cleanupGhostList(GhostListType *list){
    NodeType *currentNode = list->head;
    NodeType *nextNode;

    while (currentNode != NULL) {
        // Store the next node
        nextNode = currentNode->next;

        // Deallocate the node
        free(currentNode);

        // Move to the next node
        currentNode = nextNode;
    }

    // Set the head and tail of the list to NULL
    list->head = NULL;
    list->tail = NULL;
}

void printGhost(const GhostType *ghost) {
    // Print the id and likelihood
    printf("ID: %d\n", ghost->id);
    printf("Likelihood: %.2f\n", ghost->likelihood);

    // Print the ghost type as a string
    printf("Type: ");
    switch (ghost->ghostType) {
        case POLTERGEIST: 
            printf("Poltergeist\n"); 
            break;
        case WRAITH: 
            printf("Wraith\n"); 
            break;
        case PHANTOM: 
            printf("Phantom\n"); 
            break;
        case BULLIES: 
            printf("Bullies\n"); 
            break;
        case OTHER: 
            printf("Other\n"); 
            break;
        default: 
            printf("Unknown\n"); 
            break;
    }

    // Print the name of the ghost's room, or "Unknown" if the ghost has no room specified
    printf("Room: ");
    // Check if the ghost has a room and if the room has a name
    if (ghost->room != NULL && ghost->room->name[0] != '\0') {
        printf("%s\n", ghost->room->name);
    } else {
        printf("Unknown\n");
    }
}

void printGhostList(const GhostListType *list){
    NodeType *currentNode = list->head;

    while (currentNode != NULL) {
        // Print the ghost data
        printGhost(currentNode->ghost);
        printf("\n");

        // Move to the next node
        currentNode = currentNode->next;
    }
}

// AI HELPED IMPLEMENT THIS FUNCTION (SEE README)
void addGhostByLikelihood(GhostListType *list, GhostType *ghost) {
    // Allocate memory for a new node
    NodeType *newNode = (NodeType *)malloc(sizeof(NodeType));
    if (newNode != NULL) {
        // Initialize the node data
        newNode->ghost = ghost;
        newNode->next = NULL;

        // If the list is empty, or the new ghost's likelihood is greater than the head's likelihood
        if (list->head == NULL || ghost->likelihood > list->head->ghost->likelihood) {
            // Insert the new node at the head of the list
            newNode->next = list->head;
            list->head = newNode;
            // If the list was empty, set the tail to the new node
            if (list->tail == NULL) {
                list->tail = newNode;
            }
        }
          
        else {
            NodeType *currentNode = list->head;
            // if head not null and new ghost's likelihood is less than the head's likelihood 
            while (currentNode->next != NULL && currentNode->next->ghost->likelihood > ghost->likelihood) {
                // Move to the next node
                currentNode = currentNode->next;
            }
            // Insert the new node after the current node
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            // if new node is the last node, set tail to new node
            if (newNode->next == NULL) {
                list->tail = newNode;
            }
        }
    }
}

void printByLikelihood(const GhostListType *origList, int endsOnly){

    // Declare a temporary list and initialize it as empty
    GhostListType tempList;
    initGhostList(&tempList);

    // Traverse the given list origList
    NodeType *currentNode = origList->head;
    while (currentNode != NULL) {
        // add every ghost in origList to tempList
        addGhostByLikelihood(&tempList, currentNode->ghost);

        currentNode = currentNode->next;
    }

    // If the endsOnly parameter is true (equals 1)
    if (endsOnly) {
        // Only print the most likely and least likely ghosts in the list
        printf("Most likely ghost:\n");
        printGhost(tempList.head->ghost);
        printf("\nLeast likely ghost:\n");
        printGhost(tempList.tail->ghost);
    }
    // If the endsOnly parameter is false
    else {
        // Print each element in the temporary list
        printGhostList(&tempList);
    }

    // Clean up the memory for the temporary list
    cleanupGhostList(&tempList);
}