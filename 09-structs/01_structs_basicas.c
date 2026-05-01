/*
 * Modulo 09 — Structs Basicas
 * Archivo: 01_structs_basicas.c
 *
 * Demuestra:
 *   - Definicion de struct
 *   - Patron typedef struct
 *   - Acceso a campos con punto (.)
 *   - Arreglos de structs
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 01_structs_basicas 01_structs_basicas.c
 */

#include <stdio.h>
#include <string.h>

/* Estructura basica para representar un libro */
struct Libro {
    char titulo[80];
    char autor[60];
    int paginas;
    float precio;
};

/* Patron typedef para evitar escribir 'struct' cada vez */
typedef struct {
    char nombre[50];
    float nota1;
    float nota2;
    float nota3;
} Estudiante;

/* Prototipos */
void imprimirLibro(struct Libro l);
float promedioNotas(Estudiante e);

int main(void) {
    printf("=== STRUCTS BASICAS ===\n\n");

    /* --- 1. Struct simple con inicializacion --- */
    struct Libro libro1;
    strcpy(libro1.titulo, "El Quijote");
    strcpy(libro1.autor, "Cervantes");
    libro1.paginas = 863;
    libro1.precio = 25.50f;

    printf("Libro 1:\n");
    imprimirLibro(libro1);

    /* --- 2. Struct con inicializacion directa --- */
    struct Libro libro2 = {"1984", "George Orwell", 328, 18.90f};

    printf("\nLibro 2:\n");
    imprimirLibro(libro2);

    /* --- 3. Typedef struct — Estudiante --- */
    Estudiante alum1 = {"Ana Garcia", 8.5f, 9.0f, 7.5f};

    printf("\nEstudiante: %s\n", alum1.nombre);
    printf("Promedio: %.2f\n", promedioNotas(alum1));

    /* --- 4. Arreglo de structs --- */
    struct Libro biblioteca[3] = {
        {"Cien Anios de Soledad", "Garcia Marquez", 471, 22.00f},
        {"Rayuela", "Julio Cortazar", 600, 19.50f},
        {"Ficciones", "Jorge Borges", 224, 15.80f}
    };

    printf("\n=== BIBLIOTECA ===\n");
    for (int i = 0; i < 3; i++) {
        printf("[%d] %s — %.2f\n", i + 1, biblioteca[i].titulo, biblioteca[i].precio);
    }

    /* --- 5. Modificar campos --- */
    printf("\n=== MODIFICAR CAMPOS ===\n");
    biblioteca[0].precio = 20.00f;
    printf("Precio actualizado de '%s': %.2f\n", biblioteca[0].titulo, biblioteca[0].precio);

    return 0;
}

/* Imprime los datos de un libro */
void imprimirLibro(struct Libro l) {
    printf("  Titulo:  %s\n", l.titulo);
    printf("  Autor:   %s\n", l.autor);
    printf("  Paginas: %d\n", l.paginas);
    printf("  Precio:  $%.2f\n", l.precio);
}

/* Calcula el promedio de las 3 notas de un estudiante */
float promedioNotas(Estudiante e) {
    return (e.nota1 + e.nota2 + e.nota3) / 3.0f;
}
