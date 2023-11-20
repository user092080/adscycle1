#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to push a new node onto the stack
struct Node *push(struct Node *top, int data) {
    struct Node *newNode = createNode(data);
    if (top == NULL) {
        return newNode;
    }
    newNode->next = top;
    top->prev = newNode;
    return newNode;
}

// Function to pop a node from the stack
struct Node *pop(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty. Unable to pop.\n");
        return NULL;
    }
    struct Node *temp = top;
    top = top->next;
    if (top != NULL) {
        top->prev = NULL;
    }
    free(temp);
    return top;
}

// Function to search for a value in the stack
int search(struct Node *top, int value) {
    struct Node *current = top;
    int position = 1;

    while (current != NULL) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1; // Value not found
}

// Function to display the stack
void displayStack(struct Node *top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *top = NULL;
    int choice, data, searchValue, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push a value onto the stack\n");
        printf("2. Pop a value from the stack\n");
        printf("3. Search for a value in the stack\n");
        printf("4. Display the stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &data);
                top = push(top, data);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &searchValue);
                position = search(top, searchValue);
                if (position != -1) {
                    printf("Value %d found at position %d.\n", searchValue, position);
                } else {
                    printf("Value %d not found in the stack.\n", searchValue);
                }
                break;

            case 4:
                displayStack(top);
                break;

            case 5:
                // Free memory for all nodes in the stack
                while (top != NULL) {
                    struct Node *temp = top;
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
