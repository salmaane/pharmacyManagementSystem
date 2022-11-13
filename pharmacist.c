#include<stdio.h>
#include<stdlib.h>
#include "pharmacist.h"
#include "functions.h"


void phLogin() {
  int choice,found;
  choice=menu("\nDo you have an account ?\n\t1. Yes\n\t2. No\n\t3. Exit",1,3);

  if(choice == 3) return;
  if(choice == 1) {
    found = logIn("pharmacist.txt");
    if(found) phMenu();
  } else {
    signUp("pharmacist.txt");
  }
}


void phMenu() {
//  int choice = menu("");
}