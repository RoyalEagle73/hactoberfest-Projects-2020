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

void insertionAtPosition(Node **head,int x,int pos)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    if(pos==1)
    {
        newNode->next = (*head);
        (*head) = newNode;
        return;
    }

    Node *temp = (*head);
    for(int i=0;i<pos-2;i++)
    {
        temp = temp->next;
        if(!temp)
        {
            cout<<"!! You have Entered a Wrong Position !!\n";
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertionAtLast(Node **head,int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    Node *temp = (*head);
    while(temp->next)
        temp = temp->next;

    temp->next = newNode;
}

void deletionFromBeginning(Node **head)
{
    if(!(*head)) return;

    Node *temp = (*head);
    (*head) = (*head)->next;
    delete(temp);
}

void deletionFromPosition(Node **head, int pos)
{
    if(!(*head)) return;

    Node *temp = (*head);
    if(pos==1)
    {
        (*head) = temp->next;
        free(temp);
        return;
    }

    for(int i=0;i<pos-2;i++)
    {
        temp = temp->next;
        if(!temp)
        {
            cout<<"!! You have Entered a Wrong Position !!\n";
            return;
        }
    }

    Node *temp1 = temp->next;
    temp->next = temp1->next;
    delete(temp1);
}

void deletionFromLast(Node **head)
{
    Node *temp = (*head), *prev;
    while(temp->next)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete(temp);
}

void reverseList(Node **head)
{
    Node *curr = (*head), *prev = NULL, *next = NULL;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*head) = prev;
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

void showChoices()
{
    cout << "MENU\n";
    cout<<"Enter 1 for Insertion At Beginning\n";
    cout<<"Enter 2 for Insertion At any Specified Position\n";
    cout<<"Enter 3 for Insertion At End\n";
    cout<<"Enter 4 for Deletion At Beginning\n";
    cout<<"Enter 5 for Deletion At any Specified Position\n";
    cout<<"Enter 6 for Deletion At End\n";
    cout<<"Enter 7 for Reversing the List\n";
    cout<<"Enter 8 for Displaying the List\n";
    cout<<"Enter 9 to Exit\n";
    cout <<"Enter Your Choice :- ";
}

int main()
{
    Node *head = NULL;

    int x,pos;
    int choice;
	do
	{
        showChoices();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the value you want to Insert: ";
			cin >> x;
			insertionAtBeginning(&head,x);
			printList(head);
			break;
		case 2:
			cout << "Enter the value you want to Insert & Position: ";
			cin >> x >> pos;
			insertionAtPosition(&head,x,pos);
			printList(head);
			break;
		case 3:
			cout << "Enter the value you want to Insert: ";
			cin >> x;
			insertionAtLast(&head,x);
			printList(head);
			break;
		case 4:
			deletionFromBeginning(&head);
			printList(head);
			break;
		case 5:
			cout << "Enter the Position of Node you want to Delete: ";
			cin >> pos;
			deletionFromPosition(&head,pos);
			printList(head);
			break;
        case 6:
			deletionFromLast(&head);
			printList(head);
			break;
        case 7:
			reverseList(&head);
			printList(head);
			break;
        case 8:
			printList(head);
			break;
        case 9:
			return 0;
			break;
		default:
			cout<<"!!! Oops Invalid Input !!!\n";
		}
	}while (choice != 9);
    return 0;
}
