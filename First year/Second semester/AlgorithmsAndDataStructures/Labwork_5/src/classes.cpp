#include "classes.h"

Node::Node() {
    data = "";
    next_node = nullptr;
}

Node::Node(string data_to_add) {
    data = std::move(data_to_add);
    next_node = nullptr;
}


string Node::get_data() {
    return data;
}

Node *Node::get_next_node() {
    return next_node;
}

void Node::set_next_node(Node *node_to_add){
    next_node = node_to_add;
}

SinglyLinkedList::SinglyLinkedList() {
    head_node = nullptr;
}

void SinglyLinkedList::add_node(string data_to_add) {
    Node* node_to_add = new Node(std::move(data_to_add));

    // якщо головний вузол порожній (список пустий)
    if (is_empty()) {
        // ініціалізуємо головний вуззол вузлом node_to_add
        head_node = node_to_add;
    }
    // якщо головний вузол не порожній (список не пустий)
    else{
        // тимчасовий вузол
        Node* temp_node = head_node;

        // ітеруємось поки наступний вузол не буде дорівнювати nullptr
        // тобто, ітеруємось до останнього вузла
        while (temp_node->get_next_node() != nullptr) {
            // змінюємо тимчасовий вузол наступним вузлом
            temp_node = temp_node->get_next_node();
        }

        // додаємо вузол node_to_add як останній
        temp_node->set_next_node(node_to_add);
    }

}

void SinglyLinkedList::show_list() {
    // якщо головний вузол порожній (список пустий)
    if (is_empty()) {
        cout << "List is empty" << endl;
    }
    // якщо головний вузол не порожній (список не пустий)
    else{
        Node* temp_node = head_node;

        // Ітеруємось по вузлам (ітеруємось поки останній вузол не буде дорівнювати nullptr)
        while (temp_node != nullptr) {
            cout << temp_node->get_data() << " ";
            // змінюємо тимчасовий вузол наступним вузлом
            temp_node = temp_node->get_next_node();
        }
    }

}

int SinglyLinkedList::get_list_size() {
    // кількість елементів у списку
    int list_size = 0;
    Node *temp_node = head_node;

    while (temp_node != nullptr) {
        // змінюємо тимчасовий вузол наступним вузлом
        temp_node = temp_node->get_next_node();
        list_size++;
    }

    return list_size;
}

void SinglyLinkedList::delete_head_node() {
    // переміщуємо перший покажчик на наступний вузол
    head_node = head_node->get_next_node();
}

bool SinglyLinkedList::is_empty() {
    // якщо головний вузол порожній (список пустий)
    if (head_node == nullptr)
        return true;
    else return false;
}

void SinglyLinkedList::delete_note(int position){
    if (is_empty()) {
        cout << "List is empty" << endl;
    }
    else{
        int list_size = get_list_size();

        // перевіряємо чи позиція менша за довжину списку
        // якщо позиція більша, то виводимо повідомлення про помилку
        if (position > list_size) {
            cout << "Index is greater that list size" << endl;
        }
        // якщо ж позиція менша
        else{
            // якщо позиція == 1, то видаляємо головний вузол
            if (position == 1) {
                delete_head_node();
            }
            else{
                Node *temp_node1 = head_node;
                Node *temp_node2 = nullptr;

                // Ітеруємось по вузлам, поки не буде досягнута позиція
                while (position > 1) {
                    position--;

                    // змінюємо другий тимчасовий вузол на перший
                    temp_node2 = temp_node1;

                    // змінюємо перший вузол на наступний
                    temp_node1 = temp_node1->get_next_node();
                }

                // наступний вузол першого тимчасового вузла
                Node *next_node = temp_node1->get_next_node();
                // змінюємо покажчик другого тимчасового вузла на наступний вузол
                temp_node2->set_next_node(next_node);

                // видаляємо перший тимчасовий вузол
                delete temp_node1;
            }
        }
    }
}

Node* SinglyLinkedList::get_node(int position) {
    if (is_empty()) {
        cout << "List is empty" << endl;
    }
    else{
        int list_size = get_list_size();

        // перевіряємо чи позиція менша за довжину списку
        // якщо позиція більша, то виводимо повідомлення про помилку
        if (position > list_size) {
            cout << "Index is greater that list size" << endl;
        }
            // якщо ж позиція менша
        else{

            Node *temp_node = head_node;

            // Ітеруємось по вузлам, поки не буде досягнута позиція
            while (position > 1) {
                position--;

                // змінюємо перший вузол на наступний
                temp_node = temp_node->get_next_node();
            }

            return temp_node;
        }
    }
}






