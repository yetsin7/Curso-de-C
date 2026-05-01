/*
 * ============================================================
 * Modulo 04 -- Control de Flujo
 * Archivo: 01_condicionales.c
 * ============================================================
 *
 * Este archivo explica como tomar decisiones en C usando:
 *
 *   - if
 *   - else if
 *   - else
 *   - switch
 *
 * Una condicion permite ejecutar una parte del codigo solo cuando
 * una regla se cumple.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o condicionales 01_condicionales.c
 *
 * Ejecutar:
 *   Windows: condicionales.exe
 *   Linux/macOS: ./condicionales
 */

#include <stdio.h>

int main(void) {
    printf("=== CONDICIONALES EN C ===\n\n");

    /*
     * Ejemplo 1: if, else if y else.
     *
     * El programa revisa la nota y muestra una calificacion.
     */
    int nota = 75;

    if (nota >= 90) {
        printf("Calificacion: A\n");
    } else if (nota >= 80) {
        printf("Calificacion: B\n");
    } else if (nota >= 70) {
        printf("Calificacion: C\n");
    } else if (nota >= 60) {
        printf("Calificacion: D\n");
    } else {
        printf("Calificacion: F\n");
    }

    /*
     * Ejemplo 2: operador ternario.
     *
     * Sirve para elegir entre dos valores de forma breve.
     */
    int edad = 20;
    printf("Edad: %d -- %s\n", edad, (edad >= 18) ? "Mayor de edad" : "Menor de edad");

    /*
     * Ejemplo 3: switch.
     *
     * switch es util cuando una variable puede tener varios valores
     * concretos, como dias de la semana u opciones de menu.
     */
    printf("\n=== SWITCH: DIAS ===\n");

    int dia = 3;

    switch (dia) {
        case 1:
            printf("Lunes\n");
            break;
        case 2:
            printf("Martes\n");
            break;
        case 3:
            printf("Miercoles\n");
            break;
        case 4:
            printf("Jueves\n");
            break;
        case 5:
            printf("Viernes\n");
            break;
        case 6:
        case 7:
            printf("Fin de semana\n");
            break;
        default:
            printf("Dia invalido\n");
    }

    /*
     * Ejemplo 4: switch con operaciones.
     */
    printf("\n=== SWITCH: CALCULADORA ===\n");

    char operacion = '+';
    int a = 8;
    int b = 3;

    switch (operacion) {
        case '+':
            printf("%d + %d = %d\n", a, b, a + b);
            break;
        case '-':
            printf("%d - %d = %d\n", a, b, a - b);
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, a * b);
            break;
        case '/':
            printf("%d / %d = %d\n", a, b, a / b);
            break;
        default:
            printf("Operacion desconocida\n");
    }

    /*
     * Ejemplo 5: condiciones anidadas.
     *
     * Una condicion anidada es una condicion dentro de otra.
     */
    printf("\n=== CONDICIONES ANIDADAS ===\n");

    int tieneCuenta = 1;
    int saldo = 50;

    if (tieneCuenta) {
        if (saldo >= 100) {
            printf("Puedes comprar\n");
        } else {
            printf("Saldo insuficiente\n");
        }
    } else {
        printf("Debes crear una cuenta\n");
    }

    return 0;
}
