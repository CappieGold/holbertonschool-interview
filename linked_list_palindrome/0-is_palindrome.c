#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer to the first node of the list
 *
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast, *prev, *currentNode, *next;
    int result = 1;

    /* Lists of length 0 or 1 are palindromes */
    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return 1;

    /* 1) Find the midpoint using slow/fast pointers */
    slow = *head;
    fast = *head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* 2) Reverse the second half in-place */
    prev = NULL;
    currentNode = slow;
    while (currentNode)
    {
        next = currentNode->next;
        currentNode->next = prev;
        prev = currentNode;
        currentNode = next;
    }
    /* 'prev' now points to head of reversed second half */

    /* 3) Compare first half and reversed second half */
    listint_t *first = *head;
    listint_t *second = prev;
    while (second)
    {
        if (first->n != second->n)
        {
            result = 0;
            break;
        }
        first = first->next;
        second = second->next;
    }

    /* 4) Restore the list by reversing the second half again */
    currentNode = prev;
    prev = NULL;
    while (currentNode)
    {
        next = currentNode->next;
        currentNode->next = prev;
        prev = currentNode;
        currentNode = next;
    }
    /* List is back to original order */

    return result;
}
