//
// Created by Fan Zhikang on 2019-03-10.
//

#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;
#define N 101
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
    double cost;

    bool operator<(const Edge &A) const {
        return cost < A.cost;
    }
} edge[6000];

struct Point {
    double x, y;

    double getDistance(Point A) {
        double tmp = (x - A.x) * (x - A.x) + (y - A.y) * (y - A.y);
        return sqrt(tmp);
    }
}list[101];
int main(){
    int n;
    while (scanf("%d",&n)!=EOF){
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf",&list[i].x,&list[i].y);
        }
        int size = 0;
        for (int j = 1; j <= n; ++j) {
            for (int i = j+1; i <=n ; ++i) {
                edge[size].a = j;
                edge[size].b = i;
                edge[size].cost = list[j].getDistance(list[i]);
                size++;
            }
        }
        sort(edge,edge+size);
        for (int k = 1; k <= n; ++k) {
            Tree[k]=-1;
        }
        double ans = 0;
        for (int l = 0; l < size; ++l) {
            int a = findRoot(edge[l].a);
            int b = findRoot(edge[l].b);
            if(a!=b){
                Tree[a] = b;
                ans += edge[l].cost;
            }
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
