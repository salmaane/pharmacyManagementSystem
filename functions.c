#include "headers.h"


int menu(char *str,int min,int max) {
  int choice;
  do{
    printf("%s\n\t\tyour choice:_",str);
    scanf("%d",&choice);
    fflush(stdin);
    ClearScreen();

    if(choice > max || choice < min) {
      printf("\nEnter a valid choice please.\n");
      continue;
    }
    break;
  }while(1);
  return choice;
}

//-------------------------------------------

void ClearScreen()
{
  int n;
  for (n = 0; n < 10; n++)
    printf( "\n\n\n\n\n\n\n\n\n\n" );
}
