#include "functions.h"
using namespace std;

int main() {
    // читаємо текст з консоли, поки не буде натиснуто комбінацію Ctrl+Enter
    string text_to_write = capture_text();
    // записуємо цей текст у файл input.txt
    write_empty_file("input.txt", text_to_write);

    // читаємо текст з файлу input.txt у змінну text
    string text = read_input_file("input.txt");
    printf("\nText on input:\n%s\n\n", text.c_str());

    // вектор з реченнями тексту
    vector<string> sentences = split_sentences(text);
    // виводимо елементи вектора в консоль
    print_vector(sentences);

    // вектор з найдовшими словами кожного реченя
    vector<string> longest_words = get_longest_words(sentences);
    // виводимо найдовшы слова в консоль
    print_longest_words(longest_words);

    // записуємо текст у файл output.txt
    write_file("output.txt", longest_words, sentences);
    // читаємо записаний текст з файлу output.txt
    read_output_file("output.txt");
}
