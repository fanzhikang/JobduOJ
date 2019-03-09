//
// Created by Fan Zhikang on 2019-03-09.
//

#include <stdio.h>

using namespace std;
#define N 1001
int Tree[N];

int findRoot(int x) {
    if (Tree[x] == -1) return x;
    else {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF && n != 0) {
        scanf("%d", &m);
        for (int i = 1; i < N; ++i) {
            Tree[i] = -1;
        }
        while (m-- != 0) {
            int a, b;
            scanf("%d%d", &a, &b);
            a = findRoot(a);
            b = findRoot(b);
            if (a != b) Tree[a] = b;
        }
        int sum = 0;
        for (int j = 1; j <=n; ++j) {
            if (Tree[j] ==-1) sum++;
        }
        if (sum==1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
