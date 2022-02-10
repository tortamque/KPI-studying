#ifndef INC_2LABWORK_1_FUNCTIONS_H
#define INC_2LABWORK_1_FUNCTIONS_H
#endif

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/** Отримує текст з клавітури, поки не натиснута комбінація клавіш Ctrl+Enter
 *  @return: текст з клавітури
 */
string capture_text();

/** Виводить елементі вектора в консоль
 *  @param vec: вектор
 */
void print_vector(const vector<string>& vec);

/** Читає текст з вхідного файлу
 *  @param file_name: назва файлу
 *  @return: текст з файлу
 */
string read_input_file(const string& file_name);

/** Ділить речення у тексті у вектор
 *  @param text: текст
 *  @return: вектор з реченнями
 */
vector<string> split_sentences(const string& text);

/** Виводить в консоль найдовші слова і їй довжину
 *  @param longest_words: вектор
 */
void print_longest_words(const vector<string>& longest_words);

/** Отримує найдовші слова із вектора речень
 *  @param sentences: вектор з реченнями
 *  @return: вектор з найдовшими словами
 */
vector<string> get_longest_words(const vector<string>& sentences);

/** Записує текст у файл
 *  @param file_name: найзва файлу
 *  @param longest_words: вектор з найдовшими словами речень
 *  @param sentences: вектор з реченнями
 */
void write_file(const string& file_name, const vector<string>& longest_words, vector<string>& sentences);

/** Записує текст у файл input
 *  @param file_name: найзва файлу
 *  @param text: текст
 */
void write_empty_file(const string& file_name, const string& text);

/** Читає текст з вихідного файлу
 *  @param file_name: назва файлу
 */
void read_output_file(const string& file_name);
