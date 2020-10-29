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

char checkLength(Node *head)
{
    Node *p = head;
    while(1)
    {
        if(p==NULL)
            return 'e';

        if(p->next==NULL)
            return 'o';
        p = p->next->next;
    }
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
    cout<<"Length of the Linked List is :- ";
    (checkLength(head)=='e') ? cout<<"Even" : cout<<"Odd" ;
    return 0;
}
