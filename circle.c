#include <stdio.h>
#include <stdlib.h>
int *queue, front = -1, rear = -1, size;
void initializeQueue();
int isFull(), isEmpty();
void enqueue(int element);
int dequeue();
int searchElement(int element);
void displayQueue();

int main() {
    int choice, element, searchResult;

    printf("Enter the size of Queue: ");
    scanf("%d", &size);

    initializeQueue();

    do {
        printf("1. Enqueue element)\n");
        printf("2. Dequeue element)\n");
        printf("3. Search element\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enter: ");
                scanf("%d", &element);
                enqueue(element);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                searchResult = searchElement(element);
                if (searchResult != -1) {
                    printf("%d found at position %d\n", element, searchResult);
                } else {
                    printf("%d not found \n", element);
                }
                break;

            case 4:
                displayQueue();
                break;

            case 5:
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    free(queue);

    return 0;
}


void initializeQueue() {
    queue = (int *)malloc(size * sizeof(int));
}


int isFull() {
    return (front == (rear + 1) % size);
}
int isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    queue[rear] = element;
    printf("%d enqueued to the queue\n", element);
}

int dequeue() {
    int element;
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }

    element = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }

    printf("%d Dequeued \n", element);
    return element;
}
int searchElement(int element) {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }

    int current = front;
    int position = 1;

    do {
        if (queue[current] == element) {
            return position;
        }

        current = (current + 1) % size;
        position++;
    } while (current != (rear + 1) % size);

    return -1;
}
void displayQueue() {
 if (isEmpty()) {
   printf("Queue is empty\n");
   return;
  }

 printf(" The Circular Queue elements: ");
 int current = front;
 do {
    printf("%d ", queue[current]);
     current = (current + 1) % size;
    } while (current != (rear + 1) % size);

    printf("\n");
}
