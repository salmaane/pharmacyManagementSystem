#include "headers.h"



int main() {
  printf("\n=============  Welcome to ENSAH Pharmacy  =====================\n\n");

  int choice;
  do {
    choice = menu("\nYou are :\n\t1. Pharmacist\n\t2. Customer\n\t3. Exit",1,3);
    switch(choice) {
      case 1 :
        phAccountCheck();
        break;
      case 2 :
        break;
      case 3 :
        printf("Have a good day!");
      default:
        break;
    }
  } while (choice != 3);

}
