#include<bits/stdc++.h>
using namespace std;
/* Link list node */
struct Node
{
int data;
struct Node* next;
};

/* Function to get the nth node from the last of a linked list*/
Node *deleteNthFromLast(Node *head, int n)
{
    // If linked list is empty
    if (head == NULL)
        return NULL;

    Node *temp  = head;
    int len = 0;
    while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    //From the begining
    n = len-n+1;

    if (len < n)
      return head;

    Node *ptr = head, *prev;
    if(n<=1)
    {
        head = head->next;
        return head;
    }
    // Traverse list and delete n-th node from starting
    int c = 0;
    while (ptr != NULL)
    {
        c++;
        if(c==n)
            break;
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    delete(ptr);
    return head;
}

void push(struct Node** head_ref, int new_data)
{
struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
new_node->data = new_data;
new_node->next = (*head_ref);

(*head_ref) = new_node;
}

void printList(Node * head)
{
    while(head !=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int main()
{
struct Node* head = NULL;

// create linked 35->15->4->20
push(&head, 20);
push(&head, 4);
push(&head, 15);
push(&head, 35);
printList(head);
head = deleteNthFromLast(head,4);
printList(head);
return 0;
}
