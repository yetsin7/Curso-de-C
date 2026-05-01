# Modulo 10 -- Manejo de Archivos

Este modulo ensena a persistir datos usando la biblioteca estandar de C. Aprenderas a crear,
leer y manipular archivos de texto y binarios, asi como a construir un mini-proyecto practico
que registra y calcula calificaciones de estudiantes.

## Archivos del modulo

- `01_escritura_archivos.c` — Escritura de archivos de texto con fopen, fprintf y fputs
- `02_lectura_archivos.c` — Lectura de archivos con fgets, fscanf y manejo de EOF
- `03_archivos_binarios.c` — Archivos binarios con fread, fwrite, fseek y ftell
- `04_registro_notas.c` — Mini-proyecto: sistema de registro y promedio de calificaciones

## Compilacion

Cada archivo es autocontenido y se compila de forma independiente:

```bash
gcc -Wall -Wextra -std=c11 -o escritura 01_escritura_archivos.c
gcc -Wall -Wextra -std=c11 -o lectura 02_lectura_archivos.c
gcc -Wall -Wextra -std=c11 -o binarios 03_archivos_binarios.c
gcc -Wall -Wextra -std=c11 -o registro 04_registro_notas.c
```
