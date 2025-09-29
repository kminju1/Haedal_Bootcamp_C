#include <stdio.h>

int main() {
    int y;

    if (scanf("%d", &y) != 1) return 0;

    int is_leap = ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
    printf("%d\n", is_leap ? 1 : 0);

    return 0;
}