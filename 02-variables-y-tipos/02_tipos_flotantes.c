/*
 * Modulo 02 - Tipos Flotantes
 * Compilar: gcc -Wall -Wextra -std=c11 -o 02_tipos_flotantes 02_tipos_flotantes.c
 *
 * Explora los tipos de punto flotante: float, double y long double.
 * Muestra diferencias de precision, limites desde float.h y
 * especificadores de formato para imprimir con distintos decimales.
 */

#include <stdio.h>
#include <float.h>

int main(void) {
    printf("=== MODULO 02 - TIPOS FLOTANTES ===\n\n");

    /* --- float --- */
    printf("--- float (precision simple) ---\n");

    float f_temp = 36.6f;
    float f_pi = 3.14159265358979323846f;

    printf("Temperatura float: %.2f\n", f_temp);
    printf("Pi float:          %.2f\n", f_pi);
    printf("Pi float (10 dec): %.10f\n", f_pi);

    /* --- double --- */
    printf("\n--- double (precision doble) ---\n");

    double d_temp = 36.6;
    double d_pi = 3.14159265358979323846;

    printf("Temperatura double: %.2f\n", d_temp);
    printf("Pi double:          %.2f\n", d_pi);
    printf("Pi double (10 dec): %.10f\n", d_pi);

    /* --- long double --- */
    printf("\n--- long double (precision extendida) ---\n");

    long double ld_pi = 3.14159265358979323846L;

    printf("Pi long double:     %.2Lf\n", ld_pi);
    printf("Pi long double(10d):%.10Lf\n", ld_pi);
    printf("Pi long double(20d):%.20Lf\n", ld_pi);

    /* --- Comparacion de precision --- */
    printf("\n--- Comparacion de precision ---\n");

    float f_val = 1.0f / 3.0f;
    double d_val = 1.0 / 3.0;

    printf("1/3 como float:  %.10f\n", f_val);
    printf("1/3 como double: %.10f\n", d_val);

    /* --- Tamano de tipos flotantes --- */
    printf("\n--- Tamano en bytes ---\n");

    printf("sizeof(float):       %zu bytes\n", sizeof(float));
    printf("sizeof(double):      %zu bytes\n", sizeof(double));
    printf("sizeof(long double): %zu bytes\n", sizeof(long double));

    /* --- Valores maximos --- */
    printf("\n--- Valores maximos ---\n");

    printf("FLT_MAX:  %e\n", FLT_MAX);
    printf("DBL_MAX:  %e\n", DBL_MAX);
    printf("LDBL_MAX: %Le\n", LDBL_MAX);

    /* --- Precision en digitos --- */
    printf("\n--- Digitos de precision ---\n");

    printf("FLT_DIG:  %d digitos significativos\n", FLT_DIG);
    printf("DBL_DIG:  %d digitos significativos\n", DBL_DIG);
    printf("LDBL_DIG: %d digitos significativos\n", LDBL_DIG);

    return 0;
}
