//
// Created by Fan Zhikang on 2019-03-05.
//

#include <stdio.h>

int gcd(int a, int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("%d\n", a * b / gcd(a, b));
    }
    return 0;
}