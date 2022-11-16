#include "../headers.h"


void phAccountCheck() {
  int choice;
  choice=menu("\nDo you have an account ?\n\t1. Yes\n\t2. No\n\t3. Exit",1,3);

  if(choice == 3) return;
  if(choice == 1) {
    pharmacist *phmc = phLogIn();
    if(phmc != NULL) {
      phMenu(*phmc);
    }
  } else {
    pharmacist phmc = phSignUp();
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

  printf("\nEnter your Phone number:_");
  scanf("%[^\n]s", phmc.phone_number);
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

  FILE *fp = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/"
                   "pharmacist/pharmacist.txt","ab");

  if(fp==NULL) {
    printf("file error.");
  }
  fwrite(&phmc, sizeof(pharmacist),1,fp);
  printf("\naccount created successfully.\n");
  fclose(fp);

  return phmc;
}

//---------------------------------------------

pharmacist* phLogIn() {
  char username[30], password[30];
  int found = 0;
  pharmacist *phmc;

  printf("\nEnter your username:_");
  scanf("%s",username);
  fflush(stdin);

  printf("Enter your password:_");
  scanf("%[^\n]s",password);
  fflush(stdin);

  FILE *fp = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/"
                   "pharmacist/pharmacist.txt","rb");

  if(fp==NULL) {
    printf("Error: Cannot open file\n");
    return NULL;
  }
  while(fread(phmc,sizeof(pharmacist),1,fp)){
    if(strcmp(phmc->username,username) == 0 && strcmp(phmc->password,password) == 0) {
      found = 1;
      break;
    }
  }
  fclose(fp);
  if(!found) {
    printf("\nUsername or password is incorrect.\n");
    return NULL;
  }
  return phmc;
}

//------------------------------------------

void phMenu(pharmacist phmc){
  int choice;
  printf("\nWelcome %s!",phmc.fname);
  while(1){
    choice = menu("\nWhich operation you want to do ?\n\t1. Add new medicine"
                  "\n\t2. Delete medicine\n\t3. Update medicine\n\t4. View stock"
                  "\n\t5. Search medicine\n\t6. Update your profile\n\t7. Logout", 1, 7);
    switch (choice) {
      case 1:
        addMedicine();
        break;
      case 2:
        deleteMedicine();
        break;
      case 3:
        updateMedicine();
        break;
      case 4:
        viewStock();
        break;
      case 5:
        searchMedicine();
        break;
      case 6:
        updateInfos();
        break;
      case 7:
        return;
      default:
        break;
    }
  }
}

//------------------------------------------------------

medicine requestMedicineInfos(){
  medicine mdcn;

  printf("\nMEDICINE ID:_");
  scanf("%d",&mdcn.id);
  fflush(stdin);

  printf("\nMEDICINE NAME:_");
  scanf("%s",mdcn.name);
  fflush(stdin);

  printf("\nMEDICINE SUPPLIER NAME:_");
  scanf("%s",mdcn.supplier_name);
  fflush(stdin);

  printf("\nMEDICINE COMPANY NAME:_");
  scanf("%s",mdcn.company_name);
  fflush(stdin);

  printf("\nMEDICINE MANUFACTURING DATE:_");
  scanf("%s",mdcn.mfc_date);
  fflush(stdin);

  printf("\nMEDICINE EXP DATE:_");
  scanf("%s",mdcn.exp_date);
  fflush(stdin);

  printf("\nMEDICINE UNIT COST:_");
  scanf("%d",&mdcn.unit_cost);
  fflush(stdin);

  printf("\nMEDICINE SALE COST:_");
  scanf("%d",&mdcn.sale_cost);
  fflush(stdin);

  printf("\nMEDICINE QUANTITY:_");
  scanf("%d",&mdcn.quantity);
  fflush(stdin);

  return mdcn;
}

//------------------------------------------------------

void addMedicine() {
  medicine mdcn = requestMedicineInfos();

  FILE *fp = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/"
                   "pharmacist/medicine.txt","ab");

  fwrite(&mdcn,sizeof(medicine),1,fp);

  fclose(fp);
}

//------------------------------------------------------

void deleteMedicine() {
  
}

//------------------------------------------------------

void updateMedicine() {

}

//------------------------------------------------------

void viewStock() {

}

//------------------------------------------------------

void searchMedicine() {

}

//------------------------------------------------------

void updateInfos() {

}