#ifndef INC_2LABWORK_3_CLASSES_H
#define INC_2LABWORK_3_CLASSES_H

#endif //INC_2LABWORK_3_CLASSES_H
#pragma once

class CircleOnPlane{
private:
    float radius;
    int x_coordinates;
    int y_coordinates;
public:
    CircleOnPlane(float , int, int);
    float GetArea() const;
    void DisplayInfo() const;
};