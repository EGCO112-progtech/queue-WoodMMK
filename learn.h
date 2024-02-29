#include <stdio.h>
#include <stdlib.h>

//create node structure
struct node{
    int queue; //queue or order
    char name[50]; 
    struct node * next;
};

typedef struct node Node;
typedef Node * nodeptr;

//create queue structure with node structure inside
typedef struct{
    nodeptr head, tail;  
    int size;  //very important
}Q;

void print_size(Q*);
void print_tail(Q*);
void NQ(Q*);
void print_current(Q*);


void print_size(Q* Qptr)
{
    printf("There are %d orders in queue.\n", Qptr->size);
}

void print_tail(Q* Qptr)
{
    char to_continue;
    printf("------------------------\n");
    if(Qptr->tail == NULL)
    {
        printf("--- Nothing in Q yet ---\n");
    }else
    {
        printf("last order's name is %s\n", Qptr->tail->name);
    }    
    printf("------------------------\n");
    getchar();   
}

void print_current(Q* Qptr){
    int current_size = Qptr->size;
    if(Qptr->head == NULL) 
    {
        printf("--    Nothing in Q    --\n");
        return;
    }

    nodeptr temp = Qptr->head;
    printf("(HEAD) -> 1. %s -> ", temp->name);
    for(int i = 1; i < Qptr->size;i++)
    {
        temp = temp->next;
        printf("%d. %s -> ", (i+1),temp->name);
    }
    printf("(TAIL)\n");
    return;
}

void NQ(Q* Qptr)
{
    nodeptr request = (nodeptr) malloc (sizeof(Node)); //create request node

    // {linking part}+----------------------------

    if(Qptr->size == 0)
    {   // special case : the first order
        
        // point everything to request node
        Qptr->head = request;
        Qptr->tail = request;

        //set tail's next pointer to NULL
        Qptr->tail->next = NULL;
    }
    else 
    {// second order <-> size is more than 1
        Qptr->tail->next = request; //link before's next to request
        Qptr->tail = request; //link tail to last pointer
        request->next = NULL; //set tail's next pointer to NULL
    }
    
    Qptr->size++; // increase size of queue
    int current =  Qptr->size; //size of queue

    // {end linking part}+------------------------

    // 
    printf("Your queue : %d\n", current); //show current queue
    printf("enter your name : ");
    scanf("%s", Qptr->tail->name);
    printf("finish NQ\n");
}

void DQ(Q* Qptr){
    nodeptr temp = Qptr->head;
    if(Qptr->size == 1){
        //just delete the last one and set pointer to null
        free(temp);
    }
    Qptr->head = Qptr->head->next;
    free(temp);
}