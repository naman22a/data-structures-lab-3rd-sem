#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
    char name[20];
    char section;
    int roll_no;
    char branch[20];
};

struct Node
{
    struct Student data;
    struct Node *next;
};

struct Node *head = NULL;
int n = 0;

void insertAtHead(struct Student student)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory Full\n");
        exit(1);
    }

    newNode->data = student;

    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtPosition(struct Student student, int position)
{
    if (position == 1)
    {
        insertAtHead(student);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory Full\n");
        exit(1);
    }
    newNode->data = student;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *cur = head;
    int i = 0;
    while (i != position - 2)
    {
        cur = cur->next;
        i++;
    }

    if (cur == NULL)
    {
        printf("Invalid position\n");
        exit(1);
    }

    newNode->next = cur->next;
    cur->next = newNode;
}

void traversal()
{
    struct Node *cur = head;
    while (cur != NULL)
    {
        printf("%s -> ", cur->data.name);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Student first = {
        "Naman",
        'A',
        5,
        "AIML"};
    struct Student second = {
        "Jayant",
        'A',
        12,
        "AIML"};

    insertAtPosition(first, 1);
    insertAtPosition(second, 2);
    insertAtPosition(second, 2);
    traversal();

    return 0;
}