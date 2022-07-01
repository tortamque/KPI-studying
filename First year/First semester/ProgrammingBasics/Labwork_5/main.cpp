#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Enter a number(n): ";

    //вводимо n
    long long n;
    cin >> n;
    cout << endl;

    //ітеруємось через числа від 1 до n включно
    for(int i = 1; i <= n; i++){
        //кількість цифр у числі
        int numLength = 0;
        //коефіцієнт
        int k = i;

        //рахуємо кількість цифр у числі
        while(k >= 1) {
            //ділимо коефіцієнт на 10
            k /= 10;
            //додаємо до кількості цифр одиницю
            numLength++;
        }

        //квадрат числа i
        double square = pow(i, 2);
        //дільник
        double divisor = pow(10, numLength);
        /* ділимо квадрат числа i на дільник
           наприклад, якщо квадрат i - двозначне число, то отримуємо остачу від вілення від 10
           якщо квадрат i - тризначне число, то отримуємо остачу від вілення від 100 і т.д. */
        unsigned int condition = static_cast<int>(fmod(square, divisor));

        //якщо остача від ділення дорівнює початковому числу i, то виводимо результат в консоль
        if(condition == i)
            printf("%d = %.0f\n", i, square);
    }
}
