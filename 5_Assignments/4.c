#define _CRT_SECURE_NO_WARNINGS  // scanf, fopen 같은 함수 쓸 때 경고 방지
#include <stdio.h>

int main() {
    // 입력받을 변수 선언
    char name[10];  // 이름 저장용 문자열
    int age;        // 나이 저장용 정수

    // student.txt 파일을 쓰기 모드로 열기
    FILE *fp = fopen("student.txt", "wt");
    // "wt"는 텍스트 쓰기 모드로 파일이 없으면 생성되고, 있으면 덮어씀.

    for (int i = 0; i < 3; i++) {
        printf("%d번째 학생 이름과 나이 입력 (name age): ", i + 1);
        scanf("%s %d", name, &age);  // 문자열(name)과 정수(age) 입력받기
        getchar();  // 입력 버퍼에 남은 개행 문자 제거 (다음 입력 오류 방지)

        // 파일에 출력 (형식: 이름 나이)
        fprintf(fp, "%s %d\n", name, age);
    }

    fclose(fp);  // 파일 닫기
    return 0;    // 정상 종료
}
