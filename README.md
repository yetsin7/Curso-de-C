# Curso de C — De cero a PRO

> Repositorio oficial: <https://github.com/yetsin7/curso-de-c>

## Hola, Nicaragua

Este libro fue escrito pensando en ti: estudiante, autodidacta o curioso de Nicaragua que quiere aprender a programar de verdad, sin pagar cursos caros, sin necesitar internet permanente y sin requisitos previos. Si estás en Managua, León, Estelí, Matagalpa, Bluefields, Granada o cualquier rincón del país, este material es para ti.

También es para toda Centroamérica y Latinoamérica: cualquier persona que quiera aprender C en español, con explicaciones claras y ejemplos que sí se entienden.

## ¿Por qué existe este libro?

La misión es simple: **aumentar el número de programadores en Nicaragua**. Aprender a programar abre puertas a empleos mejor pagados, proyectos propios y libertad profesional. Pero muchos cursos son caros, dependen de internet rápido o asumen conocimientos que no todos tienen.

Por eso este libro:

- Es **100% gratuito**, para siempre.
- **No requiere registro** ni cuentas ni correos.
- Funciona **sin internet** (offline) una vez que clonas el repositorio.
- **No asume conocimientos previos**: empieza desde cero.
- Está escrito en **español claro**, sin traducciones forzadas ni jerga innecesaria.

Si esto te ayuda, **compártelo** con otro nicaragüense que quiera aprender. Pásalo por WhatsApp, USB, lo que sea. Mientras más personas aprendan, mejor para todos.

## ¿Qué es este libro?

Una guía práctica y progresiva para aprender C desde cero hasta un nivel profesional. Este libro no solo enseña sintaxis: enseña cómo el software usa la memoria, cómo se comunica con el sistema operativo y por qué C está tan cerca del hardware.

## ¿Para quién es?

- Principiantes que quieren aprender su primer lenguaje de bajo nivel
- Programadores de otros lenguajes (Python, JavaScript, etc.) que quieren entender cómo funciona la memoria y el hardware
- Estudiantes de informática, sistemas o electrónica
- Cualquier persona que quiera entender la base sobre la que se construyen sistemas operativos, compiladores, drivers y software embebido

## ¿Por qué C?

C es el lenguaje que define cómo funciona la computación moderna. Linux, Windows, macOS, Python, Ruby, SQLite y miles de herramientas críticas están escritas en C. Aprenderlo te da:

- Comprensión real de la memoria y los punteros
- Control total sobre el hardware
- Base sólida para aprender C++, Rust, sistemas embebidos
- Habilidad para leer código de bajo nivel y contribuir a proyectos de sistemas

## Qué aprenderás sobre la computadora

En C verás con más claridad que en muchos otros lenguajes:

- cómo viven los datos en memoria;
- qué diferencia hay entre stack y heap;
- qué significa compilar un programa;
- cómo una instrucción termina ejecutándose en la máquina;
- por qué un error de memoria puede romper un programa.

---

## Cómo estudiar este libro

1. Lee el `README.md` de cada capítulo.
2. Compila y ejecuta cada archivo por separado.
3. Cambia valores y observa el resultado.
4. Intenta explicar cada ejemplo sin leer el comentario.
5. Si algo falla, lee el error del compilador con calma.

## Cómo compilar

### Con GCC (recomendado)

```bash
gcc -o programa archivo.c
./programa
```

Con advertencias habilitadas (recomendado siempre):

```bash
gcc -Wall -Wextra -o programa archivo.c
./programa
```

### Con Clang

```bash
clang -o programa archivo.c
./programa
```

### Compilar con SQLite (capítulo 12)

```bash
gcc -o programa archivo.c -lsqlite3
```

### Instalar GCC

- **Linux (Debian/Ubuntu):** `sudo apt install gcc`
- **macOS:** `xcode-select --install` (instala clang con alias gcc)
- **Windows:** Instalar [MinGW-w64](https://winlibs.com/) o usar WSL

---

## Estructura del libro

| Cap | Tema                     | Contenido principal                                        |
|-----|--------------------------|------------------------------------------------------------|
| 01  | Introducción             | Hola mundo, historia de C, primer programa                 |
| 02  | Variables y tipos        | int, float, char, bool, sizeof, rangos                     |
| 03  | Operadores               | Aritméticos, lógicos, bitwise, ternario                    |
| 04  | Control de flujo         | if/else, switch, for, while, do-while                      |
| 05  | funciones                | Declaración, prototipos, recursividad, paso por referencia |
| 06  | Arreglos y Strings       | Arrays 1D/2D, char[], string.h                             |
| 07  | Punteros                 | &, *, aritmética de punteros, punteros a funciones         |
| 08  | Structs                  | struct, typedef, union, enum, CRUD básico                  |
| 09  | Manejo de archivos       | fopen, fclose, fread, fwrite, fprintf, fgets               |
| 10  | Memoria dinámica         | malloc, calloc, realloc, free, valgrind                    |
| 11  | Preprocesador            | #define, #include, #ifdef, macros, include guards          |
| 12  | Proyecto Biblia          | SQLite3 en C, consultas reales sobre biblia_rv60.sqlite3   |

---

## Base de datos de la Biblia

A partir del **capítulo 09** y especialmente en el **capítulo 12**, los ejemplos utilizan una base de datos SQLite con la Biblia Reina-Valera 1960.

Ruta de la base de datos desde la raíz del libro:

```
../../datos/biblia_rv60.sqlite3
```

Desde los archivos dentro de cada capítulo la ruta relativa es:

```
../../datos/biblia_rv60.sqlite3
```

---

## convenciones del libro

- Todo el código es **compilable directamente** con gcc sin dependencias externas (salvo cap. 12)
- Los comentarios en el código están en **español**
- Cada capítulo tiene su propio `README.md` con la teoría y ejemplos `.c` con código funcional
- Los archivos no superan las 200 líneas para mantener la legibilidad

---

## Cómo apoyar este proyecto

Este libro es un esfuerzo independiente y gratuito. Si te sirve, hay varias maneras de apoyarlo, todas gratis:

- **Dale una estrella** al repositorio en GitHub: <https://github.com/yetsin7/curso-de-c>
- **Compártelo** con amigos, compañeros de clase, profesores o cualquier persona que quiera aprender a programar.
- **Abre un issue** si encuentras un error, un ejemplo poco claro o una mejora posible.
- **Envía un pull request** con correcciones, mejoras de redacción, ejemplos extra o capítulos adicionales.
- **Recomiéndalo** en tu universidad, instituto técnico, grupo de estudio o comunidad local.

Cada estrella, cada compartida y cada contribución ayuda a que más nicaragüenses (y latinoamericanos) descubran este recurso.

---

## Licencia

Material educativo de uso libre para aprendizaje personal.
