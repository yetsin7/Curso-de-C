/*
 * Modulo 05 — Paso por Valor y Referencia
 * Compilar: gcc -Wall -Wextra -std=c11 -o 02_valor 02_paso_por_valor.c
 *
 * Temas: paso por valor (copias), paso por puntero (modifica original), swap.
 */

#include <stdio.h>

/* --- Prototipos --- */

/* Intenta modificar una copia (no afecta al original) */
void intentar_cambiar(int numero);

/* Modifica el valor original usando puntero */
void cambiar_real(int *numero);

/* Intercambia dos valores usando punteros */
void intercambiar(int *a, int *b);

/* --- Funcion principal --- */

int main(void) {
    printf("=== PASO POR VALOR ===\n");

    int x = 10;
    printf("x antes de intentar_cambiar: %d\n", x);
    intentar_cambiar(x);
    printf("x despues de intentar_cambiar: %d (no cambio)\n\n", x);

    printf("=== PASO POR REFERENCIA ===\n");

    int y = 10;
    printf("y antes de cambiar_real: %d\n", y);
    cambiar_real(&y);
    printf("y despues de cambiar_real: %d (si cambio)\n\n", y);

    printf("=== INTERCAMBIAR VALORES ===\n");

    int a = 100, b = 200;
    printf("Antes: a = %d, b = %d\n", a, b);
    intercambiar(&a, &b);
    printf("Despues: a = %d, b = %d\n", a, b);

    return 0;
}

/* --- Implementaciones --- */

/*
 * intentar_cambiar — Recibe una COPIA del valor.
 * La variable original en main() no se modifica.
 * Recibe: numero como entero (copia).
 * Retorna: nada.
 */
void intentar_cambiar(int numero) {
    numero = 99;  /* Solo modifica la copia local */
}

/*
 * cambiar_real — Recibe la DIRECCION de memoria.
 * Usa * para acceder y modificar el valor real.
 * Recibe: puntero a entero.
 * Retorna: nada (modifica el original).
 */
void cambiar_real(int *numero) {
    *numero = 99;  /* Modifica el valor en la direccion original */
}

/*
 * intercambiar — Intercambia dos enteros via punteros.
 * Recibe: punteros a los dos enteros.
 * Retorna: nada (modifica ambos originales).
 */
void intercambiar(int *a, int *b) {
    int temporal = *a;
    *a = *b;
    *b = temporal;
}
