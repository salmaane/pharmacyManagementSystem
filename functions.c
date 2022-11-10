#include<stdio.h>
#include<stdlib.h>
#include "functions.h"


int menu(char *str,int min,int max) {
  int choice;
  do{
    printf("%s\n\t\tyour choice:_",str);
    scanf("%d",&choice);
    if(choice > max || choice < min) {
      printf("\nEnter a valid choice please.\n");
      continue;
    }
    break;
  }while(1);
  return choice;
}

//---------------------------------------------

void logIn() {
  char username[30], password[30];

  printf("\nEnter your username:_");
  scanf("%s",username);
  fflush(stdin);

  printf("Enter your password:_");
  scanf("%[^\n]s",password);
  fflush(stdin);
}

//--------------------------------------------

void signIn() {

}