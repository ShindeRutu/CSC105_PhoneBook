
#include<stdbool.h>
#include"graph-adjList.h"
#ifndef QUEUE_H
    #define QUEUE_H
    typedef info* eleType_q;
    
    //DATA
    
    struct q_node
    {
        eleType_q data;
        struct q_node *next;

    };
    typedef struct q_node node;
    struct queue
    {
        struct q_node *front;
        struct q_node *rear;
        int count;
    };
    typedef struct queue qType;
    
    //Function :  creates a new empty queue
    //precondition : none
    //input: none
    //output: qType
    //postCondition : an Empty queue is created
    qType createQueue();

    // Function: checks if the queue is empty
    // Precondition: none
    // Input:  queueType
    // output: true if queue is empty and false if queue is not empty
    // Postcondition: none
    _Bool isEmpty(qType);
    
    
    // Function: inserts an element on rear
    // Precondition: queue is not full
    // Input: *queueType, eleType
    // output: true if enque is successful and false if enque is not successful
    // Postcondition: new element is inserted
    _Bool enqueue(eleType_q, qType *q1);
    
    // Function: destroys the queue
    // Precondition: queue is created
    // Input: *queueType
    // output: none
    // Postcondition: deletes all elements and free memory
    void destroyQueue(qType *);
    
    // Function: removes element from front of the queue
    // Precondition: queue is not empty
    // Input: *queueType
    // output: element from the front queue
    // Postcondition: element at front is deleted
    eleType_q dequeue(qType *);
    
    //Function: displays the elements of the queue
    //Precondition: queue is not empty
    //Input: queueType
    //output: displays the elements of the queue
    //Postcondition: none
    void display(qType *);
    
    // Function: checks if the queue is full
    // Precondition: none
    // Input:  queueType
    // output: true if queue is full and false if queue is not full
    // Postcondition: none
     _Bool isFull(qType);
#endif