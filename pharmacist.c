#include "headers.h"


void phAccountCheck() {
  int choice;
  pharmacist phmc;
  choice=menu("\nDo you have an account ?\n\t1. Yes\n\t2. No\n\t3. Exit",1,3);

  if(choice == 3) return;
  if(choice == 1) {
    phmc = phLogIn();
    phMenu(phmc);
  } else {
    phmc = phSignUp();
    phMenu(phmc);
  }
}

//------------------------------------------------------

pharmacist requestInfos(){
  pharmacist phmc;

  printf("\nEnter your first name:_");
  scanf("%[^\n]s", phmc.fname);
  fflush(stdin);

  printf("\nEnter your last name:_");
  scanf("%[^\n]s", phmc.lname);
  fflush(stdin);

  printf("\nEnter your Birthday:_");
  scanf("%[^\n]s", phmc.birthday);
  fflush(stdin);

  printf("\nChoose an username:_");
  scanf("%[^\n]s", phmc.username);
  fflush(stdin);

  return phmc;
}

//-----------------------------------------------

pharmacist phSignUp() {

  pharmacist phmc = requestInfos();
  char pass1[30],pass2[30];

  do{
    printf("\nChoose a password (between 8 and 20 characters):_");
    scanf("%[^\n]s",pass1);
    fflush(stdin);
    if(strlen(pass1)<8 || strlen(pass1)>20) {
      continue;
    }
    printf("\nConfirm your password:_");
    scanf("%[^\n]s",pass2);
    fflush(stdin);
    if(strcmp(pass1,pass2) == 0) {
      break;
    } else {
      printf("\nYour password doesn't match.\n");
    }
  } while(1);
  strcpy(phmc.password, pass1);

  FILE *fp = fopen("../pharmacist.txt","ab");

  if(fp==NULL) {
    printf("file error.");
  }
  fwrite(&phmc, sizeof(pharmacist),1,fp);
  printf("\naccount created successfully.");
  fclose(fp);

  return phmc;
}

//---------------------------------------------

pharmacist phLogIn() {
  char username[30], password[30];
  int found = 0;
  pharmacist phmc;

  printf("\nEnter your username:_");
  scanf("%s",username);
  fflush(stdin);

  printf("Enter your password:_");
  scanf("%[^\n]s",password);
  fflush(stdin);

  FILE *fp = fopen("../pharmacist.txt","rb");

  if(fp==NULL) {
    printf("file error.");
  }
  while(fread(&phmc,sizeof(pharmacist),1,fp)){
    if(strcmp(phmc.username,username) == 0 && strcmp(phmc.password,password) == 0) {
      found = 1;
      break;
    }
  }
  fclose(fp);
  if(!found) {
    printf("\nUsername or password is incorrect.");
  }
  return phmc;
}

//------------------------------------------

void phMenu(pharmacist phmc){

}