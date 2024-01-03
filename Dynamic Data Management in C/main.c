#include "defs.h"

int main(){

  int choice;

  // create a building
  BuildingType building;

  // Initialize the building data
  initBuilding(&building);
  loadBuildingData(&building);


  while (1) {
  // Print the menu and get the user's choice
    printMenu(&choice);

    switch (choice) {
      case 1:
  // 1 = Print rooms
        printRooms(building.rooms);
        break;
      case 2:
  // 2 = Print ghosts
        printGhostList(building.ghosts);
        break;
      case 3:
  // 3 = Print ghosts by likelihood
        printByLikelihood(building.ghosts, 0);
        break;
      case 4:
  // 4 = Print most/least likely ghosts
        printByLikelihood(building.ghosts, 1);
        break;
      case 0:
  // 0 = Exit
        cleanupBuilding(&building);
        return 0;
        default:
  // Invalid choice
          printf("Invalid selection. Please try again.\n");
          break;
        }
    }
  
  return 0;
}

void printMenu(int *choice)
{
  printf("\nMAIN MENU\n");
  printf("  (1) Print rooms\n");
  printf("  (2) Print ghosts\n");
  printf("  (3) Print ghosts by likelihood\n");
  printf("  (4) Print most/least likely ghosts\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%2d", choice);
  while (getchar() != '\n');
}