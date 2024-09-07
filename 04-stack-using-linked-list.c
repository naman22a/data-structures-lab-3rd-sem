#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

// TC: O(N)
void traverse(struct Node *head)
{
    struct Node *cur = head;
    while (cur != NULL)
    {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
}

// TC: O(1)
struct Node *push(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // check if memory is available
    if (newNode == NULL)
    {
        printf("Stack overflow error\n");
        return head;
    }

    newNode->data = value;
    newNode->next = head;
    head = newNode;
    return head;
}

// TC: O(1)
struct Node *pop(struct Node *head)
{
    if (head == NULL)
    {
        printf("Stack underflow error\n");
        return head;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
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

    while (true)
    {
        printf("=========== MENU ===========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");

        int option;
        printf("Enter option(1-5): ");
        scanf("%d", &option);

        int value;
        switch (option)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            head = push(head, value);
            break;

        case 2:
            head = pop(head);
            break;

        case 3:
            printf("Peek: %d\n", peek(head));
            break;

        case 4:
            traverse(head);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid option\n");
            break;
        }
    }

    return 0;
}
