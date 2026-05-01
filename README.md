# Curso de C — De cero a PRO

> Repositorio oficial: <https://github.com/yetsin7/Curso-de-C>

## Documentacion de referencia

Consulta [Documentación-C.md](./Documentación-C.md) para estudiar
con enlaces tecnicos recomendados durante el curso.

## Hola, Nicaragua

Este libro fue escrito pensando en ti: estudiante, autodidacta o curioso de Nicaragua que quiere aprender a programar de verdad, sin pagar cursos caros, sin necesitar internet permanente y sin requisitos previos. Si estas en Managua, Leon, Esteli, Matagalpa, Bluefields, Granada o cualquier rincon del pais, este material es para ti.

Tambien es para toda Centroamerica y Latinoamerica: cualquier persona que quiera aprender C en espanol, con explicaciones claras y ejemplos que si se entienden.

## Por que existe este libro

La mision es simple: **aumentar el numero de programadores en Nicaragua**. Aprender a programar abre puertas a empleos mejor pagados, proyectos propios y libertad profesional. Pero muchos cursos son caros, dependen de internet rapido o asumen conocimientos que no todos tienen.

Por eso este libro:

- Es **100% gratuito**, para siempre.
- **No requiere registro** ni cuentas ni correos.
- Funciona **sin internet** (offline) una vez que clonas el repositorio.
- **No asume conocimientos previos**: empieza desde cero.
- Esta escrito en **espanol claro**, sin traducciones forzadas ni jerga innecesaria.

Si esto te ayuda, **compartelo** con otro nicaraguense que quiera aprender. Pasalo por WhatsApp, USB, lo que sea. Mientras mas personas aprendan, mejor para todos.

## Que aprenderas sobre la computadora

En C veras con mas claridad que en muchos otros lenguajes:

- como viven los datos en memoria;
- que diferencia hay entre stack y heap;
- que significa compilar un programa;
- como una instruccion termina ejecutandose en la maquina;
- por que un error de memoria puede romper un programa.

## Como compilar

### Con GCC (recomendado)

```bash
gcc -Wall -Wextra -o programa archivo.c
./programa
```

### Con Clang

```bash
clang -Wall -Wextra -o programa archivo.c
./programa
```

### Instalar GCC

- **Linux (Debian/Ubuntu):** `sudo apt install gcc`
- **macOS:** `xcode-select --install` (instala clang con alias gcc)
- **Windows:** Instalar [MinGW-w64](https://winlibs.com/) o usar WSL

## Para quien es

- Principiantes que quieren aprender su primer lenguaje de bajo nivel
- Programadores de otros lenguajes que quieren entender como funciona la memoria y el hardware
- Estudiantes de informatica, sistemas o electronica
- Cualquier persona que quiera entender la base sobre la que se construyen sistemas operativos, compiladores, drivers y software embebido

## Por que C

C es el lenguaje que define como funciona la computacion moderna. Linux, Windows, macOS, Python, Ruby, SQLite y miles de herramientas criticas estan escritas en C. Aprenderlo te da:

- Comprension real de la memoria y los punteros
- Control total sobre el hardware
- Base solida para aprender C++, Rust, sistemas embebidos
- Habilidad para leer codigo de bajo nivel y contribuir a proyectos de sistemas

---

## Estructura del libro

1. `01-introduccion` — Hola mundo, historia de C, compilacion, primer programa
2. `02-variables-y-tipos` — int, float, double, char, bool, sizeof, rangos y limites
3. `03-operadores` — aritmeticos, relacionales, logicos, bitwise, asignacion, ternario
4. `04-control-de-flujo` — if/else, switch, for, while, do-while, break, continue
5. `05-funciones` — declaracion, prototipos, paso por valor, recursividad, scope
6. `06-arreglos-y-strings` — arrays 1D y 2D, char arrays, string.h, operaciones
7. `07-proyecto-fundamentos` — proyecto integrador con checklist y desafio extra
8. `08-punteros` — &, *, aritmetica de punteros, punteros a funciones, void pointers
9. `09-structs` — struct, typedef, union, enum, structs anidados, CRUD basico
10. `10-manejo-de-archivos` — fopen, fclose, fread, fwrite, fprintf, fgets, modo binario
11. `11-memoria-dinamica` — malloc, calloc, realloc, free, valgrind, memory leaks
12. `12-preprocesador-y-headers` — #define, #include, #ifdef, macros, include guards
13. `13-arquitectura-y-buenas-practicas` — modularidad, Makefiles, testing, debugging
14. `14-proyecto-final-pro` — proyecto completo integrador con checklist

## Resultado esperado

Al terminar deberias poder escribir programas en C que manipulen memoria directamente,
manejen archivos, usen estructuras de datos y entiendas como funciona el software a
nivel bajo.

## Convenciones del libro

- Todo el codigo es **compilable directamente** con gcc sin dependencias externas
- Los comentarios en el codigo estan en **espanol**
- Cada modulo tiene archivos `.c` con codigo funcional y ejemplos practicos
- Los archivos no superan las 250 lineas para mantener la legibilidad
- Se usan advertencias `-Wall -Wextra` en todos los ejemplos

---

## Como apoyar este proyecto

Este libro es un esfuerzo independiente y gratuito. Si te sirve, hay varias maneras de apoyarlo, todas gratis:

- **Dale una estrella** al repositorio en GitHub: <https://github.com/yetsin7/Curso-de-C>
- **Compartelo** con amigos, companeros de clase, profesores o cualquier persona que quiera aprender a programar.
- **Abre un issue** si encuentras un error, un ejemplo poco claro o una mejora posible.
- **Envia un pull request** con correcciones, mejoras de redaccion, ejemplos extra o capitulos adicionales.
- **Recomiendalo** en tu universidad, instituto tecnico, grupo de estudio o comunidad local.

Cada estrella, cada compartida y cada contribucion ayuda a que mas nicaraguenses (y latinoamericanos) descubran este recurso.

---

## Que estudiar despues

Si quieres seguir la ruta natural para desarrollo de sistemas y bajo nivel, despues de C lo mas recomendable es estudiar:

1. C++: programacion orientada a objetos y STL
2. Rust: seguridad de memoria sin garbage collector
3. Sistemas embebidos: Arduino, ESP32, microcontroladores
4. Sistemas operativos: como funciona Linux por dentro
5. Python interno: como CPython esta escrito en C

## Licencia

Material educativo de uso libre para aprendizaje personal.
