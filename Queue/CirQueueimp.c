#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
int queue[SIZE],front=-1,rear=-1;
void insert(int queue[],int element)
{
	if(front == (rear+1)%SIZE)
	{
	printf("The Queue is full!\n");
	return;
	}
	if(front == -1)
	{
	front=0;
	}
	rear = (rear+1)%SIZE;
	queue[rear] = element;	
}
void delete(int queue[])
{
	int element;
	if(rear==-1)
	{
	printf("The queue is empty!\n");
	return;
	}
	else
	{
	element = queue[front];
	if(front==rear)
	{
	front=rear-1;
	}
	else
	{
	front = (front+1)%SIZE;
	}
	printf("%d",element);
	}
}
void displayQueue()
{
	int i;
	if(rear==-1)
	{
	printf("The queue is empty!\n");
	return;
	}
	else
	{
	for(i=front;i!=rear;i=(i+1)%SIZE)
	{
	printf("%d\t",queue[i]);
	}
	printf("%d\n\n",queue[i]);
	}
}
void main()
{
	int ch=-1;
	while(ch!=0)
	{
	printf("Enter your choice: 1 for inserting into the queue, \n 2 for deleting out of the queue, \n 3 for displaying all the queue elements and 0 to exit: \n\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	{
	int n;
	printf("Enter the element to be inserted:");
	scanf("%d",&n);
	insert(queue,n);
	break;
	}
	case 2:
	{
	int n;
	printf("The deleted element is:");
	delete(queue);
	break;
	}
	case 3:
	{
	printf("The elements are:\n");
	displayQueue();
	break;
	}
	}
}
}

