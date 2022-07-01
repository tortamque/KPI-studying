#include <iostream>
using namespace std;

/** Рахує кількість слів у рядку
 *  @param input: Рядок
 *  @return:      Кількість слів
 */
int count_words(const string& input);

/** Ділить рядок на окремі слова
 *  @param input: Рядок
 *  @param array: Масив, куди будуть записані слова
 */
void cut_string(const string& input, string *array);

/** Сортує слова в масиві за зростанням їх довжини методом сортування вставками
 *  @param array: Масив
 *  @param size:  Розмір масиву
 */
void sort_string(string *array, int size);

/** Виводить елементи масиву в консоль
 *  @param array: Масив
 *  @param size:  Розмір масиву
 */
void print_array(string array[], int size);

int main() {
    string input;
    cout << "Enter a string:";
    getline(cin , input);

    // кількість слів у масиві
    int words_count = count_words(input);
    string words[words_count];

    cut_string(input, words);
    sort_string(words, words_count);

    print_array(words, words_count);
}

int count_words(const string& input){
    // кількість слів у рядку
    // (від початку дорівнює 1, тому що слів у рядку на 1 більше ніж пробілів)
    int words = 1;
    //позиція пробілу у рядку
    size_t space_position = input.find(' ', 0);

    // поки в рядку є пробіли, рахуємо їх
    while(space_position != string::npos){
        words++;
        space_position = input.find(' ',space_position+1);
    }

    return words;
}

void cut_string(const string& input, string *array){
    // позиція поточного пробілу у рядку
    size_t space_position = 0;
    // позиція минулого пробілу у рядку
    size_t previous_space_position;
    // підрядок
    string sub_string;

    // знаходимо і виділяємо перше слово у рядку
    // (ми це робимо поза межами циклу, бо в циклі не буде враховуватись перший символ цього слова)
    previous_space_position = space_position;
    space_position = input.find(' ',space_position);
    sub_string = input.substr(previous_space_position, space_position-previous_space_position);
    array[0] = sub_string;

    // знаходимо і виділяємо інші слова у рядку
    for(int i = 1; space_position != string::npos; i++){
        // позиція минулого пробілу у рядку = позиції поточного пробілу у рядку
        previous_space_position = space_position;
        // знаходимо позицію поточного пробілу у рядку
        space_position = input.find(' ',space_position + 1);
        // формуємо підрядок:
        // початкова позиція підрядка  = позиція минулого пробілу у рядку + 1
        // кількість символів підрядку = позиція поточного пробілу у рядку -  позиція минулого пробілу у рядку - 1
        // (в цих випадках додаємо/віднімаємо одиницю, щоб у словах не враховувася пробіл)
        sub_string = input.substr(previous_space_position + 1, space_position - previous_space_position - 1);
        // додаємо підрядок(слово) у масив
        array[i] = sub_string;
    }
}

void sort_string(string *array, int size){
    int i, j;
    string tmp;

    // цикл проходу
    for(i=1; i < size; i++){
        tmp = array[i];

        // пошук елемента в масиві
        for(j = i-1; j >= 0 && array[j].size() > tmp.size(); j--)
            // рухаємо елемент вправо, поки він не досягне своєї позиції
            array[j+1] = array[j];

        // місце елемента знайдено, вствляємо його на позицію j+1
        array[j+1] = tmp;
    }
}

void print_array(string array[], int size){
    cout << "Sorted string:\n";

    for(int i = 0; i < size; i++)
        printf("%d) %s\n", i+1, array[i].c_str());
}
