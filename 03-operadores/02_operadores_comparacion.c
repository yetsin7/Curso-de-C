/*
 * Modulo 03 -- Operadores de Comparacion
 * Archivo: 02_operadores_comparacion.c
 *
 * Demuestra los operadores de comparacion en C:
 *   - Igualdad (==) y desigualdad (!=)
 *   - Mayor que (>), menor que (<)
 *   - Mayor o igual (>=), menor o igual (<=)
 *   - Error comun: confundir = con ==
 *   - Operador ternario (condicion ? valor_si : valor_no)
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 02_comparacion 02_operadores_comparacion.c
 */

#include <stdio.h>

int main(void) {
    /* Operadores de comparacion basicos */
    printf("=== OPERADORES DE COMPARACION ===\n");

    int x = 7, y = 10;

    printf("x = %d, y = %d\n", x, y);
    printf("%d == %d  => %d (igual)\n", x, y, x == y);
    printf("%d != %d  => %d (distinto)\n", x, y, x != y);
    printf("%d >  %d  => %d (mayor que)\n", x, y, x > y);
    printf("%d <  %d  => %d (menor que)\n", x, y, x < y);
    printf("%d >= %d  => %d (mayor o igual)\n", x, y, x >= y);
    printf("%d <= %d  => %d (menor o igual)\n", x, y, x <= y);

    /* Error comun: = vs == */
    printf("\n--- CUIDADO: = vs == ---\n");

    int a = 5;
    printf("a = %d\n", a);

    /* Comparacion CORRECTA con == */
    printf("a == 5 devuelve: %d\n", a == 5);  /* 1 (verdadero) */
    printf("a == 3 devuelve: %d\n", a == 3);  /* 0 (falso) */

    /* ATENCION: "a = 3" es ASIGNACION, no comparacion!
       Esto modifica el valor de 'a' y devuelve 3 (verdadero) */
    printf("ERROR comun: escribir if(a = 3) en vez de if(a == 3)\n");
    printf("Nunca uses = dentro de una condicion, usa siempre ==\n");

    /* Operador ternario */
    printf("\n=== OPERADOR TERNARIO ===\n");

    int edad = 20;
    /* Sintaxis: condicion ? valor_si_true : valor_si_false */
    const char *mensaje = (edad >= 18) ? "Mayor de edad" : "Menor de edad";
    printf("Con %d anios: %s\n", edad, mensaje);

    /* Encontrar el mayor de dos numeros */
    int p = 15, q = 9;
    int mayor = (p > q) ? p : q;
    int menor = (p < q) ? p : q;
    printf("mayor(%d, %d) = %d\n", p, q, mayor);
    printf("menor(%d, %d) = %d\n", p, q, menor);

    /* Valor absoluto con ternario */
    int num = -7;
    int absoluto = (num < 0) ? -num : num;
    printf("valor absoluto de %d = %d\n", num, absoluto);

    /* Ternario anidado (usar con moderacion) */
    int nota = 85;
    const char *calificacion = (nota >= 90) ? "Excelente"
                              : (nota >= 70) ? "Aprobado"
                              : "Reprobado";
    printf("Nota %d: %s\n", nota, calificacion);

    return 0;
}
