#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node_dl {
    int data;
    struct node_dl *prev, *next;
};

struct node *start=NULL; //singly linked list
struct node_dl *START=NULL; //doubly linked list
struct node *last=NULL; //circular linked list
const int max=10;
int stack[10], top=-1; //array stack
struct node *TOP=NULL; //stack using linked list
int queue[10], front=-1, rear=-1; //array queue
int cq[10],frontcq=-1, rearcq=-1; //circular queue
struct node *FRONT=NULL, *REAR=NULL; //queue using linked lisr



//SINGLY LINKED LIST


void sl_print()
{
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d\t", ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void sl_ins_beg()
{
    int n;
    struct node *new;
    new=(struct node*) malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &n);
    new->data=n;
    new->next=start;
    start=new;
    sl_print();
}

void sl_ins_end()
{
    int n;
    struct node *last=start;
    struct node *new;
    new=(struct node*) malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &n);
    new->data=n;
    if(start==NULL)
        start=new;
    while(last->next!=NULL)
        last=last->next;
    last->next=new;
    new->next=NULL;
    sl_print();
}

void sl_ins_pos()
{
    int num,n,pos,temp=1;
    struct node *ptr=start;
    struct node *new;
    new=(struct node*) malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &n);
    new->data=n;
    printf("Enter after which data to be inserted: ");
    scanf("%d", &num);
    while(ptr->data!=num)
        ptr=ptr->next;
    /*
    printf("Enter position to insert the new node: ");
    scanf("%d", &pos);
    while(temp!=pos)
    {
        ptr=ptr->next;
        temp++;
    }
    */
    new->next=ptr->next;
    ptr->next=new;
    sl_print();
}

void sl_del_beg()
{
    if(start==NULL)
        printf("List is empty!");
    else
        start=start->next;
    sl_print();
}

void sl_del_end()
{
    if(start==NULL)
    {
        printf("List is empty!");
        return;
    }
    struct node *last=start, *prev;
    while(last->next!=NULL)
    {
        prev=last;
        last=last->next;
    }
    prev->next=NULL;
    sl_print();
}

void sl_del_pos()
{
    if(start==NULL)
    {
        printf("List is empty!");
        return;
    }
    struct node *ptr=start, *prev=start;
    int num,pos,i=1;
    
    printf("Enter data item to be deleted: ");
    scanf("%d", &num);
    while(ptr->next!=NULL && ptr->data!=num)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    if(prev==start)
        start=NULL;
    if(ptr->data!=num)
        printf("No such element found!");
    else
        prev->next=ptr->next;
    /*
    printf("Enter the position of node to be deleted: ");
    scanf("%d", &pos);
    while(i<pos-1)
    {
        prev=prev->next;
        i++;
    }
    ptr=prev->next;
    prev->next=ptr->next;*/
    free(ptr);
    sl_print();
}

void sl_del()
{
    struct node *ptr=start,*temp;
    while(ptr->next!=NULL)
    {
        temp=ptr->next;
        free(ptr);
        ptr=temp;
    }
    start=NULL;
}

void singlylist()
{
    int ch, choice;
    do 
    {
        printf("\nMENU- SINGLY LINKED LIST\n");
        printf("1.Insert node at beginning\n");
        printf("2.Insert node at end\n");
        printf("3.Insert node after a particular node\n");
        printf("4.Delete first node\n");
        printf("5.Delete last node\n");
        printf("6.Delete a particular node\n");
        printf("7.Delete list\n");
        printf("8.Display list\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: sl_ins_beg();
                    break;
            case 2: sl_ins_end();
                    break;
            case 3: sl_ins_pos();
                    break;
            case 4: sl_del_beg();
                    break;
            case 5: sl_del_end();
                    break;
            case 6: sl_del_pos();
                    break;
            case 7: sl_del();
                    break;
            case 8: sl_print();
                    break;
        }
        printf("Do you want to continue?(1/2)");
        scanf("%d", &choice);
    }while(choice==1);
}

//ARRAY STACK

void arr_stack_print()
{
    int i;
    for(i=0;i<=top;i++)
        printf("%d\t", stack[i]);
    printf("\n");
}

int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void arr_push()
{
    int num;
    if(top==max-1)
        printf("Stack full!");
    else 
    {
        ++top;
        printf("Enter data: ");
        scanf("%d", &num);
        stack[top]=num;
    }
    arr_stack_print();
}

