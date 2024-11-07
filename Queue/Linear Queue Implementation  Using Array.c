#include<stdio.h>
#include<stdlib.h>
#define size 5

void enqueue();
void dequeue();
void print();

int arr[size];
int rear = -1;
int front = -1;

int main() {
    int ch;
    while (1) {
        printf("1. Enqueue operation\n");
        printf("2. Dequeue Operation\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                print();
                break;
            case 4:
                return 0;
            default:
                printf("Incorrect choice\n");
        }
    }
}

void enqueue() {
    int insert_item;
    
    if (rear == size - 1) {
        printf("Overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        printf("Element to be inserted in the queue: ");
        scanf("%d", &insert_item);
        rear = rear + 1;
        arr[rear] = insert_item;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
    } else {
        printf("Element deleted from the queue: %d\n", arr[front]);
        front = front + 1;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void print() {
    int i;
    
    if (front == -1) {
        printf("Empty queue\n");
    } else {
        printf("Queue: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
