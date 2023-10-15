#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *insertAtBeginning(Node *head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = head;

    return newNode;
}

Node *deleteNodeAtPosition(Node *head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (position == 1) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node *prev = NULL;
    Node *current = head;
    int currentPosition = 1;

    while (current != NULL && currentPosition < position) {
        prev = current;
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position out of range.\n");
        return head;
    }

    prev->next = current->next;
    free(current);

    return head;
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;

    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert node at the beginning\n");
        printf("2. Delete node at a specific position\n");
        printf("3. Print the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteNodeAtPosition(head, position);
                break;

            case 3:
                printf("Linked list:\n");
                printList(head);
                break;

            case 4:
                freeList(head);
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
