#include <iostream>
#include <random>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void cocktail_sort(int *A) {
    int *start = A;
    int *end = A + 9;
    bool flag;

    while (*start != *end) {
        flag = false;
        for (int *t = start; t < end; t++) {
            if (*t > *(t + 1)) {
                swap(t, t + 1);
                flag = true;
            }
        }
        if (flag) {
            --end;
            for (int *t = end; start < t; t--) {
                if (*t < *(t - 1)) {
                    swap(t, t - 1);
                }
            }
            ++start;
        }
        else {
            break;
        }
    }
}

void print(const int arr[], const int size) {
    std::cout << "[ ";
    for(int i{0}; i < size; i++) {
        if (i != size - 1) {
            std::cout << arr[i] << ", ";
        }
        else {
            std::cout << arr[i];
        }
    }
    std::cout << " ]" << std::endl;
}

int *array() {
    std::random_device generator;
    std::mt19937 engine(generator());
    std::uniform_int_distribution<int> dist(1, 100);
    static int randArray[10];
    for (int i{0}; i < 10; i++) {
        randArray[i] = dist(engine);
    }
    return randArray;
}

int main() {

    int *A = array();
    std::cout << "Before cocktail sort: ";
    print(A, 10);

    cocktail_sort(A);
    std::cout << " After cocktail sort: ";
    print(A, 10);

    return 0;
}
