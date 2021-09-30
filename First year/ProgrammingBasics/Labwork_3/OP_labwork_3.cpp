#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n; // створюємо змінну n
    cout << "Enter n: "; // виводим текст в консоль
    cin >> n; // присвоюєм значення змінній

    double x; // створюємо змінну x
    cout << "Enter x (0 < x < 1): "; // виводим текст в консоль
    cin >> x; // присвоюєм значення змінній

    int counter = 1; // створюємо лічильник
    double result = 1; // створюєму змінну для результату (1, тому що так задано в умові)

    // цикл буде працювати до поки лічильник меньше або дорівнює n
    while (counter <= n) {
        // добавляємо значення до результату
        result += pow(-1, counter) * ((pow(x, 2 * counter) + 1) / (pow(2, counter) + 1));
        counter++; // збільшуєм лічильник
    }

    // виводимо результат в консоль з точністю до 5-ї цифри після коми
    printf("The result is %.5g", result);
}
