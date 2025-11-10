#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //파일 열기
    FILE *fp = fopen("data.txt", "wt"); //fILE* 는 파일을 가리키는 포인터
    //"wt"는 쓰기(write), 텍스트(text) 모드로 기존 파일 내용은 덮어씀

    if (fp == NULL) { //파일 못열면 비정상 종료
        printf("Failed to open file");

        return -1;
    }

    fputc('A', fp); //파일에 문자 하나씩 기록하기
    fputc('B', fp);
    fputc('C', fp);
    //실행 후 data.txt 파일을 열면 ABC가 저장되어 있음

    fclose(fp); //파일 닫기
    return 0;
}