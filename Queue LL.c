#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    if (rear == NULL) {
        front = rear = n;
        return;
    }
    rear->next = n;
    rear = n;
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* t = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(t);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* t = front;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &ch);
        if (ch == 1) {
            scanf("%d", &x);
            enqueue(x);
        } else if (ch == 2) {
            dequeue();
        } else if (ch == 3) {
            display();
        } else if (ch == 4) {
            break;
        }
    }
    return 0;
}
