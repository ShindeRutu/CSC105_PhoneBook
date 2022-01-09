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

  int choice, ip2;
  node *root;
  info input;
  info input2;
  info input3;
  //keyType inputData;
  char dltKey[20], serKey, choice2, z;
  char searchkey[20], key[20];
  long long int newno, newtelno;
  char newemail[20];
  bool status;
  FILE *rd;
  FILE *wr;

  printf("\n\t\t\t\t\t***********   PHONE-BOOK   **********");

  conBook *tree = createContactList();
  queueType q = createQueue();
  stackType s = createStack();

  do
  {
    printf("\n\n\t\t\t\t\t\t 1-> ADD A CONTACT  \n\t\t\t\t\t\t 2-> SHOW_CONTACTS \n\t\t\t\t\t\t 3-> EDIT_CONTACT \n\t\t\t\t\t\t 4-> CALL \n\t\t\t\t\t\t 5-> SEARCH \n\t\t\t\t\t\t 6->FAVOURITES LIST\n\t\t\t\t\t\t 7-> CALL LOG \n\t\t\t\t\t\t 8-> DELETE_CONTACT\n\t\t\t\t\t\t 9->IMPORT/EXPORT CONTACTS\n\t\t\t\t\t\t 10->EXIT");
    printf("\nEnter your choice: \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1: //INSERT_CONTACT

      printf("\nEnter the details to be added:\n");
      printf("\nEnter the name:\n");
      scanf(" %s", input.key); //it searches first if name present or not

      if (search(tree->root, input.key))
      {
        printf("Name already present....please select another name \n");
      }
      else
      {

        printf("\nEnter the Phone number: \n");

        while (scanf("%lld%c", &input.mobNumber, &z) != 2 || z != '\n')
        {
          while (getchar() != '\n')
            printf("Please enter numbers\n");
          continue;
        }
        printf("\nEnter the telephone number: \n");

        while (scanf("%lld%c", &input.TelNumber, &z) != 2 || z != '\n')
        {
          while (getchar() != '\n')
            printf("Please enter numbers\n");
          continue;
        }

        printf("\nEnter the email-id: \n");
        scanf("%s", input.email);

        printf("\nIs this contact Favourite ?\nIf yes press 1 if No press 0 \n");
        scanf("%d", &input.fav);

        if (input.fav == 1)
        {
          input2 = input;
          enqueue(input2, &q);
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
      printf("\n Enter the name of the person you want to edit: \n");
      scanf("%s", searchkey);
      node *b = search(tree->root, searchkey);
      if (b == NULL)
      {
        printf("Contact with this name is not found \n");
      }
      else
      {
        printf("What do you want to edit? \n");
        printf("1->Change mobile number\n2->Change telephone number\n3->Change email id\n\t");
        scanf("%d", &choice2);
        switch (choice2)
        {

        case 1:
          printf("Enter new mobile number\n\n");
          scanf("%lld", &newno);
          b->data.mobNumber = newno;

          break;

        case 2:
          printf("Enter new Telephone number\n\n");
          scanf("%lld", &newtelno);
          b->data.TelNumber = newtelno;
          break;

        case 3:
          printf("Enter new Email id\n\n");
          scanf("%s", newemail);
          b->data.email - newemail;

          break;

        default:
          printf("please select from 1-2-3\n");
          break;
        }

        //	b->data.mobNumber = 1234;
      }

      break;

    case 4: //CALL
      printf("\n Enter the name of the person you want to call: \n");
      scanf("%[^\n]s", searchkey);
      node *p = search(tree->root, searchkey);
      if (p == NULL)
      {
        printf("Contact with this name is not found \n");
      }
      else
      {
        printf("Contact found\n");
        printf("now calling......\n");
        push(&p->data, &s);
      }
      break;

    case 5: //search
      printf("\n Enter the name of the person you want to search: \n");
      scanf("%[^\n]s", searchkey);
      node *n = search(tree->root, searchkey);
      if (n == NULL)
      {
        printf("Contact with this name is not found \n");
      }
      else
      {
        printf("Contact found\n\n\n");
        printf("\t\t\t\t\t\tName: %s\n\t\t\t\t\t Phone number: %lld\n\t\t\t\t\t Telphone number: %lld\n\t\t\t\t\t Email: %s\n\n", n->data.key, n->data.mobNumber, n->data.TelNumber, n->data.email);
      }
      break;

    case 6: //fav
      if (!isEmpty(q))
      {

        display(&q);
      }
      else
      {
        printf("No favourite contacts to display\n");
      }
      break;

    case 7: //display recent calls

      if (!isstackEmpty(s))
      {
        displaystack(&s);
      }
      else
      {
        printf("No recent calls\n\n");
      }

      break;

    case 8: //delete contact
    {
      if (!contactlist_isEmpty(tree))

      {
        printf("Please enter name.\n");
        scanf("%[^\n]s", dltKey);

        if (deleteContact(tree, dltKey) == true)
          printf("\n\ndata deleted successfully...");
        else
          printf("\n\ndata not deleted...\n");
      }
      else
        printf("No contacts to delete\n");
    }
    break;

    case 9: // Import/Export contacts
    {
      int ip;
      printf("Do you want to import or export contacts\n 1) Import from a file\n 2) Export to a file\n\t");
      scanf("%d", &ip);
      switch (ip)
      {
      case 1:
      {

        char file[20];
        printf("Enter the file name you want to import contacts from: \n");

        scanf("%s", &file);
        rd = fopen(file, "r");
        if (rd == NULL)
        {
          printf("\n\t%s File NOT FOUND!\n", file);
        }
        char c;
        if (c = (fgetc(rd)) != ':')
        {
          printf("This is not a valid file, please choose a file which has been exportd from this system\n");
          break;
        }

        while (c = (fgetc(rd)) != EOF)
        {
          fscanf(rd, "%[^\n]s", &input3.key);
          fscanf(rd, "%lld", &input3.mobNumber);
          fscanf(rd, "%lld", &input3.TelNumber);
          fscanf(rd, "%s", &input3.email);
          fscanf(rd, "%d", &input3.fav);
          if (input3.fav == 1)
          {
            input2 = input;
            enqueue(input3, &q);
          }
          if (newContact(tree, input3))
          {
          }
          else
          {
            printf("can't import %s", input3.key);
          }
        }
        fclose(rd);
        printf("********* Contact(s) imported from file %s *********\n", file);
      }
      break;
      case 2:
      {
        char file2[20];
        if (tree->root == NULL)
        {
          printf("There are no contacts to export");
          break;
        }

        printf("Enter the name of the file you want to export contact to : ");
        scanf("%s", &file2);
        FILE *ww = fopen(file2, "w");
        // fprintf(ww, "done");
        Export(tree, ww);
        fclose(ww);
        printf("*********Contact(s) exported to file %s *********\n", file2);
      }
      break;
      default:
        printf("Enter correct option");
        break;
      }
    }
    break;
    case 10: //exit
      printf("\n\t\t\t\t\tEXIT");
      break;
    default:
      printf("\n\t\t\t\t\tInvalid choice please choose between 1-10");
      break;
    }
  } while (choice != 10);
  return 0;
}