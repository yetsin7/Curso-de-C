/*
 * Modulo 04 -- Condicionales
 * Archivo: 01_condicionales.c
 *
 * Demuestra las estructuras condicionales en C:
 *   - if / else if / else
 *   - switch / case / default
 *   - Condiciones anidadas
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o condicionales 01_condicionales.c
 */

#include <stdio.h>

int main(void) {
    /* ===== IF / ELSE IF / ELSE ===== */
    printf("=== CONDICIONAL: Calificaciones ===\n");

    int nota = 75;

    if (nota >= 90) {
        printf("Calificacion: A (Excelente)\n");
    } else if (nota >= 80) {
        printf("Calificacion: B (Muy bien)\n");
    } else if (nota >= 70) {
        printf("Calificacion: C (Bien)\n");
    } else if (nota >= 60) {
        printf("Calificacion: D (Suficiente)\n");
    } else {
        printf("Calificacion: F (Reprobado)\n");
    }

    /* Condicional con operador ternario */
    int edad = 20;
    printf("Edad: %d -- %s\n", edad, (edad >= 18) ? "Mayor de edad" : "Menor de edad");

    /* ===== SWITCH / CASE ===== */
    printf("\n=== SWITCH: Dias de la semana ===\n");

    int dia = 3;  /* 1=Lunes, 2=Martes, etc. */

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
            /* Fall-through: sabado y domingo comparten mensaje */
            printf("Fin de semana\n");
            break;
        default:
            printf("Dia invalido\n");
    }

    /* Switch con caracteres */
    printf("\n=== SWITCH: Calculadora basica ===\n");

    char operacion = '+';
    int a = 8, b = 3;

    switch (operacion) {
        case '+': printf("%d + %d = %d\n", a, b, a + b); break;
        case '-': printf("%d - %d = %d\n", a, b, a - b); break;
        case '*': printf("%d * %d = %d\n", a, b, a * b); break;
        case '/': printf("%d / %d = %d\n", a, b, a / b); break;
        default:  printf("Operacion desconocida: %c\n", operacion);
    }

    /* ===== CONDICIONES ANIDADAS ===== */
    printf("\n=== CONDICIONES ANIDADAS: Acceso ===\n");

    int tieneCuenta = 1;  /* 1 = si, 0 = no */
    int saldo = 50;

    if (tieneCuenta) {
        if (saldo >= 100) {
            printf("Acceso completo: puedes comprar\n");
        } else {
            printf("Saldo insuficiente. Necesitas al menos 100\n");
        }
    } else {
        printf("Crea una cuenta para continuar\n");
    }

    return 0;
}
