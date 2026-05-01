/*
 * ============================================================
 * Modulo 13 -- Arquitectura y Buenas Practicas
 * Archivo: 02_manajo_errores.c
 * ============================================================
 *
 * Este archivo explica manejo profesional de errores en C.
 *
 * En C, muchas funciones no lanzan excepciones como en otros lenguajes.
 * Normalmente indican errores usando valores de retorno, punteros NULL,
 * errno o codigos propios.
 *
 * Buenas practicas vistas aqui:
 *
 *   - validar parametros antes de usarlos
 *   - devolver codigos de error claros
 *   - usar perror cuando falla una funcion del sistema
 *   - evitar division por cero
 *   - liberar memoria antes de terminar
 *
 * Nota: el archivo se llama 02_manajo_errores.c porque asi existe en el
 * repositorio. El nombre recomendado seria 02_manejo_errores.c.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 02_manajo_errores.c -o 02_manajo_errores
 *
 * Ejecutar:
 *   Windows: 02_manajo_errores.exe
 *   Linux/macOS: ./02_manajo_errores
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================
 * CODIGOS DE ERROR PERSONALIZADOS
 * ============================================================ */

#define ERR_EXITO       0
#define ERR_MEMORIA    -1
#define ERR_ARCHIVO    -2
#define ERR_PARAMETRO  -3
#define ERR_RANGO      -4

/*
 * Convierte un codigo de error en un mensaje legible.
 */
const char *error_descripcion(int codigo) {
    switch (codigo) {
        case ERR_EXITO:
            return "Operacion exitosa";
        case ERR_MEMORIA:
            return "Error de asignacion de memoria";
        case ERR_ARCHIVO:
            return "Error al abrir archivo";
        case ERR_PARAMETRO:
            return "Parametro invalido";
        case ERR_RANGO:
            return "Valor fuera de rango permitido";
        default:
            return "Error desconocido";
    }
}

/* ============================================================
 * FUNCIONES CON MANEJO DE ERRORES
 * ============================================================ */

/*
 * Reserva memoria para un buffer de enteros.
 *
 * buf es un doble puntero porque la funcion necesita modificar el puntero
 * original que recibe main().
 */
int buffer_crear(int **buf, int tamano) {
    if (buf == NULL) {
        return ERR_PARAMETRO;
    }

    if (tamano <= 0) {
        return ERR_RANGO;
    }

    *buf = malloc((size_t)tamano * sizeof(int));

    if (*buf == NULL) {
        perror("[malloc] Fallo al asignar memoria");
        return ERR_MEMORIA;
    }

    memset(*buf, 0, (size_t)tamano * sizeof(int));

    return ERR_EXITO;
}

/*
 * Intenta abrir un archivo de lectura.
 */
int archivo_procesar(const char *ruta) {
    if (ruta == NULL) {
        return ERR_PARAMETRO;
    }

    FILE *f = fopen(ruta, "r");

    if (f == NULL) {
        fprintf(stderr, "[archivo_procesar] No se pudo abrir: %s -- ", ruta);
        perror("");
        return ERR_ARCHIVO;
    }

    printf("[OK] Archivo '%s' abierto correctamente\n", ruta);
    fclose(f);

    return ERR_EXITO;
}

/*
 * Divide dos numeros de forma segura.
 */
int division_segura(int a, int b, float *resultado) {
    if (resultado == NULL) {
        return ERR_PARAMETRO;
    }

    if (b == 0) {
        fprintf(stderr, "[ERROR] Division por cero: %d / 0\n", a);
        return ERR_RANGO;
    }

    *resultado = (float)a / (float)b;

    return ERR_EXITO;
}

int main(void) {
    printf("=== MANEJO DE ERRORES EN C ===\n\n");

    int *buffer = NULL;
    int rc = buffer_crear(&buffer, 10);

    if (rc != ERR_EXITO) {
        fprintf(stderr, "Fallo: %s\n", error_descripcion(rc));
        return 1;
    }

    printf("[OK] Buffer creado: %s\n", error_descripcion(rc));

    rc = archivo_procesar("archivo_inexistente.txt");

    if (rc != ERR_EXITO) {
        printf("[INFO] %s\n", error_descripcion(rc));
    }

    float res = 0.0f;

    rc = division_segura(10, 3, &res);

    if (rc == ERR_EXITO) {
        printf("[OK] 10 / 3 = %.2f\n", res);
    }

    rc = division_segura(5, 0, &res);

    if (rc != ERR_EXITO) {
        printf("[INFO] %s\n", error_descripcion(rc));
    }

    rc = division_segura(1, 1, NULL);

    if (rc != ERR_EXITO) {
        printf("[INFO] %s\n", error_descripcion(rc));
    }

    free(buffer);
    buffer = NULL;

    printf("\n=== Fin del programa ===\n");

    return 0;
}
