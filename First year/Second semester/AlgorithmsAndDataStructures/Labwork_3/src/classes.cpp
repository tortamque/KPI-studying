#include "classes.h"
#include <random>
#include <algorithm>

int Graph::get_size() {
    return graph_size;
}

void Graph::print() {
    for(int i = 0; i < get_size(); i++){
        for(int j = 0; j < get_size(); j++){
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void Graph::generate_manually(){
    int size = get_size();

    for(int i = 0; i < size; i++){
        vector<int> row;

        for(int j = 0; j < size; j++){
            printf("Enter data on row %d column %d: ", i+1, j+1);

            int input_data;
            cin >> input_data;

            row.push_back(input_data);
        }

        adjacency_matrix.push_back(row);
    }
}

void Graph::initialize_zeroes(){
    int size = get_size();

    for(int i = 0; i < size; i++){
        vector<int> row;

        for(int j = 0; j < size; j++){
            row.push_back(0);
        }

        adjacency_matrix.push_back(row);
    }
}

void Graph::generate_randomly(){
    int size = get_size();
    initialize_zeroes();

    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            int random_number = rand() % 2;

            adjacency_matrix[i][j] = random_number;
            adjacency_matrix[j][i] = random_number;
        }
    }
}

Graph::Graph(int size, char mode, int begin_vertex, int end_vertex) {
    graph_size = size;
    this->begin_vertex = begin_vertex;
    this->end_vertex = end_vertex;

    if(mode == 'm' || mode == 'M'){
        generate_manually();
    }
    else if(mode == 'r' || mode == 'R'){
        generate_randomly();
    }
}

bool Graph::is_vector_contains(vector<int> vec, int value) {
    if(std::find(vec.begin(), vec.end(), value) != vec.end()) {
        return true;
    } else {
        return false;
    }
}

void Graph::fill_missed_vertices(vector<int> &path) {
    int size = get_size();
    // вершина, якої не вистачає
    int missed_vertex = -1;

    for(int i = 1; i <= size; i++){
        if(is_vector_contains(path, i) == false){
            // якщо вершина знайдена, то ініціалізуємо її
            missed_vertex = i-1;
        }
    }

    // i координата вершини, з якої перейшли в іншу вершину
    int last_vertex_i = -1;
    // j координата вершини, з якої перейшли в іншу вершину
    int last_vertex_j = -1;
    // якщо якоїсь вершини не вистачає
    if(missed_vertex != -1){
        // ініціалізуємо i останнім елементом вектора path і віднімаємо від нього одиницю
        // наприклад, якщо path буде 3,1,4,6 то i буде дорівнювати 5 (6 - останній елемент, і віднімаємо від нього одиницю)
        for(int i = path[path.size()-1] - 1; i > 0; i--){
            for(int j = size-1; j > 0; j--){
                // якщо i != j, тобто не беремо вершину, яка інцидентна сама собі
                if(i != j){
                    // якщо елемент матриці = 1 і j = зниклій вершині
                    if(adjacency_matrix[i][j] == 1 && j == missed_vertex){
                        //додаємо вершину в вектор path
                        path.push_back(j+1);
                        // змінюємо зниклу вершину на -1, для того, щоб далі не додавались зайві елементи у вектор path
                        missed_vertex = -1;
                    }
                    // якщо елемент матриці = 1 і координата вершини i != j або координата вершини j != i і зникла вершина != -1
                    if(adjacency_matrix[i][j] == 1 && (last_vertex_i != j || last_vertex_j != i) && missed_vertex != -1){
                        // додаємо вершину в вектор
                        path.push_back(j + 1);
                        // змінюємо i координату останньої вершини на поточну вершину
                        last_vertex_i = i;
                        // змінюємо j координату останньої вершини на поточну вершину
                        last_vertex_j = j;

                        // змінюємо i на j
                        i = j;
                        // присвоюємо j значення size
                        j = size;
                    }
                }
            }
        }
    }
}

vector<int> Graph::detour() {
    int size = get_size();
    vector<int> path;
    path.push_back(1);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size ; j++){
            if(i != j){
                if(adjacency_matrix[i][j] == 1 && is_vector_contains(path, j+1) == false){
                    path.push_back(j + 1);

                    i = j;
                    j = -1;
                }
            }
        }
    }

    fill_missed_vertices(path);

    return path;
}

vector<int> Graph::find_path(vector<int> detour) {
    vector<int> path;

    // чи знайдена початкова вершина графу в векторі
    bool is_begin_vertex_found = false;
    // чи знайдена кінцева вершина графу в векторі
    bool is_end_vertex_found = false;

    // ітеруємось через вектор зліва на право
    for(int i = 0; i < detour.size(); i++){
        // якщо елемент вектору = початковій вершині
        if(detour[i] == begin_vertex)
            // маркуємо її як знайдену
            is_begin_vertex_found = true;
        // якщо елемент вектору = кінцевій вершині
        else if(detour[i] == end_vertex) {
            // маркуємо її як знайдену
            is_end_vertex_found = true;
            // додаємо її у вектор
            path.push_back(detour[i]);
        }

        // якщо початкова вершина знайдена, а кінцева ще ні
        if(is_begin_vertex_found == true && is_end_vertex_found == false){
            //додаємо елемент у вектор path
            path.push_back(detour[i]);
        }
    }

    // якщо розмір вектору менше за 2, це означає, що шлях потрібно шукати в зворотньому напрямку
    // наприклад, якщо даний маршрут 1 3 4 2 6 і потрібно знайти шлях від 2 до 4
    // то потрібно шукати шлях не зліва на право, а справа на ліво
    if(path.size() < 2){
        path.clear();

        // чи знайдена початкова вершина графу в векторі
        is_begin_vertex_found = false;
        // чи знайдена кінцева вершина графу в векторі
        is_end_vertex_found = false;

        // ітеруємось через вектор справа на ліво
        for(int i = get_size() - 1; i > 0; i--){
            // якщо елемент вектору = кінцевій вершині
            if(detour[i] == end_vertex) {
                // маркуємо її як знайдену
                is_end_vertex_found = true;
                // додаємо її у вектор
                path.push_back(detour[i]);
            }
            // якщо елемент вектору = початковій вершині
            else if(detour[i] == begin_vertex)
                // маркуємо її як знайдену
                is_begin_vertex_found = true;

            // якщо початкова вершина знайдена, а кінцева ще ні
            if(is_end_vertex_found == false && is_begin_vertex_found == true){
                //додаємо елемент у вектор path
                path.push_back(detour[i]);
            }
        }
    }

    return path;
}


