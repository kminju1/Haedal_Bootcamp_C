#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int **A = (int**)malloc(N*sizeof(int*));
    for (int i = 0; i < N; i++) {
        A[i] = (int*)malloc(M*sizeof(int));
    }
    int B[MAX][MAX] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] += B[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}