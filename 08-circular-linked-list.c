#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[20];
} College;

typedef struct Node_
{
    College data;
    struct Node_ *next;
} Node;

Node *head = NULL;

void traversal()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *cur = head;
    do
    {
        printf("ID: %d, Name: %s \n", cur->data.id, cur->data.name);
        cur = cur->next;
    } while (cur != head);
}

void insertAtHead(College data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        Node *last = head;
        while (last->next != head)
            last = last->next;

        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }
}

void deleteAtTail()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *last = head;
        Node *secondLast = NULL;
        while (last->next != head)
        {
            secondLast = last;
            last = last->next;
        }
        secondLast->next = head;
        free(last);
    }
}

int main()
{
    College c1 = {2, "BVP"};
    College c2 = {1, "VIPS"};

    insertAtHead(c1);
    insertAtHead(c2);
    traversal();

    printf("\n");

    deleteAtTail();
    traversal();

    return 0;
}