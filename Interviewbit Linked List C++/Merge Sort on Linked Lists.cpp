// C++ code for linked list merged sort
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

/* function prototypes */
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source,
					Node** frontRef, Node** backRef);

/* sorts the linked list by changing next pointers (not data) */
Node* MergeSort(Node * headRef)
{
	Node *head = headRef;
	Node *a, *b;
	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) {
		return head;
	}

	FrontBackSplit(head, &a, &b);

	a = MergeSort(a);
	b = MergeSort(b);

	/* answer = merge the two sorted lists together */
	headRef = SortedMerge(a, b);
	return headRef;
}

Node* SortedMerge(Node* a, Node* b)
{
	Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	/* Pick either a or b, and recur */
	if (a->data <= b->data) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

void FrontBackSplit(Node* source,Node** frontRef, Node** backRef)
{
	Node* fast, *slow;
	slow = source;
	fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL)
    {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	/* 'slow' is before the midpoint in the list, so split it in two at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main()
{
	/* Start with the empty list */
	Node* res = NULL;
	Node* a = NULL;

	/* Let us create a unsorted linked lists to test the functions
Created lists shall be a: 2->3->20->5->10->15 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);

	/* Sort the above created Linked List */
	a = MergeSort(a);

	cout << "Sorted Linked List is: \n";
	printList(a);

	return 0;
}
