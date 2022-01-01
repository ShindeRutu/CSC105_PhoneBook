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

  info input;
  keyType inputData;
  int dltKey, serKey;
  
	
  
  printf("\n***********PhoneBook**********\n\n");

	conBook *tree = createContactList();
	
 
	
  
 printf("1-# INSERT_CONTACT # \t 2-# SHOW_CONTACT #\t 3-# EDIT_CONTACT # \n\n \t 4-# RECENT_CALLS \t 5-# FAVOURITES \t 6-# DELETE_CONTACT ");
 printf("\nEnter your choice: \n");
  //  scanf("%d",&choice);
   do{
 	switch(choice){
		 case 1: //INSERT_CONTACT

				 printf("\nEnter the details to be added\n:-\t");
                    scanf("%s%d",input.key,&input.mobNumber,input.email,input.fav);
                		printf("\n");                             
					
                    if(BST_insert(tree,input)==true)
                        printf("\n contact added \n");
                    
			break;
		
		case 2: //show contact list
				if(!isEmpty(tree))
                    {   
                        printf("\nCONTACT LIST: \n");
                        BST_intraverse(tree);
                    }
                    else
                        printf("\n no contacts to display \n");

		break;
		 	 
		case 3: //EDIT_CONTACT


		break;

		case 4: //RECENT_CALLS
		break;

		case 5: //search
		break;

		case 6: //fav
		break;

		case 7: //delete
			if(!isEmpty(tree))
                    {
                       while(scanf("%d",&key) != 1)
						{
							while(getchar()!='\n');

							printf("Invalid input! Please enter a roll no of integer data type.");
							printf("\n");
        				    continue; 

						}
                        if(BST_del(tree,key)==true)
                            printf("\nDEL SuccessFul %d",key);
                        else
                            printf("\n NOT FOUND");
                    }
                    else
                        printf("\nUnderflow");
                        break;

		break;

		case 8: //exit
			printf("\nEXIT");
		break;
		default:
			printf("\nInvalid choice please choose between 1-7");
			break;

			
			  
	 }
  }while(choice!=7);
  return 0;
}