#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *left, *right;
};
struct node *root = NULL;

struct node* createNode(int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
    printf("Duplicate value not allowed!\n");
    return root;
}

void preorder(struct node* root) {
if (root != NULL) {
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);

}
}

void inorder(struct node* root) {
if (root != NULL) {
inorder(root->left);
printf("%d", root->data);
inorder(root->right);
}
}


void postorder(struct node* root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%d", root->data);
}
}

int search(struct node* root,int key) {
if (root == NULL)
return 0;
if (root->data == key)
return 1;
if (key == root->data)
return search(root->left, key);
else
return search(root->right, key);
}

int countNodes(struct node* root) {
if (root == NULL)
return 0;
return 1 + countNodes(root->left) + countNodes(root->right);
}
int height(struct node* root){
if (root == NULL)
    return 0;
int leftH = height(root->left);
int rightH = height(root->right);
return (leftH >rightH ? leftH : rightH) + 1;
}


int main() {
int choice, value;
printf("\n 1. Insert Node\n 2.Preorder\n 3.Inorder\n 4.Postorder\n 5.Search\n 6.countNodes\n 7.height\n 8.Exit ");
while (1) {

printf("enter your choice :");
scanf("%d",&choice);

switch (choice) {

case 1:
printf("Enter value: ");
scanf("%d",&value);
root = insert(root, value);
break;

case 2:
printf("Preorder:" );
preorder(root);
break;

case 3:
printf("Inorder:");
inorder(root);
break;

case 4:
printf("Postorder:");
postorder(root);
break;

case 5:
printf("Enter the searching element :");
scanf("%d", &value);
if (search(root, value))
printf("%d searched element is there", value);
else
printf("%d the element not found  .", value);
break;

case 6:
printf("Total nodes = %d", countNodes(root));
break;

case 7:
printf("Height  = %d", height(root));
break;

case 8:
exit(0);

}
}
return 0;
}
