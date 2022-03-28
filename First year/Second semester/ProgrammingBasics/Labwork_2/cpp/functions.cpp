#include "functions.h"

string capture_text(){
    cout << "Enter your product info by the following format: Name,DD.MM.YY,Days\nPress Enter to go to the next line\nPress Ctrl + D - to end writing\n";

    string text;
    string line;
    // ascii код комбінації клавіш Ctrl + D
    int ascii_code = 94;
    // поки не натиснута комбінація клавіш Ctrl + D
    while(int(line[0]) != ascii_code){
        getline(cin, line);
        text += line + '\n';
    }
    // відкидаємо 4 зайвих символи (2 зайвих \n і ^D)
    text = text.substr(0, text.size()-4);

    return text;
}

void write_empty_file(const string& file_name, const string& text){
    // бінарний потік write_file (для читання і запису)
    ofstream write_file(file_name, ios::binary);
    // записуємо текст у файл
    write_file << text;
    // закриваємо потік(файл)
    write_file.close();
}

string read_input_file(const string& file_name){
    // бінарний потік read_file (тільки для читання)
    ifstream read_file(file_name, ios::binary);
    string text;

    while (!read_file.eof()){
        text += read_file.get();
    }
    // закриваємо потік(файл)
    read_file.close();

    // відкидуємо зайвий символ
    text = text.substr(0, text.size()-1);

    return text;
}

void print_vector(const vector<string>& vec){
    cout << "Lines vector:\n";

    for(auto & i : vec){
        cout << i << "\n";
    }
    cout << "\n";
}

vector<string> split_lines(const string& text){
    // вектор з рядками
    vector<string> lines;
    // позиція минулого символу нового рядку
    int previous_position = 0;
    // лічильник (рахує символи тексту)
    int counter = 0;

    while(counter <= text.size()){
        // якщо символ дорівнює символу нового рядка або counter дорівнює останньому символу тексту
        if(text[counter] == '\n' || counter == text.size()){
            // рядок (підрядок, який починається з позиції минулого символу нового рядка довжиною counter-previous_position)
            string line = text.substr(previous_position, counter-previous_position);
            // добавляємо цей рядок у вектор
            lines.push_back(line);
            // оновлюємо позицію крапки
            previous_position = counter+1;
        }
        counter++;
    }

    return lines;
}

vector<vector<string>> split_information(const vector<string>& lines){
    // двовимірний вектор з інформацією
    // зберігає у собі загальну інформацію про всі вироби
    vector<vector<string>> general_information;

    for(int i=0;i<lines.size();i++){
        // позиція минулої коми
        int previous_position = 0;
        // лічильник (рахує символи тексту)
        int counter = 0;
        // вектор з інформацією про конкретний виріб (назва, дата покупки, срок гарантії)
        vector<string> information_vector;

        while(counter <= lines[i].size()){
            // якщо символ дорівнює роздільнику або останньому символу слова
            if(lines[i][counter] == ',' || counter == lines[i].size()){
                // слово (підрядок, який починається з позиції минулого розділювача довжиною counter-previous_position)
                string info = lines[i].substr(previous_position, counter-previous_position);
                // добавляємо інформацію у вектор конкретного виробу
                information_vector.push_back(info);
                // оновлюємо позицію
                previous_position = counter+1;
            }
            counter++;
        }

        // добавляємо вектор з інформацією про конкретний виріб у двовимірний загальний вектор
        general_information.push_back(information_vector);
    }

    return general_information;
}

void write_file(const string& file_name, const string& string_to_write){
    // потік write_file (для читання і запису) в режимі бінарного запису і дозапису у кінець файлу
    ofstream write_file(file_name, ios::app | ios::binary);
    // записуємо текст у файл
    write_file << string_to_write;

    // закриваємо потік(файл)
    write_file.close();
}

int get_unix_timestamp(const string& day,const string& month,const string& year){
    // час (структура, що містить календарну дату та час, розбиту на її компоненти.)
    tm time{};

    // створюємо потік
    // має бути наступного формату: 2022-24-02T00:00:00.000Z (YYYY, MM, DD)
    istringstream ss("20" + year + "-" + month + "-" + day + "T00:00:00.000Z");

    // отримуємо unix час нашого потоку
    ss >> get_time(&time, "%Y-%m-%dT%H:%M:%S");
    // конвертуємо час у календарний
    time_t time_stamp = mktime(&time);

    return static_cast<int>(time_stamp);
}

void check_warranty(vector<vector<string>> information, const string& todays_date){
    for(int i=0; i < information.size(); i++){
        // дата покупки виробу (формату 24.02.22)
        string buy_date = information[i][1];
        // день покупки виробу
        string buy_date_day = buy_date.substr(0, 2);
        // місяць покупки виробу
        string buy_date_month = buy_date.substr(3, 2);
        // рік покупки виробу
        string buy_date_year = buy_date.substr(6, 2);
        // отримуємо unix час дати покупки виробу
        int buy_date_unix = get_unix_timestamp(buy_date_day, buy_date_month, buy_date_year);

        // термін гарантії
        int warranty_term = stoi(information[i][2]);
        // рахуємо дату закінчення гарантійного терміну
        // (unix час дати покупки виробу + термін гарантії * 86400 (кількість секунд в одному дні))
        int warranty_expire_date = buy_date_unix + warranty_term * 86400;

        // день сьогоднішньої дати
        string todays_date_day = todays_date.substr(0, 2);
        // місяць сьогоднішньої дати
        string todays_date_month = todays_date.substr(3, 2);
        // рік сьогоднішньої дати
        string todays_date_year = todays_date.substr(6, 2);
        // отримуємо unix час дати сьогоднішньої дати
        int todays_date_unix = get_unix_timestamp(todays_date_day, todays_date_month, todays_date_year);

        // якщо unix час дати сьогоднішньої дати більший за unix час дати покупки виробу
        // (тобто термін гарантії скінчився)
        if(todays_date_unix > warranty_expire_date){
            // виводимо цю інформацію в консоль
            printf("Warranty have been expired for product %s\n", information[i][0].c_str());
            // формуємо рядок для запису
            string string_to_write = "Warranty have been expired for product: " + information[i][0] + "," + information[i][1] + "," + information[i][2] + "\n";

            // записуємо цю інформацію у файл
            write_file("output.txt", string_to_write);
        }

    }
}

void read_output_file(const string& file_name){
    // інарний потік read_output_file (тільки для читання)
    ifstream read_output_file(file_name, ios::binary);
    // виводимо в консоль текст з файлу
    cout << "\nOutput file:\n" << read_output_file.rdbuf() << "\n";
    // закриваємо потік(файл)
    read_output_file.close();
}

string read_today_date(){
    string todays_date;
    cout << "Enter today's date (in format dd.mm.yy): ";
    getline(cin, todays_date);

    return todays_date;
}
