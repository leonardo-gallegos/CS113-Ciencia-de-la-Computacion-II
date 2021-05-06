#include <iostream>
#include <random>

// Swap function: Allows to swap elements within the array
// Permite intercambiar dos elementos dentro del array
void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void transposeArray(int (*Array)[3]) {
    // 'low' hace referencia al primer elemento por debajo de la diagonal
    // que nose servirá para sumar al puntero 'p'
    int low = 1;
    for (int(*p)[3]{Array}; p < Array + 3;  p++) {
        // El intercambio solo se realizará entre los elementos de la
        // triangular inferior y la trinagular superior
        // Es decir, cuando el puntero 'p' hace referencia al primer
        // elemento de la primera fila que es parte de la diagonal
        // no cambiará
        if(p == Array) {
            continue;
        }
        else {
            // tmp hace referencia al primer elemento de cada fila
            int *tmp = *p;
            // 'row' alamacena el valor de 'low' que cambiará mientras
            // 'q' apunta a los elementos de cada fila antes de la diagonal 
            int row = low;
            for (int *q{*p}; q < tmp + row; q++) {
                    // 'row_element' hace referencia al primer elemento de
                    // la fila anterior, ya que cuando 'p' apunta a la primera fila
                    // no se realiza ningún intercambio
                    int *row_element = *(p - low);
                    // 'row_element' almacena el valor correspondiente de 'q' pero
                    // al otro lado de la diagonal
                    row_element += row;
                    // Finalmente intercambiamos ambos elementos
                    swap(q, row_element);
                    // Mientras 'p' siga haciendo referencia a la misma fila
                    // el valor de 'low' se reducirá en uno para 'q' y 'row_element'
                    // sean opuestos
                    low--;
            }
            // Una vez que completamos los intercambios en la fila 'low' recupera su valor
            low = row; 
        }
        // 'low' hace referencia a la fila - 1
        low += 1;
    } 
}

// Print array function (using pointers)
// Imprime el array con formato entre corchetes, separando los valores
// correspondientes a cada fila y columna. No estuve seguro de si
// usar corchetes o llaves para el formato.
void printArray(int (*Array)[3]) {
    for (int(*p)[3]{Array}; p < Array + 3;  p++) {
        // Cuando el puntero 'p ' apunta al inicio del array (primera fila)
        if (p == Array) {
            std::cout << "[";
        }
        for (int *q{*p}; q < *(p + 1); q++) {
            // Cuando el puntero 'q' apunta al inicio de la fila (primera columna)
            if (q == *p) {
                std::cout << "[" << *q << ", ";
            }
            // Cuando el puntero 'q' apunta al fin de la fila (último elemento)
            else if (q + 1 == *(p + 1)) {
                std::cout << *q << "]";
                // Cuando el puntero 'p' no apunta al fin del array
                // Esto permite separar cada fila del array entre comas
                if (p != Array + 2){
                    std::cout << ", ";
                }
            }
            // Cuando el puntero 'q' apunta a los elementos dentro de cada fila,
            // pero que sean diferentes al inicio y al fin de cada fila.
            else {
                std::cout << *q << ", ";
            }         
        }
        // Cuando el puntero 'p ' apunta al fin del array (última fila)
        if (p == Array + 2) {
            std:: cout << "]";
        }
    }
}

// Set random 2D array function
// Asigna valores aleatorios a los elementos de
// un array ya creado
void set2DArray(int (*randArray)[3]) {
    // No lo expliqué muy bien en la primera tarea, pero usé la librería <random> 
    // para obtener numeros aleatorios, ya que estuve investigando y me encontré
    // con una conferencia de Stephan T. Lavavej (STL) senior developer de 
    // Visual C++ Libraries, en la que advertía que usar rand() y srand() es
    // una práctica mala.
    // Link: https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful

    // random_device es un generador de números aleatorios que produce números 
    // aleatorios no deterministas
    std::random_device generator;
    // mt19937 es un generador pseudoaleatorio Mersenne Twister de números de 
    // 32 bits con un tamaño de estado de 19937 bits
    std::mt19937 engine(generator());
    
    // uniform_int_distribution<int> produce valores enteros de acuerdo con 
    // una distribución discreta uniforme
    std::uniform_int_distribution<int> dist(1, 100);
   
    for (int(*p)[3]{randArray}; p < randArray + 3;  p++) {
        for (int *q{*p}; q < *(p + 1); q++) {
            *q = dist(engine);
        }
    }
}

// Create random 2D array function
// Crea un array de tamaño 3x3
// Usé el operador new, ya que el concepto de crear un array y asignar valores a un 
// array ya  creado me confundió un poco, así que decidí implementar ambas funciones
// por temor a que una o ambas estén mal
int (*create2DArray())[3] {
    std::random_device generator;
    std::mt19937 engine(generator());
    std::uniform_int_distribution<int> dist(1, 100);
    int (*randArray)[3] = new int [3][3];
    for (int(*p)[3]{randArray}; p < randArray + 3;  p++) {
        for (int *q{*p}; q < *(p + 1); q++) {
            *q = dist(engine);
        }
    }
    return randArray;
}

 

int main() {

    int A[3][3] = {{1, 2, 3}, 
                   {4, 5, 6}, 
                   {7, 8, 9}};
    
    int B[3][3];
    set2DArray(B);

    int (*C)[3] = create2DArray();
    
    std::cout << "Matrix A before transpose: ";
    printArray(A);
    std::cout << std::endl;
    std::cout << "Matrix A after transpose: ";
    transposeArray(A);
    printArray(A);
    std::cout << std::endl;


    std::cout << "Matrix B before transpose: ";
    printArray(B);
    std::cout << std::endl;
    std::cout << "Matrix B after transpose: ";
    transposeArray(B);
    printArray(B);
    std::cout << std::endl;

    std::cout << "Matrix C before transpose: ";
    printArray(C);
    std::cout << std::endl;
    std::cout << "Matrix C after transpose: ";
    transposeArray(C);
    printArray(C);
    std::cout << std::endl;
    delete[] C;
    
}