#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front=0,rear=-1;
void insert(int a[],int x)
{
	++rear;
	if(rear==MAX)
	{
	printf("Queue full");
	exit(1);
	}
	a[rear]=x;
}
int delete(int a[])
{
	int x,i;
	if(front>rear)
	{
	printf("\nQueue is empty");
	exit(1);
	}
	x=a[0];
	for(i=0;i<rear;i++)
	{
	a[i]=a[i+1];
	}
	rear--;
	return x;
}
void main()
{
	int ch=-1,a[MAX];
	while(ch!=0)
	{
	printf("Enter your choice: 1 for inserting into the stack, 2 for deleting out of the stack,3 for displaying all the queue elements and 0 to exit:");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	{
	int n;
	printf("Enter the element to be inserted:");
	scanf("%d",&n);
	insert(a,n);
	break;
	}
	case 2:
	{
	int n;
	printf("The deleted element is:");
	n = delete(a);
	printf("%d\n",n);
	break;
	}
	case 3:
	{
	int n;
	printf("The elements are:\n");
	while(n!=-999)
	{
	n = delete(a);
	printf("%d\n",n);
	}
	break;
	}
	}
	}
}

