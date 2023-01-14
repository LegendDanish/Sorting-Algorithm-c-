#pragma once
#include<ctime>
#include<iostream>
#pragma warning(disable : 4996)
using namespace std;

class SystemTime
{
public:

    int hour1, hour2, minute1, minute2, sec1, sec2;

    void BeforeOperation()
    {
        time_t t = time(0);
        tm* t1 = localtime(&t);
        hour1 = t1->tm_hour;
        minute1 = t1->tm_min;
        sec1 = t1->tm_sec;
    }
    void AfterOperation()
    {
        time_t t = time(0);
        tm* t1 = localtime(&t);
        hour2 = t1->tm_hour;
        minute2 = t1->tm_min;
        sec2 = t1->tm_sec;
    }

    void TimeDifference()
    {
        int sum1, sum2, result;

        sum1 = (hour1 * 3600) + (minute1 * 60) + sec1;
        sum2 = (hour2 * 3600) + (minute2 * 60) + sec2;
        result = sum2 - sum1;
        cout << "Time Before Sort = " << hour1 << ":" << minute1 << ":" << sec1 << endl;
        cout << "Time After Sort = " << hour2 << ":" << minute2 << ":" << sec2 << endl;
        cout << "Time Difference is = " << result * 1000 << " ms" << endl;
    }
};


