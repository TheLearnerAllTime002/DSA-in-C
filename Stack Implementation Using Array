#include <stdio.h>
#include <stdlib.h>

void push(int n, int *top, int *arr);
void pop(int *top, int *arr);
void display(int top, int *arr);

int main() {
    int n, *arr;
    printf("Enter the size of the stack: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));
    int top = -1;

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(n, &top, arr);
                break;
            case 2:
                pop(&top, arr);
                break;
            case 3:
                display(top, arr);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    free(arr);
    return 0;
}

void push(int n, int *top, int *arr) {
    if (*top == n - 1) {
        printf("Stack Overflow\n");
    } else {
        (*top)++;
        printf("Enter the data to be pushed: ");
        scanf("%d", &arr[*top]);
        printf("%d pushed onto the stack.\n", arr[*top]);
    }
}

void pop(int *top, int *arr) {
    if (*top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d has been popped\n", arr[*top]);
        (*top)--;
    }
}

void display(int top, int *arr) {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("The stack is:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", arr[i]);
        }
    }
}


