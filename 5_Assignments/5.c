#define _CRT_SECURE_NO_WARNINGS  // 보안 경고 방지용 (Visual Studio용)
#include <stdio.h>
#include <stdlib.h>  // malloc, free 함수 사용하려면 필요

int main() {
    // int 크기만큼 동적 메모리 할당 → ptr1이 그 메모리를 가리킴
    int* ptr1 = (int*)malloc(sizeof(int));
    // int 3개 크기만큼 동적 메모리 할당 → ptr2가 그 메모리를 가리킴
    int* ptr2 = (int*)malloc(sizeof(int) * 3);

    *ptr1 = 20;  // ptr1이 가리키는 메모리에 20 저장

    // ptr2가 가리키는 공간에 0, 1, 2 저장
    for (int i = 0; i < 3; i++) {
        ptr2[i] = i;
    }

    // ptr1의 값 출력 (20)
    printf("%d\n", *ptr1);

    // ptr2 배열의 값 출력 (0 1 2)
    for (int i = 0; i < 3; i++) {
        printf("%d ", ptr2[i]);
    }

    // 동적으로 할당한 메모리 해제
    free(ptr1);
    free(ptr2);

    return 0;  // 정상 종료
}
