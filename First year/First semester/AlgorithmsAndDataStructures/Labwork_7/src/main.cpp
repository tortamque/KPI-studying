#include <iostream>
using namespace std;

/** Выводить в консоль елементи масиву.
 *  Нічого не повертає
 *  array:      масив
 *  array_size: довжина масиву */
void print_array(char array[], int array_size);

/** Ініціалізує перший масив згідно з формулою .
 *  Нічого не повертає
 *  array: масив */
void init_first_array(char (&array)[10]);

/** Ініціалізує другий масив згідно з формулою.
 *  Нічого не повертає
 *  array: масив */
void init_second_array(char (&array)[10]);

/** Ініціалізує третій масив згідно з формулою.
 *  Нічого не повертає
 *  array: масив */
void init_result_array(char (&array)[10]);

/** Знаходить спільні елементи в двох масивах
 *  Нічого не повертає
 *  array1:       перший масив
 *  array2:       другий масив
 *  result_array: результуючий масив (всі дані зберігаються в ньому, так как ми передаємо його через посилання) */
void find_similar(const char array1[], const char array2[], char (&result_array)[10]);

/** Знаходить значення, яке є мінімальним та, більшим за задане P
 *  Повертає значення, яке є мінімальним та, більшим за задане P
 *  array: масив
 *  p:     задане число */
char find_minimal(const char array[], int p);


int main() {
    // створюємо перший масив
    char array1[10];
    // заповнюємо його символами, згідно з формулою
    init_first_array(array1);

    printf("First array:  ");
    print_array(array1, 10);

    // створюємо другий масив
    char array2[10];
    // заповнюємо його символами, згідно з формулою
    init_second_array(array2);

    printf("Second array: ");
    print_array(array2, 10);

    // створюємо результуючий масив
    char result_array[10];
    // заповнюємо його символами з кодом 0
    init_result_array(result_array);

    // знаходимо спільні елементи перших двох масивів і записуємо їх у третій
    find_similar(array1, array2, result_array);

    printf("Result array: ");
    print_array(result_array, 10);

    int P;
    printf("Enter P: ");
    cin >> P;

    char minimal_value = find_minimal(result_array, P);
    printf("Result: %c", minimal_value);
}


void print_array(char array[], int array_size){
    cout << "[";

    // ітеруємось через кожен елемент масиву і виводимо їх в консоль
    for(int i = 0; i < array_size; i++)
        cout << array[i] << " ";

    cout << "]" << endl;
}


void init_first_array(char (&array)[10]){
    for(int i = 0; i < 10; i++)
        array[i] = static_cast<char>(55 - 2 * i);
}


void init_second_array(char (&array)[10]){
    for(int i = 0; i < 10; i++)
        array[i] = static_cast<char>(40 + 3 * i);
}


void init_result_array(char (&array)[10]){
    for(int i = 0; i < 10; i++)
        array[i] = 0;
}


void find_similar(const char array1[], const char array2[], char (&result_array)[10]){
    // ітеруємось через елементи першого масиву
    for(int i = 0; i < 10; i++)
        // ітеруємось через елементи другого масиву
        for(int j = 0; j < 10; j++)
            // якщо елемент i першого масиву співпав х елементом j другого масиву
            if(array1[i] == array2[j])
                // записуємо цей елемент в результуючий масив
                result_array[i] = array2[j];
}


char find_minimal(const char array[], int p){
    // ітеруємось через елементи  масиву
    for(int i=9; i >= 0; i--)
        // якщо символ більший за задане P
        if(array[i] > p)
            // повертаєм цей символ
            return array[i];
    return 0;
}
