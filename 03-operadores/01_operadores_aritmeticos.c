/*
 * Modulo 03 -- Operadores Aritmeticos
 * Archivo: 01_operadores_aritmeticos.c
 *
 * Demuestra los operadores aritmeticos en C:
 *   - Suma, resta, multiplicacion, division y modulo
 *   - Division entera vs division flotante
 *   - Asignacion compuesta (+=, -=, *=, /=)
 *   - Incremento y decremento (++, --)
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 01_aritmeticos 01_operadores_aritmeticos.c
 */

#include <stdio.h>

int main(void) {
    /* Operadores aritmeticos basicos */
    printf("=== OPERADORES ARITMETICOS ===\n");

    int a = 10, b = 3;

    printf("%d + %d = %d\n", a, b, a + b);   /* Suma */
    printf("%d - %d = %d\n", a, b, a - b);   /* Resta */
    printf("%d * %d = %d\n", a, b, a * b);   /* Multiplicacion */
    printf("%d / %d = %d (division entera)\n", a, b, a / b);
    printf("%d %% %d = %d (modulo/residuo)\n", a, b, a % b);

    /* Division entera vs division flotante */
    printf("\n--- Division entera vs flotante ---\n");
    printf("5 / 2 (enteros) = %d\n", 5 / 2);           /* Resultado: 2 */
    printf("5.0 / 2 (flotante) = %.2f\n", 5.0 / 2);    /* Resultado: 2.50 */
    printf("(double)5 / 2 (cast) = %.2f\n", (double)5 / 2);

    /* Asignacion compuesta */
    printf("\n=== ASIGNACION COMPUESTA ===\n");

    int x = 10;
    printf("x inicial = %d\n", x);

    x += 5;
    printf("x += 5  => %d\n", x);  /* x = x + 5 */

    x -= 3;
    printf("x -= 3  => %d\n", x);  /* x = x - 3 */

    x *= 2;
    printf("x *= 2  => %d\n", x);  /* x = x * 2 */

    x /= 4;
    printf("x /= 4  => %d\n", x);  /* x = x / 4 */

    /* Incremento y decremento */
    printf("\n=== INCREMENTO Y DECREMENTO ===\n");

    int n = 5;
    printf("n = %d\n", n);

    /* Post-incremento: usa el valor, luego incrementa */
    printf("n++ = %d (valor antes de incrementar)\n", n++);
    printf("despues de n++, n = %d\n", n);

    /* Pre-incremento: incrementa primero, luego usa el valor */
    printf("++n = %d (valor despues de incrementar)\n", ++n);

    /* Post-decremento */
    int m = 10;
    printf("m = %d, m-- = %d, luego m = %d\n", m, m--, m);

    /* Pre-decremento */
    printf("m = %d, --m = %d\n", m, --m);

    return 0;
}
