/*
    Authors : 1) Rutu Shinde 
              2) Suraj Pandey
              3) Dinesh Gawas
    Program for : PhoneBook
    DS used : Stack, Queue, BST
    Date created :  November 2021 
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"phoneBook.h"

/********** contactlist_isEmpty() ****************/
_Bool contactlist_isEmpty(conBook *cList)
{
  if(conBook->count == 0)
    return true;
  else 
    return false; 
}


/*********** Create_contactlist() ****************/
conBook* createContactList()
{

}
  

/*********** newContact() ****************/
 _Bool newContact(conBook *cList , info data)
 {

 }


/************* insertContact() ****************/
node* _insert(node *root, node *newPtr)
{

}


/*************** displayContactKList() **************/
void displayContactList(conBook *cList)
{

}


/*************** display()***************/
void _display(node *root)    // inorder trravel : recursive method
{

}
  

/************* deleteContact() ************/
_Bool deleteContact(conBook *cList, keyType dltKeyName)
{

}


/************* delete() *************/
node* _delete(node *, keyType,_Bool*)   //recursive method
{

} 


/********** searchContact() ***********/
node* _search(node *root,keyType serKeyName)
{

}

  
/******* modifyContact() ***********/
_Bool modifyContact(conBook *cList ,keyType keyName, info data)
{

}  


/********* recentCallLog() ************/
_Bool recentCallLog(conBook *cList)
{
  
}


/********* favContact() **************/
_Bool favContact(conBook *cList, keyType keyName)
{

}


/*********** impExpContact() ***********/


/******** mergeContact() **************/