#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int num1 = 0;
    int num2 = 1;
    int num3;

    if (n == 0) {
        printf("%d\n", num1);
        return 0;
    } 
    else if (n == 1) {
        printf("%d\n", num2);
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
    }

    printf("%d", num2);

    return 0;
}