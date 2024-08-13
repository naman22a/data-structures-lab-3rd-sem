#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int *arr;
    int size;
    int top;
};

struct Stack *createStack(int size)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->arr = (int *)malloc(sizeof(int) * stack->size);
    stack->top = -1;
    return stack;
}

bool isEmpty(struct Stack *s)
{
    return s->top == -1;
}

bool isFull(struct Stack *s)
{
    return s->top == s->size - 1;
}

void push(struct Stack *s, int value)
{
    if (isFull(s))
        printf("Stack overflow error\n");

    else
    {
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
        printf("Stack underflow error\n");
    else
    {
        int value = s->arr[s->top];
        s->top--;
        return value;
    }
}

int peek(struct Stack *s)
{
    if (isEmpty(s))
        printf("Stack underflow error\n");
    else
        return s->arr[s->top];
}

void traverse(struct Stack *s)
{
    if (isEmpty(s))
        printf("Stack is empty\n");
    else
    {
        for (int i = 0; i <= s->top; i++)
            printf("%d ", s->arr[i]);
        printf("\n");
    }
}

int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    struct Stack *s = createStack(size);

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
            push(s, value);
            break;

        case 2:
            pop(s);
            break;

        case 3:
            printf("Peek: %d", peek(s));
            break;

        case 4:
            traverse(s);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid option\n");
            break;
        }
    }

    free(s->arr);
    free(s);

    return 0;
}