#include "functions.h"

int main() {
    string text = capture_text();
    printf("Entered text:\n%s\n\n", text.c_str());

    SinglyLinkedList list;

    fill_list(list, text);

    printf("List after filling:\n");
    list.show_list();

    char character = capture_char();
    delete_words(character, list);

    printf("\nList after deleting words with start and end character %c:\n", character);
    list.show_list();
}
