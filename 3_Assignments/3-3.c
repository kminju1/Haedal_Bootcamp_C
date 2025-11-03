#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    char S[21];
    char P[161];

    for (int i = 0; i < T; i++) {
        int R;
        scanf("%d %s", &R, S); 
        
        for (int j = 0; S[j] != '\0'; j++) {
            for (int k = 0; k < R; k++) {
                printf("%c", S[j]);
            }
        }

        printf("\n");

    }
    
    return 0;
}