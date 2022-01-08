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
#include <string.h>
#include "phoneBook.h"
#include "stack.h"

/********** contactlist_isEmpty() ****************/
_Bool contactlist_isEmpty(conBook *cList)
{
  if (cList->count == 0)
    return true;
  else
    return false;
}

/*********** Create_contactlist() ****************/
conBook *createContactList()
{
  conBook *newbook = (conBook *)malloc(sizeof(conBook));

  if (!newbook)
  {

    return NULL;
  }
  else
  {

    newbook->root = NULL;
    newbook->count = 0;
    return newbook;
  }
}

/*********** newContact() ****************/
bool newContact(conBook *cList, info data)
{
	
	{
  node *new_ptr;
  new_ptr = (node *)malloc(sizeof(node));

  if (!new_ptr)
  {

    return false;
  }
  else
  {

    new_ptr->left = new_ptr->right = NULL;
    new_ptr->data = data;

    if (cList->root == NULL)
    {

      cList->root = new_ptr;
    }
    else
    {
    //   bool status = _insert(cList->root, new_ptr);
    //   if (!status)
    //   {
    //     return false;
    //   }
    _insert(cList->root, new_ptr);
    }
    cList->count++;
    return true;
  }
}
}



/************* insertContact() ****************/
node* _insert(node *root, node *newPtr)
{

  if(!root){
  		return newPtr;
  	}
  	if(strcmp(newPtr->data.key, root->data.key)<0){

  		root->left = _insert(root->left, newPtr);
  	}
  	else if(strcmp(newPtr->data.key, root->data.key)>0)
	{
  		root->right = _insert(root->right, newPtr);
  	}
	else
	{
		printf("Name already present....please select another name");
		return NULL;
	}
  	return root;
}


/*************** display contact()***************/
void _display_contactlist(node *root) // inorder trravel : recursive method
{
  if (root != NULL)
  {
    _display_contactlist(root->left); //inorder
    //_print(root->data.key);
    printf("Name: %s\n Phone number: %d \n Telphone number: %d\n Email: %s \n\n", root->data.key, root->data.mobNumber, root->data.TelNumber, root->data.email);
    _display_contactlist(root->right);
  }
}

/*************** displayContactKList() **************/
void displayContactList(conBook *cList)
{
  _display_contactlist(cList->root);
}



/************* deleteContact() ************/
bool deleteContact(conBook *cList, keyType dltkey)
{
  bool success;
  node *newRoot;
  newRoot = _delete(cList->root, dltkey, &success);
  if(success)
  {
    cList->root = newRoot;
    cList->count--;
  }
  return success;
}

/************* delete() *************/
node *_delete(node *root, keyType dltkey, bool *success) //recursive method
{
  if (root == NULL)
  {
    *success = false;
    return NULL;
  }
 	 if(strcmp(dltkey, root->data.key) <0 )
  	{
    	root->left = _delete(root->left, dltkey, success);
  	}
  	else if (strcmp(dltkey, root->data.key) >0 )
  	{
    	root->right = _delete(root->right, dltkey, success);
  	}
  	else
  	{
    	if (root->left && root->right) // 2 children
    {
      //finding inorder predecessor for node to be deleted
      node *inorder_pre = root->left;
      while (inorder_pre->right)
      {
        inorder_pre = inorder_pre->right;
      }
      //copy data of inorder into node to deleted
      root->data = inorder_pre->data;
      //delete inorder pre
      root->left = _delete(root->left, inorder_pre->data.key, success);
    }
    else //0 or 1 child
    {
      node *temp = root;
      if (root->left == NULL)
      {
        root = root->right;
      }
      else if (root->right == NULL)
      {
        root = root->left;
      }
      free(temp);
      *success = true;
    }
  }
  return root;
}

/********** searchContact() ***********/
node *search(node *root, keyType serkey)
{

  if (root == NULL)
  {
    return NULL;
  }
  if (strcmp(root->data.key, serkey) == 0)
  {
    return root;
  }
  else if (strcmp(serkey, root->data.key) <0)
  {
    return search(root->left, serkey);
  }
  else
  {
    return search(root->right, serkey);
  }
}


/********* recentCallLog() ************/
_Bool recentCallLog(conBook *cList)
{
	//incoming, outgoing and missed flag if 1 then added initially 0
}

/********* callContact() **************/
// node *call(node *, keyType)
// {

//   if (root == NULL)
//   {
//     return NULL;
//   }
//   if (strcmp(root->data.key, serkey) == 0)
//   {

//     return root;
//   }
//   else if (strcmp(serkey, root->data.key) == -1)
//   {
//     return search(root->left, serkey);
//   }
//   else
//   {
//     return search(root->right, serkey);
//   }
// }

