#include "lists.h"

/**
 * @list: is the enter  list to check
 *
 * Return: 1 when the check answer is true, 0 when the condition is not list
 */
int check_cycle(listint_t *list)
{
        listint_t *slow = list;
        listint_t *fast = list;

        if (!list)
                return (0);

        while (slow && fast && fast->next)
        {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast)
                        return (1);
        }

        return (0);
}
