#include <stdio.h>
#define SIZE 5
int stack[SIZE], top = -1;

void push(int value){

if (top==SIZE-1){
    printf("stack overflow");
}
else{

    top++;
    stack[top]=value;
    printf("%d pushed into the stack",value);
}
}
void pop(){
if(top==-1){
        printf("stack underflow");
}
else{
    printf("%d popped from the stack",stack[top]);
    top--;
}
}
void display(){
    if (top == -1)
        printf("Stack is empty\n");
    else {
        for (int i = top; i >= 0; i--)

            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice,value;
    while (1) {
        printf("\n1.Push 2.Pop 3.Display 4.Exit ");
        printf("enter your choice");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("enter the vaue to push:");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;

        }
    }
}
