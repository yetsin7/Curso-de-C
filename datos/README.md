# Datos — Base de datos de la Biblia

Este directorio contiene la base de datos SQLite usada como proyecto avanzado en el curso.

## Archivo principal

```text
biblia_rv60.sqlite3
```

Ruta relativa desde cualquier modulo del curso:
```text
../../datos/biblia_rv60.sqlite3
```

## Estructura de la base de datos

La base almacena la Biblia Reina-Valera 1960 con las siguientes tablas:

```sql
CREATE TABLE libros (
    id INTEGER PRIMARY KEY,
    nombre TEXT NOT NULL,
    abrev TEXT,
    testamento TEXT
);

CREATE TABLE versiculos (
    id INTEGER PRIMARY KEY,
    libro_id INTEGER NOT NULL,
    capitulo INTEGER NOT NULL,
    versiculo INTEGER NOT NULL,
    texto TEXT NOT NULL
);
```

## Como usar desde C

Para consultar esta base necesitas:

1. Instalar SQLite3 en tu sistema
2. Incluir `<sqlite3.h>` en tu codigo
3. Compilar enlazando la biblioteca: `gcc archivo.c -lsqlite3 -o programa`

Ejemplo basico de conexion:

```c
sqlite3 *db;
int rc = sqlite3_open("../../datos/biblia_rv60.sqlite3", &db);
if (rc != SQLITE_OK) {
    printf("Error: %s\n", sqlite3_errmsg(db));
    return 1;
}
/* ... consultas ... */
sqlite3_close(db);
```

## Consultas utiles

```sql
-- Listar todos los libros
SELECT nombre, abrev, testamento FROM libros ORDER BY id;

-- Buscar versiculos por palabra clave
SELECT v.texto, l.nombre, v.capitulo, v.versiculo
FROM versiculos v JOIN libros l ON v.libro_id = l.id
WHERE v.texto LIKE '%amor%' LIMIT 10;

-- Contar versiculos por libro
SELECT l.nombre, COUNT(*) as total
FROM versiculos v JOIN libros l ON v.libro_id = l.id
GROUP BY l.nombre ORDER BY total DESC;
```

## Modulos relacionados

- `10-manejo-de-archivos` — Bases de lectura/escritura
- `11-memoria-dinamica` — Gestion de resultados dinamicos
- `14-proyecto-final-pro` — Proyecto integrador

## Recomendaciones

- Verifica siempre los codigos de retorno de SQLite
- Usa sentencias preparadas (`sqlite3_prepare_v2`) para seguridad
- Cierra la conexion con `sqlite3_close` al terminar
- Finaliza statements con `sqlite3_finalize`
