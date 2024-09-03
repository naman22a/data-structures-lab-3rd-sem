#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

// TC: O(N)
void display(struct Node *head)
{
    struct Node *cur = head;
    while (cur != NULL)
    {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
}

// TC: O(1)
void push(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Stack overflow error\n");
        return;
    }

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// TC: O(1)
void pop(struct Node **head)
{
    if (head == NULL)
    {
        printf("Stack underflow error\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// TC: O(1)
int peek(struct Node *head)
{
    if (head == NULL)
        return -1;
    return head->data;
}

int main()
{
    struct Node *head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    pop(&head);

    display(head);

    printf("Peek: %d", peek(head));

    return 0;
}
