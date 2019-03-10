//
// Created by Fan Zhikang on 2019-03-10.
//

#include <stdio.h>
#include <algorithm>

using namespace std;
#define N 100
int Tree[N];

int findRoot(int x) {
    if (Tree[x] == -1) return x;
    else {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

struct Edge {
    int a, b;
    int cost;

    bool operator<(const Edge &A) const {
        return cost < A.cost;
    }
} edge[6000];

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        for (int i = 1; i <= n * (n - 1) / 2; ++i) {
            scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost);
        }
        sort(edge + 1, edge + 1 + n * (n - 1) / 2);
        for (int j = 1; j <= n; ++j) {
            Tree[j] = -1;
        }
        int ans = 0;
        for (int k = 1; k <= n * (n - 1) / 2; ++k) {
            int a = findRoot(edge[k].a);
            int b = findRoot(edge[k].b);
            if (a != b) {
                Tree[a] = b;
                ans += edge[k].cost;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}