void arr_pop()
{
    if(top==max-1)
        printf("Stack full!");
    else 
    {
        printf("%d\n", stack[top]);
        top--;
    }
    arr_stack_print();
}

void arr_peek()
{
    if(!isempty())
        printf("%d\n", stack[top]);
    arr_stack_print();
}

void array_stack()
{
    
    int ch,choice;
    do {
        printf("\nMENU- ARRAY STACK\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display stack\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: arr_push();
                    break;
            case 2: arr_pop();
                    break;
            case 3: arr_peek();
                    break;
            case 4: arr_stack_print();
                    break;
        }
        printf("Do you want to continue?(1/2)");
        scanf("%d", &choice);
    }while(choice==1);
}

//ARRAY QUEUE

void arr_queue_print()
{
    int i;
    for(i=0;i<=top;i++)
        printf("%d\t", queue[i]);
    printf("\n");
}

int isfull()
{
    if(rear==max-1)
        return 1;
    else
        return 0;
}

int qisempty()
{
    if(front==-1)
        return 1;
    else
        return 0;
}

void arr_enqueue()
{
    int num;
    if(isfull())
    {
        printf("Queue is full!\n");
        return;
    }
    if(rear==-1)
        front++;
    rear++;
    printf("Enter data : ");
    scanf("%d", &num);
    queue[rear]=num;
    arr_queue_print();
}

