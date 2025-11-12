#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100
#define FILENAME "todo_list.txt"

typedef struct {
    char task[MAX_LENGTH];     // 할 일 내용
    int  completed;            // 완료 여부 (0: 미완료, 1: 완료)
    char due_date[11];         // 기한: YYYY-MM-DD
    char created_at[17];       // 추가 시각: YYYY-MM-DD_HH:MM  (16자 + '\0')
    char completed_at[17];     // 완료 시각: YYYY-MM-DD_HH:MM  또는 "-"
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

/* 현재 시각을 "YYYY-MM-DD_HH:MM" 형식으로 buf에 채워 넣음 */
static void now_str(char *buf, size_t sz) {
    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    strftime(buf, sz, "%Y-%m-%d_%H:%M", lt);
}

/* 저장된 언더스코어 형식을 출력용 공백으로 바꿔서 찍기 */
static void print_time_pretty(const char *ts) {
    if (strcmp(ts, "-") == 0) { printf("-"); return; }
    for (const char *p = ts; *p; ++p) putchar(*p == '_' ? ' ' : *p);
}

void loadTasks() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) return;

    /* 포맷: completed due created completed_at task... */
    while (task_count < MAX_TASKS &&
           fscanf(file, "%d %10s %16s %16s ", 
                  &tasks[task_count].completed,
                  tasks[task_count].due_date,
                  tasks[task_count].created_at,
                  tasks[task_count].completed_at) == 4) {
        /* 나머지 한 줄은 task 본문(공백 포함) */
        if (fgets(tasks[task_count].task, MAX_LENGTH, file) == NULL) break;
        /* 끝 개행 제거 */
        tasks[task_count].task[strcspn(tasks[task_count].task, "\r\n")] = '\0';
        task_count++;
    }
    fclose(file);
}

void saveTasks() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("파일 저장 오류!\n");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        /* 공백 파싱을 위해 시각은 언더스코어 형식 그대로 저장 */
        fprintf(file, "%d %s %s %s %s\n",
                tasks[i].completed,
                tasks[i].due_date,
                tasks[i].created_at,
                tasks[i].completed_at,
                tasks[i].task);
    }
    fclose(file);
}

/* 남아있는 개행/쓰레기 입력 비우기 */
static void flush_stdin_line(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

void addTask() {
    if (task_count >= MAX_TASKS) {
        printf("더 이상 할 일을 추가할 수 없습니다.\n");
        return;
    }
    flush_stdin_line(); /* 이전 scanf의 개행 제거 */

    printf("새로운 할 일: ");
    fgets(tasks[task_count].task, MAX_LENGTH, stdin);
    tasks[task_count].task[strcspn(tasks[task_count].task, "\r\n")] = '\0';

    printf("완료 날짜 (YYYY-MM-DD): ");
    scanf("%10s", tasks[task_count].due_date);

    tasks[task_count].completed = 0;
    now_str(tasks[task_count].created_at, sizeof(tasks[task_count].created_at));
    strcpy(tasks[task_count].completed_at, "-");

    /* 추가 메시지 (사람이 보기 좋게 공백 표시) */
    printf("할 일이 추가되었습니다! (");
    print_time_pretty(tasks[task_count].created_at);
    printf("에 추가됨)\n");

    task_count++;
}

void displayTasks() {
    if (task_count == 0) {
        printf("할 일이 없습니다!\n");
        return;
    }
    printf("\nTODO list:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. [%c] %s (기한: %s)\n",
               i + 1,
               tasks[i].completed ? 'X' : ' ',
               tasks[i].task,
               tasks[i].due_date);

        printf("    추가: ");
        print_time_pretty(tasks[i].created_at);
        printf("    완료: ");
        print_time_pretty(tasks[i].completed_at);
        printf("\n");
    }
}

void deleteTask() {
    int num;
    displayTasks();
    if (task_count == 0) return;

    printf("삭제할 할 일 번호: ");
    scanf("%d", &num);

    if (num < 1 || num > task_count) {
        printf("잘못된 번호입니다.\n");
        return;
    }
    for (int i = num - 1; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    task_count--;
    printf("할 일이 삭제되었습니다!\n");
}

void completeTask() {
    int num;
    displayTasks();
    if (task_count == 0) return;

    printf("완료할 할 일 번호: ");
    scanf("%d", &num);

    if (num < 1 || num > task_count) {
        printf("잘못된 번호입니다.\n");
        return;
    }
    tasks[num - 1].completed = 1;
    now_str(tasks[num - 1].completed_at, sizeof(tasks[num - 1].completed_at));

    printf("할 일이 완료되었습니다! (");
    print_time_pretty(tasks[num - 1].completed_at);
    printf("에 완료됨)\n");
}

int main() {
    int choice;
    loadTasks(); // 시작 시 파일에서 불러오기

    while (1) {
        printf("\n===== TODO list =====\n");
        printf("1. 할 일 추가\n");
        printf("2. 할 일 삭제\n");
        printf("3. 목록 보기\n");
        printf("4. 완료 체크\n");
        printf("5. 종료\n");
        printf("선택 : ");
        if (scanf("%d", &choice) != 1) { flush_stdin_line(); continue; }

        switch (choice) {
        case 1: addTask(); break;
        case 2: deleteTask(); break;
        case 3: displayTasks(); break;
        case 4: completeTask(); break;
        case 5:
            saveTasks(); // 종료 시 저장
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 입력입니다.\n");
        }
    }
}
