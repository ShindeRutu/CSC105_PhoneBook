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
  int dltKey, serKey, choice2;
  char searchkey[20], key[20];
  bool status;

  printf("\n***********PhoneBook**********\n\n");

  conBook *tree = createContactList();

  do
  {
  printf("1-# ADD A CONTACT # \t 2-# SHOW_CONTACT #\t 3-# EDIT_CONTACT # \n\n \t 4-# RECENT_CALLS \t 5-# SEARCH \t 6-# DELETE_CONTACT ");
  printf("\nEnter your choice: \n");
  scanf("%d",&choice);
    switch (choice)
    {
    case 1: //INSERT_CONTACT

      do
      {
        printf("\nEnter the details to be added:\n\t");
        printf("\nEnter the name: \n\t");
        scanf("%s", &input.key);
        printf("\nEnter the Phone number: \n\t");
        scanf("%s", &input.mobNumber);
        printf("\nEnter the telephone number: \n\t");
        scanf("%s", &input.TelNumber);
        printf("\nEnter the email: \n\t");
        scanf("%s", &input.email);

        if (newContact(tree, input))
        {
          printf("\n contact added \n");

          status = false;
        }
        else
        {
          printf("Contact can't be added, Please enter different name");
          printf("1) Enter again \n 2) Quit to previous menu");
          scanf("%d", &choice2);
          if (choice2 == 1)
          {
            status = true;
          }
          else if (choice2 == 2)
          {
            status = false;
          }
        }
      } while (status==true);

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
      printf("Enter the name of the person you want to search: ");
      scanf("%s", &searchkey);
      node *n = search(tree->root, searchkey);
      if (n == NULL)
      {
        printf("Contact with this name is not found");
      }
      else
      {
        printf("Contact found");
        printf("Name: %s\n Company name: %s \n Phone number: %s \n Telphone number: %s\n Email; %s", n->data.key, n->data.companyName, n->data.mobNumber, n->data.TelNumber, n->data.email);
      }
      break;

    case 6: //fav
      break;

    case 7: //delete
      if (!contactlist_isEmpty(tree))
      {
        while (scanf("%d", &key) != 1)
        {
          while (getchar() != '\n');
          printf("Invalid input! Please enter a roll no of integer data type.");
          printf("\n");
          continue;
        }
        if (deleteContact(tree, key) == true)
          printf("\nDEL SuccessFul %d", key);
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
  } while (choice != 8);
  return 0;
}