#include<stdio.h>
#include<stdlib.h>
#define SiZE 5
int queue[SiZE];
int front=-1;
int rear=-1;
//checking if the queue is full or not
int isFull()
{
    if((front==0 && rear==SiZE-1) || (front==rear+1))
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if(front==-1)
        return 1;
    else
        return 0;
} 
//adding an element to the queue
void enqueue(int element)
{
    if(isFull())
    {
        printf("Queue is full\n");
    }
    else    {
        if(front==-1)
            front=0;            
        rear=(rear+1)%SiZE;
        queue[rear]=element;
        printf("Inserted -> %d\n", element);    
    }
}
//removing an element from the queue    
 void dequeue()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
       printf("Deleted element -> %d\n", queue[front]);
         front=(front+1)%SiZE;
         if (front==rear)
            front=rear=-1;
       
}}
    int main()
    {

        
        int ch,element;
        do{
            printf("\n---MENU---\n");
            printf("1.Enqueue\n2.Dequeue\n3.Exit\nEnter your choice: ");
            scanf("%d",&ch);
            switch(ch)           
             {
                case 1:
                    printf("Enter an element: ");
                    scanf("%d",&element);
                    enqueue(element);
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    exit(0);
                default:
                    printf("Invalid choice\n"); 
        }
    } while(ch!=3);
    return 0;
}