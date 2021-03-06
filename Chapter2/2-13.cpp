//
// Created by Fan Zhikang on 2019-02-25.
//
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct student {
    char no[20];
    char name[20];
    char sex[10];
    int age;

    bool operator<(const student &a) const {
        return strcmp(no, a.no) < 0;
    }
};

int main() {
    int n;
    student buf[1000];
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%s%s%s%d", buf[i].no, buf[i].name, buf[i].sex, &buf[i].age);
        }
        sort(buf, buf + n);
        int m;
        scanf("%d", &m);
        while (m-- != 0) {
            int ans = -1;
            char x[30];
            scanf("%s", x);
            int top = n - 1, base = 0;
            while (top >= base) {
                int mid = (top + base) / 2;
                int tmp = strcmp(buf[mid].no, x);
                if (tmp == 0) {
                    ans = mid;
                    break;
                } else if (tmp > 0) top = mid - 1;
                else base = mid + 1;
            }
            if (ans == -1) {
                printf("No Answer!\n");
            } else {
                printf("%s %s %s %d\n", buf[ans].no, buf[ans].name, buf[ans].sex, buf[ans].age);
            }
        }
    }
    return 0;
}
