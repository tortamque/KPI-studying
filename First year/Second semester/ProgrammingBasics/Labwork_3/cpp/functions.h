#ifndef INC_2LABWORK_3_FUNCTIONS_H
#define INC_2LABWORK_3_FUNCTIONS_H

#endif //INC_2LABWORK_3_FUNCTIONS_H
#pragma once

#include <iostream>
#include <vector>

#include "classes.h"
using namespace std;

/**
 * Отримує від користувача кількість кіл для генерації
 * @return: кількість кіл для генерації
 */
int GetCirclesAmount();

/**
 * Генерує круг, за заданими користувачем параметрами
 * @param i: лічильнік
 * @return: об'єкт круга
 */
CircleOnPlane GenerateCircle(int i);

/**
 * Генерує вектор із колами, які будуть створені за заданими користувачем параметрами
 * @param circles_amount: кількість кругів
 * @return: генерує вектор із колами
 */
vector<CircleOnPlane> GenerateCirlesVector(int circles_amount);

/**
 * Знаходить круг з найбільшою площею
 * @param circles: вектор із кругами
 * @return: об'єкт найбільшого круга
 */
CircleOnPlane FindLargestCirce(const vector<CircleOnPlane>& circles);

