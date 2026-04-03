#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *Q;
    int size;
    int front;
    int rear;
} CQueue;

CQueue* createQueue(int capacity) {
    CQueue *queue = (CQueue *)malloc(sizeof(CQueue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    queue->Q = (int *)malloc(capacity * sizeof(int));
    if (queue->Q == NULL) {
        printf("Memory allocation for queue array failed!\n");
        free(queue);
        return NULL;
    }
    
    queue->size = capacity;
    queue->front = -1;
    queue->rear = -1;
    
    printf("Queue created with capacity %d\n", capacity);
    return queue;
}

int isEmpty(CQueue *queue) {
    return (queue->front == -1);
}

int isFull(CQueue *queue) {
    return ((queue->rear + 1) % queue->size == queue->front);
}

void enqueue(CQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Overflow! Queue is full. Cannot insert %d\n", value);
        return;
    }
    
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    }
    else {
        queue->rear = (queue->rear + 1) % queue->size;
    }
    
    queue->Q[queue->rear] = value;
    printf("Enqueued %d at position %d\n", value, queue->rear);
}

int dequeue(CQueue *queue) {
    if (isEmpty(queue)) {
        printf("Underflow! Queue is empty. Cannot delete.\n");
        return -1;
    }
    
    int deleted = queue->Q[queue->front];
    
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        queue->front = (queue->front + 1) % queue->size;
    }
    
    printf("Dequeued %d from position %d\n", deleted, (queue->front - 1 + queue->size) % queue->size);
    return deleted;
}

int frontVal(CQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front element.\n");
        return -1;
    }
    return queue->Q[queue->front];
}

int rearVal(CQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No rear element.\n");
        return -1;
    }
    return queue->Q[queue->rear];
}

void displayQueue(CQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue Elements (Front to Rear): ");
    int i = queue->front;
    
    if (queue->front <= queue->rear) {
        while (i <= queue->rear) {
            printf("%d ", queue->Q[i]);
            i++;
        }
    }
    else {
        while (i < queue->size) {
            printf("%d ", queue->Q[i]);
            i++;
        }
        i = 0;
        while (i <= queue->rear) {
            printf("%d ", queue->Q[i]);
            i++;
        }
    }
    printf("\n");
}

void freeQueue(CQueue *queue) {
    if (queue != NULL) {
        if (queue->Q != NULL) {
            free(queue->Q);
        }
        free(queue);
    }
    printf("Queue memory freed.\n");
}

int main() {
    printf("===== CIRCULAR QUEUE IMPLEMENTATION =====\n");
    
    int capacity, choice, value;
    CQueue *queue = NULL;
    
    printf("Enter the size of the queue: ");
    scanf("%d", &capacity);
    
    queue = createQueue(capacity);
    
    if (queue == NULL) {
        return 1;
    }
    
    while (1) {
        printf("\n---MENU---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Front Value\n");
        printf("5. Rear Value\n");
        printf("6. Is Empty\n");
        printf("7. Is Full\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter an element to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
                
            case 2:
                dequeue(queue);
                break;
                
            case 3:
                displayQueue(queue);
                break;
                
            case 4:
                if (!isEmpty(queue)) {
                    printf("Queue front: %d\n", frontVal(queue));
                }
                break;
                
            case 5:
                if (!isEmpty(queue)) {
                    printf("Queue rear: %d\n", rearVal(queue));
                }
                break;
                
            case 6:
                if (isEmpty(queue)) {
                    printf("Queue is EMPTY\n");
                } else {
                    printf("Queue is NOT empty\n");
                }
                break;
                
            case 7:
                if (isFull(queue)) {
                    printf("Queue is FULL\n");
                } else {
                    printf("Queue is NOT full\n");
                }
                break;
                
            case 8:
                freeQueue(queue);
                printf("\n===== PROGRAM COMPLETED =====\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
