//TWO STACK using array

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top1;
    int top2;
} TwoStacks;

// Function to initialize the two stacks
void initialize(TwoStacks* ts) {
    ts->top1 = -1;
    ts->top2 = MAX;
}

// Function to check if the first stack is empty
int isEmptyStack1(TwoStacks* ts) {
    return ts->top1 == -1;
}

// Function to check if the second stack is empty
int isEmptyStack2(TwoStacks* ts) {
    return ts->top2 == MAX;
}

// Function to check if the array is full
int isFull(TwoStacks* ts) {
    return ts->top1 + 1 == ts->top2;
}

// Function to push an element onto the first stack
void pushStack1(TwoStacks* ts, int data) {
    if (isFull(ts)) {
        printf("Stack Overflow!\n");
        return;
    }
    ts->arr[++ts->top1] = data;
}

// Function to push an element onto the second stack
void pushStack2(TwoStacks* ts, int data) {
    if (isFull(ts)) {
        printf("Stack Overflow!\n");
        return;
    }
    ts->arr[--ts->top2] = data;
}

// Function to pop an element from the first stack
int popStack1(TwoStacks* ts) {
    if (isEmptyStack1(ts)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return ts->arr[ts->top1--];
}

// Function to pop an element from the second stack
int popStack2(TwoStacks* ts) {
    if (isEmptyStack2(ts)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return ts->arr[ts->top2++];
}

// Function to display the first stack
void displayStack1(TwoStacks* ts) {
    if (isEmptyStack1(ts)) {
        printf("Stack 1 is empty.\n");
        return;
    }
    printf("Stack 1: ");
    for (int i = 0; i <= ts->top1; i++) {
        printf("%d ", ts->arr[i]);
    }
    printf("\n");
}

// Function to display the second stack
void displayStack2(TwoStacks* ts) {
    if (isEmptyStack2(ts)) {
        printf("Stack 2 is empty.\n");
        return;
    }
    printf("Stack 2: ");
    for (int i = MAX - 1; i >= ts->top2; i--) {
        printf("%d ", ts->arr[i]);
    }
    printf("\n");
}

// Main function to test the above functions
int main() {
    TwoStacks ts;
    initialize(&ts);
    
    int choice, data;
    while (1) {
        printf("\n1. Push to Stack 1\n2. Push to Stack 2\n3. Pop from Stack 1\n4. Pop from Stack 2\n5. Display Stack 1\n6. Display Stack 2\n7. Check if Full\n8. Check if Stack 1 is Empty\n9. Check if Stack 2 is Empty\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to push to Stack 1: ");
                scanf("%d", &data);
                pushStack1(&ts, data);
                break;
            case 2:
                printf("Enter data to push to Stack 2: ");
                scanf("%d", &data);
                pushStack2(&ts, data);
                break;
            case 3:
                data = popStack1(&ts);
                if (data != -1)
                    printf("Popped from Stack 1: %d\n", data);
                break;
            case 4:
                data = popStack2(&ts);
                if (data != -1)
                    printf("Popped from Stack 2: %d\n", data);
                break;
            case 5:
                displayStack1(&ts);
                break;
            case 6:
                displayStack2(&ts);
                break;
            case 7:
                if (isFull(&ts))
                    printf("Stack is full.\n");
                else
                    printf("Stack is not full.\n");
                break;
            case 8:
                if (isEmptyStack1(&ts))
                    printf("Stack 1 is empty.\n");
                else
                    printf("Stack 1 is not empty.\n");
                break;
            case 9:
                if (isEmptyStack2(&ts))
                    printf("Stack 2 is empty.\n");
                else
                    printf("Stack 2 is not empty.\n");
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
