#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

//stack 구현
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return (s->top == -1);
}

int isStackFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

void push(Stack *s, int x) {
    if (isStackFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++(s->top)] = x;
}

int pop(Stack *s) {
    if (isStackEmpty(s)) return -1;
    return s->data[(s->top)--];
}

int stackTop(Stack *s) {
    if (isStackEmpty(s)) return -1;
    return s->data[s->top];
}

int stackSize(Stack *s) {
    return s->top + 1;
}

//Queue 구현
typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isQueueEmpty(Queue *q) {
    return (q->front == q->rear);
}

int isQueueFull(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void enqueue(Queue *q, int x) {
    if (isQueueFull(q)) {
        printf("Queue overflow!\n");
        return;
    }
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) return -1;
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return val;
}

int queueFront(Queue *q) {
    if (isQueueEmpty(q)) return -1;
    return q->data[q->front];
}

int queueBack(Queue *q) {
    if (isQueueEmpty(q)) return -1;
    return q->data[(q->rear + MAX_SIZE - 1) % MAX_SIZE];
}

int queueSize(Queue *q) {
    return (q->rear - q->front + MAX_SIZE) % MAX_SIZE;
}

//메인 함수
int main(void) {
    int N;
    scanf("%d", &N);
    getchar(); // 개행 제거

    Stack stack;
    Queue queue;
    initStack(&stack);
    initQueue(&queue);

    char cmd[20];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", cmd);

        if (strcmp(cmd, "push") == 0) {           // 스택 push
            scanf("%d", &x);
            push(&stack, x);
        }
        else if (strcmp(cmd, "pop") == 0) {
            printf("%d\n", pop(&stack));
        }
        else if (strcmp(cmd, "top") == 0) {
            printf("%d\n", stackTop(&stack));
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", stackSize(&stack));
        }
        else if (strcmp(cmd, "empty") == 0) {
            printf("%d\n", isStackEmpty(&stack));
        }

        //Queue 관련 명령
        else if (strcmp(cmd, "enqueue") == 0) {
            scanf("%d", &x);
            enqueue(&queue, x);
        }
        else if (strcmp(cmd, "dequeue") == 0) {
            printf("%d\n", dequeue(&queue));
        }
        else if (strcmp(cmd, "front") == 0) {
            printf("%d\n", queueFront(&queue));
        }
        else if (strcmp(cmd, "back") == 0) {
            printf("%d\n", queueBack(&queue));
        }
        else if (strcmp(cmd, "qsize") == 0) {
            printf("%d\n", queueSize(&queue));
        }
        else if (strcmp(cmd, "qempty") == 0) {
            printf("%d\n", isQueueEmpty(&queue));
        }
    }

    return 0;
}
