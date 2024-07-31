#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int insert(int arr[], int *n, int value, int position);
int delete(int arr[], int *n, int position);
void update(int arr[], int n, int value, int position);
void display(int arr[], int n);

int insert(int arr[], int *n, int value, int position) {
    if (*n >= MAX_SIZE) {
        printf("Array is full.\n");
        return -1;
    }
    if (position < 0 || position > *n) {
        printf("Invalid Position!\n");
        return -1;
    }
    int i;
 
    for (i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*n)++;
    return 0;
}

int delete(int arr[], int *n, int position) {
    if (*n <= 0) {
        printf("Array is empty.\n");
        return -1;
    }
    if (position < 0 || position >= *n) {
        printf("Invalid Position!\n");
        return -1;
    }
    int i;
   
    for (i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    return 0;
}

void update(int arr[], int n, int value, int position) {
    if (position < 0 || position >= n) {
        printf("Invalid position.\n");
        return;
    }
    arr[position] = value;
}

void display(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *a;  
    int n = 0;
    int choice, value, position, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid array size!\n");
        return -1;
    }
   
   
      a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert value at any position\n");
        printf("2. Delete element from any position\n");
        printf("3. Update value at any position\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert (0 to %d): ", n);
                scanf("%d", &position);
                if (insert(a, &n, value, position) == 0) {
                    display(a, n);
                }
                break;
            case 2:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &position);
                if (delete(a, &n, position) == 0) {
                    display(a, n);
                }
                break;
            case 3:
                printf("Enter new value: ");
                scanf("%d", &value);
                printf("Enter position to update (0 to %d): ", n - 1);
                scanf("%d", &position);
                update(a, n, value, position);
                display(a, n);
                break;
            case 4:
            printf("Thank you for using and inspecting my code <:)>");
                free(a);  
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
