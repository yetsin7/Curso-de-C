/*
 * ============================================================
 * Modulo 03 -- Operadores
 * Archivo: 04_calculadora_impuestos.c
 * ============================================================
 *
 * Objetivo de este archivo
 * ------------------------
 * Este programa usa operadores de C en un ejemplo practico:
 * una calculadora de impuestos y descuentos.
 *
 * Aqui se combinan varios conceptos:
 *
 *   - Operadores aritmeticos para calcular subtotales.
 *   - Operadores de comparacion para decidir descuentos.
 *   - Operadores logicos para validar datos.
 *   - Operador ternario para elegir una tasa de descuento.
 *   - Arreglos y for como adelanto de modulos posteriores.
 *
 * ------------------------------------------------------------
 * Que calcula este programa?
 * ------------------------------------------------------------
 *
 * 1. Multiplica precio por cantidad para obtener un subtotal.
 * 2. Aplica un descuento dependiendo de la cantidad comprada.
 * 3. Calcula el impuesto sobre el subtotal con descuento.
 * 4. Suma todo para obtener el precio final.
 * 5. Compara varias cantidades para encontrar la mejor oferta.
 *
 * ------------------------------------------------------------
 * Compilar
 * ------------------------------------------------------------
 *
 *   gcc -Wall -Wextra -std=c11 -o 04_calculadora 04_calculadora_impuestos.c
 *
 * Ejecutar en Windows:
 *
 *   04_calculadora.exe
 *
 * Ejecutar en Linux/macOS:
 *
 *   ./04_calculadora
 *
 */

#include <stdio.h>

int main(void) {
    printf("=== CALCULADORA DE IMPUESTOS Y DESCUENTOS ===\n\n");

    /*
     * Datos de entrada del ejemplo.
     *
     * En este punto del curso todavia no dependemos de entrada del usuario,
     * asi que los valores estan escritos directamente en el codigo.
     */
    double precio_unitario = 150.0;
    int cantidad = 5;
    const double IVA = 0.16;

    /*
     * Subtotal:
     * Es el precio antes de aplicar descuento e impuesto.
     */
    double subtotal = precio_unitario * cantidad;

    printf("Precio unitario: $%.2f\n", precio_unitario);
    printf("Cantidad: %d\n", cantidad);
    printf("Subtotal: $%.2f\n", subtotal);

    /*
     * Descuento por volumen usando operador ternario.
     *
     * Regla del negocio:
     * - Si compra 10 o mas unidades, obtiene 10% de descuento.
     * - Si compra 5 o mas unidades, obtiene 5% de descuento.
     * - Si compra menos de 5 unidades, no obtiene descuento.
     */
    double tasa_descuento = (cantidad >= 10) ? 0.10
                          : (cantidad >= 5)  ? 0.05
                          : 0.0;

    double descuento = subtotal * tasa_descuento;
    printf("Descuento aplicado: %.0f%% (-$%.2f)\n", tasa_descuento * 100, descuento);

    /*
     * Subtotal con descuento:
     * Restamos el descuento al subtotal original.
     */
    double subtotal_desc = subtotal - descuento;
    printf("Subtotal con descuento: $%.2f\n", subtotal_desc);

    /*
     * Impuesto:
     * El IVA se calcula sobre el subtotal ya descontado.
     */
    double impuesto = subtotal_desc * IVA;
    printf("IVA (%.0f%%): +$%.2f\n", IVA * 100, impuesto);

    /*
     * Precio final:
     * Es lo que el cliente debe pagar.
     */
    double precio_final = subtotal_desc + impuesto;
    printf("\n--- PRECIO FINAL: $%.2f ---\n", precio_final);

    printf("\n=== COMPARACION DE CANTIDADES ===\n");

    /*
     * Este arreglo contiene diferentes cantidades para comparar.
     * Los arreglos se estudian con mas detalle en el Modulo 06.
     */
    int cantidades[] = {1, 3, 5, 10, 20};
    int num_opciones = sizeof(cantidades) / sizeof(cantidades[0]);

    printf("\n%-10s %-12s %-12s %-12s\n", "Cantidad", "Subtotal", "Descuento", "Precio Final");
    printf("%-10s %-12s %-12s %-12s\n", "--------", "--------", "---------", "------------");

    /*
     * Este for recorre todas las cantidades del arreglo y calcula el
     * precio final para cada caso.
     */
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

    printf("\n=== MEJOR OFERTA ===\n");

    /*
     * Buscamos que cantidad produce el menor precio por unidad.
     */
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

    printf("\n=== VALIDACION DE ENTRADA ===\n");

    /*
     * Validar datos significa comprobar que los valores tienen sentido
     * antes de usarlos.
     *
     * Aqui usamos operadores logicos:
     *
     * && significa que ambas condiciones deben cumplirse.
     */
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
