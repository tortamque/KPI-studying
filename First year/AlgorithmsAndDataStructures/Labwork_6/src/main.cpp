#include <iostream>
using namespace std;

/**
    Приймає значення числа, кількості елементів арифметичної прогресії, кроку.
    Повертає суму членів арифметичної прогресії.
*/
int recursion(int num, int count, int step);


int main() {
    const int first_element = 10;
    const int number_of_elements = 10;
    const int step = 2;
    // рахуємо суму членів арифметичної прогресії
    /*  Початкове число:     10
        Кількість елементів: 10
        Крок:                 2    */
    int sum = recursion(first_element,number_of_elements,step);
    printf("The sum of the arithmetic progression is %d", sum);
}


int recursion(int num, int count, int step){
    //якщо кількість елементів більше 0
    if (count > 0)
        /*  Рахуємо значення прогресії:
            число + рекурсивна функція з аргументами:
                число + крок
                кількість елементів - 1
                крок                                    */
        return num + recursion(num + step, count - 1, step);
    return 0;
}

