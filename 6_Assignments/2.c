#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

int main(void) {
    int N;
    scanf("%d", &N);

    int queue[MAX_SIZE];
    int front = 0;   // 큐의 앞 인덱스
    int rear  = 0;   // 큐의 뒤 다음 인덱스
    int size  = 0;   // 큐에 들어있는 원소 개수

    char cmd[10];
    for (int i = 0; i < N; i++) {
        scanf("%s", cmd);

        if (strcmp(cmd, "push") == 0) {
            int x;
            scanf("%d", &x);
            // 큐에 삽입
            queue[rear] = x;
            rear = (rear + 1) % MAX_SIZE;
            size++;
        }
        else if (strcmp(cmd, "pop") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", queue[front]);
                front = (front + 1) % MAX_SIZE;
                size--;
            }
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", size);
        }
        else if (strcmp(cmd, "empty") == 0) {
            printf("%d\n", (size == 0) ? 1 : 0);
        }
        else if (strcmp(cmd, "front") == 0) {
            if (size == 0) printf("-1\n");
            else          printf("%d\n", queue[front]);
        }
        else if (strcmp(cmd, "back") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                int idx = (rear - 1 + MAX_SIZE) % MAX_SIZE;
                printf("%d\n", queue[idx]);
            }
        }
    }

    return 0;
}
