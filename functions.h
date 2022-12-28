#ifndef PHARMACYMANAGEMENTSYSTEM_FUNCTIONS_H
#define PHARMACYMANAGEMENTSYSTEM_FUNCTIONS_H

#include "customer/customer.h"

typedef struct record {
    char fname[30];
    char lname[30];
    int id;
    int sale_cost;
    int quantity;
    char medName[20];
    char date_time[30];
} record;

int menu(char *str, int min, int max);
void ClearScreen();
void showRecords();
void commitTransaction(customer cus);

#endif //PHARMACYMANAGEMENTSYSTEM_FUNCTIONS_H
