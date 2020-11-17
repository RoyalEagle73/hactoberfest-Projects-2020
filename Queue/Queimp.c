#include<stdio.h>
#include<stdlib.h>
#define MAX 100
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
int x;
if(front>rear)
{
printf("\nQueue is empty");
exit(1);
}
x=a[front];
front++;
return x;
}
void main()
{
	int a[MAX],n,x;
	printf("How many elements to insert...?");
	scanf("%d",&n);
	printf("Enter the elements...");
	for(int i=0;i<n;i++)
	{
	printf("\n");
	scanf("%d",&x);
	insert(a,x);
	}
	printf("Elements deleted sequentially:\n");
	for(int i=0;i<n;i++)
	{
	x=delete(a);
	printf("%d\n",x);
	}
}
