#include<stdio.h>
#include<stdlib.h>
#include "functions.h"
#include<string.h>


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

int logIn(char *fileName) {
  char username[30], password[30];

  printf("\nEnter your username:_");
  scanf("%s",username);
  fflush(stdin);

  printf("Enter your password:_");
  scanf("%[^\n]s",password);
  fflush(stdin);

  pharmacist phmc;
  int found = 0;
  FILE *fp = fopen(fileName,"rb");
  while(fread(&phmc,sizeof(pharmacist),1,fp)){
    if(strcmp(phmc.username,username) == 0 && strcmp(phmc.password,password) == 0) {
      found = 1;
      break;
    }
  }
  if(!found) {
    printf("\nUsername or password is incorrect.");
  }
  return found;
}

//--------------------------------------------

void signUp(char *fileName) {
  pharmacist phmc;

  printf("\nEnter your first name:_");
  scanf("%s", phmc.fname);

  printf("\nEnter your last name:_");
  scanf("%s", phmc.lname);

  printf("\nEnter your Birthday:_");
  scanf("%s", phmc.birthday);

  printf("\nChoose an username:_");
  scanf("%s", phmc.username);

  char pass1[30],pass2[30];
  do{
    printf("\nChoose a password:_");
    scanf("%s",pass1);
    printf("\nConfirm your password:_");
    scanf("%s",pass2);
    if(strcmp(pass1,pass2) == 0) {
      break;
    } else {
      printf("\nYour password doesn't match.");
    }
  } while(1);
  strcpy(phmc.password, pass1);

  FILE *fp = fopen(fileName,"ab");
  fwrite(&phmc, sizeof(pharmacist),1,fp);
  printf("\naccount created successfully.");
  fclose(fp);

}