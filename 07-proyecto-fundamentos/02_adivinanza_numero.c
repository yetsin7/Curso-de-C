/*
 * 02_adivinanza_numero.c
 * Juego de adivinanza de numero usando generacion aleatoria.
 *
 * Comando de compilacion:
 *   gcc -Wall -Wextra -std=c11 02_adivinanza_numero.c -o adivinanza_numero
 *
 * Ejecucion:
 *   ./adivinanza_numero
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_MAXIMO 50
#define INTENTOS_SIMULADOS 8

/* Genera un numero aleatorio entre 1 y el limite especificado */
int generar_numero_secreto(int limite) {
    return (rand() % limite) + 1;
}

/* Compara el intento con el numero secreto y devuelve un codigo:
 * -1 = muy bajo, 0 = correcto, 1 = muy alto */
int comparar_intentos(int intento, int secreto) {
    if (intento < secreto) {
        return -1;
    } else if (intento > secreto) {
        return 1;
    }
    return 0;
}

/* Imprime la pista segun el resultado de la comparacion */
void imprimir_pista(int resultado) {
    switch (resultado) {
        case -1:
            printf("  -> El numero secreto es MAYOR.\n");
            break;
        case 1:
            printf("  -> El numero secreto es MENOR.\n");
            break;
        case 0:
            printf("  -> ¡CORRECTO! Lo adivinaste.\n");
            break;
    }
}

int main(void) {
    /* Inicializar generador de numeros aleatorios */
    srand((unsigned int)time(NULL));

    int secreto = generar_numero_secreto(NUMERO_MAXIMO);
    int intento;
    int resultado;
    int acerto = 0;

    /* Intentos simulados (sin scanf para portabilidad) */
    int intentos[] = {25, 40, 45, 47, 49, 48, 50, 0};

    printf("--- Juego: Adivina el Numero ---\n");
    printf("He pensado un numero entre 1 y %d.\n", NUMERO_MAXIMO);
    printf("Intentos simulados:\n\n");

    /* Bucle principal del juego */
    for (int i = 0; i < INTENTOS_SIMULADOS; i++) {
        intento = intentos[i];
        printf("Intento %d: Tu guess es %d\n", i + 1, intento);

        resultado = comparar_intentos(intento, secreto);
        imprimir_pista(resultado);

        if (resultado == 0) {
            acerto = 1;
            printf("\n*** Ganaste en %d intento(s)! ***\n", i + 1);
            break;
        }
        printf("\n");
    }

    if (!acerto) {
        printf("\n*** Game Over. El numero era: %d ***\n", secreto);
    }

    return 0;
}
