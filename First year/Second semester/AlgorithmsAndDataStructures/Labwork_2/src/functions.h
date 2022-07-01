#ifndef ASD_LABWORK_2_FUNCTIONS_H
#define ASD_LABWORK_2_FUNCTIONS_H

#endif //ASD_LABWORK_2_FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "structs.h"
using namespace std;

string get_input_file_name(char *arg_values[]);
int get_person_number(char *arg_values[]);
int get_users_amount(string file_name);
int get_films_amount(string file_name);
string read_input_file(string file_name);
string parse_matrix_string(string text);
vector<vector<int>> parse_matrix(string matrix_string);
void print_matrix(vector<vector<int>> matrix, int rows, int columns);
void merge_sorting(vector<int> &matrix_row_main, vector<int> &matrix_row_secondary);
vector<vector<int>> slice_matrix(vector<vector<int>> matrix, int rows);
vector<Result> find_preferences(vector<vector<int>> matrix, int rows, int person_index);
void write_output_file(vector<Result> results, int person_number);
void sort_results(vector<Result> &results);