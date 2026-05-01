/*
 * 01_estructura_proyecto.c
 * Compilar: gcc -Wall -Wextra -std=c11 01_estructura_proyecto.c -o 01_estructura
 *
 * Ejemplo de organizacion de proyecto en C:
 * - Separacion de responsabilidades (datos, logica, presentacion)
 * - Principio de responsabilidad unica por funcion
 * - Convenciones de nomenclatura claras
 */

#include <stdio.h>
#include <string.h>

/* ============================================================
 * CAPA DE DATOS: estructuras y constantes
 * ============================================================ */

#define MAX_NOMBRE 50
#define MAX_PRODUCTOS 10

/* Estructura que representa un producto en inventario */
typedef struct {
    char nombre[MAX_NOMBRE];
    float precio;
    int cantidad;
} Producto;

/* ============================================================
 * CAPA DE LOGICA: operaciones sobre los datos
 * ============================================================ */

/* Inicializa un producto con los valores dados. Retorna 0 si es exitoso. */
int producto_inicializar(Producto *p, const char *nombre, float precio, int cantidad) {
    if (p == NULL || nombre == NULL) return -1;
    if (precio < 0 || cantidad < 0) return -2;

    strncpy(p->nombre, nombre, MAX_NOMBRE - 1);
    p->nombre[MAX_NOMBRE - 1] = '\0';
    p->precio = precio;
    p->cantidad = cantidad;
    return 0;
}

/* Calcula el valor total del inventario de un producto */
float producto_valor_total(const Producto *p) {
    if (p == NULL) return 0.0f;
    return p->precio * p->cantidad;
}

/* Verifica si hay stock disponible para un producto */
int producto_hay_stock(const Producto *p, int cantidad_solicitada) {
    if (p == NULL) return 0;
    return p->cantidad >= cantidad_solicitada;
}

/* ============================================================
 * CAPA DE PRESENTACION: muestra informacion al usuario
 * ============================================================ */

/* Imprime la ficha de un producto en formato legible */
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

/* Muestra el resumen de un catalogo de productos */
void catalogo_resumen(const Producto *productos, int cantidad) {
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

    /* Crear productos con validacion de errores */
    int rc = producto_inicializar(&inventario[total], "Laptop", 999.99f, 5);
    if (rc == 0) total++;

    rc = producto_inicializar(&inventario[total], "Mouse", 25.50f, 50);
    if (rc == 0) total++;

    rc = producto_inicializar(&inventario[total], "Teclado", 45.00f, 30);
    if (rc == 0) total++;

    /* Verificar stock antes de una venta simulada */
    int venta = 3;
    if (producto_hay_stock(&inventario[0], venta)) {
        printf("[OK] Hay stock para vender %d Laptops\n", venta);
    } else {
        printf("[ERROR] Stock insuficiente para Laptops\n");
    }

    /* Mostrar catalogo completo */
    catalogo_resumen(inventario, total);

    return 0;
}
