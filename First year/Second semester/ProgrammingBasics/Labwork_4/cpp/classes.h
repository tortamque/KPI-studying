#ifndef INC_2LABWORK_4_CLASSES_H
#define INC_2LABWORK_4_CLASSES_H

#endif //INC_2LABWORK_4_CLASSES_H
#pragma once

class Time{
private:
    int hours;
    int minutes;
    int seconds;
public:
    Time();
    Time(int hours);
    Time(int hours, int minutes);
    Time(int hours, int minutes, int seconds);

    int GetHours();
    int GetMinutes();
    int GetSeconds();
    void TimeLeft();
    void ShowInfo();

    void operator+=(int minutes_to_add);
    Time operator-(Time right_value);
};
