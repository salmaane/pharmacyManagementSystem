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
      ClearScreen();
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
  ClearScreen();
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
  ClearScreen();

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

//--------------------------------------------

void cusMenu(customer cus) {
  int choice;
  printf("\nWelcome %s",cus.fname);
  while(1) {
    choice = menu("\nWhich operation you want to do ?\n\t1. View medicines\n\t2. Shop medicine"
                  "\n\t3. View cart\n\t4. Confirm Orders\n\t5. LogOut",1,5);
    switch(choice) {
      case 1:
        showMedicines();
        break;
      case 2:
        shopMedicine();
        break;
      case 3:
        viewCart();
        break;
      case 4:
        confirmOrders();
        break;
      case 5:
        ClearScreen();
        printf("\nLogged out successfully.");
        remove("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/customer/cart.txt");
        return;
      default:
        break;
    }
  }
}


//-------------------------------------------------

void showMedicines() {
  ClearScreen();
  medicine mdcn;
  FILE *fp = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/"
                   "pharmacist/medicine.txt","rb");
  if(fp == NULL) {
    printf("\nfile not found.");
  }
  while(fread(&mdcn,sizeof(medicine),1,fp)) {
    printf("\n\tMEDICINE NAME: %s"
           "\n\tMEDICINE PRICE: %d DH\n"
            ,mdcn.name,mdcn.sale_cost);
  }
  fclose(fp);
}

//-------------------------------------------------


void shopMedicine() {
  medicine mdcn;
  char name[20];
  int found = 0;
  printf("Enter Medicine name:_");
  scanf("%s",name);
  fflush(stdin);

  FILE *fp = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/"
                   "pharmacist/medicine.txt","rb");

  while(fread(&mdcn,sizeof(medicine),1,fp)) {
    for(int i = 0; mdcn.name[i]; i++){
      mdcn.name[i] = tolower(mdcn.name[i]);
    }
    for(int i = 0; name[i]; i++){
      name[i] = tolower(name[i]);
    }
    if(strcmp(mdcn.name, name) == 0) {
      found = 1;
      break;
    }
  }
  ClearScreen();
  if(found) {
    payment(mdcn);
  } else {
    printf("\nSorry %s is not available.",name);
  }
}

//------------------------------------------------

void payment(medicine mdcn) {
  int quantity;
  do{
    printf("\nEnter wanted quantity:_");
    scanf("%d",&quantity);
    ClearScreen();
    if(quantity>mdcn.quantity) {
      printf("\nSorry only %d %s left.",mdcn.quantity,mdcn.name);
    }
    if(quantity == 0) {
      printf("\nMedicine isn't added to cart.");
      return;
    }
  } while(quantity>mdcn.quantity);

  addToCart(mdcn,quantity);
}

//------------------------------------------------

void addToCart(medicine mdcn,int quantity) {
  mdcn.quantity = quantity;

  FILE *fp = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/"
                   "customer/cart.txt","ab");
  if(fp == NULL) {
    printf("Error: file");
    return;
  }

  fwrite(&mdcn,sizeof(medicine),1,fp);
  printf("\n%d %s added to cart.",quantity,mdcn.name);

  fclose(fp);
}

//------------------------------------------------

void viewCart() {
  medicine mdcn;
  FILE *fp = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/"
                   "customer/cart.txt","rb");
  if(fp == NULL) {
    printf("\nYour Cart is Empty.");
    return;
  }

  int total =0;
  while(fread(&mdcn,sizeof(medicine),1,fp)) {
    printf("\n\tMEDICINE NAME: %s"
           "\n\tMEDICINE PRICE: %d DH\n\tMEDICINE QUANTITY: %d\n"
            ,mdcn.name,mdcn.sale_cost,mdcn.quantity);
    total += (mdcn.sale_cost * mdcn.quantity);
  }
  if(fp != NULL) {
    printf("\n\t====> You have in total : %dDH\n", total);
  }
  fclose(fp);
}

//------------------------------------------------

void confirmOrders() {
  medicine mdcn;
  FILE *fp = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/"
                   "customer/cart.txt","rb");
  if(fp == NULL) {
    printf("\nYour Cart is Empty.");
    return;
  }

  int total =0;
  while(fread(&mdcn,sizeof(medicine),1,fp)) {
    total += (mdcn.sale_cost * mdcn.quantity);
  }
  printf("\n====> You have in total : %dDH", total);

  fclose(fp);

  int choice = menu("\nDo you want to confirm your orders ?\n\t1. Yes\n\t2. No",1,2);
  if(choice == 2) {
    printf("\nOrders are not confirmed");
    return;
  }
  soldMedicine();
  if(remove("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/customer/cart.txt")==0) {
    printf("\nOrders confirmed, Thank you.");
  }
}

//------------------------------------------------

void soldMedicine() {
  medicine mdcn;
  FILE *fp = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/"
                   "customer/cart.txt","rb");

  while(fread(&mdcn,sizeof(medicine),1,fp)) {
    removeMedicine(mdcn);
  }

  fclose(fp);
}

//------------------------------------------------

void removeMedicine(medicine mdcn) {
  medicine stocked;
  FILE *fp = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/"
                   "pharmacist/medicine.txt","rb");

  fseek(fp,0,SEEK_END);
  int size = ftell(fp) / sizeof(medicine);
  medicine *medi = (medicine*)malloc(size*sizeof(medicine));

  int i=0;
  rewind(fp);
  while(fread(&stocked,sizeof(medicine),1,fp)) {
    if(mdcn.id == stocked.id) {
      stocked.quantity = stocked.quantity-mdcn.quantity;
      if(stocked.quantity < 0 ) stocked.quantity = 0;
    }
    medi[i] = stocked;
    i++;
  }
  fclose(fp);

  FILE *fw = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/"
                   "pharmacist/medicine.txt","wb");
  for(int j=0;j<i;j++) {
    fwrite(&medi[j],sizeof(medicine),1,fw);
  }
  fclose(fw);
}