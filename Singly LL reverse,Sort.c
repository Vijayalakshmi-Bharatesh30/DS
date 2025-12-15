#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

void insertEnd(struct Node** head, int x) {
    struct Node* n = createNode(x);
    if (*head == NULL) {
        *head = n;
        return;
    }
    struct Node* t = *head;
    while (t->next) t = t->next;
    t->next = n;
}

void display(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void sortList(struct Node* head) {
    struct Node* i = head;
    while (i) {
        struct Node* j = i->next;
        while (j) {
            if (i->data > j->data) {
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
            j = j->next;
        }
        i = i->next;
    }
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* cur = *head;
    struct Node* nxt;
    while (cur) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

struct Node* concatenate(struct Node* a, struct Node* b) {
    if (!a) return b;
    struct Node* t = a;
    while (t->next) t = t->next;
    t->next = b;
    return a;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n, x;

    printf("Enter number of elements for list1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&list1, x);
    }

    printf("Enter number of elements for list2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&list2, x);
    }

    sortList(list1);
    reverseList(&list1);
    list1 = concatenate(list1, list2);

    display(list1);

    return 0;
}
