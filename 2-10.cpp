#include <stdio.h>

int main() {
    int h;
    while (scanf("%d", &h) != EOF) {
        int maxlength = h + (h - 1) * 2;
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= maxlength; ++j) {
                if (j <= maxlength - h - (i - 1) * 2) {
                    printf(" ");
                } else {
                    printf("*");
                }
            }
            printf("\n");
        }
    }
    return 0;
}