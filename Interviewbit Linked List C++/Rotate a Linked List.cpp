// C++ program to rotate a linked list counter clock wise

#include <bits/stdc++.h>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;
};

// This function rotates a linked list counter-clockwise
Node* rotateList(Node *head, int k)
{
    // Rotation is done in Anti-Clockwise direction
    // for Rotation in Clockwise direction put line number 17 to 25 in comment
    int l = 0;
    Node* temp=head;
    while(temp!=NULL)
    {
        l++;
        temp = temp->next;
    }
    // modulo is used in case of B is graeter than size of List.
    k = l-k%l;

    if (k <= 0)
    return head;

	Node* current = head;

	int c = 1;
	while (c < k && current != NULL)
	{
		current = current->next;
		c++;
	}

	if (current == NULL)
		return head;

	Node *kthNode = current;

	while (current->next != NULL)
		current = current->next;

	current->next = head;
	head = kthNode->next;
	kthNode->next = NULL;
	return head;
}

void push (Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

int main(void)
{
	Node* head = NULL;
	for (int i = 60; i > 0; i -= 10)
		push(&head, i);

	cout << "Given linked list \n";
	printList(head);
	head = rotateList(head, 4);

	cout << "\nRotated Linked list \n";
	printList(head);

	return (0);
}
