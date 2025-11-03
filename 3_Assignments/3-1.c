#include <stdio.h>

int main() {
    int arr[10];

    int max = 0;
    int max_num = 0;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] > max) {
            max = arr[i];
            max_num = i+1;
        }
    }

    printf("%d\n%d\n", max, max_num);

    return 0;
}