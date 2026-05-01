/*
 * ============================================================
 * Modulo 07 -- Proyecto Fundamentos
 * Archivo: 02_adivinanza_numero.c
 * ============================================================
 *
 * Este archivo muestra un proyecto practico: un juego de adivinanza.
 *
 * El programa genera un numero secreto y compara varios intentos contra
 * ese numero. Despues indica si el intento fue muy bajo, muy alto o correcto.
 *
 * Este proyecto repasa:
 *
 *   - funciones
 *   - constantes con #define
 *   - numeros aleatorios con rand
 *   - condicionales if / else if / else
 *   - switch
 *   - bucles for
 *   - break
 *   - arreglos
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 02_adivinanza_numero.c -o adivinanza_numero
 *
 * Ejecutar:
 *   Windows: adivinanza_numero.exe
 *   Linux/macOS: ./adivinanza_numero
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_MAXIMO 50
#define INTENTOS_SIMULADOS 8

/*
 * Genera un numero aleatorio entre 1 y limite.
 *
 * rand() genera un numero pseudoaleatorio.
 * El operador modulo limita el rango.
 */
int generar_numero_secreto(int limite) {
    return (rand() % limite) + 1;
}

/*
 * Compara el intento contra el numero secreto.
 *
 * Devuelve:
 *   -1 si el intento es menor que el secreto
 *    0 si el intento es correcto
 *    1 si el intento es mayor que el secreto
 */
int comparar_intentos(int intento, int secreto) {
    if (intento < secreto) {
        return -1;
    } else if (intento > secreto) {
        return 1;
    }

    return 0;
}

/*
 * Imprime una pista segun el resultado de la comparacion.
 */
void imprimir_pista(int resultado) {
    switch (resultado) {
        case -1:
            printf("  -> El numero secreto es MAYOR.\n");
            break;
        case 1:
            printf("  -> El numero secreto es MENOR.\n");
            break;
        case 0:
            printf("  -> CORRECTO. Lo adivinaste.\n");
            break;
        default:
            printf("  -> Resultado desconocido.\n");
    }
}

int main(void) {
    /*
     * srand inicializa el generador de numeros aleatorios.
     * time(NULL) ayuda a que el numero cambie en cada ejecucion.
     */
    srand((unsigned int)time(NULL));

    int secreto = generar_numero_secreto(NUMERO_MAXIMO);
    int intento;
    int resultado;
    int acerto = 0;

    /*
     * Intentos simulados.
     *
     * Para mantener el ejemplo simple y facil de ejecutar, no usamos scanf.
     * En una version interactiva, estos valores podrian pedirse al usuario.
     */
    int intentos[] = {25, 40, 45, 47, 49, 48, 50, 0};

    printf("--- Juego: Adivina el Numero ---\n");
    printf("He pensado un numero entre 1 y %d.\n", NUMERO_MAXIMO);
    printf("Intentos simulados:\n\n");

    for (int i = 0; i < INTENTOS_SIMULADOS; i++) {
        intento = intentos[i];

        printf("Intento %d: probando %d\n", i + 1, intento);

        resultado = comparar_intentos(intento, secreto);
        imprimir_pista(resultado);

        if (resultado == 0) {
            acerto = 1;
            printf("\nGanaste en %d intento(s)!\n", i + 1);
            break;
        }

        printf("\n");
    }

    if (!acerto) {
        printf("\nGame Over. El numero era: %d\n", secreto);
    }

    return 0;
}
