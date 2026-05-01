/*
 * ============================================================
 * Modulo 09 -- Structs, Union y Enum
 * Archivo: 03_enum_y_union.c
 * ============================================================
 *
 * Este archivo explica enum y union en C.
 *
 * enum permite crear nombres para valores enteros. Esto hace que el
 * codigo sea mas legible que usar numeros sueltos.
 *
 * union permite guardar diferentes tipos de datos en la misma zona de
 * memoria. Solo debe interpretarse como un tipo a la vez.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 03_enum_y_union 03_enum_y_union.c
 *
 * Ejecutar:
 *   Windows: 03_enum_y_union.exe
 *   Linux/macOS: ./03_enum_y_union
 */

#include <stdio.h>
#include <string.h>

/*
 * Enum para representar dias de la semana.
 *
 * Por defecto, LUNES vale 0, MARTES vale 1, y asi sucesivamente.
 */
typedef enum {
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO
} DiaSemana;

/*
 * Enum para representar estados de una tarea.
 */
typedef enum {
    PENDIENTE,
    EN_PROGRESO,
    COMPLETADA,
    CANCELADA
} EstadoTarea;

/*
 * Union para almacenar un valor usando la misma memoria.
 *
 * Una union no guarda todos estos valores al mismo tiempo de forma segura.
 * Todos comparten el mismo espacio.
 */
typedef union {
    int entero;
    float decimal;
    char texto[20];
} DatoFlexible;

/*
 * Struct que combina una descripcion con un estado.
 */
typedef struct {
    char descripcion[40];
    EstadoTarea estado;
} Tarea;

const char* nombreDia(DiaSemana d);
const char* nombreEstado(EstadoTarea e);
void mostrarTarea(const Tarea *t);
void cambiarEstado(Tarea *t, EstadoTarea nuevo);

int main(void) {
    printf("=== ENUM Y UNION ===\n\n");

    /*
     * Enum basico.
     */
    DiaSemana hoy = MIERCOLES;

    printf("Hoy es: %s\n", nombreDia(hoy));
    printf("LUNES=%d, MARTES=%d, DOMINGO=%d\n", LUNES, MARTES, DOMINGO);

    printf("\n=== MAQUINA DE ESTADOS ===\n");

    /*
     * Una maquina de estados controla en que etapa esta algo.
     */
    Tarea tarea = {"Estructuras en C", PENDIENTE};

    mostrarTarea(&tarea);
    cambiarEstado(&tarea, EN_PROGRESO);
    cambiarEstado(&tarea, COMPLETADA);

    Tarea tarea2 = {"Union y Enum", PENDIENTE};

    cambiarEstado(&tarea2, EN_PROGRESO);
    cambiarEstado(&tarea2, CANCELADA);

    printf("\n=== UNION ===\n");

    DatoFlexible dato;

    /*
     * Primero usamos la union como texto.
     */
    strcpy(dato.texto, "Hola");
    printf("Como texto: %s\n", dato.texto);

    /*
     * Ahora usamos la misma memoria como entero.
     * El valor anterior ya no debe considerarse valido como texto.
     */
    dato.entero = 42;
    printf("Como entero: %d\n", dato.entero);

    /*
     * Ahora usamos la misma memoria como decimal.
     */
    dato.decimal = 3.14f;
    printf("Como decimal: %.2f\n", dato.decimal);

    printf("\n=== TAMANOS CON SIZEOF ===\n");

    printf("sizeof(int):          %zu bytes\n", sizeof(int));
    printf("sizeof(float):        %zu bytes\n", sizeof(float));
    printf("sizeof(char[20]):     %zu bytes\n", sizeof(char[20]));
    printf("sizeof(DatoFlexible): %zu bytes\n", sizeof(DatoFlexible));
    printf("sizeof(EstadoTarea):  %zu bytes\n", sizeof(EstadoTarea));

    return 0;
}

/*
 * Devuelve el nombre de un dia.
 */
const char* nombreDia(DiaSemana d) {
    const char* nombres[] = {
        "Lunes", "Martes", "Miercoles", "Jueves",
        "Viernes", "Sabado", "Domingo"
    };

    return (d >= LUNES && d <= DOMINGO) ? nombres[d] : "Desconocido";
}

/*
 * Devuelve el nombre de un estado.
 */
const char* nombreEstado(EstadoTarea e) {
    switch (e) {
        case PENDIENTE:
            return "Pendiente";
        case EN_PROGRESO:
            return "En Progreso";
        case COMPLETADA:
            return "Completada";
        case CANCELADA:
            return "Cancelada";
        default:
            return "Desconocido";
    }
}

/*
 * Imprime una tarea con su estado actual.
 */
void mostrarTarea(const Tarea *t) {
    printf("  Tarea: %-25s | Estado: %s\n", t->descripcion, nombreEstado(t->estado));
}

/*
 * Cambia el estado de una tarea y muestra la transicion.
 */
void cambiarEstado(Tarea *t, EstadoTarea nuevo) {
    printf("  '%s': %s -> %s\n",
           t->descripcion, nombreEstado(t->estado), nombreEstado(nuevo));

    t->estado = nuevo;
}
