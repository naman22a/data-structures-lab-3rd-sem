#include <stdio.h>
#include <stdlib.h>

void inputArray(int arr[], int n);
void printArray(int arr[], int n);

// TC: O(N)
// SC: O(1)
int linear_search(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    inputArray(arr, n);
    printArray(arr, n);

    int target;
    printf("Enter target: ");
    scanf("%d", &target);

    printf("Element found at index: %d\n", linear_search(arr, n, target));

    return 0;
}

void inputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}