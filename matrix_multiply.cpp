#include <iostream>
#include <random>

// Print array function
void printArray(int (*Array)[3][3]) {
    for (int(*p)[3][3]{Array}; p < Array + 3;  p++) {
        if (p == Array) {
            std::cout << "[";
        }
        for (int (*q)[3]{*p}; q < *(p + 1); q++) {
            if (q == *p) {
                std::cout << "[";
            }
            for (int *r{*q}; r < *(q + 1); r++) {
                if (r == *q) {
                std::cout << "[" << *r << ", ";
                }
                else if (r + 1 == *(q + 1)) {
                    std::cout << *r << "]";

                    if (p != Array + 3){
                        if (q  + 1 != *(p + 1)) {
                            std::cout << ", ";
                        }
                    }
                }
                else {
                    std::cout << *r << ", ";
                }
            }
        }
        std::cout << "]";
        if ( p + 1 != Array + 3) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

void set3DArray(int (*randArray)[3][3]) {
    std::random_device generator;
    std::mt19937 engine(generator());
    std::uniform_int_distribution<int> dist(1, 50);
    for (int(*p)[3][3]{randArray}; p < randArray + 3;  p++) {
        for (int (*q)[3]{*p}; q < *(p + 1); q++) {
            for (int *r{*q}; r < *(q + 1); r++) {
                *r = dist(engine);
            }
        }
    }
}

int (*create3DArray())[3][3] {
    std::random_device generator;
    std::mt19937 engine(generator());
    std::uniform_int_distribution<int> dist(1, 100);
    int (*randArray)[3][3] = new int [3][3][3];
    for (int(*p)[3][3]{randArray}; p < randArray + 3;  p++) {
        for (int (*q)[3]{*p}; q < *(p + 1); q++) {
            for (int *r{*q}; r < *(q + 1); r++) {
                *r = dist(engine);
            }
        }
    }
    return randArray;
}

// Multiply array A[0] and A[1] within the A matrix
// the result is strored inside array A[2]
// For matrix of A[3][3][3] type
void multiplyArray(int (*Array)[3][3]) {
    int(*p)[3][3]{Array + 2};
    int (*firstFactor)[3][3]{Array + 0};
    int (*secondFactor)[3][3]{Array + 1};
    int (*row_ptr)[3]{*firstFactor};
    for (int (*q)[3]{*p}; q < *(p + 1); q++) {
        int col_aux = 0;
        for (int *r{*q}; r < *(q + 1); r++) {
            int (*col_ptr)[3]{*secondFactor};
            int *row_element{*row_ptr};
            int sum_product = 0;
            for (int size{0}; size < 3; size++) {
                int *col_element{*col_ptr};
                col_element = col_element + col_aux;
                int first = *row_element;
                int second = *col_element;
                int product = first * second;
                sum_product += product;
                row_element++;
                *col_element++;
                col_ptr++;
                if (size + 1 == 3) {
                    int *row_element{*row_ptr};
                    *r = sum_product;
                }
            }
            col_aux++;
        }
        row_ptr++; 
    }
}

int main() {
    // El array A[2] de la matriz es irrelevante, ya que este array
    // contiene el resultado de multiplicar el A[0] y el A[1]
    // A es una matriz creada en la función principal
    int A[3][3][3] = {{{11, 12, 13}, {14, 15, 16}, {17, 18, 19}}, 
                      {{21, 22, 23}, {24, 25, 26}, {27, 28, 29}}, 
                      {{31, 32, 33}, {34, 35, 36}, {37, 38, 39}}};
    std::cout << "Matrix A before multiply:" << std::endl;
    printArray(A);
    std::cout << std::endl;

    std::cout << "Matrix A after multiply:" << std::endl;;
    multiplyArray(A);
    printArray(A);
    std::cout << std::endl << std::endl;

    
    // B es una matriz creada en la función principal y a traves
    // de la función set3DArray se fijan valores aleatorios a la matriz
    int B[3][3][3];
    set3DArray(B);
    std::cout << "Matrix B before multiply:" << std::endl;
    printArray(B);
    std::cout << std::endl;

    std::cout << "Matrix B after multiply:" << std::endl;
    multiplyArray(B);
    printArray(B);
    std::cout << std::endl << std::endl;

    // C es una matriz cuyos valores son asignados mediante la 
    // función create3DArray
    int (*C)[3][3] = create3DArray();
    std::cout << "Matrix C before multiply:" << std::endl;
    printArray(C);
    std::cout << std::endl;

    std::cout << "Matrix C after multiply:" << std::endl;
    multiplyArray(C);
    printArray(C);
    delete[] C;
}