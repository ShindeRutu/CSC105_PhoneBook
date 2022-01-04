/*
AUTHOR : Dineshgawas
PROGRAM: Queue
DATE CREATED: 28 SEPT 2021
*/

#include "phoneBook.h"
#ifndef _QUEUE_H
#define _QUEUE_H
  
  //data
  typedef info* eleType;

  //node
  struct queue_node{
    eleType data;
    struct queue_node *next;
  }; 

  typedef  struct queue_node qnode;
  
  struct queue{
    int count;
    qnode *front;  //front to dequeue
    qnode *rear ;  //rear to enqueue
  }; 
  typedef struct queue queueType;
    
  
  //operations which can be perfromed on data

  /*    *********************create Queue ************
  	Function: Create an empty queue
	Input:  none
	Precondition: None
	Output: queue(queueType)
	Postcondition: An Empty queue is created */
  queueType createQueue();     

  /*    ************isEmpty()************
  Function: to check if queue is empty.
	Input: queue(queueType)
	Preconditions: queue must exist
	Output: return true if queue is empty or False if queue is not empty
	Postcondition: true if queue empty else false */
  _Bool isEmpty(queueType q);
        
  /*    ***************** isFull() *******************
  Function: to check if stack is empty.
  Input: queue(queueType)
	Preconditions: queue must exist
	Output: return true if stack is full or False if stack is not full.
	Postcondition: true if stack empty else false  */    
  _Bool isFull (queueType q);
    	
  /*    ********************* enqueue  ****************
 	Function: Insert/add an element at top of the queue
	Input: queue(queueType), newelement(node)
	Precondition: The queue is not full
	Output: queue(queueType)
	Postcondition: queue with the new element/node added/linked on top  of the queue  */   
	_Bool enqueue(eleType ele, queueType *q1);
	
	
  /*   ****************** dequeue *****************
  Function: remove/delete last element from the queue
	Input: queue(queueType)
	Precondition: The queue is not empty
	Output: queue(queueType), last element(ElementType) or last node
	Postcondition: queue with the last element/node deleted from the queue */
  eleType dequeue(queueType *q1);

  /*   *************** display *************************
  	Function: to display the queue. 
	Input: queue(queueType)
	Preconditions: queue must exist
	Output: queue elements 
	Postcondition:  */     
  void displayQueue(queueType q);

  /*   *************** destroy *************************
  	Function: to destroy the queue. 
	Input: queue(queueType)
	Preconditions: queue must exist
	Output: memory location will be made free
	Postcondition: queue is destroyed, memory allocation is made
	free.*/
	void destroyQueue(queueType *q1);
  
#endif 