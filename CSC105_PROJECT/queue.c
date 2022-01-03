
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"queue.h"

_Bool isEmpty(qType q1) //it checks if the queue is empty or not
{
    if(q1.front==NULL&& q1.front==NULL)
    {
        return true;
    }
    return false;
}
_Bool isFull(qType q1) //it checks if the queue is full or not
{
    return false; //if malloc return false so it is not able to allocate extra memory 
                      // in that case isFull returns true.
}
qType createQueue() //it creates queue using of two pointers one for front and other for rear
{   
    qType q1;
    q1.count =0;
    q1.front=NULL;
    q1.rear=NULL;
    return q1;
}
_Bool enqueue(eleType_q ip_data, qType *q1) //it insert item to the queue
{
    node* newDataNode = (node*)malloc(1* sizeof(node)); //memory accocation
    if(newDataNode==NULL)
        return false;
    else
    {
        newDataNode->data=ip_data;
        if(q1->front==NULL)
        {
            q1->front=newDataNode;
            q1->rear=newDataNode;
            q1->front->next=NULL;
            q1->rear->next=NULL;
        }
        else
        {
            q1->rear->next=newDataNode;
            q1->rear=newDataNode;
            q1->rear->next=NULL;

        }
    }
}

eleType_q dequeue(qType* q1) //remove inserted item from queue and free that particular memory
 {   
    q1->count--;
    node* temp=q1->front;
    q1->front=q1->front->next;
    eleType_q poppedEle=temp->data;
    if(q1->front==NULL)
    {
        q1->rear=NULL;
    }
    free(temp);
    return(poppedEle);
}
void destroyQueue(qType*q1) //remove whole queue and free all the memories that are allocated to queue
{
    while(q1->front!=NULL)
    {
        q1->count--;
        node *temp =q1->front;
        q1->front=q1->front->next;
        free(temp);
    }
}

void display(qType *q1) //display all the elements of the queue.
{
    node *point =q1->front;
    
    while(point!=NULL)
    {
        printf("\n %s\n",point->data->data.name);
        point=point->next;
    }
    
}