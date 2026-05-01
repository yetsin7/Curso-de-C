/*
 * ============================================================
 * Modulo 13 -- Arquitectura y Buenas Practicas
 * Archivo: 01_estructura_proyecto.c
 * ============================================================
 *
 * Este archivo explica como organizar mejor un programa en C.
 *
 * Cuando un programa crece, no conviene escribir todo mezclado en main().
 * Es mejor separar responsabilidades para que el codigo sea mas claro,
 * facil de mantener y facil de probar.
 *
 * En este ejemplo se usan tres capas simples:
 *
 *   1. Capa de datos
 *      Define constantes y estructuras.
 *
 *   2. Capa de logica
 *      Contiene funciones que procesan datos y aplican reglas.
 *
 *   3. Capa de presentacion
 *      Contiene funciones que muestran informacion al usuario.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 01_estructura_proyecto.c -o 01_estructura
 *
 * Ejecutar:
 *   Windows: 01_estructura.exe
 *   Linux/macOS: ./01_estructura
 */

#include <stdio.h>
#include <string.h>

/* ============================================================
 * CAPA DE DATOS
 * ============================================================
 * Aqui colocamos constantes y estructuras.
 */

#define MAX_NOMBRE 50
#define MAX_PRODUCTOS 10

/*
 * Producto representa un producto dentro de un inventario.
 */
typedef struct {
    char nombre[MAX_NOMBRE];
    float precio;
    int cantidad;
} Producto;

/* ============================================================
 * CAPA DE LOGICA
 * ============================================================
 * Aqui colocamos operaciones que trabajan con los datos.
 */

/*
 * Inicializa un producto con validacion basica.
 *
 * Retorna:
 *   0  si todo salio bien
 *  -1  si hay punteros invalidos
 *  -2  si los datos numericos no son validos
 */
int producto_inicializar(Producto *p, const char *nombre, float precio, int cantidad) {
    if (p == NULL || nombre == NULL) {
        return -1;
    }

    if (precio < 0 || cantidad < 0) {
        return -2;
    }

    strncpy(p->nombre, nombre, MAX_NOMBRE - 1);
    p->nombre[MAX_NOMBRE - 1] = '\0';
    p->precio = precio;
    p->cantidad = cantidad;

    return 0;
}

/*
 * Calcula el valor total de un producto en inventario.
 */
float producto_valor_total(const Producto *p) {
    if (p == NULL) {
        return 0.0f;
    }

    return p->precio * p->cantidad;
}

/*
 * Verifica si hay suficiente stock para una venta.
 */
int producto_hay_stock(const Producto *p, int cantidad_solicitada) {
    if (p == NULL || cantidad_solicitada <= 0) {
        return 0;
    }

    return p->cantidad >= cantidad_solicitada;
}

/* ============================================================
 * CAPA DE PRESENTACION
 * ============================================================
 * Aqui colocamos funciones que imprimen informacion.
 */

/*
 * Imprime la ficha de un producto.
 */
void producto_imprimir(const Producto *p) {
    if (p == NULL) {
        printf("  [Producto nulo]\n");
        return;
    }

    printf("  Nombre : %s\n", p->nombre);
    printf("  Precio : $%.2f\n", p->precio);
    printf("  Stock  : %d unidades\n", p->cantidad);
    printf("  Valor total en inventario: $%.2f\n", producto_valor_total(p));
}

/*
 * Muestra el resumen de un catalogo de productos.
 */
void catalogo_resumen(const Producto *productos, int cantidad) {
    if (productos == NULL || cantidad <= 0) {
        printf("No hay productos para mostrar.\n");
        return;
    }

    printf("\n===== RESUMEN DE INVENTARIO =====\n");

    for (int i = 0; i < cantidad; i++) {
        printf("\n--- Producto %d ---\n", i + 1);
        producto_imprimir(&productos[i]);
    }

    printf("\n=================================\n");
}

/* ============================================================
 * FUNCION PRINCIPAL
 * ============================================================ */

int main(void) {
    Producto inventario[MAX_PRODUCTOS];
    int total = 0;

    int rc = producto_inicializar(&inventario[total], "Laptop", 999.99f, 5);
    if (rc == 0) {
        total++;
    }

    rc = producto_inicializar(&inventario[total], "Mouse", 25.50f, 50);
    if (rc == 0) {
        total++;
    }

    rc = producto_inicializar(&inventario[total], "Teclado", 45.00f, 30);
    if (rc == 0) {
        total++;
    }

    int venta = 3;

    if (producto_hay_stock(&inventario[0], venta)) {
        printf("[OK] Hay stock para vender %d Laptops\n", venta);
    } else {
        printf("[ERROR] Stock insuficiente para Laptops\n");
    }

    catalogo_resumen(inventario, total);

    return 0;
}
