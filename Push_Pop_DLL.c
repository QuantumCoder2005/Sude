/*push and pop of stack on doubly linkedlist*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

// Define the structure for a Stack
typedef struct Stack {
    Node* head;
    Node* tail;
} Stack;

// Function to create a new node
Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to initialize a stack
void initialize_stack(Stack* stack) {
    stack->head = NULL;
    stack->tail = NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    Node* new_node = create_node(value);
    if (stack->tail == NULL) {
        stack->head = stack->tail = new_node;
    } else {
        new_node->prev = stack->tail;
        stack->tail->next = new_node;
        stack->tail = new_node;
    }
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->tail == NULL) {
        printf("Stack is empty\n");
        return -1; // Indicates stack is empty
    }
    int pop_value = stack->tail->value;
    Node* temp = stack->tail;
    if (stack->head == stack->tail) { // Only one element in the list
        stack->head = stack->tail = NULL;
    } else {
        stack->tail = stack->tail->prev;
        stack->tail->next = NULL;
    }
    free(temp);
    printf("Popped %d from the stack\n", pop_value);
    return pop_value;
}

// Function to check if the stack is empty
int is_empty(Stack* stack) {
    return stack->tail == NULL;
}

// Function to peek at the top element of the stack
int peek(Stack* stack) {
    if (stack->tail == NULL) {
        printf("Stack is empty\n");
        return -1; // Indicates stack is empty
    }
    return stack->tail->value;
}

// Function to print the stack
void print_stack(Stack* stack) {
    Node* current = stack->tail;
    while (current) {
        printf("%d <- ", current->value);
        current = current->prev;
    }
    printf("None\n");
}

// Menu driven main function
int main() {
    Stack stack;
    initialize_stack(&stack);
    int choice, value;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Top value: %d\n", value);
                }
                break;
            case 4:
                print_stack(&stack);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

