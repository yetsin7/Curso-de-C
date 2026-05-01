/*
 * Modulo 03 -- Calculadora de Impuestos y Descuentos
 * Archivo: 04_calculadora_impuestos.c
 *
 * Proyecto practico: una calculadora que aplica impuestos y descuentos
 * a un precio base, demostrando el uso de diversos operadores en C.
 *
 * Funcionalidades:
 *   - Calculo de IVA (16%)
 *   - Descuentos por volumen (usando operador ternario)
 *   - Precio final con impuestos y descuentos
 *   - Uso de operadores aritmeticos, de comparacion y logicos
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 04_calculadora 04_calculadora_impuestos.c
 */

#include <stdio.h>

int main(void) {
    printf("=== CALCULADORA DE IMPUESTOS Y DESCUENTOS ===\n\n");

    /* Datos de entrada */
    double precio_unitario = 150.0;
    int cantidad = 5;
    const double IVA = 0.16;  /* 16% de impuesto */

    /* Calculo del subtotal */
    double subtotal = precio_unitario * cantidad;
    printf("Precio unitario: $%.2f\n", precio_unitario);
    printf("Cantidad: %d\n", cantidad);
    printf("Subtotal: $%.2f\n", subtotal);

    /* Descuento por volumen usando operador ternario */
    /* 10% si compra >= 10 unidades, 5% si >= 5, 0% si menos */
    double tasa_descuento = (cantidad >= 10) ? 0.10
                          : (cantidad >= 5)  ? 0.05
                          : 0.0;

    double descuento = subtotal * tasa_descuento;
    printf("Descuento aplicado: %.0f%% (-$%.2f)\n", tasa_descuento * 100, descuento);

    /* Subtotal con descuento */
    double subtotal_desc = subtotal - descuento;
    printf("Subtotal con descuento: $%.2f\n", subtotal_desc);

    /* Calculo del IVA */
    double impuesto = subtotal_desc * IVA;
    printf("IVA (%.0f%%): +$%.2f\n", IVA * 100, impuesto);

    /* Precio final */
    double precio_final = subtotal_desc + impuesto;
    printf("\n--- PRECIO FINAL: $%.2f ---\n", precio_final);

    /* Comparacion de precios con diferente cantidad */
    printf("\n=== COMPARACION DE CANTIDADES ===\n");

    int cantidades[] = {1, 3, 5, 10, 20};
    int num_opciones = sizeof(cantidades) / sizeof(cantidades[0]);

    printf("\n%-10s %-12s %-12s %-12s\n", "Cantidad", "Subtotal", "Descuento", "Precio Final");
    printf("%-10s %-12s %-12s %-12s\n", "--------", "--------", "---------", "------------");

    for (int i = 0; i < num_opciones; i++) {
        int cant = cantidades[i];
        double sub = precio_unitario * cant;

        double tasa = (cant >= 10) ? 0.10 : (cant >= 5) ? 0.05 : 0.0;
        double desc = sub * tasa;
        double sub_desc = sub - desc;
        double iva = sub_desc * IVA;
        double final = sub_desc + iva;

        printf("%-10d $%-11.2f $%-11.2f $%-11.2f\n", cant, sub, desc, final);
    }

    /* Determinar la mejor oferta */
    printf("\n=== MEJOR OFERTA ===\n");

    double precio_mejor = 999999.0;
    int cantidad_mejor = 0;

    for (int i = 0; i < num_opciones; i++) {
        int cant = cantidades[i];
        double sub = precio_unitario * cant;
        double tasa = (cant >= 10) ? 0.10 : (cant >= 5) ? 0.05 : 0.0;
        double desc = sub * tasa;
        double sub_desc = sub - desc;
        double iva = sub_desc * IVA;
        double final = sub_desc + iva;

        double precio_por_unidad = final / cant;

        if (precio_por_unidad < precio_mejor) {
            precio_mejor = precio_por_unidad;
            cantidad_mejor = cant;
        }
    }

    printf("Mejor precio por unidad: $%.2f comprando %d unidades\n",
           precio_mejor, cantidad_mejor);

    /* Uso de operadores logicos para validacion */
    printf("\n=== VALIDACION DE ENTRADA ===\n");

    int precio_valido = (precio_unitario > 0) && (precio_unitario < 10000);
    int cantidad_valida = (cantidad > 0) && (cantidad <= 1000);

    printf("Precio valido: %s\n", precio_valido ? "SI" : "NO");
    printf("Cantidad valida: %s\n", cantidad_valida ? "SI" : "NO");

    if (precio_valido && cantidad_valida) {
        printf("Datos correctos. Calculo realizado exitosamente.\n");
    } else {
        printf("ERROR: Datos de entrada invalidos.\n");
    }

    return 0;
}
