/*
    Authors : 1) Rutu Shinde 
              2) Suraj Pandey
              3) Dinesh Gawas
    Program for : PhoneBook
    DS used : Stack, Queue, BST
    Date created :  November 2021 
*/ 

#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

  typedef char keyType;   // fr search key
   
  //to store mandatory info of the person
  struct info
  {
    keyType key[20];        // name of the person
    char companyName;   
    int  mobNumber;  //contact_num : mobile
    int  TelNumber;  //contact num : telephone(optional)
    char email[20]; 
	short fav;    // email_add of contact
  };
  typedef struct info info;
  


  //to store additional info of the person (optional case)
  struct additionalInfo
  { 
    int  wrkContact[10];  // contact of work place   
    char nickName;      // nick name of the person
    char dob[10];       //birth date : format = day-month-yr 
    char relationship[10];  // realtion with contact
    char website[40];     // web add 
  };
  typedef struct additionalInfo addInfo;
   

  // to point previous,next contact
  struct one_contact        //node
  {
   	info data;
   	struct one_contact *left;    //point to the previous contact
    struct one_contact *right;    //point to the next contact
  };
  typedef struct one_contact node;


  // contact list tree
  struct contactBook //tree
  {
	  struct one_contact *root;    // first contact
	  int count;                   // to keep the count of contacts
  };
  typedef struct contactBook conBook;


  //to check if list is empty
  _Bool contactlist_isEmpty(conBook *cList);
  
  // to create the contact list once the program runs
  conBook* createContactList();
  
  // to add new contact to the list
  bool newContact(conBook *cList , info data);
  node* _insert(node *root, node *newPtr);

  // display contact list
  void displayContactList(conBook *cList);
  
  void _display_contactlist(node *root);    // inorder trav : recursive method
  
  // to delete the contact from the list
  _Bool deleteContact(conBook *cList, keyType dltKeyName[]);
  node* _delete(node *root, keyType dltkey[], bool *success);   //recursive method
  
  // to search the contact
  node* search(node *root,keyType serKeyName[]);
  
  // to modify/edit the contact
  _Bool modifyContact(conBook *cList ,keyType keyName, info data);

  // display recent call list
  _Bool recentCallLog(conBook *cList);

  // add contact to fav list
 _Bool favContact(conBook *cList, keyType keyName);

  // merge contact

  // import/export contact

  //void BST_Destroy(contacts *tree);

#endif