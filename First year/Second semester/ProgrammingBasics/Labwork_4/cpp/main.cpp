#include "classes.h"
#include "functions.h"

int main() {
    Time T1(12);
    T1.ShowInfo();

    Time T2(13,40);
    T2.ShowInfo();

    Time T3(21, 43,14);
    T3.ShowInfo();

    test_getters(T3);

    test_t1_increment(T1);

    test_t2_increment(T2);

    test_time_difference(T1, T2);

    test_time_left(T3);
}