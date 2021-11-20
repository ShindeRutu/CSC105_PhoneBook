 
 
 typedef char keyType;
   
   struct info
   {
     keyType key;  
     int number[10];
     char email[20];
   };

   typedef struct info info;


    struct one_contact //node
   {
   	info data;
   	struct  one_contact *left;
    struct one_contact *right;
   };

   typedef struct one_contact node;


    struct contacts //tree
  	{
	struct one_contact *root;
	int count;     
   };
   typedef struct contacts contacts;


_Bool contactlist_isEmpty(contacts *tree);

conatcts* Create_contactlist();

_Bool Insert_contact(contacts *tree , info data);

 node* _insert(node *root, node *newPtr);

void _InorderTraverse(node *root);

_Bool BST_Delete(contacts *tree, keyType dltKey);

node* _delete(node *, keyType,_Bool*);

node* _search(node *root,keyType serKey);

void BST_Destroy(contacts *tree);