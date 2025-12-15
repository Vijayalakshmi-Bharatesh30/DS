#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void createList(int n) {
    int x;
    struct Node* t;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* nnode = createNode(x);
        if (head == NULL) {
            head = nnode;
        } else {
            t = head;
            while (t->next) t = t->next;
            t->next = nnode;
            nnode->prev = t;
        }
    }
}

void insertLeft(int key, int x) {
    struct Node* t = head;
    while (t && t->data != key) t = t->next;
    if (t == NULL) return;
    struct Node* nnode = createNode(x);
    nnode->next = t;
    nnode->prev = t->prev;
    if (t->prev) t->prev->next = nnode;
    else head = nnode;
    t->prev = nnode;
}

void deleteValue(int key) {
    struct Node* t = head;
    while (t && t->data != key) t = t->next;
    if (t == NULL) return;
    if (t->prev) t->prev->next = t->next;
    else head = t->next;
    if (t->next) t->next->prev = t->prev;
    free(t);
}

void display() {
    struct Node* t = head;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int n, key, val, ch;
    scanf("%d", &n);
    createList(n);
    while (1) {
        scanf("%d", &ch);
        if (ch == 1) {
            scanf("%d %d", &key, &val);
            insertLeft(key, val);
        } else if (ch == 2) {
            scanf("%d", &key);
            deleteValue(key);
        } else if (ch == 3) {
            display();
        } else if (ch == 4) {
            break;
        }
    }
    return 0;
}
