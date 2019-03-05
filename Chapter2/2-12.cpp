#include <stdio.h>

int main() {
    int n;
    int buf[200];
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", buf + i);
        }
        int x, ans = -1;
        scanf("%d", &x);
        for (int j = 0; j < n; ++j) {
            if (buf[j] == x) {
                ans = j;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
