#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode (int data)
    {
        this->val = data;
        next = NULL;
    }
};

ListNode* head = NULL;

void push(int data)
{
    ListNode *temp = new ListNode(data);
    temp->next = head;
    head = temp;
}

ListNode* reverseList(ListNode* A) \
{
    ListNode *current = A;
    ListNode *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    A = prev;
    return A;
}

void print()
{
    struct ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main()
{
    push(20);
    push(4);
    push(15);
    push(85);

    cout << "Given linked list\n";
    print();

    head  = reverseList(head);

    cout << "\nReversed Linked list \n";
    print();
    return 0;
}
