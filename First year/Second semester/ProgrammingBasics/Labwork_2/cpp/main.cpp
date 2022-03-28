#include "functions.h"

int main() {
    // отримуємо від користувача сьогоднішню дату (у форматі dd.mm.yy)
    string todays_date = read_today_date();

    // читаємо текст з консолі, поки не буде натиснуто комбінацію Ctrl+D
    string text_to_write = capture_text();
    // записуємо цей текст у файл input.txt
    write_empty_file("input.txt", text_to_write);

    // читаємо текст з файлу input.txt у змінну text
    string text = read_input_file("input.txt");
    printf("\nText on input:\n%s\n\n", text.c_str());

    // вектор з реченнями тексту
    vector<string> lines = split_lines(text);
    // виводимо елементи вектора в консоль
    print_vector(lines);

    vector<vector<string>> information = split_information(lines);

    check_warranty(information, todays_date);
    read_output_file("output.txt");
}
