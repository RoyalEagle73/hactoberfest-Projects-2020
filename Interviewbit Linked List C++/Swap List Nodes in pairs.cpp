/* C program to pairwise swap elements in a given linked list */
#include<bits/stdc++.h>
using namespace std;

/* A linked list node */
struct Node
{
	int data;
	struct Node *next;
};

void pairWiseSwap(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL && temp->next != NULL)
	{
		swap(temp->data, temp->next->data);
		temp = temp->next->next;
	}
}
/*Recursive Function
void pairWiseSwap(struct node *head)
{
  if (head != NULL && head->next != NULL)
  {
      swap(head->data, head->next->data);
      pairWiseSwap(head->next->next);
  }
}
*/

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node =
			(struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
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

/* Driver program to test above function */
int main()
{
	struct Node *start = NULL;

	/* The constructed linked list is:
	1->2->3->4->5 */
	push(&start, 5);
	push(&start, 4);
	push(&start, 3);
	push(&start, 2);
	push(&start, 1);

	printf("Linked list before calling pairWiseSwap()\n");
	printList(start);

	pairWiseSwap(start);

	printf("\nLinked list after calling pairWiseSwap()\n");
	printList(start);

	return 0;
}
