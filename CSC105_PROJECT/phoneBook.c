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
  if(cList->count == 0)
    return true;
  else 
    return false; 
}


/*********** Create_contactlist() ****************/
conBook* createContactList()
{
	conBook* newbook = (conBook*)malloc(sizeof(conBook));

	if(conBook){

		newbook->root = NULL;
		newbook->count = 0;
		return newbook;
	}
	else{
		return NULL;
	}

}
  

/*********** newContact() ****************/
 _Bool newContact(conBook *cList , info data)
 {
	 node* new_ptr;
	 new_ptr = (node*) malloc (sizeof(node));

	 if(!new_ptr){

		 return false;
	 }
	 else{

		 new_ptr-> left = new_ptr-> right = NULL;
		 new_ptr->data = data;

		 if(cList->root == NULL){

			 cList->root = new_ptr;
		 }
		 else{

			 _insert(cList->root, new_ptr);
		 }
		 cList->count++;
		 return true;
	 }
	 

 }


/************* insertContact() ****************/
node* _insert(node *root, node *newPtr)
{
	if(!root){
		return new_ptr;
	}
	else if(new_ptr->data.key < root->data.key){

		root->left = _insert(root->left, new_ptr);
	}
	else{
		root->right = _insert(root->right, new_ptr);
	}
	return root;
}


/*************** displayContactKList() **************/
void displayContactList(conBook *cList)
{
	if(root){
		displayContactList(root->left);
		printf("\n NAME:: %s \n NUMBER:: %d \nTEL_NUMBER:: %d \n Email:: %s "root->data.key,root->data.NUMBER,root->data.nTEL_NUMBER,root->data.Email);
		displayContactList(root->right);
	}

}


/*************** display()***************/
void _display(node *root)    // inorder trravel : recursive method
{
	if(root!=NULL)
	{
		_display(root->left);
		printf("%d", root->data);
		_display(root->right);
	}
}
  

/************* deleteContact() ************/
_Bool deleteContact(conBook *cList, keyType dltkey)
{
	if(dltkey < cList->root->data.key)
	{
		deleteContact(cList->root->left, dltkey);
	}
	else if(dltkey > cList->root->data.key)
	{
		deleteContact(cList->root->right, dltkey);
	}
	//deletion
	else
	{
		
	}
}


/************* delete() *************/
node* _delete(node *root, keyType dltkey,_Bool *success)   //recursive method
{

} 


/********** searchContact() ***********/
node* _search(node *root,keyType serkey)
{

}

  
/******* modifyContact() ***********/
_Bool modifyContact(conBook *cList ,keyType key, info data)
{

}  


/********* recentCallLog() ************/
_Bool recentCallLog(conBook *cList)
{
  
}


/********* favContact() **************/
_Bool favContact(conBook *cList, keyType key)
{

}


/*********** impExpContact() ***********/


/******** mergeContact() **************/
