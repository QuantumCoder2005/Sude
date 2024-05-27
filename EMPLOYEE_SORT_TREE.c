/*
11. Write a program to efficiently search a particular employee record by using Tree data structure.
Also sort the data on emp-id in ascending order.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for an employee record
struct Employee {
    int emp_id;
    char name[50];
    int age;
};

// Structure for a node of the binary search tree
struct Node {
    struct Employee emp;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given employee record
struct Node* newNode(struct Employee emp) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->emp = emp;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new employee record into the BST
struct Node* insert(struct Node* root, struct Employee emp) {
    if (root == NULL)
        return newNode(emp);
    if (emp.emp_id < root->emp.emp_id)
        root->left = insert(root->left, emp);
    else if (emp.emp_id > root->emp.emp_id)
        root->right = insert(root->right, emp);
    return root;
}

// Function to search for an employee record by employee ID
struct Node* search(struct Node* root, int emp_id) {
    if (root == NULL || root->emp.emp_id == emp_id)
        return root;
    if (root->emp.emp_id < emp_id)
        return search(root->right, emp_id);
    return search(root->left, emp_id);
}

// Function to traverse the BST in inorder (ascending order of employee IDs)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Emp ID: %d, Name: %s, Age: %d\n", root->emp.emp_id, root->emp.name, root->emp.age);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, emp_id, age;
    char name[50];

    // Input number of employee records
    printf("Enter the number of employee records: ");
    scanf("%d", &n);

    // Input employee records
    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &emp_id);
        printf("Name: ");
        scanf("%s", name);
        printf("Age: ");
        scanf("%d", &age);

        struct Employee emp;
        emp.emp_id = emp_id;
        strcpy(emp.name, name);
        emp.age = age;

        root = insert(root, emp);
    }

    // Displaying employee records in ascending order of employee IDs
    printf("\nEmployee records sorted by emp ID (ascending order):\n");
    inorderTraversal(root);
    printf("\n");

    // Searching for an employee record by emp ID
    int search_id;
    printf("Enter the employee ID to search: ");
    scanf("%d", &search_id);
    
    struct Node* result = search(root, search_id);
    if (result != NULL)
        printf("Employee found - Emp ID: %d, Name: %s, Age: %d\n", result->emp.emp_id, result->emp.name, result->emp.age);
    else
        printf("Employee with emp ID %d not found\n", search_id);

    return 0;
}
