#include "functions.h"

int main(int arg_count, char *arg_values[]) {

    string file_name = get_input_file_name(arg_values);
    int person_number = get_person_number(arg_values);

    int users_amount = get_users_amount(file_name);
    int films_amount = get_films_amount(file_name);

    string text = read_input_file(file_name);
    string matrix_string = parse_matrix_string(text);
    vector<vector<int>> matrix = parse_matrix(matrix_string);

    cout << "Matrix on input:\n";
    print_matrix(matrix, users_amount, films_amount);

    cout << "\nSliced matrix (sliced user index in first column):\n";
    vector<vector<int>> sliced_matrix = slice_matrix(matrix, users_amount);
    print_matrix(sliced_matrix, users_amount, films_amount - 1);

    vector<Result> results = find_preferences(sliced_matrix, users_amount, person_number - 1);

    sort_results(results);

    write_output_file(results, person_number);
}
