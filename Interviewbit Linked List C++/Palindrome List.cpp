#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct newNode{
    int data;
    newNode * next;
};

void ReverseList(newNode **head1)
{
    newNode *curr = (*head1), *prev = NULL, *next = NULL;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*head1) = prev;
}

void push(newNode ** head,int ele)
{
    newNode *temp = new newNode();
    temp->data = ele;
    temp->next = (*head);
    (*head) = temp;
}

void printList(newNode * head)
{
    while(head !=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

bool isPalindrome(newNode **head)
{
    if((*head)==NULL || (*head)->next==NULL)
        return true;

    newNode *slow = (*head), *fast = slow->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    newNode *head1 = *head;
    newNode *head2 = slow->next;
    slow->next = NULL;

    ReverseList(&head2);
    while (head1 && head2)
    {
        // First add the element from list
        if (head1->data!=head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        newNode * head = new newNode();
        head = NULL;
        int n;
        cin>>n;
        int ele;
        for(int i=0;i<n;i++)
        {
            cin>>ele;
            push(&head,ele);
        }
        int ans = isPalindrome(&head);
        cout<<"List is Palindrome or not:- "<<ans;
    }
    return 0;
}
