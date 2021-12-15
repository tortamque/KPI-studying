#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

/** Генерує матрицю заданого розміру
 *  Нічого не повертає
 *  matrix:  матриця (двовимірний масив)
 *  rows:    к-сть рядків
 *  columns: к-сть стовпців  */
void generate_matrix(float** matrix, int rows, int columns);

/** Генерує масив із суми значень елементів рядків двовимірного масиву
 *  Нічого не повертає
 *  matrix:  матриця (двовимірний масив)
 *  rows:    к-сть рядків
 *  columns: к-сть стовпців
 *  array:   масив  */
void generate_array(float** matrix, int rows, int columns, float array[]);

/** Виводить елементи матриці в консоль
 *  Нічого не повертає
 *  matrix:  матриця (двовимірний масив)
 *  rows:    к-сть рядків
 *  columns: к-сть стовпців  */
void print_matrix(float** matrix, int rows, int columns);

/** Виводить елементи масиву в консоль
 *  Нічого не повертає
 *  array:   масив
 *  rows:    к-сть рядків (к-сть рядків елементів у масиві)  */
void print_array(float* array, int rows);

/** Сортує масив методом вставки за зростанням
 *  Нічого не повертає
 *  array:   масив
 *  size:    к-сть рядків елементів у масиві */
void sort_array(float* array, int size);

int main() {
    srand(time(nullptr));

    //к-сть рядків матриці
    const int rows = 6;
    //к-сть стовпців матриці
    const int columns = 4;

    //створюємо перший двовимірний динамічний масив (матрицю)
    auto **matrix = new float *[rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new float[columns];

    generate_matrix(matrix, rows, columns);
    print_matrix(matrix, rows, columns);

    float array[rows];
    generate_array(matrix, rows, columns, array);
    print_array(array, rows);

    sort_array(array, rows);
    cout << "After sorting:\n";
    print_array(array, rows);
}


void generate_matrix(float** matrix, int rows, int columns){
    //заповнюємо матрицю випадковими дійсними числами із діапазону:

    //мінімальне значенння
    const float min = 1.0;
    //максимальне значенння
    const float max = 10.0;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            //генеруємо випадкові дійсні числа від 1 до 10:
            //RAND_MAX - константа, значення якої = 32767
            //static_cast<float>(rand()) / RAND_MAX - генерує випадкові дійсні числа від 0 до 1
            //(max - min) * static_cast<float>(rand()) / RAND_MAX - генерує випадкові числа від 0 до 9
            //(max - min) * static_cast<float>(rand()) / RAND_MAX + min - генерує випадкові числа від 1 до 10
            matrix[i][j] = (max - min) * (static_cast<float>(rand()) / RAND_MAX) + min;
        }
    }
}


void generate_array(float** matrix, int rows, int columns, float *array){
    for(int i = 0; i < rows; i++){
        float sum = 0;

        for(int j = 0; j < columns; j++){
            sum += matrix[i][j];
        }

        array[i] = sum;
    }
}


void print_matrix(float** matrix, int rows, int columns){
    cout << "Matrix:\n";

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << setprecision(3) << setw(5) << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


void print_array(float* array, int rows){
    cout << "Array:\n";

    for(int i = 0; i < rows; i++)
        cout << array[i] << " ";
    cout << "\n\n";
}

void sort_array(float* array, int size){
    int i, j;
    float tmp;

    //цикл проходу
    for(i = 1; i < size; i++){
        tmp = array[i];

        //шукаємо місце елемента в масиві
        for(j = i-1; j >= 0 && array[j] > tmp; j--)
            //сдвигаємо елемент вправо (тому що алгоритм вставки за зростанням)
            array[j+1] = array[j];

        //вставляємо елемент
        array[j+1] = tmp;
    }
}
