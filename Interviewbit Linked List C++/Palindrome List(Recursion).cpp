// Recursive program to check if a given linked list is palindrome
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Link list node */
struct node
{
	char data;
	struct node* next;
};

// Initial parameters to this function are &head and head
bool isPalindromeUtil(struct node **left, struct node *right)
{
/* stop recursion when right becomes NULL */
if (right == NULL)
	return true;

/* If sub-list is not palindrome then no need to
	check for current left and right, return false */
bool isp = isPalindromeUtil(left, right->next);
if (isp == false)
	return false;

/* Check values at current left and right */
bool isp1 = (right->data == (*left)->data);

/* Move left to next node */
*left = (*left)->next;

return isp1;
}

bool isPalindrome(struct node *head)
{
isPalindromeUtil(&head, head);
}

void push(struct node** head_ref, char new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct node *ptr)
{
	while (ptr != NULL)
	{
		printf("%c->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

/* Drier program to test above function*/
int main()
{
	/* Start with the empty list */
	struct node* head = NULL;
	char str[] = "abacaba";
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
	push(&head, str[i]);
	printList(head);
	isPalindrome(head)? printf("Is Palindrome\n\n"): printf("Not Palindrome\n\n");
	}

	return 0;
}
