//
// Created by Fan Zhikang on 2019-03-06.
//

#include <stdio.h>

int mark[100001];
int prime[100001];
int primeSize;

void init() {
    primeSize = 0;
    for (int i = 2; i <= 100000; ++i) {
        if (mark[i] == true) continue;
        prime[primeSize++] = i;
        if (i >= 1000) continue;
        for (int j = i * i; j <= 100000; j += i) {
            mark[j] = true;
        }
    }
}

int main() {
    init();
    int n;
    while (scanf("%d", &n) != EOF) {
        int ansNum[30];
        int ansSize = 0;
        int ansPrime[30];
        for (int i = 0; i < primeSize; ++i) {
            if (n % prime[i] == 0) {
                ansPrime[ansSize] = prime[i];
                ansNum[ansSize] = 0;
                while (n % prime[i] == 0) {
                    ansNum[ansSize]++;
                    n /= prime[i];
                }
                ansSize++;
                if (n == 1) break;
            }
        }
        if (n != 1) {
            ansPrime[ansSize] = n;
            ansNum[ansSize++] = 1;
        }
        int ans = 0;
        for (int j = 0; j < ansSize; ++j) {
            ans += ansNum[j];
        }
        printf("%d", ans);
    }
    return 0;
}
