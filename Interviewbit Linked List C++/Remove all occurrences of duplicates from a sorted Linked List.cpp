// C++ program to remove all occurrences of duplicates from a sorted linked list.
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

struct Node *newNode(int data)
{
Node *temp = new Node;
temp -> data = data;
temp -> next = NULL;
return temp;
}

// Function to print nodes
// in a given linked list.
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node -> data);
		node = node -> next;
	}
}

// Function to remove all occurrences of duplicate elements
void removeAllDuplicates(struct Node* &start)
{
	// create a dummy node that acts like a fake head of list pointing to the original head
	Node* dummy = new Node;

	// dummy node points to the original head
	dummy -> next = start;

	// Node pointing to last node which has no duplicate.
	Node* prev = dummy;

	// Node used to traverse the linked list.
	Node* current = start;

	while(current != NULL)
	{
		while(current -> next != NULL &&
			prev -> next -> data == current -> next -> data)
			current = current -> next;

		if (prev -> next == current)
			prev = prev -> next;
		else
			prev -> next = current -> next;

		current = current -> next;
	}

	// update original head to the next of dummy node
	start = dummy -> next;
}

// Driver Code
int main()
{
	// 23->28->28->35->49->49->53->53
	struct Node* start = newNode(23);
	start -> next = newNode(28);
	start -> next -> next = newNode(28);
	start -> next ->next -> next = newNode(35);
	start -> next ->next -> next -> next = newNode(49);
	start -> next ->next -> next ->next -> next = newNode(49);
	start -> next ->next -> next ->next -> next -> next = newNode(53);
	start -> next ->next -> next ->next -> next ->next -> next = newNode(53);
	cout << "List before removal of duplicates\n";
	printList(start);

	removeAllDuplicates(start);

	cout << "\nList after removal of duplicates\n";
	printList(start);
	return 0;
}
