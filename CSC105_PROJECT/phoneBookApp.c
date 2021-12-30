/*
    Authors : 1) Rutu Shinde 
              2) Suraj Pandey
              3) Dinesh Gawas
    Program for : PhoneBook
    DS used : Stack, Queue, BST
    Date created :  November 2021 
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "phoneBook.h"


int main()
{

int choice;
  keyType inputData;
  int dltKey, serKey;
  
	
  
  printf("\n***********PhoneBook**********\n\n");

	conBook *cb = createContactList();
	
  do{
	// conBook *contact_book = createContactList();
 	//  if(!contact_book)
	//   printf("failed");
  
  
 printf("1-# CREATE_PHONEBOOK # \t 2-# INSERT_CONTACT # \t 3-# SHOW_CONTACT #\t 4-# EDIT_CONTACT # \n\n 5-# CALL \t 6-# RECENT_CALLS \t 7-# FAVOURITES \t 8-# DELETE_CONTACT \t 9-# DELETE_ALL_CONTACTS");
 printf("\nEnter your choice: \n");
  //  scanf("%d",&choice);
 	switch(choice){
		 case 1: 
		 	 
			  break;
			  
	 }
  }while(choice!=10);
  return 0;
}