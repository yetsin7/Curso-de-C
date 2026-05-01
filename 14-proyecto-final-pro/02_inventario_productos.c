/*
 * Inventario de Productos - Proyecto Final
 * Compilar: gcc -Wall -Wextra -std=c11 02_inventario_productos.c -o inventario
 *
 * Sistema de inventario con persistencia en archivos, manejo de
 * memoria dinamica, structs y operaciones de lectura/escritura.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMBRE 60
#define ARCHIVO "inventario.dat"

/* Estructura que representa un producto en inventario */
typedef struct {
    int id;
    char nombre[MAX_NOMBRE];
    float precio;
    int stock;
} Producto;

/* Carga productos desde archivo, retorna puntero a array dinamico */
Producto *cargar_inventario(int *total) {
    *total = 0;
    FILE *f = fopen(ARCHIVO, "rb");
    if (!f) return NULL;

    /* Primero cuenta registros */
    fseek(f, 0, SEEK_END);
    long bytes = ftell(f);
    *total = bytes / sizeof(Producto);
    fseek(f, 0, SEEK_SET);

    if (*total == 0) {
        fclose(f);
        return NULL;
    }

    /* Asigna memoria dinamica */
    Producto *productos = malloc(*total * sizeof(Producto));
    if (!productos) {
        printf("Error de memoria.\n");
        fclose(f);
        return NULL;
    }

    fread(productos, sizeof(Producto), *total, f);
    fclose(f);
    return productos;
}

/* Guarda todo el inventario en archivo binario */
void guardar_inventario(Producto *productos, int total) {
    FILE *f = fopen(ARCHIVO, "wb");
    if (!f) {
        printf("Error al abrir archivo.\n");
        return;
    }
    if (total > 0) {
        fwrite(productos, sizeof(Producto), total, f);
    }
    fclose(f);
}

/* Agrega un producto redimensionando el array dinamico */
Producto *agregar_producto(Producto *productos, int *total,
                           const char *nombre, float precio, int stock) {
    int nuevo_total = *total + 1;
    Producto *nuevo = realloc(productos, nuevo_total * sizeof(Producto));
    if (!nuevo) {
        printf("Error de memoria.\n");
        return productos;
    }

    Producto *p = &nuevo[nuevo_total - 1];
    p->id = nuevo_total;
    strncpy(p->nombre, nombre, MAX_NOMBRE - 1);
    p->nombre[MAX_NOMBRE - 1] = '\0';
    p->precio = precio;
    p->stock = stock;

    *total = nuevo_total;
    printf("Producto agregado: %s (ID: %d)\n", nombre, p->id);
    return nuevo;
}

/* Lista todos los productos con formato tabular */
void listar_productos(Producto *productos, int total) {
    if (total == 0) {
        printf("Inventario vacio.\n");
        return;
    }

    printf("\n%-4s %-25s %8s %6s\n", "ID", "Nombre", "Precio", "Stock");
    printf("--------------------------------------------\n");

    for (int i = 0; i < total; i++) {
        Producto *p = &productos[i];
        printf("%-4d %-25s $%7.2f %6d\n",
               p->id, p->nombre, p->precio, p->stock);
    }
    printf("Total: %d productos\n\n", total);
}

/* Busca producto por ID, retorna puntero o NULL */
Producto *buscar_por_id(Producto *productos, int total, int id) {
    for (int i = 0; i < total; i++) {
        if (productos[i].id == id) {
            return &productos[i];
        }
    }
    return NULL;
}

/* Actualiza stock de un producto, retorna 0 si exito */
int actualizar_stock(Producto *productos, int total, int id, int cantidad) {
    Producto *p = buscar_por_id(productos, total, id);
    if (!p) {
        printf("Producto no encontrado.\n");
        return -1;
    }

    p->stock += cantidad;
    if (p->stock < 0) p->stock = 0;

    printf("Stock de '%s' actualizado: %d\n", p->nombre, p->stock);
    return 0;
}

/* Muestra el menu y retorna la opcion seleccionada */
int mostrar_menu(void) {
    int op;
    printf("\n=== Inventario de Productos ===\n");
    printf("1. Agregar producto\n2. Listar todos\n3. Buscar por ID\n");
    printf("4. Actualizar stock\n0. Salir y guardar\nOpcion: ");
    scanf("%d", &op);
    while (getchar() != '\n');
    return op;
}

/* Punto de entrada principal */
int main(void) {
    int total = 0, opcion, id, cant;
    float precio;
    int stock;
    char buffer[MAX_NOMBRE];
    Producto *productos = cargar_inventario(&total);

    if (total == 0) {
        productos = agregar_producto(NULL, &total, "Teclado USB", 25.99, 50);
        productos = agregar_producto(productos, &total, "Mouse Inalambrico", 15.50, 30);
        productos = agregar_producto(productos, &total, "Monitor 24in", 199.00, 10);
    }

    do {
        opcion = mostrar_menu();
        switch (opcion) {
            case 1:
                printf("Nombre: "); fgets(buffer, MAX_NOMBRE, stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                printf("Precio: "); scanf("%f", &precio);
                printf("Stock: "); scanf("%d", &stock);
                while (getchar() != '\n');
                productos = agregar_producto(productos, &total, buffer, precio, stock);
                break;
            case 2: listar_productos(productos, total); break;
            case 3:
                printf("ID: "); scanf("%d", &id); while (getchar() != '\n');
                Producto *p = buscar_por_id(productos, total, id);
                if (p) printf("Encontrado: %s | $%.2f | Stock: %d\n", p->nombre, p->precio, p->stock);
                else printf("No encontrado.\n");
                break;
            case 4:
                listar_productos(productos, total);
                printf("ID: "); scanf("%d", &id);
                printf("Cantidad (+/-): "); scanf("%d", &cant);
                while (getchar() != '\n');
                actualizar_stock(productos, total, id, cant);
                break;
            case 0: guardar_inventario(productos, total); printf("Guardado. Saliendo...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    free(productos);
    return 0;
}
