#include "functions.h"
#include <ctime>

int main() {
    srand(time(nullptr));

    int graph_size = get_graph_size();
    char graph_mode = get_graph_mode();
    int begin_vertex = get_begin_vertex(graph_size);
    int end_vertex = get_end_vertex();

    Graph graph = Graph(graph_size, graph_mode, begin_vertex, end_vertex);
    cout << "Adjacency matrix of graph:\n";
    graph.print();

    vector<int> detour = graph.detour();
    cout << "Graph detour: ";
    print_vector(detour);

    vector<int> path = graph.find_path(detour);
    printf("Path from %d to %d: ", begin_vertex, end_vertex);
    print_vector(path);
}
