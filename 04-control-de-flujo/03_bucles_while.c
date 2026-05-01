/*
 * Modulo 04 -- Bucles while y do-while
 * Archivo: 03_bucles_while.c
 *
 * Demuestra los bucles while y do-while en C:
 *   - Bucle while
 *   - Bucle do-while
 *   - Sentencias break y continue
 *   - Bucles con condiciones compuestas
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o bucles_while 03_bucles_while.c
 */

#include <stdio.h>

int main(void) {
    /* ===== BUCLE WHILE BASICO ===== */
    printf("=== Suma de 1 a 100 (while) ===\n");

    int suma = 0;
    int n = 1;

    while (n <= 100) {
        suma += n;
        n++;
    }

    printf("Resultado: %d\n", suma);

    /* ===== POTENCIAS CON WHILE ===== */
    printf("\n=== Potencias de 2 hasta 1000 ===\n");

    int potencia = 1;

    while (potencia <= 1000) {
        printf("%d ", potencia);
        potencia *= 2;
    }
    printf("\n");

    /* ===== BUCLE DO-WHILE ===== */
    printf("\n=== Validacion con do-while ===\n");

    /* Simulamos validacion: el usuario ingresa un numero del 1 al 10 */
    int numero = 15;  /* Valor invalido inicial para demostrar el bucle */

    do {
        printf("Ingresa un numero valido (1-10): ");
        numero = 5;  /* Simulamos entrada del usuario */
        if (numero < 1 || numero > 10) {
            printf("Numero invalido, intenta de nuevo\n");
        }
    } while (numero < 1 || numero > 10);

    printf("Numero valido: %d\n", numero);

    /* ===== DO-WHILE CON CONTADOR ===== */
    printf("\n=== Iteraciones con do-while ===\n");

    int contador = 1;

    do {
        printf("Iteracion %d\n", contador);
        contador++;
    } while (contador <= 3);

    /* ===== BREAK EN WHILE ===== */
    printf("\n=== Busqueda con break ===\n");

    int valor = 1;

    while (valor <= 100) {
        if (valor % 13 == 0) {
            printf("Primer multiplo de 13 encontrado: %d\n", valor);
            break;
        }
        valor++;
    }

    /* ===== CONTINUE EN WHILE ===== */
    printf("\n=== Numeros impares con continue ===\n");

    int i = 1;

    while (i <= 15) {
        if (i % 2 == 0) {
            i++;
            continue;  /* Salta los pares */
        }
        printf("%d ", i);
        i++;
    }
    printf("\n");

    /* ===== CONDICIONES COMPUESTAS ===== */
    printf("\n=== Juego de adivinanza (simulado) ===\n");

    int secreto = 7;
    int intento = 1;
    int maxIntentos = 3;

    while (intento <= maxIntentos) {
        /* Simulamos un intento */
        int adivinanza = 3 + intento;

        if (adivinanza == secreto) {
            printf("Adivinaste en el intento %d!\n", intento);
            break;
        }

        printf("Intento %d: adivinaste %d (incorrecto)\n", intento, adivinanza);
        intento++;
    }

    if (intento > maxIntentos) {
        printf("Se acabaron los intentos. El numero era %d\n", secreto);
    }

    return 0;
}
