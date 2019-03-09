#include <stdio.h>

using namespace std;
#define N 1000
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
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0) break;
        for (int j = 1; j <= n; ++j) {
            Tree[j] = -1;
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            a = findRoot(a);
            a = findRoot(b);
            if (a != b) Tree[a] = b;
        }
        int ans = 0;
        for (int k = 1; k <= n; ++k) {
            if (Tree[k] == -1) ans++;
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}