#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    char ch;    //ch를 문자형으로 선언
    FILE *fp = fopen("/Users/minju/Desktop/WORKSPACE/Haedal_Assignments/5_Assignments/data.txt", "rt");

    if (fp == NULL) {   //파일 열기 실패 시 비정상 종료
        printf("Failed to open file");

        return -1;
    }

    for (int i = 0; i < 3; i++) {   //파일에서 문자 3개 읽기
        ch = fgetc(fp); //한 글자씩 읽기
        printf("%c\n", ch); //읽은 문자 출력
    }

    fclose(fp); //파일 닫기
    return 0;   //정상 종료
}