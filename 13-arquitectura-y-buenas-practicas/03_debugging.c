/*
 * 03_debugging.c
 * Compilar modo normal:  gcc -Wall -Wextra -std=c11 03_debugging.c -o 03_debugging
 * Compilar modo debug:   gcc -Wall -Wextra -std=c11 -DDEBUG 03_debugging.c -o 03_debugging
 *
 * Tecnicas de depuracion en C:
 * - Macros LOG y ASSERT para mensajes condicionales
 * - Compilacion condicional con #ifdef DEBUG
 * - Impresion de estado para diagnostico
 * - Estrategias comunes de debugging
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* ============================================================
 * MACROS DE DEPURACION
 * ============================================================ */

/* Macro LOG: imprime solo si DEBUG esta definido */
#ifdef DEBUG
    #define LOG(msg) fprintf(stderr, "[DEBUG] %s (%s:%d)\n", msg, __FILE__, __LINE__)
    #define LOG_VAR(fmt, var) fprintf(stderr, "[DEBUG] %s = " fmt " (%s:%d)\n", #var, var, __FILE__, __LINE__)
#else
    #define LOG(msg)           ((void)0)
    #define LOG_VAR(fmt, var)  ((void)0)
#endif

/* Macro ASSERT personalizada con mensaje descriptivo */
#define ASSERT(cond, msg) \
    do { \
        if (!(cond)) { \
            fprintf(stderr, "[ASSERT FALLIDO] %s en %s:%d -- %s\n", \
                    #cond, __FILE__, __LINE__, msg); \
            abort(); \
        } \
    } while (0)

/* ============================================================
 * FUNCIONES DE DIAGNOSTICO
 * ============================================================ */

/* Imprime el estado actual de un array para inspeccion visual */
void estado_array(const int *arr, int tamano, const char *nombre) {
    printf("Estado de '%s': [", nombre);
    for (int i = 0; i < tamano; i++) {
        printf("%d%s", arr[i], (i < tamano - 1) ? ", " : "");
    }
    printf("]\n");
}

/* Busca un valor en un array con trazas de depuracion */
int buscar_valor(const int *arr, int tamano, int objetivo) {
    LOG("Iniciando busqueda de valor en array");
    LOG_VAR("%d", tamano);
    LOG_VAR("%d", objetivo);

    for (int i = 0; i < tamano; i++) {
        LOG_VAR("%d", i);
        if (arr[i] == objetivo) {
            LOG("Valor encontrado, retornando indice");
            return i;
        }
    }

    LOG("Valor no encontrado, retornando -1");
    return -1;
}

/* Calcula el promedio de un array con aserciones defensivas */
float calcular_promedio(const int *arr, int tamano) {
    /* Aserciones que solo se ejecutan en modo debug */
    ASSERT(arr != NULL, "El puntero del array no puede ser nulo");
    ASSERT(tamano > 0, "El tamano del array debe ser mayor a cero");

    int suma = 0;
    for (int i = 0; i < tamano; i++) {
        suma += arr[i];
        LOG_VAR("%d", suma);
    }

    return (float)suma / (float)tamano;
}

/* ============================================================
 * FUNCION PRINCIPAL
 * ============================================================ */

int main(void) {
    printf("=== Tecnicas de Debugging en C ===\n\n");

    int datos[] = {10, 25, 30, 42, 18};
    int tamano = sizeof(datos) / sizeof(datos[0]);

    /* Mostrar estado inicial */
    estado_array(datos, tamano, "datos");

    /* Ejemplo de busqueda con trazas */
    int objetivo = 42;
    int pos = buscar_valor(datos, tamano, objetivo);
    if (pos >= 0) {
        printf("Valor %d encontrado en la posicion %d\n", objetivo, pos);
    } else {
        printf("Valor %d no encontrado\n", objetivo);
    }

    /* Ejemplo de promedio con aserciones */
    float promedio = calcular_promedio(datos, tamano);
    printf("Promedio del array: %.2f\n", promedio);

    /* Buscar valor inexistente */
    printf("\nBuscando valor 99...\n");
    pos = buscar_valor(datos, tamano, 99);
    printf("Resultado: %d\n", pos);

#ifdef DEBUG
    printf("\n[INFO] Compilado en modo DEBUG -- trazas activas\n");
#else
    printf("\n[INFO] Compilado en modo normal -- trazas desactivadas\n");
#endif

    printf("=== Fin del programa ===\n");
    return 0;
}
