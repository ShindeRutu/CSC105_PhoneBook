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

int main()
{

  int choice;
 // node *root;
  info input;
  //keyType inputData;
  int dltKey, serKey, choice2;
  char searchkey[20], key[20];
  bool status;

  printf("\n***********PhoneBook**********\n\n");

  conBook *tree = createContactList();
  queueType q = createQueue();
  

  do
  {
  printf("1-# ADD A CONTACT # \n 2-# SHOW_CONTACT #  \n 3-# EDIT_CONTACT # \n\n  4-# RECENT_CALLS \n 5-# SEARCH \n 6-# DELETE_CONTACT ");
  printf("\nEnter your choice: \n");
  scanf("%d",&choice);
    switch (choice)
    {
    case 1: //INSERT_CONTACT

      
        printf("\nEnter the details to be added:\n\t");
        printf("\nEnter the name: \n");
		scanf(" %[^\n]s",input.key);
		//yha search lga 
		if(search(tree->root, input.key))
		{printf("Name already present....please select another name \n\n");}


		//if(root.key == input.key)){printf("double");}
		else{
		printf("\nEnter the Phone number: \n");
        scanf("%d", &input.mobNumber);
        printf("\nEnter the telephone number: \n");
        scanf("%d", &input.TelNumber);
        printf("\nEnter the email: \n");
        scanf("%s", input.email);
		printf("Is this contact Favourite ?\nIf yes press 1 if No press 0 ");
		if((scanf("%d",&input.fav))== 1)
		{
			enqueue(input.,&q);
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
        printf("Name: %s\n Phone number: %d \n Telphone number: %d\n Email: %s\n", n->data.key, n->data.mobNumber, n->data.TelNumber, n->data.email);
      }
      break;

    case 6: //fav
      break;

    case 7: //delete
      if (!contactlist_isEmpty(tree))
      {
        while (scanf("%s", key) != 1)
        {
          while (getchar() != '\n');
          printf("Invalid input! Please enter a roll no of integer data type.\n");
          printf("\n");
          continue;
        }
        if (deleteContact(tree, key) == true)
          printf("DEL SuccessFul %s \n", key);
        else
          printf(" NOT FOUND");
      }
      else
        printf("Underflow\n");
      break;

      break;

    case 8: //exit
      printf("\nEXIT");
      break;
    default:
      printf("\nInvalid choice please choose between 1-7");
      break;
    }
  } while (choice != 8);
  return 0;
}