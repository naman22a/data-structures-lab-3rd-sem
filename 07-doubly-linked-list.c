#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    int age;
    int salary;
} Employee;

typedef struct DNode
{
    Employee data;
    struct DNode *next;
    struct DNode *prev;
} DoublyNode;

DoublyNode *head = NULL;

void traversal()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        DoublyNode *cur = head;
        printf("NULL <--> ");
        while (cur != NULL)
        {
            printf(" %s <--> ", cur->data.name);
            cur = cur->next;
        }
        printf("NULL\n");
    }
}

void insertAtHead(Employee data)
{
    if (head == NULL)
    {
        DoublyNode *newNode = (DoublyNode *)malloc(sizeof(DoublyNode));
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        DoublyNode *newNode = (DoublyNode *)malloc(sizeof(DoublyNode));
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void deleteAtTail()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    DoublyNode *cur = head;

    if (cur->next == NULL)
    {
        free(cur);
        cur = NULL;

        head = NULL;
        return;
    }

    DoublyNode *last = head;
    while (last->next != NULL)
        last = last->next;

    last->prev->next = NULL;

    free(last);
    last = NULL;
}

int main()
{
    Employee e1, e2, e3;

    strcpy(e1.name, "Jessica Jones");
    strcpy(e2.name, "Maurice Dalton");
    strcpy(e3.name, "Marco Weiss");

    e1.age = 25;
    e2.age = 42;
    e3.age = 28;

    e1.salary = 100000;
    e2.salary = 200000;
    e3.salary = 300000;

    insertAtHead(e1);
    traversal();

    insertAtHead(e2);
    insertAtHead(e3);
    traversal();

    deleteAtTail();
    traversal();

    deleteAtTail();
    traversal();

    return 0;
}