#ifndef ASD_LABWORK_3_CLASSES_H
#define ASD_LABWORK_3_CLASSES_H
#endif

#include <vector>
#include <iostream>
using namespace std;

class Graph{
private:
    vector<vector<int>> adjacency_matrix{};
    int graph_size;
    int begin_vertex;
    int end_vertex;

    int get_size();
    void generate_manually();
    void generate_randomly();
    void initialize_zeroes();
    bool is_vector_contains(vector<int> vec, int value);
    void fill_missed_vertices(vector<int> &path);
public:
    Graph(int size, char mode, int begin_vertex, int end_vertex);

    void print();
    vector<int> detour();
    vector<int> find_path(vector<int> detour);
};