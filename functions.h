#ifndef PHARMACYMANAGEMENTSYSTEM_FUNCTIONS_H
#define PHARMACYMANAGEMENTSYSTEM_FUNCTIONS_H

typedef struct pharmacist {
    char fname[30];
    char lname[30];
    char birthday[10];
    char username[30];
    char password[30];
} pharmacist;

int menu(char *str, int min, int max);

int logIn(char *fileName);

void signUp(char *fileName);


#endif //PHARMACYMANAGEMENTSYSTEM_FUNCTIONS_H
