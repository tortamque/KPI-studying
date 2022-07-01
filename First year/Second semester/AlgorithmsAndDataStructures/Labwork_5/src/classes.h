#ifndef ASD_LABWORK_5_CLASSES_H
#define ASD_LABWORK_5_CLASSES_H
#endif

#include <iostream>
using namespace std;

class Node{
private:
    string data;
    Node* next_node;

public:
    Node();
    Node(string data_to_add);

    string get_data();
    Node* get_next_node();
    void set_next_node(Node *node_to_add);
};


class SinglyLinkedList{
private:
    Node* head_node;

    void delete_head_node();
    bool is_empty();

public:
    SinglyLinkedList();

    int get_list_size();
    void add_node(string data_to_add);
    Node* get_node(int position);
    void delete_note(int position);
    void show_list();
};