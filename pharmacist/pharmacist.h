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



typedef struct medicine {
    int id;
    int unit_cost;
    int sale_cost;
    int quantity;
    char name[20];
    char supplier_name[20];
    char company_name[20];
    char mfc_date[10];
    char exp_date[10];
}medicine;

void addMedicine();
medicine requestMedicineInfos();
void deleteMedicine();
void updateMedicine();
void viewStock();
void searchMedicine();
void updateInfos(pharmacist phmc);


















#endif //PHARMACYMANAGEMENTSYSTEM_PHARMACIST_H
