#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// TC: O(N)
void traversal(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *cur = q->front;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// TC: O(1)
struct Queue *enqueue(struct Queue *q, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Queue overflow error\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (q->front == NULL && q->rear == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    return q;
}

// TC: O(1)
struct Queue *dequeue(struct Queue *q)
{
    if (q->front == NULL && q->rear == NULL)
    {
        printf("Queue underflow error\n");
        return q;
    }
    else if (q->front == q->rear)
    {
        struct Node *temp = q->front;

        q->front = NULL;
        q->rear = NULL;

        free(temp);
        temp = NULL;
    }
    else
    {
        struct Node *temp = q->front;
        q->front = q->front->next;

        free(temp);
        temp = NULL;
    }

    return q;
}

int main()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;

    while (true)
    {
        printf("=========== MENU ===========\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");

        int option;
        printf("Enter option(1-4): ");
        scanf("%d", &option);

        int value;
        switch (option)
        {
        case 1:
            printf("Enter a value: ");
            scanf("%d", &value);

            q = enqueue(q, value);

            break;

        case 2:
            q = dequeue(q);
            break;

        case 3:
            traversal(q);
            break;

        case 4:
            exit(0);
            break;

        default:
            break;
        }
    }

    return 0;
}