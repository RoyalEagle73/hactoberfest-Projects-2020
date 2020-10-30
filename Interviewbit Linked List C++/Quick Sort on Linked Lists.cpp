// C++ program for Quick Sort on Singly Linled List
#include <iostream>
#include <cstdio>
using namespace std;

/* a node of the singly linked list */
struct Node
{
	int data;
	struct Node *next;
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = new Node;

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

// Returns the last node of the list
Node *getTail(Node *cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}

// Partitions the list taking the last element as the pivot
Node *Partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
	Node *pivot = end;
	Node *prev = NULL, *cur = head, *tail = pivot;

	// During partition, both the head and end of the list might change
	// which is updated in the newHead and newEnd variables
	while (cur != pivot)
	{
		if (cur->data < pivot->data)
		{
			// First node that has a value less than the pivot - becomes
			// the new head
			if ((*newHead) == NULL)
				(*newHead) = cur;

			prev = cur;
			cur = cur->next;
		}
		else // If cur node is greater than pivot
		{
			// Move cur node to next of tail, and change tail
			if (prev)
				prev->next = cur->next;
			struct Node *tmp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}
	// If the pivot data is the smallest element in the current list, pivot becomes the head
	if ((*newHead) == NULL)
		(*newHead) = pivot;
	// Update newEnd to the current last node
	(*newEnd) = tail;
	// Return the pivot node
	return pivot;
}

//here the sorting happens exclusive of the end node
Node *QuickSort(Node *head, Node *end)
{
	if (!head || head == end)
		return head;

	Node *newHead = NULL, *newEnd = NULL;

	// Partition the list, newHead and newEnd will be updated by the partition function
	Node *pivot = Partition(head, end, &newHead, &newEnd);

	// If pivot is the smallest element - no need to recur for the left part.
	if (newHead != pivot)
	{
		// Set the node before the pivot node as NULL
		Node *tmp = newHead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;

		// Recur for the list before pivot
		newHead = QuickSort(newHead, tmp);

		// Change next of last node of the left half to pivot
		tmp = getTail(newHead);
		tmp->next = pivot;
	}
	// Recur for the list after the pivot element
	pivot->next = QuickSort(pivot->next, newEnd);

	return newHead;
}

int main()
{
	Node *a = NULL;
	push(&a, 5);
	push(&a, 20);
	push(&a, 4);
	push(&a, 3);
	push(&a, 30);

	cout << "Linked List before sorting \n";
	printList(a);

	a = QuickSort(a, getTail(a));

	cout << "Linked List after sorting \n";
	printList(a);

	return 0;
}
