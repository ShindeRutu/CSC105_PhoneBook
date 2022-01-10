
#include<stdbool.h>
#include "phoneBook.h"
#ifndef STACK_H
    #define STACK_H
    typedef info* eleTypes;
    
    //DATA
    struct stack
    {
        struct stack_node *top;  
        int count;
    };
    typedef struct stack stackType;

    struct stack_node
    {
        eleTypes data;
        struct stack_node *next;

    };
    typedef struct stack_node snode;

    //prototypes
    eleTypes peek(stackType s);
    //Function:      Returns top element of the stack without deleting.
    //Input:         stackType
    //Precondition:  stack is not Empty
    //Output:        Element from top of the stack
    //Postcondition: none.
    eleTypes pop(stackType *s);
    //Function:      removes Element from the top.
    //Input:         *StackType
    //Precondition:  stack is not empty
    //Output:        element from top of the stack 
    //Postcondition: element at the top deleted
    void destroyStack(stackType *);
    //Function:      Destroys the stak and free memory
    //Input:         *stackType
    //Precondition:  none
    //Output:        none
    //Postcondition: delete all memory and free memory
    stackType createStack();
    //Function:      creates a new empty stack
    //Input:         none
    //Precondition:  none
    //Output:        stackType
    //Postcondition: An empty stack is created
    _Bool push(eleTypes ele, stackType *s);
    //Function:      insert an element on top
    //Input:         *stackType, elementType
    //Precondition:  stack is not full
    //Output:        true if successfull, false if unsuccessfull
    //Postcondition: new element is inserted
    _Bool isstackFull(stackType s);
    //Function:      check if stack is full
    //Input:         stackType
    //Precondition:  none
    //Output:        true if full, false if not full
    //Postcondition: none
    _Bool isstackEmpty(stackType s);
    //Function:      check if stack is empty
    //Input:         stackType
    //Precondition:  none
    //Output:        true if empty, false if not empty
    //Postcondition: none
    void displaystack(stackType *s);
#endif