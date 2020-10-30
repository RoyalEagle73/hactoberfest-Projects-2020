#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    int data;
    Node *next;
};

void insertionAtBeginning(Node **head,int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = (*head);
    (*head) = newNode;
}

void printList(Node *tmp)
{
    cout<<"List is :- "<<"\n";
    while(tmp)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<"\n";
}

Node * findMiddle(Node *head)
{
    Node *fast = head, *slow = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    Node *head = NULL;
    int n; // no. of nodes
    cin>>n;
    int val;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        insertionAtBeginning(&head,val);
    }
    printList(head);
    Node * middle = findMiddle(head);
    cout<<"Middle Node/Element Is :- "<<middle->data;
    return 0;
}
