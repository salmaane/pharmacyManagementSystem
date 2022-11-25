#ifndef PHARMACYMANAGEMENTSYSTEM_CUSTOMER_H
#define PHARMACYMANAGEMENTSYSTEM_CUSTOMER_H


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



#endif //PHARMACYMANAGEMENTSYSTEM_CUSTOMER_H
