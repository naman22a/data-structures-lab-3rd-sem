#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int arr[], int n);
void inputArray(int arr[], int n);
void swap(int *a, int *b);

// TC: O(N^2)
// SC: O(1)
void selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }
        swap(&arr[mini], &arr[i]);
    }
}

// TC: O(N^2)
// SC: O(1)
void bubble_sort(int arr[], int n)
{
    // (n - 1) passes
    for (int i = 0; i <= n - 2; i++)
    {
        bool didSwap = false;
        for (int j = 0; j <= n - i - 2; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                didSwap = true;
            }
        }

        // array already sorted, no need to run n-1 passes
        if (didSwap == false)
            break;
    }
}

// TC: O(N^2)
// SC: O(1)
void insertion_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(&arr[j - 1], &arr[j]);
            j--;
        }
    }
}

void mergeArrays(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // create temporary arrays
    int left_array[n1], right_array[n2];

    // copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        left_array[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        right_array[j] = arr[mid + 1 + j];

    // merge the temporary arrays back into array
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (left_array[i] <= right_array[j])
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of left array
    while (i < n1)
    {
        arr[k] = left_array[i];
        i++;
        k++;
    }

    // copy the remaining elements of right array
    while (j < n2)
    {
        arr[k] = right_array[j];
        j++;
        k++;
    }
}

void ms(int arr[], int left, int right)
{
    // base case
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    ms(arr, left, mid);
    ms(arr, mid + 1, right);

    mergeArrays(arr, left, mid, right);
}

// TC: O(N.log(N))
// SC: O(N), actually O(2N) for temporary array and recursion stack space
void merge_sort(int arr[], int n)
{
    ms(arr, 0, n - 1);
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    inputArray(arr, n);
    printArray(arr, n);

    printf("=========== MENU ===========\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Exit\n");

    int option;
    printf("Enter option(1-5): ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        selection_sort(arr, n);
        break;
    case 2:
        bubble_sort(arr, n);
        break;
    case 3:
        insertion_sort(arr, n);
    case 4:
        merge_sort(arr, n);
        break;
    case 5:
        exit(0);
        break;

    default:
        printf("Invalid option");
        break;
    }

    printArray(arr, n);
    free(arr);

    return 0;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void inputArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