void arr_dequeue()
{
    if(qisempty())
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("%d\n", queue[front]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        front++;
    arr_queue_print();
}

void array_queue()
{
    int ch,choice;
    do {
        printf("\nMENU- ARRAY QUEUE\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: arr_enqueue();
                    break;
            case 2: arr_dequeue();
                    break;
        } 
        printf("Do you want to continue?(1/2)");
        scanf("%d", &choice);
    }while(choice==1);  
}

//STACK USING LINKED LIST

int sll_isempty()
{
    if(TOP==NULL)
        return 1;
    else
        return 0;
}

void sll_stack_print()
{
    struct node *temp=TOP;
    while(temp!=NULL)
    {
        printf("%d\t", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void sll_push()
{
    int n;
    struct node *new;
    new=(struct node*) malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &n);
    new->data=n;
    new->next=TOP;
    TOP=new;
    sll_stack_print();
}

void sll_pop()
{
    struct node *temp;
    if(sll_isempty())
    {
        printf("Stack empty!");
        return;
    }
    printf("%d\n", TOP->data);
    temp=TOP;
    TOP=TOP->next;
    temp->next=NULL;
    free(temp);
    sll_stack_print();
}

void sll_peek()
{
    if(sll_isempty())
    {
        printf("Stack empty!");
        return;
    }
    printf("%d\n", TOP->data);
    sll_stack_print();
}

void stack_linked_list()
{
    int ch,choice;
    do {
        printf("\nMENU- STACK USING LINKED LIST\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display stack\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: sll_push();
                    break;
            case 2: sll_pop();
                    break;
            case 3: sll_peek();
                    break;
            case 4: sll_stack_print();
                    break;
        }
        printf("Do you want to continue?(1/2)");
        scanf("%d", &choice);
    }while(choice==1);
}

//DOUBLY LINKED LIST

void dll_ins_beg()
{
    int n;
    struct node_dl *new;
    new=(struct node_dl*) malloc(sizeof(struct node_dl));
    printf("Enter data: ");
    scanf("%d", &n);
    new->data=n;
    new->prev=NULL;
    new->next=START;
    if(START!=NULL)
        START->prev=new;
    START=new;
}

void dll_ins_after()
{
    int n,c=0,key;
    struct node_dl *new, *temp, *previous;
    new=(struct node_dl*) malloc(sizeof(struct node_dl));
    printf("Enter data: ");
    scanf("%d", &n);
    new->data=n;
    printf("Enter the data after which this node has to be inserted: ");
    scanf("%d", &key);
    temp=START;
    if(temp==NULL)
    {
        printf("List empty!");
        return;
    }
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            previous=temp;
            c++;
            break;
        }
        temp=temp->next;
    }
    if(c==0)
        printf("No such data found!");
    new->next=previous->next;
    new->prev=previous;
    previous->next=new;
    if(new->next!=NULL)
        new->next->prev=new;
}

void dll_ins_end()
{
    struct node_dl *new, *temp=START, *previous;
    int n;
    new=(struct node_dl*) malloc(sizeof(struct node_dl));
    printf("Enter data: ");
    scanf("%d", &n);
    new->data=n;
    new->next=NULL;
    if(START==NULL)
    {
        new->prev=NULL;
        START=new;
        return;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    new->prev=temp;
    temp->next=new;
}

void doubly_linked_list()
{
    
}

/*Insertion before a given element*/

//CIRCULAR QUEUE

int cqfull()
{
    if((frontcq==0&&rearcq==max-1)||(frontcq=rearcq+1))
        return 1;
    else
        return 0;
}

int cqempty()
{
    if(frontcq==-1)
        return 1;
    else
        return 0;
}

void cq_enqueue()
{
    if(cqfull())
    {
        printf("CQ full!");
        return;
    }
    if(frontcq==-1)
        frontcq++;
    rearcq=(rearcq+1)%max;
    printf("Enter data: ");
    scanf("%d", &cq[rearcq]);
    
}

void cq_dequeue()
{
    if(cqempty())
    {
        printf("Empty CQ!");
        return;
    }
    int n;
    n=cq[frontcq];
    if(frontcq==rearcq)
    {
        frontcq=-1;
        rearcq=-1;
    }
    else
        frontcq=(frontcq+1)%max;
    printf("%d", n);
}

void circular_queue()
{
    int ch,choice;
    do {
        printf("\nMENU- CIRCULAR QUEUE\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: cq_enqueue();
                    break;
            case 2: cq_dequeue();
                    break;
        } 
        printf("Do you want to continue?(1/2)");
        scanf("%d", &choice);
    }while(choice==1);  
}

//QUEUE USING LINKED LIST

int qll_isempty()
{
    if(FRONT==NULL)
        return 1;
    else 
        return 0;
}

void qll_enqueue()
{
    struct node *new;
    int n;
    new=(struct node*) malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &n);
    new->data=n;
    new->next=NULL;
    if(qll_isempty())
    {
        FRONT=new;
        REAR=new;
        return;
    }
    REAR->next=new;
}

void qll_dequeue()
{
    struct node *temp;
    if(qll_isempty())
    {
        printf("Queue empty!");
        return;
    }
    temp=FRONT;
    FRONT=FRONT->next;
    free(temp);
}

void queue_linked_list()
{
    int ch,choice;
    do {
        printf("\nMENU- QUEUE USING LINKED LIST\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: qll_enqueue();
                    break;
            case 2: qll_dequeue();
                    break;
        } 
        printf("Do you want to continue?(1/2)");
        scanf("%d", &choice);
    }while(choice==1);
}

//CIRCULAR LINKED LIST

void add_to_empty()
{
    struct node *new;
    int n;
    new=(struct node*) malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &n);
    new->data=n;
    if(last!=NULL)
        return;
    struct node *last=(struct node*) malloc(sizeof(struct node));
    last->data=n;
    last->next=last;
    return;
}

void cll_ins_beg()
{
    if(last==NULL)
    {
        add_to_empty();
        return;
    }
    int n;
    struct node *new;
    new=(struct node*) malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &n);
    new->data=n;
    new->next=last->next;
    last->next=new;
}

void cll_ins_end()
{
    if(last==NULL)
    {
        add_to_empty();
        return;
    }
    int n;
    struct node *new;
    new=(struct node*) malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &n);
    new->data=n;
    new->next=last->next;
    last->next=new;
    last=new;
}

void sll_ins_pos()
{
    /*seems same*/
}


//MAIN

void main()
{
    int ch;
    printf("MENU\n");
    printf("1.Singly linked list \n");
    printf("2.Array stack\n");
    printf("3.Array queue\n");
    printf("4.Stack using linked list\n");
    printf("5.Doubly linked list\n");
    printf("6.Circular queue\n");
    printf("7.Queue using linked list\n");
    printf("8.Circular linked list\n");
    printf("Enter choice:");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1: singlylist();
                break;
        case 2: array_stack();
                break;
        case 3: array_queue();
                break;
        case 4: stack_linked_list();
                break;
        case 5: 
                break;
        case 6: circular_queue();
                break;
    }
}
