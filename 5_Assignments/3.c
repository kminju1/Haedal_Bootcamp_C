#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //원본 파일과 복사본 파일 포인터 선언
    FILE *org = fopen("input.txt", "rt");
    FILE *copy = fopen("output.txt", "wt");
    char str[20];

    if (org == NULL || copy == NULL) {
        printf("Failed to open file");
        return -1;
    }   //파일 읽기 실패 처리

    while (fgets(str, sizeof(str), org) != NULL) {
        fputs(str, copy);
    }   // fgets 를 한 줄씩 읽어서 fputs로 복사


    //복사가 끝난 후에 파일 끝 EOF에 도달했는지 확인하기
    if (feof(org) != 0) {
        printf("File copied successfully");
    }
    else {
        printf("Falied to copy file");
    }
    
    //파일 닫기
    fclose(org);
    fclose(copy);
    
    return 0;
}