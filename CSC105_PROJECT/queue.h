/*
                AUTHOR : 2128_dinesh
                PROGRAM: HEADER FILE OF IMPLEMENTATION FILE for QUEUE USING LINKED LIST
                DATE CREATED: SEPT 2021
                DATE MODIFIED: SEPT 2021
 */
#include <stdbool.h>
#include "phoneBook.h"
#ifndef _QUEUE_H
#define _QUEUE_H
typedef info eleType;

//DATA
struct queue
{
    struct queue_node *front; //start
    struct queue_node *rear;
    int count;
};
typedef struct queue queueType;

struct queue_node
{
    eleType data;
    struct queue_node *next;
};
typedef struct queue_node qnode;

//prototypes

// Function: removes element from front of the queue
// Precondition: queue is not empty
// Input: *queueType
// output: element from the front queue
// Postcondition: element at front is deleted
eleType dequeue(queueType *s1); //remove from begining
                                // Function: destroys the queue
// Precondition: queue is created
// Input: *queueType
// output: none
// Postcondition: deletes all elements and free memory
void destroyQueue(queueType *);

//Function :  creates a new empty queue
//precondition : none
//input: none
//output: qType
//postCondition : an Empty queue is created
queueType createQueue();
// Function: inserts an element on rear
// Precondition: queue is not full
// Input: *queueType, eleType
// output: true if enque is successful and false if enque is not successful
// Postcondition: new element is inserted
_Bool enqueue(eleType ele, queueType *s1); //add at end

// Function: checks if the queue is full
// Precondition: none
// Input:  queueType
// output: true if queue is full and false if queue is not full
// Postcondition: none
_Bool isFull(queueType s);
// Function: checks if the queue is empty
// Precondition: none
// Input:  queueType
// output: true if queue is empty and false if queue is not empty
// Postcondition: none
_Bool isEmpty(queueType s);

//Function: displays the elements of the queue
//Precondition: queue is not empty
//Input: queueType
//output: displays the elements of the queue
//Postcondition: none

void display(queueType *);

#endif