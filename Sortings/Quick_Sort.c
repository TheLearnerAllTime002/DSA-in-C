#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int size);
void swap(int *a, int *b);
int partition(int* arr, int low, int high);
void quickSort(int* arr, int low, int high);

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, n);
    free(arr);
    return 0;
}

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int* arr, int low, int high)
{
    int x = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int* arr, int low, int high)
{
    if (low < high) {
        int q = partition(arr, low, high);
        quickSort(arr, low, q - 1);
        quickSort(arr, q + 1, high);
    }
}
