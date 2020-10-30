/* C Program to remove duplicates from a sorted linked list */
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

void removeDuplicates(struct Node* head)
{
	struct Node* current = head;
	struct Node* next_next;

	/* do nothing if the list is empty */
	if (current == NULL)
	return;

	/* Traverse the list till last node */
	while (current->next != NULL)
	{
	/* Compare current node with next node */
	  if (current->data == current->next->data)
	  {
		/* The sequence of steps is important*/
		next_next = current->next->next;
		free(current->next);
		current->next = next_next;
	  }
	  else
      {
	 	current = current->next;
	  }
	}
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node *node)
{
	while (node!=NULL)
	{
	   printf("%d ", node->data);
	   node = node->next;
	}
}

int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	/* Created linked list will be 11->11->11->13->13->20 */
	push(&head, 20);
	push(&head, 13);
	push(&head, 13);
	push(&head, 11);
	push(&head, 11);
	push(&head, 11);

	printf("\n Linked list before duplicate removal ");
	printList(head);

	/* Remove duplicates from linked list */
	removeDuplicates(head);

	printf("\n Linked list after duplicate removal ");
	printList(head);

	return 0;
}
