/*
24. WAP to implement following by using stack. A. Factorial
of a given number B. Generation of Fibonacci series
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to display the stack
void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Function to compute factorial using stack
int factorial(int n) {
    struct Node* stack = NULL;
    int result = 1;

    // Push all numbers from n to 1 onto the stack
    for (int i = n; i > 1; i--) {
        push(&stack, i);
    }

    // Pop all elements and multiply
    while (!isEmpty(stack)) {
        result *= pop(&stack);
    }

    return result;
}

// Function to generate Fibonacci series using stack
void fibonacci(int n) {
    struct Node* stack = NULL;

    if (n <= 0) {
        printf("Number of terms should be positive.\n");
        return;
    }

    // Initialize first two Fibonacci numbers
    push(&stack, 1);
    if (n > 1) {
        push(&stack, 1);
    }

    printf("Fibonacci series: ");
    struct Node* temp = stack;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Generate remaining Fibonacci numbers
    for (int i = 3; i <= n; i++) {
        int first = pop(&stack);
        int second = pop(&stack);
        int next = first + second;
        printf("%d ", next);
        push(&stack, first);
        push(&stack, next);
    }
    printf("\n");
}

// Main function to test the stack operations
int main() {
    int choice, num;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Compute Factorial\n");
        printf("2. Generate Fibonacci Series\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to compute its factorial: ");
                scanf("%d", &num);
                if (num < 0) {
                    printf("Factorial of a negative number doesn't exist.\n");
                } else {
                    printf("Factorial of %d is %d\n", num, factorial(num));
                }
                break;
            case 2:
                printf("Enter the number of terms for the Fibonacci series: ");
                scanf("%d", &num);
                fibonacci(num);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


