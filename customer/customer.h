#ifndef PHARMACYMANAGEMENTSYSTEM_CUSTOMER_H
#define PHARMACYMANAGEMENTSYSTEM_CUSTOMER_H

#include "../pharmacist/pharmacist.h"

typedef struct customer {
    char fname[30];
    char lname[30];
    char birthday[10];
    char phone_number[11];
    char username[20];
    char password[20];
} customer;


void cusAccountCheck();
void cusMenu(customer cus);
customer cusRequestInfos();
customer* cusLogIn();
customer cusSignUp();
void updateInfosCUS(customer cus);

void shopMedicine();
void payment(medicine mdcn);
void addToCart(medicine mdcn,int quantity);
void showMedicines();
void viewCart();
void confirmOrders(customer cus);
void soldMedicine();
void removeMedicine(medicine mdcn);














#endif //PHARMACYMANAGEMENTSYSTEM_CUSTOMER_H
