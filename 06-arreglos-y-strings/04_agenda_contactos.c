/*
 * Modulo 06 -- Arreglos y Strings
 * Archivo: 04_agenda_contactos.c
 *
 * Proyecto practico: agenda de contactos usando arreglos de strings.
 * Demuestra: agregar, mostrar y buscar contactos.
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 04_agenda_contactos 04_agenda_contactos.c
 */

#include <stdio.h>
#include <string.h>

#define MAX_CONTACTOS 50
#define MAX_NOMBRE 40
#define MAX_TELEFONO 15

/* Agenda: cada contacto tiene nombre y telefono */
typedef struct {
    char nombre[MAX_NOMBRE];
    char telefono[MAX_TELEFONO];
} Contacto;

/* Registros actuales en la agenda */
int cantidad = 0;

/* Agrega un contacto. Retorna 1 si tuvo exito, 0 si esta lleno */
int agregarContacto(Contacto agenda[], const char *nombre, const char *telefono) {
    if (cantidad >= MAX_CONTACTOS) {
        return 0;
    }
    strncpy(agenda[cantidad].nombre, nombre, MAX_NOMBRE - 1);
    agenda[cantidad].nombre[MAX_NOMBRE - 1] = '\0';
    strncpy(agenda[cantidad].telefono, telefono, MAX_TELEFONO - 1);
    agenda[cantidad].telefono[MAX_TELEFONO - 1] = '\0';
    cantidad++;
    return 1;
}

/* Muestra todos los contactos registrados */
void mostrarContactos(const Contacto agenda[]) {
    if (cantidad == 0) {
        printf("  (agenda vacia)\n");
        return;
    }
    for (int i = 0; i < cantidad; i++) {
        printf("  [%d] %s - %s\n", i + 1, agenda[i].nombre, agenda[i].telefono);
    }
}

/* Busca un contacto por nombre. Retorna el indice o -1 */
int buscarContacto(const Contacto agenda[], const char *nombre) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(agenda[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    Contacto agenda[MAX_CONTACTOS];

    printf("=== AGENDA DE CONTACTOS ===\n\n");

    /* Agregar contactos de ejemplo */
    agregarContacto(agenda, "Ana Garcia", "555-1234");
    agregarContacto(agenda, "Carlos Lopez", "555-5678");
    agregarContacto(agenda, "Maria Torres", "555-9012");

    /* Mostrar todos */
    printf("Contactos registrados:\n");
    mostrarContactos(agenda);

    /* Buscar un contacto */
    printf("\n--- Buscar 'Carlos Lopez' ---\n");
    int pos = buscarContacto(agenda, "Carlos Lopez");
    if (pos >= 0) {
        printf("  Encontrado: %s - %s\n", agenda[pos].nombre, agenda[pos].telefono);
    } else {
        printf("  No encontrado\n");
    }

    /* Buscar uno inexistente */
    printf("\n--- Buscar 'Pedro Ruiz' ---\n");
    pos = buscarContacto(agenda, "Pedro Ruiz");
    if (pos >= 0) {
        printf("  Encontrado: %s - %s\n", agenda[pos].nombre, agenda[pos].telefono);
    } else {
        printf("  No encontrado\n");
    }

    return 0;
}
