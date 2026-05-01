/*
 * Modulo 04 -- Menu Interactivo
 * Archivo: 04_menu_interactivo.c
 *
 * Proyecto practico: sistema de menu interactivo.
 * Combina switch, do-while, if/else y bucles for.
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o menu_interactivo 04_menu_interactivo.c
 */

#include <stdio.h>

/* Muestra las opciones del menu principal */
void mostrarMenu(void) {
    printf("\n===== MENU PRINCIPAL =====\n");
    printf("1. Contar hasta N\n");
    printf("2. Calcular factorial\n");
    printf("3. Ver tabla de multiplicar\n");
    printf("4. Verificar si es primo\n");
    printf("5. Salir\n");
    printf("==========================\n");
    printf("Elige una opcion: ");
}

/* Opcion 1: Cuenta del 1 al N */
void contarHastaN(void) {
    int n;
    printf("Ingresa un numero: ");
    scanf("%d", &n);

    printf("Contando del 1 al %d: ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

/* Opcion 2: Calcula el factorial de N */
void calcularFactorial(void) {
    int n;
    printf("Ingresa un numero positivo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("No existe factorial de numeros negativos\n");
        return;
    }

    long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }

    printf("Factorial de %d = %ld\n", n, resultado);
}

/* Opcion 3: Muestra la tabla de multiplicar */
void verTablaMultiplicar(void) {
    int n;
    printf("Ingresa un numero: ");
    scanf("%d", &n);

    printf("Tabla del %d:\n", n);
    for (int i = 1; i <= 10; i++) {
        printf("  %d x %2d = %2d\n", n, i, n * i);
    }
}

/* Opcion 4: Verifica si un numero es primo */
void verificarPrimo(void) {
    int n;
    printf("Ingresa un numero: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("%d no es primo\n", n);
        return;
    }

    int esPrimo = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            esPrimo = 0;
            break;
        }
    }

    if (esPrimo) {
        printf("%d es primo\n", n);
    } else {
        printf("%d no es primo\n", n);
    }
}

int main(void) {
    int opcion = 0;

    printf("Bienvenido al programa de Control de Flujo\n");

    /* El do-while garantiza que el menu se muestra al menos una vez */
    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                contarHastaN();
                break;
            case 2:
                calcularFactorial();
                break;
            case 3:
                verTablaMultiplicar();
                break;
            case 4:
                verificarPrimo();
                break;
            case 5:
                printf("Saliendo del programa. Hasta luego!\n");
                break;
            default:
                printf("Opcion no valida. Intenta de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}
