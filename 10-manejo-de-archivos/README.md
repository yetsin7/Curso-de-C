# Modulo 10 -- Manejo de Archivos

Este modulo explica como guardar y recuperar informacion usando archivos en C.

Hasta ahora muchos programas perdian sus datos al terminar la ejecucion. Con archivos, un programa puede guardar informacion en disco y volver a usarla despues.

## Objetivo del modulo

Al terminar este modulo deberias poder:

- Abrir archivos con `fopen`.
- Escribir archivos de texto con `fprintf` y `fputs`.
- Leer archivos de texto con `fgets` y `fscanf`.
- Entender que significa EOF o fin de archivo.
- Cerrar archivos correctamente con `fclose`.
- Verificar errores al abrir o cerrar archivos.
- Trabajar con archivos binarios usando `fread` y `fwrite`.
- Usar `fseek` y `ftell` para moverse dentro de un archivo.
- Crear un mini-proyecto que guarde y lea calificaciones.

## Archivos del modulo

- `01_escritura_archivos.c`  
  Explica como crear un archivo de texto y escribir contenido usando `fprintf` y `fputs`.

- `02_lectura_archivos.c`  
  Explica como leer un archivo de texto linea por linea y como extraer datos con formato.

- `03_archivos_binarios.c`  
  Explica archivos binarios, escritura y lectura de estructuras completas con `fwrite` y `fread`.

- `04_registro_notas.c`  
  Mini-proyecto que guarda calificaciones en un archivo, las lee y calcula estadisticas.

## Como estudiar este modulo

Primero estudia la escritura de archivos. Luego estudia la lectura. Despues revisa archivos binarios. Finalmente estudia el proyecto de registro de notas.

Ruta recomendada:

1. Ejecuta `01_escritura_archivos.c`.
2. Abre el archivo `notas.txt` generado y revisa su contenido.
3. Ejecuta `02_lectura_archivos.c` para leer ese archivo.
4. Ejecuta `03_archivos_binarios.c` y observa que genera un archivo `.dat`.
5. Ejecuta `04_registro_notas.c` y revisa el archivo `calificaciones.txt`.

## Como compilar

```bash
gcc -Wall -Wextra -std=c11 -o escritura 01_escritura_archivos.c
gcc -Wall -Wextra -std=c11 -o lectura 02_lectura_archivos.c
gcc -Wall -Wextra -std=c11 -o binarios 03_archivos_binarios.c
gcc -Wall -Wextra -std=c11 -o registro 04_registro_notas.c
```

## Como ejecutar

En Windows:

```bash
escritura.exe
lectura.exe
binarios.exe
registro.exe
```

En Linux o macOS:

```bash
./escritura
./lectura
./binarios
./registro
```

## Modos comunes de apertura

| Modo | Significado |
|---|---|
| `"r"` | Leer archivo de texto. El archivo debe existir. |
| `"w"` | Escribir archivo de texto. Crea o sobrescribe. |
| `"a"` | Agregar al final de un archivo de texto. |
| `"rb"` | Leer archivo binario. |
| `"wb"` | Escribir archivo binario. Crea o sobrescribe. |
| `"ab"` | Agregar al final de un archivo binario. |

## Consejo importante

Siempre verifica si `fopen` devolvio `NULL`.

```c
FILE *archivo = fopen("datos.txt", "r");

if (archivo == NULL) {
    perror("No se pudo abrir el archivo");
    return 1;
}
```

Tambien recuerda cerrar cada archivo con `fclose`. No cerrar archivos puede causar perdida de datos o uso innecesario de recursos.
