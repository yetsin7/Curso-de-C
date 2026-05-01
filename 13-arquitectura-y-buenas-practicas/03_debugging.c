/*
 * ============================================================
 * Modulo 13 -- Arquitectura y Buenas Practicas
 * Archivo: 03_debugging.c
 * ============================================================
 *
 * Este archivo explica tecnicas de debugging en C.
 *
 * Debugging significa encontrar, entender y corregir errores en un
 * programa. En C es especialmente importante porque muchos errores pueden
 * estar relacionados con memoria, punteros, indices fuera de rango o datos
 * no inicializados.
 *
 * Tecnicas vistas aqui:
 *
 *   - macros de log
 *   - compilacion condicional con DEBUG
 *   - impresion del estado interno
 *   - aserciones defensivas
 *   - mensajes con archivo y linea
 *
 * Compilar modo normal:
 *   gcc -Wall -Wextra -std=c11 03_debugging.c -o 03_debugging
 *
 * Compilar modo debug:
 *   gcc -Wall -Wextra -std=c11 -DDEBUG 03_debugging.c -o 03_debugging
 */

#include <stdio.h>
#include <stdlib.h>

/* ============================================================
 * MACROS DE DEPURACION
 * ============================================================ */

/*
 * LOG y LOG_VAR solo imprimen cuando DEBUG esta definido.
 */
#ifdef DEBUG
    #define LOG(msg) fprintf(stderr, "[DEBUG] %s (%s:%d)\n", msg, __FILE__, __LINE__)
    #define LOG_VAR(fmt, var) fprintf(stderr, "[DEBUG] %s = " fmt " (%s:%d)\n", #var, var, __FILE__, __LINE__)
#else
    #define LOG(msg)          ((void)0)
    #define LOG_VAR(fmt, var) ((void)0)
#endif

/*
 * ASSERT verifica una condicion. Si la condicion falla, imprime un mensaje
 * y termina el programa con abort().
 */
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

/*
 * Imprime el estado actual de un arreglo.
 */
void estado_array(const int *arr, int tamano, const char *nombre) {
    if (arr == NULL || nombre == NULL || tamano < 0) {
        printf("Estado invalido para imprimir.\n");
        return;
    }

    printf("Estado de '%s': [", nombre);

    for (int i = 0; i < tamano; i++) {
        printf("%d%s", arr[i], (i < tamano - 1) ? ", " : "");
    }

    printf("]\n");
}

/*
 * Busca un valor en un arreglo usando trazas de depuracion.
 */
int buscar_valor(const int *arr, int tamano, int objetivo) {
    LOG("Iniciando busqueda de valor en arreglo");
    LOG_VAR("%d", tamano);
    LOG_VAR("%d", objetivo);

    if (arr == NULL || tamano <= 0) {
        return -1;
    }

    for (int i = 0; i < tamano; i++) {
        LOG_VAR("%d", i);

        if (arr[i] == objetivo) {
            LOG("Valor encontrado");
            return i;
        }
    }

    LOG("Valor no encontrado");
    return -1;
}

/*
 * Calcula el promedio usando aserciones defensivas.
 */
float calcular_promedio(const int *arr, int tamano) {
    ASSERT(arr != NULL, "El puntero del arreglo no puede ser NULL");
    ASSERT(tamano > 0, "El tamano del arreglo debe ser mayor a cero");

    int suma = 0;

    for (int i = 0; i < tamano; i++) {
        suma += arr[i];
        LOG_VAR("%d", suma);
    }

    return (float)suma / (float)tamano;
}

int main(void) {
    printf("=== TECNICAS DE DEBUGGING EN C ===\n\n");

    int datos[] = {10, 25, 30, 42, 18};
    int tamano = sizeof(datos) / sizeof(datos[0]);

    estado_array(datos, tamano, "datos");

    int objetivo = 42;
    int pos = buscar_valor(datos, tamano, objetivo);

    if (pos >= 0) {
        printf("Valor %d encontrado en la posicion %d\n", objetivo, pos);
    } else {
        printf("Valor %d no encontrado\n", objetivo);
    }

    float promedio = calcular_promedio(datos, tamano);
    printf("Promedio del arreglo: %.2f\n", promedio);

    printf("\nBuscando valor 99...\n");

    pos = buscar_valor(datos, tamano, 99);
    printf("Resultado: %d\n", pos);

#ifdef DEBUG
    printf("\n[INFO] Compilado en modo DEBUG. Trazas activas.\n");
#else
    printf("\n[INFO] Compilado en modo normal. Trazas desactivadas.\n");
#endif

    printf("=== Fin del programa ===\n");

    return 0;
}
