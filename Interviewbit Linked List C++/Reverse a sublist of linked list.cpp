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
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
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

// function used to reverse a linked list from position m to n which uses reverse function
ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if (m == n)
        return head;

    ListNode* revs = NULL, *revs_prev = NULL;
    ListNode* revend = NULL, *revend_next = NULL;

    // Find values of above pointers.
    int i = 1;
    ListNode* curr = head;
    while (curr && i <= n) {
        if (i < m)
            revs_prev = curr;

        if (i == m)
            revs = curr;

        if (i == n) {
            revend = curr;
            revend_next = curr->next;
        }

        curr = curr->next;
        i++;
    }
    revend->next = NULL;

    // Reverse linked list starting with revs.
    revend = reverseList(revs);

    // If starting position was not head
    if (revs_prev)
        revs_prev->next = revend;

    // If starting position was head
    else
        head = revend;

    revs->next = revend_next;
    return head;
}

int main()
{
    push(70);
    push(60);
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);
    print();cout<<"\n";
    int m =3,n=6;
    head  = reverseBetween(head, m, n);
    print();
    return 0;
}
