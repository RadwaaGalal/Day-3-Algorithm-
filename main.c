#include <stdio.h>
#include <stdlib.h>
//Implementation Linked List

//Represent a node of singly linked list
struct node
{
        int info;
        struct node *next;
};
struct node *start=NULL;
// create the linked list
void Create(){
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
            printf("\nOut of Memory Space:\n");
            //exit(0);
        }
        printf("\nEnter the data value for the node: ");
        scanf("%d",&temp->info);
        temp->next=NULL;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;}
 printf("\nData is inserted successfully in the single list.\n");}
//Display linked list on screen
void Display()
{
        struct node *ptr;
        if(start==NULL) //check if linked list is empty
        {
            printf("\nList is empty:\n");
            return;
        }
        else
        {
            ptr=start;
            printf("\nThe List elements are: ");
            while(ptr!=NULL){

                printf("%d ",ptr->info );
            ptr=ptr->next ;}}
printf("\n");
}
//Function to add element at the begin of list
void Insert_Begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
            printf("\nOut of Memory Space:\n");
            return;
        }
        printf("\nEnter the data value for the node: " );
        scanf("\n%d",&temp->info);
        temp->next =NULL;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            temp->next=start;
            start=temp;}
printf("\nData is inserted successfully in the beginning of single list.\n");}
//Function to add element at the end of list
void Insert_End()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
            printf("\nOut of Memory Space:\n");
            return;
        }
        printf("\nEnter the data value for the node: " );
        scanf("\n%d",&temp->info );
        temp->next =NULL;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            ptr=start;
            while(ptr->next !=NULL)
            {
                ptr=ptr->next ;
            }
            ptr->next =temp;}
printf("\nData is inserted successfully in the end of single list.\n");}
//Function to add element at specified position of list
void Insert_Position()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
            printf("\nOut of Memory Space:\n");
            return;
        }
        printf("\nEnter the position for the new node to be inserted: ");
        scanf("\n%d",&pos);
        printf("\nEnter the data value of the node: ");
        scanf("\n\n%d",&temp->info) ;
        temp->next=NULL;
        if(pos==0)
        {
            temp->next=start;
            start=temp;
        }
        else
        {
            for(i=0,ptr=start;i<pos-1;i++) { ptr=ptr->next;
                if(ptr==NULL)
                {
                    printf("\nPosition not found:\n");
                    return;
                }
                }
                temp->next =ptr->next ;
            ptr->next=temp;}
printf("\nData is inserted successfully in the specified position of single list.\n");}
//Function to delete element at the begin of list
void Delete_Begin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
            printf("\nList is Empty: ");
            return;
        }
        else
        {
            ptr=start;
            start=start->next ;
            printf("\nThe deleted element is : %d",ptr->info);
            free(ptr);}
