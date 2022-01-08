/*
    Authors : 1) Rutu Shinde   < ........left........ >
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
#include "queue.h"
#include "stack.h"

int main()
{

  int choice;
  node *root;
  info input;
  info input2;
  //keyType inputData;
  char dltKey[20], serKey, choice2;
  char searchkey[20], key[20];
  bool status;

  printf("\n\t\t\t\t\t***********   PHONE-BOOK   **********\n\n");

  conBook *tree = createContactList();
  queueType q = createQueue();
  stackType s = createStack();
  
  

  do
  {
  printf("\t\t\t\t\t\t 1-> ADD A CONTACT  \n\t\t\t\t\t\t 2-> SHOW_CONTACTS \n\t\t\t\t\t\t 3-> EDIT_CONTACT \n\t\t\t\t\t\t 4-> RECENT_CALLS \n\t\t\t\t\t\t 5-> SEARCH \n\t\t\t\t\t\t 6->FAV\n\t\t\t\t\t\t 7->CALL\n\t\t\t\t\t\t 8-> DELETE_CONTACT\n\t\t\t\t\t\t 8->EXIT");
  printf("\nEnter your choice: \n");
  scanf("%d",&choice);
    switch (choice)
    {
    case 1: //INSERT_CONTACT

      
        printf("\nEnter the details to be added:\n");
        printf("\nEnter the name:\n");
		scanf(" %[^\n]s",input.key); //it searches first if name present or not
		

		if(search(tree->root, input.key))
		{printf("Name already present....please select another name \n");}


		//if(root.key == input.key)){printf("double");}
		else{
		printf("\nEnter the Phone number: \n");
        scanf("%d", &input.mobNumber);
        printf("\nEnter the telephone number: \n");
        scanf("%d", &input.TelNumber);
        printf("\nEnter the email: \n");
        scanf("%s", input.email);
		printf("Is this contact Favourite ?\nIf yes press 1 if No press 0 \n");
		scanf("%d",&input.fav);
		if(input.fav==1){
			input2 = input;
			enqueue(input2,&q);
		}
		
        if (newContact(tree, input))
        {
          printf("\n contact added \n");

		}        
		}
      
      break;

    case 2: //show contact list
      if (!contactlist_isEmpty(tree))
      {
        printf("\nCONTACT LIST: \n");
        displayContactList(tree);
      }
      else
        printf("\n no contacts to display \n");

      break;

    case 3: //EDIT_CONTACT

      break;

    case 4: //RECENT_CALLS
			if(!isstackEmpty(s)){
				displaystack(&s);
			}
			else{
				printf("No recent calls\n\n");
			}
      break;

    case 5: //search
    printf("\n Enter the name of the person you want to search: \n");
      scanf("%s",searchkey);
      node *n = search(tree->root, searchkey);
      if (n == NULL)
      {
        printf("Contact with this name is not found \n");
      }
      else
      {
        printf("Contact found\n\n\n");
        printf("\t\t\t\t\t\tName: %s\n\t\t\t\t\t Phone number: %d\n\t\t\t\t\t Telphone number: %d\n\t\t\t\t\t Email: %s\n\n", n->data.key, n->data.mobNumber, n->data.TelNumber, n->data.email);
     
	  }
      break;

    case 6: //fav
		if(!isEmpty(q)){
 
			display(&q);
		}
		else{
			printf("No favourite contacts to display\n");
		}
      break;

	case 7: //call
		printf("\n Enter the name of the person you want to call: \n");
      	scanf("%s",searchkey);
      	node * p =  search(tree->root, searchkey);
      	if (p == NULL)
      	{
       	 	printf("Contact with this name is not found \n");
      	}
      	else
      	{
       	 	printf("Contact found\n");
			printf("now calling......\n");
			push(&p->data.key,&s);


       	 	// printf("\t\t\t\t\tName: %s\n\t\t\t\t\t Phone number: %d\n\t\t\t\t\t Telphone number: %d\n\t\t\t\t\t Email: %s\n\n", n->data.key, n->data.mobNumber, n->data.TelNumber, n->data.email);
     
	  	}
	break;

    case 8: //delete contact
      		{if (!contactlist_isEmpty(tree))

              {
               printf("Please enter name.\n");
			   scanf("%s",dltKey);

                    if(deleteContact(tree,dltKey)==true)
						printf("\n\ndata deleted successfully...");
                    else
                      printf("\n\ndata not deleted...\n");
                 	}
                 	else
                    	printf("No contacts to delete\n");
               		} break;


    case 9: //exit
      printf("\n\t\t\t\t\tEXIT");
      break;
    default:
      printf("\n\t\t\t\t\tInvalid choice please choose between 1-7");
      break;
    }
  } while (choice != 9);
  return 0;
}