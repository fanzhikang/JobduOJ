//
// Created by Fan Zhikang on 2019-02-26.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

struct program {
    int startTime;
    int endTime;

    bool operator<(const program &a) const {
        return endTime < a.endTime;
    }
} buf[100];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &buf[i].startTime, &buf[i].endTime);
        }
        sort(buf, buf + n);
        int currentTime = 0, ans = 0;
        for (int j = 0; j < n; ++j) {
            if (currentTime <= buf[j].startTime) {
                currentTime = buf[j].endTime;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}