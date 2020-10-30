// C++ program to rearrange a linked list in-place
#include<bits/stdc++.h>
using namespace std;

// Linkedlist Node structure
struct Node
{
	int data;
	struct Node *next;
};

// Function to create newNode in a linkedlist
Node* newNode(int key)
{
	Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

// Function to reverse the linked list
void reverselist(Node **head)
{
	Node *prev = NULL, *curr = *head, *next;

	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*head = prev;
}

// Function to print the linked list
void printlist(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		if(head->next) cout << "-> ";
		head = head->next;
	}
	cout << endl;
}

// Function to rearrange a linked list
Node* rearrange(Node *head)
{
	Node *slow = head, *fast = slow->next;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	Node *head1 = head;
	Node *head2 = slow->next;
	slow->next = NULL;

	reverselist(&head2);

	Node *curr = new Node();
    Node *ans = curr;
	while (head1 || head2)
	{
		// First add the element from list
		if (head1)
		{
			curr->next = head1;
			curr = curr->next;
			head1 = head1->next;
		}

		// Then add the element from the second list
		if (head2)
		{
			curr->next = head2;
			curr = curr->next;
			head2 = head2->next;
		}
	}
	ans = ans->next;
	return ans;
}

// Driver program
int main()
{
	Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	printlist(head); // Print original list
	head = rearrange(head);	 // Modify the list
	printlist(head); // Print modified list
	return 0;
}
