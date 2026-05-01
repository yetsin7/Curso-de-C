/*
 * 02_manajo_errores.c
 * Compilar: gcc -Wall -Wextra -std=c11 02_manajo_errores.c -o 02_manajo_errores
 *
 * Ejemplo de manejo profesional de errores en C:
 * - Codigos de retorno (0 = exito, negativo = error)
 * - Mensajes de error con perror
 * - Programacion defensiva y validaciones
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* ============================================================
 * CODIGOS DE ERROR personalizados
 * ============================================================ */

#define ERR_EXITO       0
#define ERR_MEMORIA    -1
#define ERR_ARCHIVO    -2
#define ERR_PARAMETRO  -3
#define ERR_RANGO      -4

/* Retorna una descripcion legible para cada codigo de error */
const char *error_descripcion(int codigo) {
    switch (codigo) {
        case ERR_EXITO:      return "Operacion exitosa";
        case ERR_MEMORIA:    return "Error de asignacion de memoria";
        case ERR_ARCHIVO:    return "Error al abrir archivo";
        case ERR_PARAMETRO:  return "Parametro invalido";
        case ERR_RANGO:      return "Valor fuera de rango permitido";
        default:             return "Error desconocido";
    }
}

/* ============================================================
 * FUNCIONES CON MANEJO DE ERRORES
 * ============================================================ */

/* Asigna memoria dinamica con validacion defensiva */
int buffer_crear(int **buf, int tamano) {
    /* Validacion defensiva: puntero nulo o tamano invalido */
    if (buf == NULL) return ERR_PARAMETRO;
    if (tamano <= 0) return ERR_RANGO;

    *buf = (int *)malloc((size_t)tamano * sizeof(int));
    if (*buf == NULL) {
        perror("[malloc] Fallo al asignar memoria");
        return ERR_MEMORIA;
    }

    /* Inicializar el buffer a cero tras asignacion exitosa */
    memset(*buf, 0, (size_t)tamano * sizeof(int));
    return ERR_EXITO;
}

/* Simula apertura de archivo con manejo de errno */
int archivo_procesar(const char *ruta) {
    if (ruta == NULL) return ERR_PARAMETRO;

    FILE *f = fopen(ruta, "r");
    if (f == NULL) {
        /* perror muestra el mensaje del sistema con errno */
        fprintf(stderr, "[archivo_procesar] No se pudo abrir: %s -- ", ruta);
        perror("");
        return ERR_ARCHIVO;
    }

    printf("[OK] Archivo '%s' abierto correctamente\n", ruta);
    fclose(f);
    return ERR_EXITO;
}

/* Division segura con validacion de parametros */
int division_segura(int a, int b, float *resultado) {
    if (resultado == NULL) return ERR_PARAMETRO;
    if (b == 0) {
        fprintf(stderr, "[ERROR] Division por cero: %d / 0\n", a);
        return ERR_RANGO;
    }

    *resultado = (float)a / (float)b;
    return ERR_EXITO;
}

/* ============================================================
 * FUNCION PRINCIPAL
 * ============================================================ */

int main(void) {
    printf("=== Manejo de Errores en C ===\n\n");

    /* 1. Crear buffer con validacion */
    int *buffer = NULL;
    int rc = buffer_crear(&buffer, 10);
    if (rc != ERR_EXITO) {
        fprintf(stderr, "Fallo: %s\n", error_descripcion(rc));
        return 1;
    }
    printf("[OK] Buffer creado: %s\n", error_descripcion(rc));

    /* 2. Intentar abrir archivo inexistente */
    rc = archivo_procesar("archivo_inexistente.txt");
    if (rc != ERR_EXITO) {
        printf("[INFO] %s\n", error_descripcion(rc));
    }

    /* 3. Division segura */
    float res;
    rc = division_segura(10, 3, &res);
    if (rc == ERR_EXITO) {
        printf("[OK] 10 / 3 = %.2f\n", res);
    }

    rc = division_segura(5, 0, &res);
    if (rc != ERR_EXITO) {
        printf("[INFO] %s\n", error_descripcion(rc));
    }

    /* 4. Caso con parametro nulo */
    rc = division_segura(1, 1, NULL);
    if (rc != ERR_EXITO) {
        printf("[INFO] %s\n", error_descripcion(rc));
    }

    free(buffer);
    printf("\n=== Fin del programa ===\n");
    return 0;
}
