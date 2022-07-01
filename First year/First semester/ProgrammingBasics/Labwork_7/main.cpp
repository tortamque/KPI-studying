#include <iostream>
#include <ctime>
using namespace std;

/** Генерує випадкові елементи для масиву
    @param array:      Масив
    @param array_size: Розмір масиву
 */
void generate_array(int* array, int array_size);

/** Виводить елементи масиву в консоль
    @param array:      Масив
    @param array_size: Розмір масиву
 */
void print_array(const int array[], int array_size);

/** Чи є масив арифметичною прогресією?
    @param array:      Масив
    @param array_size: Розмір масиву
    @return true, якщо масив є арифметичною прогресією або false якщо ні
 */
bool is_progression(const int array[], int array_size);

/** Знаходить найменший елемент масиву
    @param array:      Масив
    @param array_size: Розмір масиву
    @return Найменший елемент масиву
 */
int find_minimal(const int array[], int array_size);

/** Замінює парні елементи масиву на число number
    @param array:      Масив
    @param array_size: Розмір масиву
    @param number:     Число, на яке заміняться парні елементи масиву
 */
void change_even_elements(int* array, int array_size, int number);

int main() {
    srand(time(nullptr));

    cout << "Enter the size of the sequence: ";
    int size = 0;
    cin >> size;

    // створюємо масив із заданим розміром
    int sequence[size];
    // генеруємо масив випадковим чином
    generate_array(sequence, size);
    cout << "Generated array is: ";
    // виводимо елементи масиву в консоль
    print_array(sequence, size);

    // перевіряємо, чи є масив арифметичною прогресією
    bool is_local_progression = is_progression(sequence, size);
    cout << "Is progression? ";
    // виводимо значення того, чи є масив арифметичною прогресією
    // boolalpha замінює значення 1/0 на true/false
    cout << boolalpha << is_local_progression << endl;

    // якщо масив є арифметичною прогресією
    if(is_local_progression){
        // рахуємо крок прогресії
        // другий елемент масиву - перший елемент
        int step = sequence[1] - sequence[0];

        cout << "The step of the progression is: " << step << endl;
    }else{
        // знаходимо найменший елемент масиву
        int min = find_minimal(sequence, size);
        cout << "Minimal value of the sequence is: " << min << endl;

        // замінюємо парні елементи масиву на найменше число
        change_even_elements(sequence, size, min);
        cout << "Sequence after change:";
        // виводимо елементи масиву в консоль
        print_array(sequence, size);
    }
}


void generate_array(int* array, int array_size){
    for(int i = 0; i < array_size; i++)
        // ініціалізуємо елемент i випадковим числом від 1 до 10
        array[i] = rand() % 10 + 1;
}

void print_array(const int array[], int array_size){
    cout << "[";

    // ітеруємось через кожен елемент масиву і виводимо їх в консоль
    for(int i = 0; i < array_size; i++)
        cout << array[i] << " ";

    cout << "]" << endl;
}

bool is_progression(const int array[], int array_size){
    // рахуємо крок між другим і першим елементами масиву
    int step = array[1] - array[0];

    for(int i = 2; i < array_size; i++){
        int current_element = array[i];
        int last_element = array[i-1];

        // якщо різниця між двома елементами не дорівнює кроку, то повертаємо результат false
        if(current_element - last_element != step)
            return false;
    }

    // якщо різниця між усіма елементами масиву однакова, то повертаємо true
    return true;
}

int find_minimal(const int array[], int array_size){
    // беремо за мінімальний елемент масиву перший елемент
    int min = array[0];

    for(int i = 1; i < array_size; i++)
        // якщо число менше за min, то min = array[i]
        if(array[i] < min)
            min = array[i];

    return min;
}

void change_even_elements(int* array, int array_size, int number){
    for(int i = 0; i < array_size; i++)
        // якщо число парне (ділиться на 2 без остачі), то замінюєм його
        if(array[i] % 2 == 0)
            array[i] = number;
}
