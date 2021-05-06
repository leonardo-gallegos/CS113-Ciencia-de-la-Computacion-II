#include <iostream>
#include <random>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void transposeArray(int (*Array)[3][3]) {
    for (int(*p)[3][3]{Array}; p < Array + 3;  p++) {
        for (int (*q)[3]{*p}; q < *(p + 1); q++) {
            for (int *r{*q}; r < *(q + 1); r++) {
                std::cout << *r << std::endl;
            }
        }
    }
}

int main() {
    int A[3][3][3] = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{11, 12, 13}, {14, 15, 16}, {17, 18, 19}}, {{21, 22, 23}, {24, 25, 26}, {27, 28, 29}}};
    transposeArray(A);

}