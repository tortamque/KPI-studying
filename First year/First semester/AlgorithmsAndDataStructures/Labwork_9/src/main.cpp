#include <iostream>
#include <ctime>
using namespace std;

void generate_matrix(float** matrix, int size);
void print_matrix(float** matrix, int size);
float find_element(float** matrix, int size, int &x_pos, int &y_pos);
float calculate_average(float** matrix, int size);
void compare(float X, float average);

int main() {
    srand(time(nullptr));

    int size = 0;
    cout << "Enter matrix size:";
    cin >> size;

    // створюємо матрицю
    auto **matrix = new float *[size];
    for(int i = 0; i < size; i++)
        matrix[i] = new float[size];

    // генеруємо матрицю випадковими дійсними числами
    generate_matrix(matrix, size);
    // виводимо в консоль елементи матриці
    print_matrix(matrix, size);

    // позиція елемента по х
    int x_pos = 0;
    // позиція елемента по у
    int y_pos = 0;
    // перший додатний елемент матриці (обхід робимо "змійкою" по рядках)
    float X = find_element(matrix, size, x_pos, y_pos);
    printf("First positive element: %.2f. His position x: %d, y: %d\n", X, x_pos, y_pos);

    // середньоарифметичне значення елементів під побічною діагоналлю
    float average = calculate_average(matrix, size);
    printf("Average: %.2f\n", average);

    // порівнюємо X та average
    compare(X, average);
}


void generate_matrix(float** matrix, int size){
    //мінімальне значенння
    float min = -5.0;
    //максимальне значенння
    float max =  5.0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            //генеруємо випадкові дійсні числа від -5 до 5:
            //RAND_MAX - константа, значення якої = 32767
            //static_cast<float>(rand()) / RAND_MAX - генерує випадкові дійсні числа від 0 до 1
            //(max - min) * static_cast<float>(rand()) / RAND_MAX - генерує випадкові числа від 0 до 10
            //(max - min) * static_cast<float>(rand()) / RAND_MAX + min - генерує випадкові числа від -5 до 5
            matrix[i][j] = (max - min) * (static_cast<float>(rand()) / RAND_MAX) + min;
        }
    }
}

void print_matrix(float** matrix, int size){
    // виводимо в консоль елементи матриці з точністю до двох цифр після коми включно
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            printf(" %5.2f ", matrix[i][j]);

        cout << "\n";
    }
    cout << "\n";
}

float find_element(float** matrix, int size, int &x_pos, int &y_pos){
    float value = 0;

    // прохід по рядках
    for(int i = 0; i < size && value <= 0; i++){
        // якщо номер рядку непарний (1,3,5,...) (але індекс парний)
        if(i % 2 == 0){
            // то проходимо його зліва на право
            for(int j = 0; j < size; j++)
                // якщо цей елемент більше за 0, то value = цьому елементу
                // також змінюємо значення позіції цього елемента по х і у
                if(matrix[i][j] > 0){
                    value = matrix[i][j];
                    x_pos = ++i;
                    y_pos = ++j;
                }
        }
        // якщо номер рядку парний (2,4,6,...) (але індекс непарний)
        else{
            // то проходимо справа на ліво
            for(int j = size - 1; j >= 0; j--)
                // якщо цей елемент більше за 0, то value = цьому елементу
                // також змінюємо значення позіції цього елемента по х і у
                if(matrix[i][j] > 0){
                    value = matrix[i][j];
                    x_pos = ++i;
                    y_pos = ++j;
                }
        }
    }

    return value;
}

float calculate_average(float** matrix, int size){
    float sum = 0;
    float num_count = 0;
    cout << "Elements under the side diagonal:";

    for(int i = 1; i < size; i++){
        for(int j = size-i; j < size; j++){
            printf(" %.2f", matrix[i][j]);
            sum += matrix[i][j];
            num_count++;
        }
    }
    cout << "\n";

    float average = sum/num_count;
    return average;
}

void compare(float X, float average){
    if(X > average)
        printf("X(%.2f) is greater than average(%.2f)", X, average);
    else
        printf("X(%.2f) is less than average(%.2f)", X, average);
}
