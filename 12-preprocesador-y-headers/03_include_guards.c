/*
 * 03_include_guards.c -- Demostracion de include guards
 * Compilar: gcc -Wall -Wextra -std=c11 -o 03_guards 03_include_guards.c
 *
 * Incluye ambos headers y muestra como los guards previenen
 * la inclusion multiple que causaria errores de redefinicion.
 */

#include <stdio.h>
#include "constantes.h"
#include "utilidades.h"

/*
 * Sin los guards (#ifndef/#define/#endif) en los headers,
 * incluir "constantes.h" dos veces produciria errores como:
 *   error: redefinition of 'MIN'
 * Los guards aseguran que el contenido se procese una sola vez.
 */

int main(void) {
    printf("=== INCLUDE GUARDS ===\n");
    printf("Ambos headers incluidos correctamente.\n");
    printf("Los guards previenen inclusion multiple.\n");

    printf("\n=== USANDO MACROS DE constantes.h ===\n");
    printf("Pi: %.10f\n", PI);
    printf("MAX_SIZE: %d\n", MAX_SIZE);
    printf("SQUARE(7) = %d\n", SQUARE(7));
    printf("MIN(10, 20) = %d\n", MIN(10, 20));
    printf("MAX(10, 20) = %d\n", MAX(10, 20));

    printf("\n=== USANDO FUNCIONES DE utilidades.h ===\n");
    imprimir_separador();
    log_debug("03_include_guards.c", 25, "Programa iniciado correctamente");
    imprimir_separador();

    printf("\n=== COMBINANDO HEADERS ===\n");
    int num = 5;
    long fact = factorial(num);
    printf("Factorial de %d = %ld\n", num, fact);

    int primo_test = 17;
    if (es_primo(primo_test)) {
        printf("%d es primo\n", primo_test);
    } else {
        printf("%d NO es primo\n", primo_test);
    }

    printf("\n=== CONVERSION DE TEMPERATURA ===\n");
    double celsius = 36.5;
    printf("%.1f C = %.1f F\n", celsius, CELSIUS_A_FAHRENHEIT(celsius));

    return 0;
}
