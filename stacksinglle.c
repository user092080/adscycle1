#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to push a new element onto the stack
struct Node* push(struct Node* top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = top;

    return newNode;
}

// Function to pop an element from the stack
struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return NULL;
    }

    struct Node* temp = top;
    top = top->next;
    free(temp);

    return top;
}

// Function to perform a linear search in the stack
int linearSearch(struct Node* top, int target) {
    struct Node* current = top;
    int position = 1;

    while (current != NULL) {
        if (current->data == target) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;  // Return -1 if target is not found
}

// Function to display the stack
void displayStack(struct Node* top) {
    struct Node* current = top;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* top = NULL;
    int choice, data, target, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push element onto the stack\n");
        printf("2. Pop element from the stack\n");
        printf("3. Linear search in the stack\n");
        printf("4. Display the stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                top = push(top, data);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                printf("Enter target element to search: ");
                scanf("%d", &target);
                position = linearSearch(top, target);
                if (position != -1)
                    printf("Element %d found at position %d\n", target, position);
                else
                    printf("Element %d not found in the stack\n", target);
                break;

            case 4:
                printf("Stack:\n");
                displayStack(top);
                break;

            case 5:
                // Free memory allocated for the stack
                while (top != NULL) {
                    struct Node* temp = top;
                    top = top->next;
                    free(temp);
                }
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
