#include <iostream>
#include <random>

// Renzo Leonardo Gallegos Vilca

// Función que crea una matriz de tamaño "row x col" y establece valores
// con un incremento fijo "increment" a cada componente. El valor por
// defecto del incremento es cero, esto creará una matriz de ceros.

// Nota: Si el valor del incremento es -1 se asignarán valores aleatorios
// a cada componente de la matriz
int (**createArray(int row, int col, int increment = 0)){
    // La librería random requiere la versión 9.2 de GCC para generar
    // diferentes valores en cada ejecución del programa
    std::random_device generator;
    std::mt19937 engine(generator());
    std::uniform_int_distribution<int> dist(1, 100);

    int** Array;
    Array = new int*[row];
    for(int** i{Array}; i < Array + row; i++) {
        *i = new int[col];
    }

    int plus = 0;
    for(int** i{Array}; i < Array + row; i++) {
        for(int* j{*i}; j < *i + col; j++) {
            if (increment == -1) {
                *j = dist(engine);
            }
            else {
                plus += increment;
                *j = plus;
            }
        }
    }
    return Array;
}

// Función para multiplicar la matriz A por la matriz B
// A(nxm) * B(mxo) = C(nxo)
void MULT_MAT(int** A, int** B, int** C, int n, int m, int o) {
    // Filas de la matriz C
    int** e = C;
    // Filas de la matriz B
    int** g = B;
    // Recorremos la matriz A y sus 'n' filas
    for(int** i{A}; i < A + n; i++) {
        // Recorremos la matriz A y sus 'm' columnas
        // Nota: el valor de 'm' representa la dimensión de la matriz A
        // respecto a sus columnas y deberá ser igual a la dimensión de
        // la matriz B respecto a sus filas.
        for(int* j{*i}; j < *i + m; j++) {
            // Columnas de C
            int* f{*e};
            // Recorremos las columnas de B
            for(int* h{*g}; h < *g + o; h++) {
                int multiply = 0;
                multiply = (*j) * (*h);
                // El valor de la primera fila y columna de la matriz A
                // se multiplicará con los valores de la primera fila de
                // la matriz B y así respectivamente, para la siguiente
                // columna de la primera fila se sumarán los valores
                // correspondientes con los nuevos.
                *f = *f + multiply;
                f++;
                // Cuando el puntero que hace referencia a las columnas 
                // de C exceda el tamaño de la matriz lo regresamos al 
                // comienzo
                if(f == *e + o) {
                  f = f - o;
                }
            }
            g++;
            // Cuando el puntero que hace referencia a las filas de B 
            // exceda el tamaño de la matriz lo regresamos al comienzo
            if(g == B + m) {
                g = g - m;
            }
        }
        // Recorremos las filas de la matriz C una vez que termine la
        // multiplicación de una fila de A con la matriz B para así
        // pasar a la siguiente fila de A
        e++;
    }
}

// Función para eliminar la matriz
void deleteArray(int **Array, int row) {
    for(int** i{Array}; i < Array + row; i++) { 
        delete[] *i;
    }
    delete[] Array;
}

// Función que imprime la matriz
void printArray(int **Array, int row, int col) {
    for(int** i{Array}; i < Array + row; i++) {  
        for(int* j{*i}; j < *i + col; j++) {
          std::cout << *j << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {

    // Dimensiones de las matrices (Para probar con diferentes valores)
    // Solo se deben modificar estas variables probar otras dimensiones
    // A(nxm) * B(mxo) = C(nxo)
    int n = 5;
    int m = 4;
    int o = 4;

    // Creación de las matrices

    // Creación de matriz y asignación de valores mediante función
    int **A = createArray(n, m, 1); // Con incremento de 1
    int **B = createArray(m, o, 10); // Con incremento de 10

    // Asignando valores mediante bucle (Como se aprendió en clase)
    int **C; // Matriz de ceros (resultado)
    // Creación
    C = new int*[n];
    for(int** i{C}; i < C + n; i++) {
            *i = new int[o];
        }
    // Asignación
    for(int** i{C}; i < C + n; i++) {
        for(int* j = *i; j < *i + o; j++) {
            int cero = 0;
            *j = cero;
      }
    }
    // Este proceso se pudo hacer mediate la siguiente línea:
    // int **C = createArray(n, m); 
    // No se usa el tercer argumento ya que es una matriz de ceros
    

    // Impresión de las matrices A y B mediante función
    std::cout << "--------Matriz A----------" << std::endl;
    (void) printArray(A, n, m);
    std::cout << "--------------------------" << std::endl;

    std::cout << "--------Matriz B----------" << std::endl;
    (void) printArray(B, m, o);
    std::cout << "--------------------------" << std::endl;
    
    // FUNCIÓN DE MULTIPLICACIÓN DE MATRICES DINÁMICAS
    MULT_MAT(A, B, C, n, m, o);

    std::cout << "--------Matriz C----------" << std::endl;
    (void) printArray(C, n, o);
    std::cout << "--------------------------" << std::endl;

    // Eliminando punteros

    // Eliminando mediante función
    (void) deleteArray(A, n);
    (void) deleteArray(B, m);

    // Eliminando mediante bucle en función principal (como se aprendió en clase)
    for(int** i{C}; i < C + n; i++) { 
        delete[] *i;
    }
    delete[] C;
    // Esto también se pudo hacer mediante la siguiente línea:
    // (void) deleteArray(C, n);

    return 0;
}