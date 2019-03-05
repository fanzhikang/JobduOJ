#include <stdio.h>
#include <string.h>

#define ISLEAP(x) x%100!=0 && x%4==0 || x%400==0 ? 1:0
int dayOfMonth[13][2] = {
        0, 0,
        31, 31,
        28, 29,
        31, 31,
        30, 30,
        31, 31,
        30, 30,
        31, 31,
        31, 31,
        30, 30,
        31, 31,
        30, 30,
        31, 31
};

struct Date {
    int Day;
    int Month;
    int Year;

    void nextDay() {
        Day++;
        if (Day > dayOfMonth[Month][ISLEAP(Year)]) {
            Day = 1;
            Month++;
            if (Month > 12) {
                Month = 1;
                Year++;
            }
        }
    }
};

int buf[5001][13][32];

char monthName[13][20] = {
        "",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
};
char weekName[7][20] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
};

int Abs(int x) {
    return x < 0 ? -x : x;
}

int main() {
    Date tmp;
    tmp.Year = 0;
    tmp.Month = 1;
    tmp.Day = 1;
    int cnt = 0;
    while (tmp.Year != 3001) {
        buf[tmp.Year][tmp.Month][tmp.Day] = cnt;
        tmp.nextDay();
        cnt++;
    }
    int d, m, y;
    char s[20];
    while (scanf("%d%s%d", &d, s, &y) != EOF) {
        for (m = 1; m <= 12; ++m) {
            if (strcmp(s, monthName[m]) == 0) {
                break;
            }
        }
        int days = buf[y][m][d] - buf[2019][2][22];
        days += 5;
        puts(weekName[(days % 7 + 7) % 7]);
    }
    return 0;
}