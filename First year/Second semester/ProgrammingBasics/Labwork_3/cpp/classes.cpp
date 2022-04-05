#include <iostream>
#include "classes.h"

/** Конструктор класу CircleOnPlane
 *  @param radius: Радіус круга
 *  @param x_coordinates: Координати центру по осі Ox
 *  @param y_coordinates:Координати центру по осі Oy
 */
CircleOnPlane::CircleOnPlane(float radius, int x_coordinates, int y_coordinates) {
    this->radius = radius;
    this->x_coordinates = x_coordinates;
    this->y_coordinates = y_coordinates;
}

/** Рахує площу круга
 *  @return: площа круга
 */
float CircleOnPlane::GetArea() const {
    float area = 3.1415f * radius * radius;

    return area;
}

/** Виводить в консоль інформацію про коло
 */
void CircleOnPlane::DisplayInfo() const{
    printf("Circle's radius: %f, area: %f and coordinates of its center: x = %d, y = %d", radius, GetArea(), x_coordinates, y_coordinates);
}
