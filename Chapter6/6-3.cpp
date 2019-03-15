//
// Created by Fan Zhikang on 2019-03-15.
//

#include <stdio.h>
#include <queue>

using namespace std;
struct N {
    int a, b, c;
    int t;
};
queue<N> Q;
bool mark[101][101][101];

void AtoB(int &a, int sa, int &b, int sb) {
    if (sb - b >= a) {
        b += a;
        a = 0;
    } else {
        a -= sb - b;
        b = sb;
    }
}

int BFS(int s, int n, int m) {
    while (Q.empty() == false) {
        N now = Q.front();
        Q.pop();
        int a, b, c;
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(a, s, b, n);
        if (mark[a][b][c] == false) {
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if (a == s / 2 && b == s / 2) return tmp.t;
            if (c == s / 2 && b == s / 2) return tmp.t;
            if (a == s / 2 && c == s / 2) return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(b, n, a, s);
        if (mark[a][b][c] == false) {
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if (a == s / 2 && b == s / 2) return tmp.t;
            if (c == s / 2 && b == s / 2) return tmp.t;
            if (a == s / 2 && c == s / 2) return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(a, s, c, m); //a􏴪􏷞c
        if (mark[a][b][c] == false) {
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if (a == s / 2 && b == s / 2) return tmp.t;
            if (c == s / 2 && b == s / 2) return tmp.t;
            if (a == s / 2 && c == s / 2) return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(c, m, a, s); //c􏴪􏷞a
        if (mark[a][b][c] == false) {
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if (a == s / 2 && b == s / 2) return tmp.t;
            if (c == s / 2 && b == s / 2) return tmp.t;
            if (a == s / 2 && c == s / 2) return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(b, n, c, m); //b􏴪􏷞c
        if (mark[a][b][c] == false) {
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if (a == s / 2 && b == s / 2) return tmp.t;
            if (c == s / 2 && b == s / 2) return tmp.t;
            if (a == s / 2 && c == s / 2) return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(c, m, b, n); //c􏴪􏷞b
        if (mark[a][b][c] == false) {
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if (a == s / 2 && b == s / 2) return tmp.t;
            if (c == s / 2 && b == s / 2) return tmp.t;
            if (a == s / 2 && c == s / 2) return tmp.t;
            Q.push(tmp);
        }
    }
    return -1;
}

int main() {
    int s, n, m;
    while (scanf("%d%d%d", &s, &n, &m) != EOF) {
        if (s == 0) break; //􏲔s􏰊0,则n.m􏰊0则􏱏出
        if (s % 2 == 1) { //􏲔s􏰊􏽄数则􏰉􏴏􏲳􏴞􏲺,􏰮􏻁输出NO
            puts("NO");
            continue;
        }
        for (int i = 0; i <= s; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= m; k++) {
                    mark[i][j][k] = false;
                }
            }
        } //􏱱􏱲􏱳􏻠􏳤
        N tmp;
        tmp.a = s;
        tmp.b = 0;
        tmp.c = 0;
        tmp.t = 0; //􏱱􏱲􏰋􏻠􏳤
        while (Q.empty() == false) Q.pop(); //􏴑空􏺭列􏰔􏻠􏳤 Q.push(tmp); //将􏱱􏱲􏻠􏳤􏷌入􏺭列
        mark[s][0][0] = true; //􏳃􏳄􏱱􏱲􏻠􏳤
        int rec = BFS(s, n, m); //􏺰􏰗􏺱􏳏􏹭􏹮
        if (rec == -1) //􏲔􏰊-1输出NO
            puts("NO");
        else printf("%d\n", rec);//􏲖则输出􏰷􏰸
    }
    return 0;
}