
#include "queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


    eleType dequeue(queueType *s1) // It removes top element and display popped element
    {
      s1->count--;
      q_node *temp=s1->front;
      s1->front=s1->front->next;
     // s1->rear=NULL;->cond
      //s1->rear = NULL;
      eleType dequeued=temp->data;
      if(s1->front==NULL){
        s1->rear=NULL;
      }
      free(temp);
      return (dequeued);
      /*if((s1->front)==NULL)
      return false;
      q_node *temp=s1->front;
      s1->front=s1->front->next;
      if((s1->front)==NULL)
      s1->rear = NULL;
      s1->rear=s1->rear-1;
      eleType dequeued=temp->data;
      free(temp);
      return (dequeued);*/
    }    ///return (dequeue);
      
        /*s1->count--;
        q_node *temp=s1->front;
        //case1 stack is empty(we do not handle since it is created already)
        //case2 non empty stack
        //case 2a deleting only top element
        s1->front =s1->front->next;
         eleType dequeuedEle =temp->data;
            free(temp);
            return (dequeuedEle);*/

    void destroyQueue(queueType *s1) //It destroy stack and free the allocated dynamic memory
    { 
        while(s1->front!=NULL)
        {s1->count--;
        q_node *temp =s1->front;
        s1->front =s1->front->next;
        free(temp);
        }
    }


  bool enqueue(eleType ip_data ,queueType *s1){ // Adds elemens on top of the stack
	q_node *newDataq_node = (q_node *) malloc(1* sizeof(q_node)); // Allocate memory
	if(newDataq_node == NULL)
		return false;
	
	else{
		newDataq_node->data = ip_data;
		if(s1->front==NULL){
			s1->front=newDataq_node;
			s1->rear=newDataq_node;
			s1->front->next=NULL;
			s1->rear->next=NULL;
		}
		else{
		s1->rear->next=newDataq_node;
		s1->rear=newDataq_node;
		s1->rear->next = NULL;	 
		}	
	
	}	
	
}


    bool isFull(queueType s1) // checks the memory of the sys is full or not
    {
        return false;
    }
    
    bool isEmpty(queueType s1) //check is there something into the stack or not
    {
        if(s1.front==NULL)
        {
            return true;
        }
        return false;
    }

    queueType createQueue() // creates the stack in Linkedlist.
    {
        queueType s;
        s.count=0;
        s.front=NULL;
        s.rear= NULL;
        return s;
    }


 void display(queueType *s1)  
{    
    q_node *ptr = s1->front;        
    if(s1->front == NULL)  
    {  
      //return false;
      printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        while(ptr != NULL)   
        {  
            printf("\n%d\n",ptr->data);  
            ptr = ptr->next; 

            //return true;
        }  
    }  
}  