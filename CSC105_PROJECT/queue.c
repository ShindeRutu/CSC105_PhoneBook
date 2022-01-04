/*
AUTHOR : Dineshgawas
PROGRAM: STACK USING LINKED LIST(ADT specification)
DATE CREATED: SEPT 2021
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"queue.h"




/********* cretaeQueue()  *******/
queueType createQueue()
{
  queueType q;
  q.front = NULL;
  q.rear = NULL;
  q.count = 0;  // intial num of node is 0
  return q;
}

/* ==========Isfull ===========*/
// further impro
bool isFull(queueType q1)
{
  return false;   // assumption:  memory is never full // false bcz we can add as many elements as system permits, hence no need to consider this condition.  
}

/*************isEmpty()***************/    
 bool isEmpty(queueType q1)
 {
    if(q1.front == NULL) //or if s1.count == 0
       return true;
    else 
        return false;
 }

/***************Enqueue ()***************/  
bool enqueue(eleType ip_data, queueType *q1)
{   
  //Allocating memory
  qnode *newNode =(qnode*) malloc(1*sizeof(qnode));
  
  if(newNode == NULL)
    return false;
   
  else
  {
    newNode->data = ip_data;
    newNode->next = NULL;
         
    //case of enqueue in an empty queue
    if(q1->rear == NULL &&  q1->front == NULL)
    {
      //make rear anf ront point at same node
       q1->front = q1->rear = newNode;
    }
         
    else // Case of push in  non empty stack
    {
      //add newnode in rear->next
      q1->rear->next = newNode;
      // make the new node as the rear node
      q1->rear = newNode;
    }
    q1->count++;
    return true;
  }
}

eleType dequeue(queueType *q1)
{

   qnode *temp = q1->front;  // temperoray node
   
   // a. if only one eleement in stack
   // b. if more than one element in stack
   
   q1->front = q1->front->next;   
   //' this handels both cases a and b
  
   eleType dequeue_Ele = temp->data;
   //q1->count--;
   //free the first node
   free(temp);
   q1->count--;
   return (dequeue_Ele);
}

/************ display()**************/  
void displayQueue(queueType q1)
{
  printf("\nQueue: ");
  qnode *temp = q1.front;
  //printf("%d",temo->data);
  while(temp!=NULL)
  {
     //printf("%d->",temp->data);
     temp = temp->next;
  }
  printf("NULL\n");
}


void destroyQueue(queueType *q1)
{
  qnode *temp;     
  while(q1->front!=NULL)  //q1->rear!=NULL && 
     {
	     
        temp = q1->front;
        q1->front = q1->front->next;
        q1->count--;
        free(temp);
     }
}