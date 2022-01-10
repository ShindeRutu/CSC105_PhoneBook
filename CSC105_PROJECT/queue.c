/*
                AUTHOR : 2128_dinesh
                PROGRAM: IMPLEMENTATION FILE for QUEUE USING LINKED LIST
                DATE CREATED: SEPT 2021
                DATE MODIFIED: SEPT 2021
 */
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

eleType dequeue(queueType *s1) // It removes top element and display popped element
{
    s1->count--;
    qnode *temp = s1->front;
    s1->front = s1->front->next;
    // s1->rear=NULL;->cond
    //s1->rear = NULL;
    eleType dequeued = temp->data;
    if (s1->front == NULL)
    {
        s1->rear = NULL;
    }
    free(temp);
    return (dequeued);
}

void destroyQueue(queueType *s1) //It destroy stack and free the allocated dynamic memory
{
    while (s1->front != NULL)
    {
        s1->count--;
        qnode *temp = s1->front;
        s1->front = s1->front->next;
        free(temp);
    }
}

bool enqueue(eleType ip_data, queueType *s1)
{                                                            // Adds elemens on top of the stack
    qnode *newDataNode = (qnode *)malloc(1 * sizeof(qnode)); // Allocate memory
    if (newDataNode == NULL)
        return false;

    else
    {
        newDataNode->data = ip_data;
        if (s1->front == NULL)
        {
            s1->front = newDataNode;
            s1->rear = newDataNode;
            s1->front->next = NULL;
            s1->rear->next = NULL;
        }
        else
        {
            s1->rear->next = newDataNode;
            s1->rear = newDataNode;
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
    if (s1.front == NULL)
    {
        return true;
    }
    return false;
}

queueType createQueue() // creates the stack in Linkedlist.
{
    queueType s;
    s.count = 0;
    s.front = NULL;
    s.rear = NULL;
    return s;
}

void display(queueType *s1)
{
    qnode *ptr = s1->front;
    if (s1->front == NULL)
    {
        //return false;
        // printf("\nEmpty queue\n");
    }
    else
    {
        printf("\nFavourite list .....\n");
        while (ptr != NULL)
        {
            printf("\nName - %s\n", ptr->data.key);
            printf("Mobile number - %lld\n", ptr->data.mobNumber);
            printf("Tel number - %lld\n", ptr->data.TelNumber);
            printf("E mail - %s\n", ptr->data.email);

            ptr = ptr->next;
        }
    }
}