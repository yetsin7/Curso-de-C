/*
 * ============================================================
 * Modulo 12 -- Preprocesador y Headers
 * Archivo: 03_include_guards.c
 * ============================================================
 *
 * Este archivo explica los include guards.
 *
 * Un include guard evita que el contenido de un header se procese mas de
 * una vez dentro del mismo archivo fuente.
 *
 * Sin include guards, incluir el mismo header varias veces puede producir
 * errores de redefinicion.
 *
 * Forma clasica de un include guard:
 *
 *   #ifndef NOMBRE_DEL_HEADER_H
 *   #define NOMBRE_DEL_HEADER_H
 *
 *   contenido del header
 *
 *   #endif
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 03_guards 03_include_guards.c
 *
 * Ejecutar:
 *   Windows: 03_guards.exe
 *   Linux/macOS: ./03_guards
 */

#include <stdio.h>
#include "constantes.h"
#include "utilidades.h"

/*
 * Implementaciones de las funciones declaradas en utilidades.h.
 *
 * En proyectos mas grandes, estas funciones normalmente irian en un
 * archivo separado llamado utilidades.c.
 */
void imprimir_separador(void) {
    printf("----------------------------------------\n");
}

void log_debug(const char *archivo, int linea, const char *mensaje) {
    printf("[DEBUG] %s:%d -> %s\n", archivo, linea, mensaje);
}

long factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

int es_primo(int n) {
    if (n < 2) {
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    printf("=== INCLUDE GUARDS ===\n");
    printf("Los headers fueron incluidos correctamente.\n");
    printf("Los guards previenen inclusion multiple.\n");

    printf("\n=== USANDO MACROS DE constantes.h ===\n");
    printf("PI: %.10f\n", PI);
    printf("MAX_SIZE: %d\n", MAX_SIZE);
    printf("SQUARE(7) = %d\n", SQUARE(7));
    printf("MIN(10, 20) = %d\n", MIN(10, 20));
    printf("MAX(10, 20) = %d\n", MAX(10, 20));

    printf("\n=== USANDO FUNCIONES DE utilidades.h ===\n");
    imprimir_separador();
    log_debug(__FILE__, __LINE__, "Programa iniciado correctamente");
    imprimir_separador();

    printf("\n=== COMBINANDO HEADERS ===\n");

    int num = 5;
    long fact = factorial(num);
    printf("Factorial de %d = %ld\n", num, fact);

    int primo_test = 17;

    if (es_primo(primo_test)) {
        printf("%d es primo\n", primo_test);
    } else {
        printf("%d no es primo\n", primo_test);
    }

    printf("\n=== CONVERSION DE TEMPERATURA ===\n");

    double celsius = 36.5;
    printf("%.1f C = %.1f F\n", celsius, CELSIUS_A_FAHRENHEIT(celsius));

    return 0;
}
