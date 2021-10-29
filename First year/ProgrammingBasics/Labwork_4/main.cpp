#include <iostream>
#include <cmath>
using namespace std;

double f_quadratic(double x) {
    //повертає значення квадратної функції
    return -2 * pow(x, 2) + 3 * x + 6;
}

double f_linear(double x) {
    //повертає значення лінійної функції
    return x + 2;
}

int main() {
    const signed short a = -1;      // початкова точка інтегрування
    const unsigned short b = 2;     // кінцева точка інтегрування
    const unsigned short n = 10000; //розбиття функції на параболи (точність)
    double h = static_cast<double>(b - a) / n; //крок розбиття

    //додаємо до суми значення функції на початку і кінці інтегрування
    double area_quadratic = f_quadratic(a) + f_quadratic(b);
    //додаємо до суми значення функції на початку і кінці інтегрування
    double area_linear = f_linear(a) + f_linear(b);

    //ітеруємось через функцію, розбиту на параболи
    for (int i = a; i < n - 1; i++) {
        /*перевіряємо, чи число i парне
        якщо так, множимо значення функції на разбитій параболі на 2
        якщо ні, то множимо значення функції на разбитій параболі на 4 */
        i % 2 == 0 ? area_quadratic += 2 * f_quadratic(a + i * h) : area_quadratic += 4 * f_quadratic(a + i * h);
        i % 2 == 0 ? area_linear += 2 * f_linear(a + i * h) : area_linear += 4 * f_linear(a + i * h);
    }
    area_quadratic *= h / 3; //множимо весь вираз на 1/3
    area_linear *= h / 3; //множимо весь вираз на 1/3

    //площа інтегрованої функції (площа квадратичної функції - площа лінійної функції)
    double final_area = area_quadratic - area_linear;
    cout << "Area quadratic = " << area_quadratic << "\nArea linear = "  << area_linear <<"\nIntegral = "  <<final_area << endl;
}