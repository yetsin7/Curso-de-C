/*
 * ============================================================
 * Modulo 07 -- Proyecto Fundamentos
 * Archivo: 01_calculadora_propina.c
 * ============================================================
 *
 * Este archivo muestra un proyecto practico: una calculadora de propina.
 *
 * El programa calcula:
 *
 *   - el monto de la propina
 *   - el total de la cuenta
 *   - cuanto paga cada persona
 *   - cuanto aporta cada persona de propina
 *
 * Este proyecto repasa fundamentos importantes:
 *
 *   - variables
 *   - operaciones aritmeticas
 *   - funciones
 *   - parametros
 *   - valores de retorno
 *   - validacion basica
 *   - salida formateada con printf
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 01_calculadora_propina.c -o calculadora_propina
 *
 * Ejecutar:
 *   Windows: calculadora_propina.exe
 *   Linux/macOS: ./calculadora_propina
 */

#include <stdio.h>

/*
 * Calcula la propina.
 *
 * subtotal es el valor de la cuenta antes de propina.
 * porcentaje es el porcentaje de propina que se desea aplicar.
 *
 * Ejemplo:
 *   subtotal = 100
 *   porcentaje = 15
 *   propina = 15
 */
float calcular_propina(float subtotal, float porcentaje) {
    return subtotal * (porcentaje / 100.0f);
}

/*
 * Divide un total entre varias personas.
 *
 * Si personas es 0 o negativo, devuelve 0 para evitar una division invalida.
 */
float total_por_persona(float total, int personas) {
    if (personas <= 0) {
        return 0.0f;
    }

    return total / personas;
}

/*
 * Imprime un resumen claro de la cuenta.
 */
void imprimir_resumen(float subtotal, float porcentaje_propina, float propina,
                      float total, float propina_persona,
                      float total_persona, int personas) {
    printf("\n========================================\n");
    printf("         RESUMEN DE LA CUENTA\n");
    printf("========================================\n");
    printf("Subtotal:             $%.2f\n", subtotal);
    printf("Propina (%.0f%%):       $%.2f\n", porcentaje_propina, propina);
    printf("Total:                $%.2f\n", total);
    printf("----------------------------------------\n");
    printf("Personas:             %d\n", personas);
    printf("Propina por persona:  $%.2f\n", propina_persona);
    printf("Total por persona:    $%.2f\n", total_persona);
    printf("========================================\n");
}

int main(void) {
    printf("--- Calculadora de Propina ---\n");

    /*
     * Valores de ejemplo.
     *
     * En una version mas avanzada, estos valores podrian pedirse con scanf.
     */
    float subtotal = 85.50f;
    float porcentaje_propina = 15.0f;
    int num_personas = 3;

    /*
     * Primero calculamos la propina.
     */
    float monto_propina = calcular_propina(subtotal, porcentaje_propina);

    /*
     * Luego calculamos el total de la cuenta.
     */
    float total_cuenta = subtotal + monto_propina;

    /*
     * Finalmente dividimos entre el numero de personas.
     */
    float propina_cadauno = total_por_persona(monto_propina, num_personas);
    float total_cadauno = total_por_persona(total_cuenta, num_personas);

    printf("Subtotal de la cuenta: $%.2f\n", subtotal);
    printf("Porcentaje de propina: %.0f%%\n", porcentaje_propina);
    printf("Numero de personas:    %d\n", num_personas);

    imprimir_resumen(subtotal, porcentaje_propina, monto_propina, total_cuenta,
                     propina_cadauno, total_cadauno, num_personas);

    return 0;
}
