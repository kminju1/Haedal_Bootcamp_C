#include <stdio.h>

#define MAX 1001

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    char S[MAX];
    for (int i = 0; i < T; i++) {
        fgets(S, MAX, stdin); 
        
        int num;
        for (num = 0; S[num] != '\n'; num++) {}

        printf("%c%c\n", S[0], S[num-1]);
    }

    return 0;
}