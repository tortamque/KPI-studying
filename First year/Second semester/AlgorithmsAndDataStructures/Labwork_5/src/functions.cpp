#include "functions.h"
#include <vector>

string capture_text(){
    string text;

    cout << "Enter text separated by space: ";
    getline(cin, text);

    return text;
}

char capture_char(){
    char character;

    cout << "\n\nEnter the character with which words will be deleted: ";
    cin >> character;

    return character;
}

vector<string> split_words(const string& text){
    // вектор зі словами
    vector<string> lines;
    // позиція минулого пробілу
    int previous_position = 0;
    // лічильник (рахує символи тексту)
    int counter = 0;

    while(counter <= text.size()){
        // якщо символ дорівнює пробілу або counter дорівнює останньому символу тексту
        if(text[counter] == ' ' || counter == text.size()){
            // рядок (підрядок, який починається з позиції минулого пробілу довжиною counter-previous_position)
            string line = text.substr(previous_position, counter-previous_position);
            // добавляємо це слово у вектор
            lines.push_back(line);
            // оновлюємо позицію пробілу
            previous_position = counter+1;
        }
        counter++;
    }

    return lines;
}

void fill_list(SinglyLinkedList &list, const string& text){
    vector<string> words = split_words(text);

    for (const auto& word : words) {
        list.add_node(word);
    }
}

void delete_words(char character, SinglyLinkedList &list){
    int list_size = list.get_list_size();

    for (int i = 1; i <= list_size; ++i) {
        // вузол
        Node *node = list.get_node(i);
        // слово із вузла
        string word = node->get_data();

        // якщо довжина слова більша за 1 символ
        if(word.size() > 1){
            int first_char_position = 0;
            int last_char_position = word.size() - 1;

            // якщо слово починається і закінчується заданою літерою
            if(word[first_char_position] == character && word[last_char_position] == character){
                // видаляємо літеру
                list.delete_note(i);
                // зменшуємо розмір списку на 1
                list_size--;
                // зменшуємо лічильник на 1
                i--;
            }
        }
    }
}