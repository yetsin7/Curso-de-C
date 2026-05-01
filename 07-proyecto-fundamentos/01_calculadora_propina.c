/*
 * 01_calculadora_propina.c
 * Calculadora de propina que divide la cuenta entre varias personas.
 *
 * Comando de compilacion:
 *   gcc -Wall -Wextra -std=c11 01_calculadora_propina.c -o calculadora_propina
 *
 * Ejecucion:
 *   ./calculadora_propina
 */

#include <stdio.h>

/* Calcula el monto de la propina dado el subtotal y el porcentaje */
float calcular_propina(float subtotal, float porcentaje) {
    return subtotal * (porcentaje / 100.0f);
}

/* Calcula el total por persona dividiendo el total general */
float total_por_persona(float total, int personas) {
    if (personas <= 0) {
        return 0.0f;
    }
    return total / personas;
}

/* Imprime el resumen formateado de la cuenta */
void imprimir_resumen(float subtotal, float propina, float total,
                      float propina_persona, float total_persona,
                      int personas) {
    printf("\n========================================\n");
    printf("         RESUMEN DE LA CUENTA\n");
    printf("========================================\n");
    printf(" Subtotal:            $%.2f\n", subtotal);
    printf(" Propina (%.0f%%):      $%.2f\n", calcular_propina(100.0f, 0), propina);
    printf(" Total:               $%.2f\n", total);
    printf("----------------------------------------\n");
    printf(" Personas:            %d\n", personas);
    printf(" Propina por persona: $%.2f\n", propina_persona);
    printf(" Total por persona:   $%.2f\n", total_persona);
    printf("========================================\n");
}

int main(void) {
    /* Valores de ejemplo (simulando entrada del usuario) */
    float subtotal = 85.50f;
    float porcentaje_propina = 15.0f;
    int num_personas = 3;

    /* Calculos principales */
    float monto_propina = calcular_propina(subtotal, porcentaje_propina);
    float total_cuenta = subtotal + monto_propina;
    float propina_cadauno = total_por_persona(monto_propina, num_personas);
    float total_cadauno = total_por_persona(total_cuenta, num_personas);

    /* Mostrar datos de entrada */
    printf("--- Calculadora de Propina ---\n");
    printf(" Subtotal de la cuenta: $%.2f\n", subtotal);
    printf(" Porcentaje de propina: %.0f%%\n", porcentaje_propina);
    printf(" Numero de personas:    %d\n", num_personas);

    /* Imprimir resumen final */
    imprimir_resumen(subtotal, monto_propina, total_cuenta,
                     propina_cadauno, total_cadauno, num_personas);

    return 0;
}
