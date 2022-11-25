#include "../headers.h"


void cusAccountCheck() {
  int choice;
  choice=menu("\nDo you have an account ?\n\t1. Yes\n\t2. No\n\t3. Exit",1,3);

  if(choice == 3) return;
  if(choice == 1) {
    customer *cus = cusLogIn();
    if(cus != NULL) {
      cusMenu(*cus);
    }
  } else {
    customer cus = cusSignUp();
    cusMenu(cus);
  }
}

//------------------------------------------------------

customer cusRequestInfos(){
  customer cus;

  printf("\nEnter your first name:_");
  scanf("%[^\n]s", cus.fname);
  fflush(stdin);

  printf("\nEnter your last name:_");
  scanf("%[^\n]s", cus.lname);
  fflush(stdin);

  printf("\nEnter your Birthday (dd/mm/yyyy):_");
  scanf("%[^\n]s", cus.birthday);
  fflush(stdin);

  printf("\nEnter your Phone number:_");
  scanf("%[^\n]s", cus.phone_number);
  fflush(stdin);

  printf("\nChoose an username:_");
  scanf("%[^\n]s", cus.username);
  fflush(stdin);

  return cus;
}

//-----------------------------------------------

customer cusSignUp() {

  customer cus = cusRequestInfos();
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
  strcpy(cus.password, pass1);

  FILE *fp = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/"
                   "customer/customer.txt","ab");

  if(fp==NULL) {
    printf("file error.");
  }
  fwrite(&cus, sizeof(customer),1,fp);
  printf("\naccount created successfully.\n");
  fclose(fp);

  return cus;
}

//---------------------------------------------

customer* cusLogIn() {
  char username[30], password[30];
  int found = 0;
  customer *cus;

  printf("\nEnter your username:_");
  scanf("%s",username);
  fflush(stdin);

  printf("Enter your password:_");
  scanf("%[^\n]s",password);
  fflush(stdin);

  FILE *fp = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/"
                   "customer/customer.txt","rb");

  if(fp==NULL) {
    printf("Error: Cannot open file\n");
    return NULL;
  }
  while(fread(cus,sizeof(customer),1,fp)){
    if(strcmp(cus->username,username) == 0 && strcmp(cus->password,password) == 0) {
      found = 1;
      break;
    }
  }
  fclose(fp);
  if(!found) {
    printf("\nUsername or password is incorrect.\n");
    return NULL;
  }
  return cus;
}

//-------------------------------------------

void cusMenu(customer cus) {
  printf("Logged in!");
}