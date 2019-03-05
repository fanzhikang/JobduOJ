//
// Created by Fan Zhikang on 2019-03-04.
//

#include <stdio.h>

int main() {
    int m;
    long long a, b;
    while (scanf("%d", &m) != EOF && m != 0) {
        scanf("%lld%lld", &a, &b);
        a = a + b;
        int ans[50], size = 0;
        while (a != 0) {
            ans[size++] = a % m;
            a /= m;
        }
        for (int i = size - 1; i >= 0; i--) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}