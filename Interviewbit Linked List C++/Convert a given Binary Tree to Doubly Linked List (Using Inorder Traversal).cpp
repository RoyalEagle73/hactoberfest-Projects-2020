// C++ program to convert a given Binary
// Tree to Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

// Structure for tree and linked list
struct Node
{
	int data;
	Node *left, *right;
};

// A simple recursive function to convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked list
void BTtoDLL(Node *root, Node **head)
{
    // Base case
    if (root == NULL) return;

    // Initialize previously visited node as NULL. This is
    // static so that the same value is accessible in all recursive
    // calls
    static Node* prev = NULL;

    // Recursively convert left subtree
    BTtoDLL(root->left, head);

    // Now convert this node
    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    // Finally convert right subtree
    BTtoDLL(root->right, head);
}

// Utility function for allocating node for Binary
// Tree.
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// Utility function for printing double linked list.
void printList(Node* head)
{
	printf("Extracted Double Linked list is:\n");
	while (head)
	{
		printf("%d ", head->data);
		head = head->right;
	}
}

// Driver program to test above function
int main()
{
	/* Constructing below tree
			  5
			 / \
			3	6
		   / \	 \
		   1 4	  8
		  / \	 / \
		  0 2	 7 9 */
	Node* root = newNode(5);
	root->left = newNode(3);
	root->right = newNode(6);
	root->left->left = newNode(1);
	root->left->right = newNode(4);
	root->right->right = newNode(8);
	root->left->left->left = newNode(0);
	root->left->left->right = newNode(2);
	root->right->right->left = newNode(7);
	root->right->right->right = newNode(9);

	Node* head = NULL;

	BTtoDLL(root, &head);

	printList(head);

	return 0;
}
