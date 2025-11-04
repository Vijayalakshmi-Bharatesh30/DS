#include <stdio.h>
#define SIZE 5  // define queue size

int queue[SIZE];
int rear = -1;
int front = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue overflow!\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Enqueued value: %d\n", queue[rear]);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow!\n");
    } else {
        printf("Dequeued value: %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
