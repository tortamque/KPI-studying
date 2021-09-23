#include <iostream>
using namespace std;
int main()
{
    float x; // вхідне дане
    float y; // результат
    cout << "Enter x: "; // виводимо текст в консоль
    cin >> x; // введення x
    /*рахуємо значення y в залежності від значення x
    * якщо x менше 0, то y = -x
    * інакше (якщо x більше або дорівнює 0), то y = x^2*/
    (x < 0) ? y = -x : y = x * x; 
    printf("y is %g", y); // виводимо значення y в консоль
}