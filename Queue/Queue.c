#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 26

typedef struct {
    char data[MAX_QUEUE_SIZE];
    int front, rear, size;
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

int isFull(Queue *queue) {
    return queue->size == MAX_QUEUE_SIZE;
}

void enqueue(Queue *queue, char value) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }

    queue->data[queue->rear] = value;
    queue->size++;

    // エンキュー時の出力
    printf("Enqueue: %c, Queue: ", value);
    for (int i = 0; i < queue->size; ++i) {
        printf("%c ", queue->data[(queue->front + i) % MAX_QUEUE_SIZE]);
    }
    printf("\n");
}

char dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return '\0';
    }

    char value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        initializeQueue(queue);
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
        queue->size--;
    }

    // デキュー時の出力
    printf("Dequeue: %c, Queue: ", value);
    for (int i = 0; i < queue->size; ++i) {
        printf("%c ", queue->data[(queue->front + i) % MAX_QUEUE_SIZE]);
    }
    printf("\n");

    return value;
}

int main() {
    Queue myQueue;
    initializeQueue(&myQueue);

    // 任意の順番でエンキュー
    enqueue(&myQueue, 'C');
    enqueue(&myQueue, 'A');
    enqueue(&myQueue, 'B');
    enqueue(&myQueue, 'F');

    // デキューして表示
    dequeue(&myQueue);
    dequeue(&myQueue);

    // 新たなデーキューとエンキュー
    enqueue(&myQueue, 'D');
    dequeue(&myQueue);
    enqueue(&myQueue, 'E');

    return 0;
}