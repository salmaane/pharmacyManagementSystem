#ifndef PHARMACYMANAGEMENTSYSTEM_PHARMACIST_H
#define PHARMACYMANAGEMENTSYSTEM_PHARMACIST_H



typedef struct pharmacist {
    char fname[30];
    char lname[30];
    char birthday[10];
    char phone_number[11];
    char username[20];
    char password[20];
} pharmacist;

void phAccountCheck();
pharmacist* phLogIn();
pharmacist phSignUp();
pharmacist requestInfos();
void phMenu(pharmacist phmc);

void addMedicine();
void deleteMedicine();
void updateMedicine();
void viewStock();
void searchMedicine();
void updateInfos();


















#endif //PHARMACYMANAGEMENTSYSTEM_PHARMACIST_H
