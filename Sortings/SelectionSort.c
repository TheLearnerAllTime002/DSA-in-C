#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[100], int n)
{
    int i, j, index, temp;

    for (i = 0; i < n - 1; i++)
    {
        index = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }

        if (index != i)
        {
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("After Sorting : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    selectionSort(arr, n);

    printf("\nSorted array: \n");
    printArray(arr, n);

    free(arr);

    return 0;
}
