// C++ program to get intersection point of two linked list
#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct ListNode {
     int val;
     ListNode *next;
};

ListNode* getIntersectionNode(ListNode* A, ListNode* B) {

    if(!A || !B)
       return NULL;

    ListNode *A1 = A, *B1 = B;
    int c1=0,c2=0;

    while(A1)
    {
        c1++;
        A1 = A1->next;
    }

    while(B1)
    {
        c2++;
        B1 = B1->next;
    }

    int d = abs(c1-c2);
    ListNode *A2 = A, *B2=B;

    if(c1>c2)
    {
        while(d-- && A2)
            A2 = A2->next;
    }
    else if(c2>c1)
    {
        while(d-- && B2)
            B2 = B2->next;
    }
    while(B2 && A2)
    {
        if(A2 == B2)
            return A2;
        A2 = A2->next;
        B2 = B2->next;
    }
    return NULL;
}
int main()
{
/*
	Create two linked lists

	1st 3->6->9->15->30
	2nd 10->15->30

	15 is the intersection point
*/
    struct ListNode* newNode;
    struct ListNode* head1 = (struct ListNode*) malloc(sizeof(struct ListNode));
    head1->val = 10;

    struct ListNode* head2 = (struct ListNode*) malloc(sizeof(struct ListNode));
    head2->val = 3;

    newNode = (struct ListNode*) malloc (sizeof(struct ListNode*));
    newNode->val = 6;
    head2->next = newNode;

    newNode = (struct ListNode*) malloc (sizeof(struct ListNode));
    newNode->val = 9;
    head2->next->next = newNode;

    newNode = (struct ListNode*) malloc (sizeof(struct ListNode));
    newNode->val = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = (struct ListNode*) malloc (sizeof(struct ListNode));
    newNode->val = 30;
    head1->next->next= newNode;

    head1->next->next->next = NULL;

    ListNode* Ans = getIntersectionNode(head1,head2);
    while(Ans)
    {
        cout<<Ans->val<<" ";
        Ans = Ans->next;
    }
}
