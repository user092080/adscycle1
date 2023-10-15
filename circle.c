#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a circular queue
struct CircularQueue {
    int *arr;
    int front, rear;
    int capacity;
    bool isFull;
};

// Function to create a circular queue
struct CircularQueue* createCircularQueue(int capacity) {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    queue->arr = (int*)malloc(capacity * sizeof(int));
    if (queue->arr == NULL) {
        printf("Memory allocation failed.\n");
        free(queue);
        exit(EXIT_FAILURE);
    }

    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->isFull = false;
    return queue;
}

// Function to check if the circular queue is empty
bool isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1);
}

// Function to check if the circular queue is full
bool isFull(struct CircularQueue* queue) {
    return (queue->isFull);
}

// Function to enqueue an element
void enqueue(struct CircularQueue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Unable to enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = data;

    if (queue->front == ((queue->rear + 1) % queue->capacity)) {
        queue->isFull = true;
    }
}

// Function to dequeue an element
void dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Unable to dequeue.\n");
        return;
    }

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
        queue->isFull = false;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
}

// Function to search for an element in the queue
int search(struct CircularQueue* queue, int value) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Unable to search.\n");
        return -1;
    }

    int index = queue->front;
    while (index != queue->rear) {
        if (queue->arr[index] == value) {
            return index;
        }
        index = (index + 1) % queue->capacity;
    }

    if (queue->arr[index] == value) {
        return index;
    }

    printf("Value not found in the queue.\n");
    return -1;
}

// Function to display the queue
void displayQueue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int index = queue->front;
    while (index != queue->rear) {
        printf("%d -> ", queue->arr[index]);
        index = (index + 1) % queue->capacity;
    }
    printf("%d -> NULL\n", queue->arr[index]);
}

// Function to free the allocated memory for the queue
void freeQueue(struct CircularQueue* queue) {
    free(queue->arr);
    free(queue);
}

int main() {
    int capacity, choice, data, searchValue;

    printf("Enter the capacity of the circular queue: ");
    scanf("%d", &capacity);

    struct CircularQueue* queue = createCircularQueue(capacity);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Search\n");
        printf("4. Display the queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;

            case 2:
                dequeue(queue);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &searchValue);
                int position = search(queue, searchValue);
                if (position != -1) {
                    printf("Value %d found at position %d.\n", searchValue, position);
                }
                break;

            case 4:
                displayQueue(queue);
                break;

            case 5:
                freeQueue(queue);
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
