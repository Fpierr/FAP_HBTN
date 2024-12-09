#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

Already defined in Leetcode
*/

/* 
   * reverseBetween - reverses a sublist of a singly linked list
   * @head: a pointer to the head of the linked list
   * @left: the starting position of the sublist
   * @right: the ending position of the sublist

   * Ruturn: A pointer to the head of newlist or null if !head.
*/
struct ListNode* reverseBetween(struct ListNode *head, int left, int right)
{
    struct ListNode *dummy, *preLeft, *leftNode, *current;
    struct ListNode *prev, *nextNode, *newHead;
    int i;

    if (!head || left == right)
        return (head);

    dummy = malloc(sizeof(struct ListNode));
    if (!dummy)
        return (NULL);

    dummy->next = head;
    preLeft = dummy;

    /* Move preLeft to the node just before the `left` position */
    for (i = 1; i < left; i++)
        preLeft = preLeft->next;

    leftNode = preLeft->next;
    current = leftNode;
    prev = NULL;

    /* Reverse the sublist between left and right */
    for (i = left; i <= right; i++)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    /* Reconnect the reversed sublist with the rest of the list */
    preLeft->next = prev;
    leftNode->next = current;

    /* Return the modified list */
    newHead = dummy->next;
    free(dummy);
    return (newHead);
}
