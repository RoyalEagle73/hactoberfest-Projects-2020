#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

void push(struct Node** head_ref, int new_data);

/*This solution uses the temporary dummy to build up the result list */
struct Node* sortedIntersect(struct Node* a, struct Node* b)
{
struct Node dummy;
struct Node* tail = &dummy;
dummy.next = NULL;

/* Once one or the other list runs out -- we're done */
while (a != NULL && b != NULL)
{
	if (a->data == b->data)
	{
	push((&tail->next), a->data);
	tail = tail->next;
	a = a->next;
	b = b->next;
	}
	else if (a->data < b->data) /* advance the smaller list */
	a = a->next;
	else
	b = b->next;
}
return(dummy.next);
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
			(struct Node*) malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
while (node != NULL)
{
printf("%d ", node->data);
node = node->next;
}
}

/* Drier program to test above functions*/
int main()
{
/* Start with the empty lists */
struct Node* a = NULL;
struct Node* b = NULL;
struct Node *intersect = NULL;

/* Let us create the first sorted linked list to test the functions
Created linked list will be 1->2->3->4->5->6 */
push(&a, 6);
push(&a, 5);
push(&a, 4);
push(&a, 3);
push(&a, 2);
push(&a, 1);

/* Let us create the second sorted linked list
Created linked list will be 2->4->6->8 */
push(&b, 8);
push(&b, 6);
push(&b, 4);
push(&b, 2);

/* Find the intersection two linked lists */
intersect = sortedIntersect(a, b);

printf("\n Linked list containing common items of a & b \n ");
printList(intersect);

getchar();
}
