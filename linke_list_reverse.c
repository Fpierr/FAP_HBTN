#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list.*/
struct ListN {
    int val;
    struct ListN *next;
};

/* 
   * reverseBetween - reverses a sublist of a singly linked list
   * @head: a pointer to the head of the linked list
   * @left: the starting position of the sublist
   * @right: the ending position of the sublist

   * Ruturn: A pointer to the head of newlist or null if !head.
*/
struct ListN* reverseBetween(struct ListN* head, int left, int right) {
    if (!head || left == right) {
        return head;
    }

    struct ListN *dummy = malloc(sizeof(struct ListN));
    dummy->next = head;
    struct ListN *preLeft = dummy;

    // Move preLeft to the node just before the `left` position
    for (int i = 1; i < left; i++) {
        preLeft = preLeft->next;
    }

    /* The start of the sublist to be reversed */
    struct ListN *leftNode = preLeft->next;
    struct ListN *current = leftNode;
    struct ListN *prev = NULL;
    struct ListN *nextNode;

    /* Reverse the sublist between left and right */
    for (int i = left; i <= right; i++) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    /* Reconnect the reversed sublist with the rest of the list */
    preLeft->next = prev;
    leftNode->next = current;

    /* Return the modified list */
    struct ListN* newHead = dummy->next;
    free(dummy);
    return newHead;
}
