#include <iostream>
#include <cmath>
using namespace std;


/**
    Приймає значення числа і точності.
    Повертає корінь третьої степені з числа.
*/
double third_root(double number, int precision);


int main() {
    //створюємо змінну "а" і присвоюємо їй значення
    int a;
    cout << "Enter value a: ";
    cin >> a;

    //створюємо змінну "b" і присвоюємо їй значення
    int b;
    cout << "Enter value b: ";
    cin >> b;

    //створюємо змінну "n"(точність) і присвоюємо їй значення
    int n;
    cout << "Enter value n (precision): ";
    cin >> n;

    /*  за умовою задачі потрібно знайти корінь дев'ятої степені з а
        для цього візьмемо корінь третьої степені з а
        потім вьзмемо корінь третьої степені з минулого кореня
        таким чином отримаємо корінь дев'ятої степені   */

    //рахуємо корінь третьої степені з а
    double third_root_a = third_root(a, n);
    //рахуємо корінь третьої степені з минулого кореня
    double ninth_root_a = third_root(third_root_a, n);

    /*  для обчислення кореня шостої степені з b
        візьмемо корінь третьої степені з b
        потім вьзмемо квадратний корінь з минулого кореня
        таким чином отримаємо корінь шостої степені   */

    //рахуємо корінь третьої степені з b
    double third_root_b = third_root(b, n);
    //рахуємо квадратний корінь з минулого кореня
    double sixth_root_b = sqrt(third_root_b);

    //рахуємо корінь третьої степені з суми a і b (a+b)
    double third_root_sum = third_root(a+b, n);

    //рахуємо Y
    double Y = ninth_root_a + sixth_root_b + third_root_sum;

    //виводимо обчислення в консоль
    printf("Ninth root of a = %.3f\nSixth root of b = %.3f\nThird root of sum = %.3f\nY = %.3f", ninth_root_a, sixth_root_b, third_root_sum, Y);
}


double third_root(double number, int precision){
    // повертає корінь третьої степені з числа
    double result = number;

    for(int i = 0; i <= precision; i++)
        result = 1.0/3.0 * ((number/pow(result, 2)) + 2 * result);

    return result;
}

