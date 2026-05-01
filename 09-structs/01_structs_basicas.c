/*
 * ============================================================
 * Modulo 09 -- Structs, Union y Enum
 * Archivo: 01_structs_basicas.c
 * ============================================================
 *
 * Este archivo explica las estructuras basicas en C.
 *
 * Un struct permite agrupar varios datos relacionados bajo un mismo tipo.
 *
 * Ejemplo:
 * Un libro no tiene solo un dato. Tiene titulo, autor, paginas y precio.
 * En vez de manejar esas variables por separado, podemos agruparlas en
 * una sola estructura llamada Libro.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 01_structs_basicas 01_structs_basicas.c
 *
 * Ejecutar:
 *   Windows: 01_structs_basicas.exe
 *   Linux/macOS: ./01_structs_basicas
 */

#include <stdio.h>
#include <string.h>

/*
 * Definicion de una estructura.
 *
 * struct Libro crea un nuevo tipo compuesto por varios campos.
 */
struct Libro {
    char titulo[80];
    char autor[60];
    int paginas;
    float precio;
};

/*
 * typedef permite crear un nombre mas comodo para un tipo.
 *
 * Gracias a typedef, podemos escribir Estudiante en vez de struct Estudiante.
 */
typedef struct {
    char nombre[50];
    float nota1;
    float nota2;
    float nota3;
} Estudiante;

void imprimirLibro(struct Libro l);
float promedioNotas(Estudiante e);

int main(void) {
    printf("=== STRUCTS BASICAS ===\n\n");

    /*
     * Crear un struct y llenar sus campos uno por uno.
     *
     * El operador punto permite acceder a los campos de una estructura.
     */
    struct Libro libro1;

    strcpy(libro1.titulo, "El Quijote");
    strcpy(libro1.autor, "Cervantes");
    libro1.paginas = 863;
    libro1.precio = 25.50f;

    printf("Libro 1:\n");
    imprimirLibro(libro1);

    /*
     * Inicializacion directa de un struct.
     *
     * Los valores se colocan en el mismo orden en que fueron definidos
     * los campos dentro de la estructura.
     */
    struct Libro libro2 = {"1984", "George Orwell", 328, 18.90f};

    printf("\nLibro 2:\n");
    imprimirLibro(libro2);

    /*
     * Uso de typedef struct.
     */
    Estudiante alum1 = {"Ana Garcia", 8.5f, 9.0f, 7.5f};

    printf("\nEstudiante: %s\n", alum1.nombre);
    printf("Promedio: %.2f\n", promedioNotas(alum1));

    /*
     * Arreglo de structs.
     *
     * Esto permite guardar varios libros en una sola coleccion.
     */
    struct Libro biblioteca[3] = {
        {"Cien Anios de Soledad", "Garcia Marquez", 471, 22.00f},
        {"Rayuela", "Julio Cortazar", 600, 19.50f},
        {"Ficciones", "Jorge Borges", 224, 15.80f}
    };

    printf("\n=== BIBLIOTECA ===\n");

    for (int i = 0; i < 3; i++) {
        printf("[%d] %s - $%.2f\n", i + 1, biblioteca[i].titulo, biblioteca[i].precio);
    }

    /*
     * Modificar un campo de un struct dentro de un arreglo.
     */
    printf("\n=== MODIFICAR CAMPOS ===\n");

    biblioteca[0].precio = 20.00f;

    printf("Precio actualizado de '%s': $%.2f\n",
           biblioteca[0].titulo, biblioteca[0].precio);

    return 0;
}

/*
 * Imprime todos los campos de un libro.
 */
void imprimirLibro(struct Libro l) {
    printf("  Titulo:  %s\n", l.titulo);
    printf("  Autor:   %s\n", l.autor);
    printf("  Paginas: %d\n", l.paginas);
    printf("  Precio:  $%.2f\n", l.precio);
}

/*
 * Calcula el promedio de las tres notas de un estudiante.
 */
float promedioNotas(Estudiante e) {
    return (e.nota1 + e.nota2 + e.nota3) / 3.0f;
}