printf("\nFirst element deleted successfully from the list.\n");}
//Function to delete element at the end of list
void Delete_End()
{
        struct node *temp,*ptr;
        if(start==NULL)
        {
            printf("\nList is Empty:\n");
            //exit(0);
        }
        else if(start->next ==NULL)
        {
            ptr=start;
            start=NULL;
            printf("\nThe deleted element is: %d",ptr->info);
            free(ptr);
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
                {
                    temp=ptr;
                    ptr=ptr->next;
                }
                temp->next=NULL;
                printf("\nThe deleted element is: %d",ptr->info);
                free(ptr);}
printf("\nLast element deleted successfully from the list.\n");}
//Function to delete element at specified position of list
void Delete_Position()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
            printf("\nThe List is Empty:\n");
            //exit(0);
        }
        else
        {
            printf("\nEnter the position of the node to be deleted: ");
            scanf("\n%d",&pos);
            if(pos==0){
                    ptr=start;
                    start=start->next ;
                    printf("\nThe deleted element is:%d\n\n ",ptr->info  );
                    free(ptr);}
            else
                {
                    ptr=start;
                    for(i=0;i<pos;i++) {
                        temp=ptr; ptr=ptr->next ;
                        if(ptr==NULL)
                            {
                                printf("\nPosition not Found:\n");
                                return;
                            }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is: %d",ptr->info );
                        free(ptr);}}
printf("\nthe element deleted successfully from the list.\n");}
int Print_Linked_List_Menue()
{
    int choice;
    printf("\n");
    printf("1.Create\n");
    printf("2.Display\n");
    printf("3.Insert at the beginning\n");
    printf("4.Insert at the end\n");
    printf("5.Insert at specified position\n");
    printf("6.Delete from beginning\n");
    printf("7.Delete from the end\n");
    printf("8.Delete from specified position\n");
    printf("9.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    return choice;
}
//-----------------------------------------------------------------------------------//
//Implement Queue using previous Linked List
struct node *front = NULL,*rear = NULL;
//Function  to add elements to the queue:
void EnQueue(value)
{
    struct node *newNode;//create a new linked list node
    struct node *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode ->info = value;
    newNode -> next = NULL;
    if(front == NULL)//If queue is empty, then new node is front and rear both
        front = rear = newNode;
    else
    {
        rear -> next = newNode;
        rear = newNode;
    }
    printf("\nData is inserted successfully in the Queue.\n");
}
//Function to remove elements from the queue
void DeQueue()
{
    if(front == NULL)//check if queue is empty
        printf("\n (Queue is Empty)\n\n");
    else
    {
        struct node *temp = front;
        front = front -> next;
        printf("\nDeleted element is: %d\n", temp->info);
        printf("\nData is deleted successfully from the Queue.\n\n");
        free(temp);
    }
}
//Display Queue using linked list on screen
void Display_Queue()
{
    if(front == NULL)// check if queue is empty
        printf("\nQueue is Empty:\n");
    else
    {
        struct node *temp = front;
        printf("\nThe Queue(using Linked List) elements are: ");
        while(temp->next != NULL)
        {
            printf("%d ",temp->info);
            temp = temp -> next;
        }
        printf("%d \n",temp->info);
   }
}
//Function to display the front value
void Get_Front()
{
    if(front==NULL)//check if the queue is empty
         printf("\nQueue is Empty:\n");
    else
        printf("\nData at front of the queue is %d \n",front->info);
}
void Get_Rear()
//Function to display the rear value
{
    if(rear==NULL)//check if the queue is empty
         printf("\nQueue is Empty:\n");
    else
        printf("\nData at rear of the queue is %d \n",rear->info);
}
int Print_Queue_Menue()
{
    int choice;
    printf("\n");
    printf("1.EnQueue\n");
    printf("2.DeQueue\n");
    printf("3.Display \n");
    printf("4.Get Front\n");
    printf("5.Get Rear\n");
    printf("6.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    return choice;
}
//-----------------------------------------------------------------------------------//
//Implement Queue using Stack

//Function to initialize top of two stacks
int stack1[100], stack2[100];
int top1 = -1, top2 = -1;
int count = 0;

void create()
{
top1 = top2 = -1;
}
//Function to push an element to stack
void push1(int element)
{
// Pushing the element to stack1
stack1[++top1] = element;
}
//Function to pop element from stack
int pop1()
{
// Pop element from stack1
return(stack1[top1--]);
}
//Function to push an element on to stack
void push2(int element)
{
// Pushing the element to stack2
stack2[++top2] = element;
}

//Function to pop an element from stack
int pop2()
{
// pop element from stack2
return(stack2[top2--]);
}
//Function to enqueue an element into the queue using stack
void Enqueue_Queue_Stack()
{
int data, i,R;
printf("Enter the data value : ");
scanf("%d", &data);
push1(data); // Push data from stack to the queue
count++;
printf("\nData is inserted successfully in the Queue.\n");
}
//Function to dequeue an element from the queue using stack
void Dequeue_Queue_Stack()
{
int i;
for (i = 0;i <= count;i++)
{
push2(pop1()); // Pop elements from stack1 and push them to stack2
}
pop2(); // Pop the element from stack2 which is the element to be dequeued
count--;
for (i = 0;i <= count;i++)
{
push1(pop2());} // Push back all the elements from stack2 to stack1
 printf("\nData is deleted successfully from the Queue.\n\n");}

void Display_Queue_Stack()
{
int i;
if(top1 == -1)
{
printf("\nQueue is Empty:\n");
}
else
{
printf("\nThe Queue(using Stack) elements are: ");
for (i = 0;i <= top1;i++)
{
printf("%d ", stack1[i]);
}
printf("\n");
}}
int Print_Queue_Stack_Menue()
{
    int choice;
    printf("\n");
    printf("1.EnQueue\n");
    printf("2.DeQueue\n");
    printf("3.Display \n");
    printf("4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    return choice;
}
//main function
int main()
{
    //make variables
    int choice= -1 ,value,option;
    printf("choose [1] to using Linked List\n\nchoose [2] to using Queue(By Linked List)\n\nchoose [3] to using Queue(By Stack)\n\n");
    scanf("%d" ,&option);
//To check if user's choice is correct!
  while(option>3 || option<1)
{
    printf("Invalid Choice: ......> TRy Again\n");
    scanf("%d" ,&option);
}
//to use Single Linked List
  if(option == 1){
     printf("\nYou Use Linked List ---->\n\n");
     while(choice!=9){
      choice = Print_Linked_List_Menue();
      if(choice == 1)
          Create();
      else if(choice == 2)
          Display();
      else if(choice == 3)
          Insert_Begin();
      else if(choice == 4)
          Insert_End();
      else if(choice == 5)
          Insert_Position();
      else if(choice == 6)
          Delete_Begin();
      else if(choice == 7)
          Delete_End();
      else if(choice == 8)
          Delete_Position();
      else if(choice == 9)
          printf("Exit");
      else
          printf("\nEnter correct choice\n");}}

//To Use Queue using Liked list
if(option == 2){
    printf("\nYou use Queue Using Linked List ---->\n\n");
    while(choice!=6){
      choice = Print_Queue_Menue();
      if(choice == 1){
            printf("Insert the value you want to add: ");
            scanf("%d" , &value);
            EnQueue(value);
            }
      else if(choice == 2)
          DeQueue();
      else if(choice == 3)
          Display_Queue();
      else if(choice == 4)
          Get_Front();
      else if(choice == 5)
          Get_Rear();
      else if(choice == 6)
          printf("Exit");
      else
          printf("\nEnter correct choice\n");}}
//To use Queue using Stack
if(option == 3)
    printf("\nYou use Queue using Stack ---->\n\n");
{
     while(choice!=4){
      choice = Print_Queue_Stack_Menue();
      if(choice == 1)
            Enqueue_Queue_Stack();
      else if(choice == 2)
            Dequeue_Queue_Stack();
      else if(choice == 3)
          Display_Queue_Stack();
      else if(choice == 4)
          printf("Exit");
      else
          printf("\nEnter correct choice\n");}}
}
