//infix to Postfix
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

char stk[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

char peek() {
    return stk[top];
}

char pop() {
    if (isEmpty())
        return -1;
    char ch = stk[top];
    top--;
    return ch;
}

void push(char oper) {
    if (isFull())
        printf("Stack Full!!!!\n");
    else {
        top++;
        stk[top] = oper;
    }
}

int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch) {
    switch (ch) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

void convertInfixToPostfix(char* expression) {
    int i, j;
    int len = strlen(expression);
    char* result = (char*)malloc((len + 1) * sizeof(char));

    for (i = 0, j = 0; expression[i]; ++i) {
        if (checkIfOperand(expression[i]))
            result[j++] = expression[i];
        else if (expression[i] == '(')
            push(expression[i]);
        else if (expression[i] == ')') {
            while (!isEmpty() && peek() != '(')
                result[j++] = pop();
            if (!isEmpty() && peek() != '(')
                return; // invalid expression
            else
                pop();
        } else { // if an operator
            while (!isEmpty() && precedence(expression[i]) <= precedence(peek()))
                result[j++] = pop();
            push(expression[i]);
        }
    }

    while (!isEmpty())
        result[j++] = pop();

    result[j] = '\0';
    printf("Postfix expression: %s\n", result);
    free(result);
}

int main() {
    char expression[MAX];
    printf("Enter an infix expression: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = '\0'; // Remove newline character if any
    convertInfixToPostfix(expression);
    return 0;
}
