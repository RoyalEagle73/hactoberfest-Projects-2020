// C++ code for linked list merged sort
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

Node *mergeTwoLists(Node *l1, Node *l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    Node* head = NULL;    // head of the list to return

    // find first element (can use dummy node to put this part inside of the loop)
    if(l1->data < l2->data)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }

    Node* p = head;     // pointer to form new list

    while(l1 && l2)
    {
        if(l1->data < l2->data)
        {
            p->next = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }

    // add the rest of the tail, done!
    if (l1)
        p->next=l1;
    else
        p->next=l2;

    return head;
}

Node* MergeSort(Node* A) {
    Node* head = A;
    if (head == NULL || head->next == NULL)
        return head;

    // find the middle place
    Node *p1 = head;
    Node *p2 = head->next;

    while(p2 && p2->next)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    p2 = p1->next;
    p1->next = NULL;

    return mergeTwoLists(MergeSort(head), MergeSort(p2));
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
