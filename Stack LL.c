#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node* next};
struct Node* top=NULL;

void push(int value){
struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
if(!newNode){
    printf("stack overflow");
    return;
}
newNode->data=value;
newNode->next=top;
top=newNode;
printf("%d pushed to the stack",value);
}

int pop(){
if(top==NULL){
    printf("stack underflow");
    return -1;
}
struct Node* temp=top;
int popped=temp->data;
top=top->next;
free(temp);
return popped;
}

void display(){
if(top==NULL){
    printf("stack is empty");
    return;
}
struct Node* temp=top;
printf("stack elements");
while(temp!=NULL){
    printf("%d",temp->data);
    temp=temp->next;
}
printf("\n");
}

int main(){
int choice,value;
while(1){
    printf("1.push 2.pop 3.display 4.exit\n");
    scanf("%d",&choice);
    switch(choice){
case 1:
    printf("enter value to push");
    scanf("%d",&value);
    push(value);
    break;

    case 2:
        value=pop();
        if (value!=-1)
            printf("top element %d",value);
        break;

    case 3:
        display();
        break;
    case 4:
        exit(0);

    }
}
}
