/*
 * ============================================================
 * Modulo 03 -- Operadores
 * Archivo: 02_operadores_comparacion.c
 * ============================================================
 *
 * Objetivo de este archivo
 * ------------------------
 * Este programa explica los operadores de comparacion en C.
 *
 * Los operadores de comparacion sirven para comparar valores.
 * El resultado de una comparacion es verdadero o falso.
 *
 * En C, normalmente:
 *
 *   1 significa verdadero.
 *   0 significa falso.
 *
 * ------------------------------------------------------------
 * Operadores de comparacion
 * ------------------------------------------------------------
 *
 *   ==  igual a
 *   !=  diferente de
 *   >   mayor que
 *   <   menor que
 *   >=  mayor o igual que
 *   <=  menor o igual que
 *
 * ------------------------------------------------------------
 * Cuidado importante
 * ------------------------------------------------------------
 *
 * En C, = y == NO significan lo mismo.
 *
 *   =   asigna un valor.
 *   ==  compara dos valores.
 *
 * Ejemplo:
 *
 *   edad = 18;   asigna 18 a edad.
 *   edad == 18;  pregunta si edad vale 18.
 *
 * ------------------------------------------------------------
 * Compilar
 * ------------------------------------------------------------
 *
 *   gcc -Wall -Wextra -std=c11 -o 02_comparacion 02_operadores_comparacion.c
 *
 * Ejecutar en Windows:
 *
 *   02_comparacion.exe
 *
 * Ejecutar en Linux/macOS:
 *
 *   ./02_comparacion
 *
 */

#include <stdio.h>

int main(void) {
    printf("=== OPERADORES DE COMPARACION ===\n");

    int x = 7;
    int y = 10;

    printf("x = %d, y = %d\n", x, y);

    /*
     * Cada comparacion imprime 1 si es verdadera y 0 si es falsa.
     */
    printf("%d == %d  => %d (igual)\n", x, y, x == y);
    printf("%d != %d  => %d (distinto)\n", x, y, x != y);
    printf("%d >  %d  => %d (mayor que)\n", x, y, x > y);
    printf("%d <  %d  => %d (menor que)\n", x, y, x < y);
    printf("%d >= %d  => %d (mayor o igual)\n", x, y, x >= y);
    printf("%d <= %d  => %d (menor o igual)\n", x, y, x <= y);

    /*
     * Diferencia entre asignacion y comparacion.
     */
    printf("\n--- CUIDADO: = vs == ---\n");

    int a = 5;
    printf("a inicia con valor %d\n", a);

    printf("a == 5 devuelve: %d\n", a == 5);
    printf("a == 3 devuelve: %d\n", a == 3);

    /*
     * Nunca confundas:
     *
     *   if (a = 3)   -> asigna 3 a a. Esto casi siempre es un error.
     *   if (a == 3)  -> compara si a vale 3. Esto es lo correcto.
     *
     * Muchos compiladores muestran una advertencia si usas = dentro
     * de una condicion. Por eso usamos -Wall -Wextra.
     */
    printf("Usa == para comparar. Usa = solo para asignar.\n");

    /*
     * Operador ternario.
     *
     * Sirve para elegir entre dos valores usando una condicion.
     *
     * Sintaxis:
     *
     *   condicion ? valor_si_verdadero : valor_si_falso
     */
    printf("\n=== OPERADOR TERNARIO ===\n");

    int edad = 20;
    const char *mensaje = (edad >= 18) ? "Mayor de edad" : "Menor de edad";
    printf("Con %d anios: %s\n", edad, mensaje);

    /*
     * Encontrar el mayor y el menor entre dos numeros.
     */
    int p = 15;
    int q = 9;

    int mayor = (p > q) ? p : q;
    int menor = (p < q) ? p : q;

    printf("mayor(%d, %d) = %d\n", p, q, mayor);
    printf("menor(%d, %d) = %d\n", p, q, menor);

    /*
     * Valor absoluto:
     * Si el numero es negativo, lo multiplicamos por -1.
     * Si no es negativo, lo dejamos igual.
     */
    int num = -7;
    int absoluto = (num < 0) ? -num : num;
    printf("valor absoluto de %d = %d\n", num, absoluto);

    /*
     * El ternario puede anidarse, pero no conviene abusar.
     * Si la expresion se vuelve dificil de leer, es mejor usar if/else.
     */
    int nota = 85;
    const char *calificacion = (nota >= 90) ? "Excelente"
                              : (nota >= 70) ? "Aprobado"
                              : "Reprobado";

    printf("Nota %d: %s\n", nota, calificacion);

    return 0;
}
