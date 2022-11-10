#include<stdio.h>
#include<stdlib.h>
#include "pharmacist.h"
#include "functions.h"


void phLogin() {
  int choice;
  choice = menu("\nDo you have an account ?\n\t1. Yes\n\t2. No\n\t3. Exit",1,3);
  if(choice == 3) return;
  if(choice == 1) {
    logIn();
  } else {
    signIn();
  }
}