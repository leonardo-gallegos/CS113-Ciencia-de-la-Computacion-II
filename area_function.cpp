#include <iostream>
#include <math.h>

float areaCirc(float radius, float empty) {
    float pi = atan(1) * 4;
    return pi * radius * radius;
}


float areaRect(float base, float height) {
    return base * height;
}


float areaTrian(float base, float height) {
    return base * height / 2;
}

int main() {
    
    int parm[2] = {10, 15};

    float (*pf[3])(float, float) = {areaCirc, areaRect, areaTrian};

    char phrase[3][100] = {"circle", "rectangle", "triangle"};

    for (int i{0}; i < 3; i++) {
        std::cout << "Area of " << phrase[i] << ": " << pf[i](*parm, *(parm + 1)) << std::endl;
    }
}