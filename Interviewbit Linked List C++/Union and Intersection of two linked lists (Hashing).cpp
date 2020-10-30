// C++ program to find union and intersection of
// two unsorted linked lists in O(m+n) time.
#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

/* A utility function to insert a node at the
begining of a linked list*/
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void storeEle(struct Node* head1, struct Node *head2, unordered_map<int, int> &eleOcc)
{
	struct Node* ptr1 = head1;
	struct Node* ptr2 = head2;
	while (ptr1 != NULL || ptr2 != NULL)
	{
		if (ptr1!=NULL)
		{
			eleOcc[ptr1->data]++;
			ptr1=ptr1->next;
		}
		if (ptr2 != NULL)
		{
			eleOcc[ptr2->data]++;
			ptr2=ptr2->next;
		}
	}
}

/* Function to get union of two linked lists head1 and head2 */
struct Node *getUnion(unordered_map<int, int> eleOcc)
{
	struct Node *result = NULL;

	// Push all the elements into the resultant list
	for (auto it=eleOcc.begin(); it!=eleOcc.end(); it++)
		push(&result, it->first);

	return result;
}

/* Function to get intersection of two linked lists head1 and head2 */
struct Node *getIntersection(unordered_map<int, int> eleOcc)
{
	struct Node *result = NULL;

	// Push a node with an element having occurrence
	// of 2 as that means the current element is present
	// in both the lists
	for (auto it=eleOcc.begin(); it!=eleOcc.end(); it++)
		if (it->second == 2)
			push(&result, it->first);

	// return resultant list
	return result;
}

/* A utility function to print a linked list*/
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf ("%d ", node->data);
		node = node->next;
	}
}

void printUnionIntersection(Node *head1, Node *head2)
{
	// Store all the elements of both lists in the map
	unordered_map<int, int> eleOcc;
	storeEle(head1, head2, eleOcc);

	Node *intersection_list = getIntersection(eleOcc);
	Node *union_list = getUnion(eleOcc);

	printf("\nIntersection list is \n");
	printList(intersection_list);

	printf("\nUnion list is \n");
	printList(union_list);
}

/* Drier program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;

	/* create a linked lits 11->10->15->4->20 */
	push(&head1, 1);
	push(&head1, 2);
	push(&head1, 3);
	push(&head1, 4);
	push(&head1, 5);

	/* create a linked lits 8->4->2->10 */
	push(&head2, 1);
	push(&head2, 3);
	push(&head2, 5);
	push(&head2, 6);

	printf("First list is \n");
	printList(head1);

	printf("\nSecond list is \n");
	printList(head2);

	printUnionIntersection(head1, head2);

	return 0;
}
