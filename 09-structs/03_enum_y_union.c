/*
 * Modulo 09 — Enum y Union
 * Archivo: 03_enum_y_union.c
 *
 * Demuestra:
 *   - Enum para constantes con nombre
 *   - Union para memoria compartida
 *   - Comparacion de sizeof
 *   - Maquina de estados practica con enum
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 03_enum_y_union 03_enum_y_union.c
 */

#include <stdio.h>
#include <string.h>

/* Enum para dias de la semana */
typedef enum {
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO
} DiaSemana;

/* Enum para estados de una tarea */
typedef enum {
    PENDIENTE,
    EN_PROGRESO,
    COMPLETADA,
    CANCELADA
} EstadoTarea;

/* Union para almacenar un valor en diferentes formatos */
typedef union {
    int entero;
    float decimal;
    char texto[20];
} DatoFlexible;

/* Estructura que combina enum y datos */
typedef struct {
    char descripcion[40];
    EstadoTarea estado;
} Tarea;

/* Prototipos */
const char* nombreDia(DiaSemana d);
const char* nombreEstado(EstadoTarea e);
void mostrarTarea(const Tarea *t);
void cambiarEstado(Tarea *t, EstadoTarea nuevo);

int main(void) {
    printf("=== ENUM Y UNION ===\n\n");

    /* --- 1. Enum basico --- */
    DiaSemana hoy = MIERCOLES;
    printf("Hoy es: %s\n", nombreDia(hoy));

    /* Los enum son enteros por debajo */
    printf("LUNES=%d, MARTES=%d, DOMINGO=%d\n", LUNES, MARTES, DOMINGO);

    /* --- 2. Maquina de estados con enum --- */
    printf("\n=== MAQUINA DE ESTADOS ===\n");

    Tarea tarea = {"Estructuras en C", PENDIENTE};
    mostrarTarea(&tarea);

    cambiarEstado(&tarea, EN_PROGRESO);
    cambiarEstado(&tarea, COMPLETADA);

    Tarea tarea2 = {"Union y Enum", PENDIENTE};
    cambiarEstado(&tarea2, EN_PROGRESO);
    cambiarEstado(&tarea2, CANCELADA);

    /* --- 3. Union — memoria compartida --- */
    printf("\n=== UNION ===\n");

    DatoFlexible dato;

    strcpy(dato.texto, "Hola");
    printf("Como texto: %s\n", dato.texto);

    dato.entero = 42;
    printf("Como entero: %d\n", dato.entero);

    dato.decimal = 3.14f;
    printf("Como decimal: %.2f\n", dato.decimal);

    /* --- 4. Comparacion de tamaños --- */
    printf("\n=== TAMAÑOS CON SIZEOF ===\n");
    printf("sizeof(int):       %zu bytes\n", sizeof(int));
    printf("sizeof(float):     %zu bytes\n", sizeof(float));
    printf("sizeof(char[20]):  %zu bytes\n", sizeof(char[20]));
    printf("sizeof(DatoFlexible): %zu bytes (toma el mayor)\n", sizeof(DatoFlexible));
    printf("sizeof(EstadoTarea):  %zu bytes (es un int)\n", sizeof(EstadoTarea));

    return 0;
}

/* Devuelve el nombre del dia como cadena */
const char* nombreDia(DiaSemana d) {
    const char* nombres[] = {"Lunes", "Martes", "Miercoles",
                             "Jueves", "Viernes", "Sabado", "Domingo"};
    return (d >= LUNES && d <= DOMINGO) ? nombres[d] : "Desconocido";
}

/* Devuelve el nombre del estado como cadena */
const char* nombreEstado(EstadoTarea e) {
    switch (e) {
        case PENDIENTE:    return "Pendiente";
        case EN_PROGRESO:  return "En Progreso";
        case COMPLETADA:   return "Completada";
        case CANCELADA:    return "Cancelada";
        default:           return "Desconocido";
    }
}

/* Imprime una tarea con su estado */
void mostrarTarea(const Tarea *t) {
    printf("  Tarea: %-25s | Estado: %s\n", t->descripcion, nombreEstado(t->estado));
}

/* Cambia el estado y muestra la transicion */
void cambiarEstado(Tarea *t, EstadoTarea nuevo) {
    printf("  '%s': %s -> %s\n", t->descripcion,
           nombreEstado(t->estado), nombreEstado(nuevo));
    t->estado = nuevo;
}
