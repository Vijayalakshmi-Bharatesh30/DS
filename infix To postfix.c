#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[]) {
    char postfix[SIZE], ch;
    int i = 0, k = 0;
    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (top != -1)
        postfix[k++] = pop();
    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[SIZE];
    printf("Enter Infix Expression: ");
    gets(infix);
    infixToPostfix(infix);
    return 0;
}
