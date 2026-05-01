/*
 * ============================================================
 * Modulo 09 -- Structs, Union y Enum
 * Archivo: 04_sistema_inventario.c
 * ============================================================
 *
 * Este archivo muestra un mini-proyecto: un sistema de inventario.
 *
 * El programa permite:
 *
 *   - guardar productos en un arreglo
 *   - agregar productos nuevos
 *   - mostrar el inventario
 *   - buscar productos por nombre
 *   - calcular un resumen del inventario
 *
 * Este proyecto combina struct, enum, arreglos, strings, funciones,
 * punteros a struct y control de flujo.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 04_sistema_inventario 04_sistema_inventario.c
 *
 * Ejecutar:
 *   Windows: 04_sistema_inventario.exe
 *   Linux/macOS: ./04_sistema_inventario
 */

#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 20
#define MAX_NOMBRE 50

/*
 * Enum para representar las opciones del menu.
 *
 * Esto evita usar numeros sueltos directamente en el switch.
 */
typedef enum {
    OPC_AGREGAR = 1,
    OPC_MOSTRAR,
    OPC_BUSCAR,
    OPC_RESUMEN,
    OPC_SALIR
} OpcionMenu;

/*
 * Producto agrupa los datos relacionados de un producto.
 */
typedef struct {
    char nombre[MAX_NOMBRE];
    float precio;
    int cantidad;
} Producto;

int agregarProducto(Producto inventario[], int total);
void mostrarInventario(const Producto inventario[], int total);
int buscarProducto(const Producto inventario[], int total, const char* nombre);
void mostrarResumen(const Producto inventario[], int total);

int main(void) {
    Producto inventario[MAX_PRODUCTOS];
    int total = 0;
    int opcion;

    printf("=== SISTEMA DE INVENTARIO ===\n\n");

    /*
     * Cargar productos iniciales de ejemplo.
     */
    strcpy(inventario[0].nombre, "Teclado");
    inventario[0].precio = 45.90f;
    inventario[0].cantidad = 30;

    strcpy(inventario[1].nombre, "Mouse");
    inventario[1].precio = 25.50f;
    inventario[1].cantidad = 50;

    strcpy(inventario[2].nombre, "Monitor");
    inventario[2].precio = 299.99f;
    inventario[2].cantidad = 15;

    total = 3;

    /*
     * Menu principal.
     *
     * Se repite hasta que el usuario elige salir.
     */
    do {
        printf("\n--- Menu ---\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Buscar producto\n");
        printf("4. Resumen del inventario\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case OPC_AGREGAR:
                total = agregarProducto(inventario, total);
                break;

            case OPC_MOSTRAR:
                mostrarInventario(inventario, total);
                break;

            case OPC_BUSCAR: {
                char busqueda[MAX_NOMBRE];

                printf("Nombre a buscar: ");
                scanf("%49s", busqueda);

                int idx = buscarProducto(inventario, total, busqueda);

                if (idx >= 0) {
                    printf("Encontrado: %s | $%.2f | Stock: %d\n",
                           inventario[idx].nombre,
                           inventario[idx].precio,
                           inventario[idx].cantidad);
                } else {
                    printf("Producto no encontrado.\n");
                }

                break;
            }

            case OPC_RESUMEN:
                mostrarResumen(inventario, total);
                break;

            case OPC_SALIR:
                printf("Saliendo del sistema.\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != OPC_SALIR);

    return 0;
}

/*
 * Agrega un producto nuevo al inventario.
 *
 * Devuelve el nuevo total de productos.
 */
int agregarProducto(Producto inventario[], int total) {
    if (total >= MAX_PRODUCTOS) {
        printf("Inventario lleno, no se puede agregar.\n");
        return total;
    }

    Producto *p = &inventario[total];

    printf("Nombre del producto: ");
    scanf("%49s", p->nombre);

    printf("Precio: ");
    scanf("%f", &p->precio);

    printf("Cantidad: ");
    scanf("%d", &p->cantidad);

    total++;

    printf("Producto agregado correctamente.\n");
    return total;
}

/*
 * Muestra todos los productos del inventario.
 */
void mostrarInventario(const Producto inventario[], int total) {
    if (total == 0) {
        printf("Inventario vacio.\n");
        return;
    }

    printf("\n%-15s | %-10s | %-10s\n", "Producto", "Precio", "Cantidad");
    printf("-----------------------------------------\n");

    for (int i = 0; i < total; i++) {
        printf("%-15s | $%-9.2f | %d\n",
               inventario[i].nombre,
               inventario[i].precio,
               inventario[i].cantidad);
    }
}

/*
 * Busca un producto por nombre.
 *
 * Devuelve el indice si lo encuentra.
 * Devuelve -1 si no existe.
 */
int buscarProducto(const Producto inventario[], int total, const char* nombre) {
    for (int i = 0; i < total; i++) {
        if (strcmp(inventario[i].nombre, nombre) == 0) {
            return i;
        }
    }

    return -1;
}

/*
 * Calcula y muestra un resumen del inventario.
 */
void mostrarResumen(const Producto inventario[], int total) {
    float valorTotal = 0.0f;
    int unidadesTotal = 0;

    for (int i = 0; i < total; i++) {
        valorTotal += inventario[i].precio * inventario[i].cantidad;
        unidadesTotal += inventario[i].cantidad;
    }

    printf("\nResumen del Inventario:\n");
    printf("  Productos distintos: %d\n", total);
    printf("  Unidades totales:    %d\n", unidadesTotal);
    printf("  Valor total:         $%.2f\n", valorTotal);
}
