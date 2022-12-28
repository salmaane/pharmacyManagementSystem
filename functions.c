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

//-------------------------------------------

void showRecords() {
   record log;
   FILE *fp = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem"
                    "/pharmacist/log.txt","rb");

   printf("---------------------------------------------------");
   while(fread(&log,sizeof(record),1,fp)){
     printf("\n\tMedicine Id: %d\n\tCustomer: %s %s\n\tMedicine Name: %s\n\tDate and Time: %s"
            "\tQuantity: %d\n\tPrice: %d DH\n\tTotal: %d DH\n",log.id, log.fname,
            log.lname, log.medName, log.date_time, log.quantity, log.sale_cost, log.sale_cost*log.quantity);
     printf("---------------------------------------------------");
   }

   fclose(fp);
}

//-----------------------------------------

void commitTransaction(customer cus) {
  medicine mdcn;
  record log;

  time_t rawTime;
  struct tm *info;
  time(&rawTime);
  info = localtime(&rawTime);

  FILE *fr = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/"
                   "customer/cart.txt","rb");
  FILE *fw = fopen("C:/Users/pc/Desktop/dev/C/pharmacyManagementSystem/pharmacist/log.txt","ab");

  while(fread(&mdcn,sizeof(medicine),1,fr)) {
    log.id = mdcn.id;
    log.sale_cost = mdcn.sale_cost;
    log.quantity = mdcn.quantity;
    strcpy(log.fname,cus.fname);
    strcpy(log.lname,cus.lname);
    strcpy(log.medName,mdcn.name);
    strcpy(log.date_time, asctime(info));

    fwrite(&log,sizeof(record),1,fw);
  }

  fclose(fr);
  fclose(fw);
}