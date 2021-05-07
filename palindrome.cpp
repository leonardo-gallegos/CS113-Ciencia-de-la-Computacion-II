#include <iostream>

void removeSpace(char* string) {
    char *temp = string;
    for (; *string; string++) {
        if (*string != ' ') {
            *temp = *string;
            temp++;
        }
    }
    *temp = '\0';
}

bool palindrome(char* string) {
    // Eliminamos los espacios de la cadena
    removeSpace(string);
    // El puntero 'p' apunta al inicio de la cadena
    char *end{string};
    // Creamos un puntero temporal que nos ayuda a comparar
    // los caracteres con el puntero 'p'
    char *start;
    // Hacemos que el puntero 'p' apunte al final de la cadena
    while (*end != '\0') {
        end++;
    }
    end--;

    // El puntero 'temp' apunta al inicio de la cadena
    for (start = string; start <= end;) {
        // Comparamos el caracter de la derecha con el de la izquierda
        if (*start == *end) {
            end--;
            // Si es palindromo 'temp' será igual a 'p + 1'
            start++;
        }
        else {
            break;
        }
    }
    // Si 'temp' es mayor que 'p', es decir todos los caracteres
    // de la cadena cumplieron la comparación, por lo tanto la
    // cadena es un palindromo
    if (end < start) {
        return true;
    }
    // No es palindromo
    else {
        return false;
    }
}

void checkPalindrome(char (*string)[100], int size) {
    char (*p)[100] = string;
    for(int i{0}; i < size; i++) {
        bool checkPalindrome = palindrome(*p);
        if (checkPalindrome) {
            std::cout << "Frase "<< i + 1 << " es palindromo" << std::endl;
        }
        else {
            std::cout << "Frase "<< i + 1 << " no es palindromo" << std::endl;
        }
        p++;
    }
}

int main() {
    char A[5][100] = {"amo la paloma",      // Frase 1 es palindromo
                      "roma se asoma",      // Frase 2 no es palindromo
                      "ali tomo tila",      // Frase 3 es palindromo
                      "anita lava la tina", // Frase 4 es palindromo
                      "ramona come mora"};  // Frase 5 no es palindromo

    checkPalindrome(A, 5);
}