                                                                                            
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    if (newNode == NULL) {
        printf("failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeg(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 0) {
        printf("Invalid\n");
        return head;
    }

    if (position == 0) {
        return insertAtBeg(head, data);
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = head; 
    int count = 0;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf(" out of range\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head; 
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

struct Node* deleteNodeAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        return head;
    }

    if (position == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head; 
    int count = 0;

    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return head;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    return head;
}

void display(struct Node* head) {
    struct Node* temp = head; 
    while (temp != NULL) {
        printf("%d , ", temp->data);
        temp = temp->next;
    }
    printf("null\n");
}

int main() {
    struct Node* head = NULL;
    int data, choice, position;

    printf("Enter the number ");
    int numNodes;
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter values  %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

  do {
        printf("\nLinked List: ");
        display(head);
        printf("\n1. Insert at the beginning\n");
        printf("2. Insert at a  position\n");
        printf("3. Insert at the end\n"); 
        printf("4. Delete at a  position\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value beginning: ");
                scanf("%d", &data);
                head = insertAtBeg(head, data);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 3:
                printf("Enter value to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteNodeAtPosition(head, position);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

