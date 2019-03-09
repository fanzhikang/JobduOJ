//
// Created by Fan Zhikang on 2019-03-09.
//
#include <stdio.h>

using namespace std;

#define N 10000001
int Tree[N];

int findRoot(int x) {
    if (Tree[x] == -1) return x;
    else {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int sum[N];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i < N; ++i) {
            Tree[i] = -1;
            sum[i] = 1;
        }
        while (n-- != 0) {
            int a, b;
            scanf("%d%d", &a, &b);
            a = findRoot(a);
            b = findRoot(b);
            if (a != b) {
                Tree[a] = b;
                sum[b] += sum[a];
            }
        }
        int ans = 1;
        for (int j = 1; j < N; ++j) {
            if (Tree[j] == -1 && sum[j] > ans) ans = sum[j];
        }
        printf("%d\n", ans);
    }
    return 0;
}
