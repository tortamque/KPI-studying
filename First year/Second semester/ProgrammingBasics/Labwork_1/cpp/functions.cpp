#include "functions.h"

string capture_text(){
    cout << "Enter your text\nPress Enter to go to the next line\nPress Ctrl + D - to end writing\n";

    string text;
    string line;
    // ascii код комбінації клавіш Ctrl + D
    int ascii_code = 94;
    // поки не натиснута комбінація клавіш Ctrl + D
    while(int(line[0]) != ascii_code){
        getline(cin, line);
        text += line + '\n';
        cout << "\nCurrent text:\n" << text << "Enter another line:\n";
    }
    // відкидаємо 4 зайвих символи (2 зайвих \n і ^D)
    text = text.substr(0, text.size()-4);

    return text;
}

void print_vector(const vector<string>& vec){
    cout << "Sentences vector:\n";

    for(auto & i : vec){
        cout << i << "\n";
    }
    cout << "\n";
}

string read_input_file(const string& file_name){
    // потік read_file (тільки для читання)
    ifstream read_file(file_name);
    string text;
    string line;

    // поміщаємо текст з потоку у змінну line
    while (getline(read_file, line)){
        text += line + '\n';
    }
    // закриваємо потік(файл)
    read_file.close();

    // відкидуємо зайвий символ
    text = text.substr(0, text.size()-1);

    return text;
}

vector<string> split_sentences(const string& text){
    // вектор з реченнями
    vector<string> sentences;
    // позиція минулої крапки
    int previous_position = 0;
    // лічильник (рахує символи тексту)
    int counter = 0;

    while(counter <= text.size()){
        // якщо символ дорівнює крапці або (counter дорівнює останньому символу тексту і минулий символ не дорівнює крапці)
        // (counter == text.size() && text[counter-1] != '.') потрібно для того, що б цикл корректно виділив останнє речення, якщо воно записане без крапки
        if(text[counter] == '.' || text[counter] == '\n' || (counter == text.size() && text[counter-1] != '.')){
            // речення (підрядок, який починається з позиції минулої крапки довжиною counter-previous_position)
            string sentence = text.substr(previous_position, counter-previous_position);
            // добавляємо це речення у вектор
            sentences.push_back(sentence);
            // оновлюємо позицію крапки
            previous_position = counter+1;
        }
        counter++;
    }

    return sentences;
}

vector<string> split_words(const vector<string>& sentences, int i){
    // вектор зі словами
    vector<string> words;
    // позиція минулої крапки
    int previous_position = 0;
    // лічильник (рахує символи тексту)
    int counter = 0;

    while(counter <= sentences[i].size()){
        // якщо символ дорівнює розділюнику або останньому символу слова
        if(sentences[i][counter] == ',' || sentences[i][counter] == ' ' || counter == sentences[i].size()){
            // слово (підрядок, який починається з позиції минулого розділювача довжиною counter-previous_position)
            string word = sentences[i].substr(previous_position, counter-previous_position);
            // добавляємо це слово у вектор
            words.push_back(word);
            // оновлюємо позицію
            previous_position = counter+1;
        }
        counter++;
    }


    return words;
}

void print_longest_words(const vector<string>& longest_words){
    for(int i =0; i < longest_words.size(); i++){
        printf("Longest word in sentence #%d is: \"%s\" and its length: %d\n", i+1, longest_words[i].c_str(), longest_words[i].length());
    }
    cout << "\n";
}

vector<string> get_longest_words(const vector<string>& sentences){
    // вектор з найдовшими словами
    vector<string> longest_words;

    for(int i=0; i < sentences.size(); i++){
        // ділимо речення на слова
        vector<string> words = split_words(sentences, i);
        // найдовше слово (перше слово у реченні)
        string longest_word = words[0];

        for(int j=1; j<words.size();j++){
            // якщо довжина слова більша за довжину longest_word
            if(words[j].size() > longest_word.size()){
                // оновлюємо найдовше слово
                longest_word = words[j];
            }
        }
        // добавляємо найдовше слово у вектор
        longest_words.push_back(longest_word);
    }

    return longest_words;
}

void write_file(const string& file_name, const vector<string>& longest_words, vector<string>& sentences){
    // потік write_file (для читання і запису)
    ofstream write_file(file_name);
    // записуємо текст у файл
    for(int i=0; i < sentences.size(); i++){
        write_file << to_string(longest_words[i].size()) + " " + longest_words[i] + " | " + sentences[i] + "\n";
    }
    // закриваємо потік(файл)
    write_file.close();
}

void write_empty_file(const string& file_name, const string& text){
    // потік write_file (для читання і запису)
    ofstream write_file(file_name);
    // записуємо текст у файл
    write_file << text;
    // закриваємо потік(файл)
    write_file.close();
}

void read_output_file(const string& file_name){
    // потік read_output_file (тільки для читання)
    ifstream read_output_file(file_name);
    // виводимо в консоль текст з файлу
    cout << read_output_file.rdbuf() << "\n";
    // закриваємо потік(файл)
    read_output_file.close();
}