/*
 * ============================================================
 * Modulo 06 -- Arreglos y Strings
 * Archivo: 04_agenda_contactos.c
 * ============================================================
 *
 * Este archivo muestra un proyecto practico: una agenda de contactos.
 *
 * La agenda usa varios conceptos importantes:
 *
 *   - arreglos para guardar varios contactos
 *   - strings para guardar nombres y telefonos
 *   - struct para agrupar datos relacionados
 *   - funciones para organizar el programa
 *   - strcmp para comparar strings
 *   - strncpy para copiar strings de forma controlada
 *
 * Aunque struct se estudia con mas detalle despues, aqui se usa de forma
 * sencilla para representar un contacto con nombre y telefono.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 04_agenda_contactos 04_agenda_contactos.c
 *
 * Ejecutar:
 *   Windows: 04_agenda_contactos.exe
 *   Linux/macOS: ./04_agenda_contactos
 */

#include <stdio.h>
#include <string.h>

#define MAX_CONTACTOS 50
#define MAX_NOMBRE 40
#define MAX_TELEFONO 15

/*
 * Un contacto tiene dos datos:
 * - nombre
 * - telefono
 *
 * Cada dato se guarda como un arreglo de caracteres.
 */
typedef struct {
    char nombre[MAX_NOMBRE];
    char telefono[MAX_TELEFONO];
} Contacto;

/*
 * cantidad indica cuantos contactos hay actualmente en la agenda.
 */
int cantidad = 0;

/*
 * Agrega un contacto a la agenda.
 *
 * Devuelve 1 si se agrego correctamente.
 * Devuelve 0 si la agenda esta llena.
 */
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

/*
 * Muestra todos los contactos registrados.
 */
void mostrarContactos(const Contacto agenda[]) {
    if (cantidad == 0) {
        printf("  (agenda vacia)\n");
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        printf("  [%d] %s - %s\n", i + 1, agenda[i].nombre, agenda[i].telefono);
    }
}

/*
 * Busca un contacto por nombre.
 *
 * strcmp devuelve 0 cuando dos strings tienen el mismo contenido.
 */
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

    /*
     * Agregamos contactos de ejemplo.
     *
     * En una version mas avanzada, estos datos podrian pedirse al usuario.
     */
    agregarContacto(agenda, "Ana Garcia", "555-1234");
    agregarContacto(agenda, "Carlos Lopez", "555-5678");
    agregarContacto(agenda, "Maria Torres", "555-9012");

    printf("Contactos registrados:\n");
    mostrarContactos(agenda);

    /*
     * Buscar un contacto existente.
     */
    printf("\n--- Buscar 'Carlos Lopez' ---\n");

    int pos = buscarContacto(agenda, "Carlos Lopez");

    if (pos >= 0) {
        printf("  Encontrado: %s - %s\n", agenda[pos].nombre, agenda[pos].telefono);
    } else {
        printf("  No encontrado\n");
    }

    /*
     * Buscar un contacto que no existe.
     */
    printf("\n--- Buscar 'Pedro Ruiz' ---\n");

    pos = buscarContacto(agenda, "Pedro Ruiz");

    if (pos >= 0) {
        printf("  Encontrado: %s - %s\n", agenda[pos].nombre, agenda[pos].telefono);
    } else {
        printf("  No encontrado\n");
    }

    return 0;
}
