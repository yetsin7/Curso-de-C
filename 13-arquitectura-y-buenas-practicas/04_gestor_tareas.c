/*
 * ============================================================
 * Modulo 13 -- Arquitectura y Buenas Practicas
 * Archivo: 04_gestor_tareas.c
 * ============================================================
 *
 * Este archivo muestra un mini-proyecto: gestor de tareas.
 *
 * El objetivo es aplicar buenas practicas dentro de un programa completo:
 *
 *   - separar datos, logica y presentacion
 *   - usar nombres claros
 *   - validar parametros
 *   - devolver codigos de error
 *   - usar enum para estados
 *   - activar logs solo en modo DEBUG
 *
 * Compilar modo normal:
 *   gcc -Wall -Wextra -std=c11 04_gestor_tareas.c -o 04_gestor_tareas
 *
 * Compilar modo debug:
 *   gcc -Wall -Wextra -std=c11 -DDEBUG 04_gestor_tareas.c -o 04_gestor_tareas
 */

#include <stdio.h>
#include <string.h>

/* ============================================================
 * CONSTANTES Y MACROS DE DEPURACION
 * ============================================================ */

#define MAX_TAREAS      20
#define MAX_DESCRIPCION 100

#ifdef DEBUG
    #define LOG(msg) fprintf(stderr, "[DEBUG] %s (%s:%d)\n", msg, __FILE__, __LINE__)
#else
    #define LOG(msg) ((void)0)
#endif

/* ============================================================
 * CAPA DE DATOS
 * ============================================================ */

typedef enum {
    PENDIENTE,
    EN_PROGRESO,
    COMPLETADA
} EstadoTarea;

typedef struct {
    char descripcion[MAX_DESCRIPCION];
    EstadoTarea estado;
    int id;
} Tarea;

typedef struct {
    Tarea tareas[MAX_TAREAS];
    int total;
} GestorTareas;

/* ============================================================
 * CAPA DE LOGICA
 * ============================================================ */

/*
 * Inicializa el gestor dejandolo vacio.
 */
void gestor_inicializar(GestorTareas *gt) {
    if (gt == NULL) {
        return;
    }

    gt->total = 0;
    memset(gt->tareas, 0, sizeof(gt->tareas));

    LOG("Gestor de tareas inicializado");
}

/*
 * Agrega una nueva tarea.
 *
 * Retorna:
 *   0  exito
 *  -1  parametro invalido
 *  -2  gestor lleno
 *  -3  descripcion vacia
 */
int gestor_agregar(GestorTareas *gt, const char *descripcion) {
    if (gt == NULL || descripcion == NULL) {
        return -1;
    }

    if (gt->total >= MAX_TAREAS) {
        return -2;
    }

    if (strlen(descripcion) == 0) {
        return -3;
    }

    Tarea *t = &gt->tareas[gt->total];

    strncpy(t->descripcion, descripcion, MAX_DESCRIPCION - 1);
    t->descripcion[MAX_DESCRIPCION - 1] = '\0';
    t->estado = PENDIENTE;
    t->id = gt->total + 1;

    gt->total++;

    LOG("Tarea agregada exitosamente");
    return 0;
}

/*
 * Cambia el estado de una tarea por su ID.
 */
int gestor_cambiar_estado(GestorTareas *gt, int id, EstadoTarea nuevo_estado) {
    if (gt == NULL || id <= 0) {
        return -1;
    }

    for (int i = 0; i < gt->total; i++) {
        if (gt->tareas[i].id == id) {
            gt->tareas[i].estado = nuevo_estado;
            LOG("Estado de tarea cambiado");
            return 0;
        }
    }

    return -4;
}

/* ============================================================
 * CAPA DE PRESENTACION
 * ============================================================ */

/*
 * Convierte un estado enum a texto legible.
 */
const char *estado_a_texto(EstadoTarea estado) {
    switch (estado) {
        case PENDIENTE:
            return "Pendiente";
        case EN_PROGRESO:
            return "En Progreso";
        case COMPLETADA:
            return "Completada";
        default:
            return "Desconocido";
    }
}

/*
 * Imprime todas las tareas del gestor.
 */
void gestor_imprimir(const GestorTareas *gt) {
    if (gt == NULL) {
        return;
    }

    printf("\n===== LISTA DE TAREAS (%d) =====\n", gt->total);

    if (gt->total == 0) {
        printf("  No hay tareas registradas.\n");
        printf("=================================\n");
        return;
    }

    for (int i = 0; i < gt->total; i++) {
        const Tarea *t = &gt->tareas[i];
        printf("  [%d] %s -- %s\n", t->id, estado_a_texto(t->estado), t->descripcion);
    }

    printf("=================================\n");
}

int main(void) {
    GestorTareas gt;
    gestor_inicializar(&gt);

    printf("--- Gestor de Tareas ---\n");

    int rc = gestor_agregar(&gt, "Estudiar punteros en C");
    if (rc == 0) {
        printf("[OK] Tarea 1 agregada\n");
    }

    rc = gestor_agregar(&gt, "Practicar structs");
    if (rc == 0) {
        printf("[OK] Tarea 2 agregada\n");
    }

    rc = gestor_agregar(&gt, "Completar modulo 13");
    if (rc == 0) {
        printf("[OK] Tarea 3 agregada\n");
    }

    gestor_cambiar_estado(&gt, 1, EN_PROGRESO);
    gestor_cambiar_estado(&gt, 2, COMPLETADA);

    gestor_imprimir(&gt);

#ifdef DEBUG
    printf("\n[INFO] Modo DEBUG activo\n");
#endif

    return 0;
}
