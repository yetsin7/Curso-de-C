# Modulo 07 -- Proyecto Fundamentos

Este modulo integra los conceptos aprendidos desde el Modulo 01 hasta el Modulo 06.

Aqui ya no estudias un concepto aislado. En este modulo usas variables, operadores, funciones, control de flujo, arreglos y salida formateada para construir programas mas completos.

## Objetivo del modulo

Al terminar este modulo deberias poder:

- Leer un problema y dividirlo en partes pequenas.
- Crear funciones para organizar la logica.
- Usar variables y operadores para hacer calculos.
- Usar condicionales para tomar decisiones.
- Usar bucles para repetir procesos.
- Usar arreglos para manejar varios datos.
- Mostrar resultados claros con `printf`.
- Compilar y probar proyectos completos.

## Archivos del modulo

- `01_calculadora_propina.c`  
  Proyecto que calcula propina, total de cuenta y division entre varias personas.

- `02_adivinanza_numero.c`  
  Juego de adivinanza que usa numeros aleatorios, funciones, condicionales, bucles y arreglos.

- `03_checklist.md`  
  Lista de verificacion para confirmar que dominas los fundamentos antes de avanzar.

- `04_reto_extra.md`  
  Reto adicional para construir un sistema de notas usando arreglos, funciones y condicionales.

## Como estudiar este modulo

Primero ejecuta los dos proyectos `.c`. Despues lee el checklist y marca honestamente lo que ya entiendes. Finalmente intenta resolver el reto extra sin copiar una solucion completa.

Ruta recomendada:

1. Compila `01_calculadora_propina.c`.
2. Ejecutalo y revisa el resultado.
3. Cambia el subtotal, porcentaje de propina y numero de personas.
4. Compila `02_adivinanza_numero.c`.
5. Ejecutalo varias veces y observa como cambia el numero secreto.
6. Revisa `03_checklist.md`.
7. Intenta crear `reto_sistema_notas.c` siguiendo `04_reto_extra.md`.

## Como compilar

Calculadora de propina:

```bash
gcc -Wall -Wextra -std=c11 01_calculadora_propina.c -o calculadora_propina
```

Juego de adivinanza:

```bash
gcc -Wall -Wextra -std=c11 02_adivinanza_numero.c -o adivinanza_numero
```

## Como ejecutar

En Windows:

```bash
calculadora_propina.exe
adivinanza_numero.exe
```

En Linux o macOS:

```bash
./calculadora_propina
./adivinanza_numero
```

## Consejo importante

Cuando construyas proyectos, no empieces escribiendo todo de golpe. Primero resuelve una parte pequena, compila, prueba y luego agrega la siguiente parte.

Esa forma de trabajar evita errores grandes y te ayuda a entender mejor cada paso.
