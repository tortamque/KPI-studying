#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

/** Генерує випадкові елементи для матриці
 *  @param matrix: Матриця (двовимірний масив)
 *  @param size:   Розмір матриці
 */
void generate_matrix(int** matrix, int size);

/** Виводить елементи матриці в консоль
 *  @param matrix: Матриця (двовимірний масив)
 *  @param size:   Розмір матриці
 */
void print_matrix(int** matrix, int size);

/** Знаходить максимальне значення у рядку матриці
 *  @param matrix:     Матриця (двовимірний масив)
 *  @param size:       Розмір матриці
 *  @param row_number: Індекс рядку, у якому потрібно знайти максимальне значення
 *  @return:           Максимальне значення у рядку
 */
int find_max_value(int** matrix, int size, int row_number);

/** Скалярно множить рядок матриці на стовпець з найбільшим елементом рядку
 *  @param matrix: Матриця (двовимірний масив)
 *  @param vector: Масив, куди будуть записані результати
 *  @param size:   Розмір матриці
 */
void scalar_multiply(int** matrix, int *vector, int size);

/** Виводить елементи масиву в консоль
 *  @param array: Масив
 *  @param size:  Розмір масиву
 */
void print_array(int array[], int size);

int main(){
    srand(time(nullptr));

    int size = 0;
    cout << "Enter the size your array (n):";
    cin >> size;

    //створюємо двовимірний динамічний масив (матрицю)
    auto **matrix = new int *[size];
    for(int i = 0; i < size; i++)
        matrix[i] = new int[size];

    //заповнюємо матрицю випадковими числами
    generate_matrix(matrix, size);
    //виводимо елементи матриці в консоль
    print_matrix(matrix, size);

    //створюємо масив (за умовою вектор)
    int X[size];
    //скалярно множимо i-тий рядок матриці matrix на стовпець, що містить найбільший елемент у цьому рядку
    scalar_multiply(matrix, X, size);
    //виводимо елементи масиву в консоль
    print_array(X, size);


    //очищуємо пам'ять після використання двовимірного масиву
    for (int i = 0; i < size; i++)
        delete [] matrix[i];
    delete [] matrix;
}

void generate_matrix(int** matrix, int size){
    //заповнюємо матрицю випадковими числами із діапазону:
    //мінімальне значенння
    const int min = 1.0;
    //максимальне значенння
    const int max = 10.0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            //генеруємо випадкові числа від min до max:
            matrix[i][j] = rand() % max + min;
        }
    }
}


void print_matrix(int** matrix, int size){
    cout << "Matrix:\n";

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << setw(2) << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


int find_max_value(int** matrix, int size, int row_number){
    //максимальне значення у рядку матриці (перше)
    int max = matrix[row_number][0];
    //індекс максимального значення у рядку
    int index = 0;

    //ітеруємось через елементи матриці
    for(int j = 0; j < size; j++){
        //якщо якесь значення рядку матриці більше за max,
        //то max дорівнює цьому значенню і index дорівнює індексу в масиві цього значення
        if(matrix[row_number][j] > max){
            max = matrix[row_number][j];
            index = j;
        }
    }
    printf("Max value of %d row of matrix is: %d\n", row_number+1, max);

    return index;
}


void scalar_multiply(int** matrix, int *vector, int size){
    //ітеруємось через рядки матриці
    for(int i = 0; i < size; i++){
        //індекс максимального значення в рядку
        int max_index = find_max_value(matrix, size, i);
        //скалярний добуток
        int multiplied_value = 0;

        //скалярно множимо i-тий рядок матриці matrix на стовпець, що містить найбільший елемент у цьому рядку
        /*наприклад, якщо маємо матрицю:
            7  2  5
            5  4  7
            3 10  8
            То найбільший елемент 1 рядку: 7 і його індекс: 0
            найбільший елемент 2 рядку: 7 і його індекс: 2
            найбільший елемент 3 рядку: 10 і його індекс: 1,

            Тоді перший рядок (7 2 5) скалярно множимо на стовпець (7 5 3)
            другий рядок (5 4 7) скалярно множимо на стовпець (5 7 8)
            третій рядок (3 10 8) скалярно множимо на стовпець (2 4 10) */
        for(int j = 0; j < size; j++)
            multiplied_value += matrix[i][j] * matrix[j][max_index];

        //додаємо значення скалярного добутку в масив
        vector[i] = multiplied_value;
    }
    cout << "\n";
}


void print_array(int array[], int size){
    cout << "Final vector:\n";

    for(int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << "\n";
}
