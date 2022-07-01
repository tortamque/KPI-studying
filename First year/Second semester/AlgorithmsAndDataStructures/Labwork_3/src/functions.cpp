#include <iostream>
#include "classes.h"
using namespace std;

int get_graph_size(){
    int graph_size;

    cout << "Enter graph size: ";
    cin >> graph_size;

    return graph_size;
}

char get_graph_mode(){
    char graph_mode;

    cout << "Would you like enter graph manually or generate it randomly?\nM - Manually, R - Randomly: ";
    cin >> graph_mode;

    while (graph_mode != 'm' && graph_mode != 'M' && graph_mode != 'r' && graph_mode != 'R'){
        cout << "Error. Enter either M or R: \n";
        cin >> graph_mode;
    }

    return graph_mode;
}

int get_begin_vertex(int matrix_size){
    int begin_vertex;

    cout << "Enter begin vertex: ";
    cin >> begin_vertex;

    while (begin_vertex > matrix_size){
        cout << "Error. Begin vertex must be lower or equal to graph size";
        cin >> begin_vertex;
    }

    return begin_vertex;
}

int get_end_vertex(){
    int end_vertex;

    cout << "Enter end vertex: ";
    cin >> end_vertex;

    while (end_vertex < 1){
        cout << "Error. End vertex must be greater or equal to 1";
        cin >> end_vertex;
    }

    return end_vertex;
}

void print_vector(const vector<int>& vec){
    for(int i : vec)
        cout << i << " ";
    cout << "\n";
}