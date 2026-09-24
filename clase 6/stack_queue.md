# Simulacion de una rockola usando Queue

vector almacena canciones. 10 canciones por artista

Matriz almacena artistas. 10 artistas

--- 
resultado esperado

poder reproducir canciones.

poder avanzar y retroceder la cancion.

poder eliminar y actualizar la lista de canciones por distintos artistas

1. cavetown
    - Lemon Boy 
    - Home 
    - Meteor Shower 
    - Devil Town 
    - Juliet 
    - Fool
    - Talk to me
    - Poison
    - Hazel
    - Best friend
1. Stomach book
    - Casket kids 
    - Animals
    - Bambi
    - Fukouna Girl
    - Tragedy
    - Let you Down
    - We all fall down
    - SICK SICK SICK
    - Paper dolls
    - Anachy!!!
1. Set it Off
    - I'd Rather Drown 
    - Plastic Promises 
    - Why Worry
    - Partners in Crime 
    - Rotten
    - Evil people
    - horrible kids
    - Wolf in sheep's clothing
    - No control
    - Nigthmare
4. Nirvana:
    - Smells Like Teen Spirit 
    - The Man Who Sold the World 
    - Dumb 
    - Lake of Fire 
    - Rape Me 
    - About at girl
    - Sappy
    - In Bloom
    - Silver
    - Drain You
1. Linkin Park
    - Numb 
    - Faint 
    - In the End 
    - The Emptiness Machine 
    - Lost
    - Crawling 
    - Burn it down
    - Heavy
    - Bleed it out
    - Talking to myself
1. Los Retros:
    - Someone to Spend Time With 
    - Amtrak 
    - Looking Back 
    - Friends
    - Last Day on Earth
    - Sweet Honey
    - Room Gloom
    - Purple Nights
    - Likewise
    - Lonely
    - Old times
1. Missa Sinfonia
    - Vulnerables
    - No es verdad
    - Privilegios 
    - Tarde para el plan B
    - Piratas
    - Desconexión Emocional
    - El tiempo
    - Aqui estoy
    - Fantasma enamorado
    - Nuestros limites
1. Ado 
    - Ussewa
    - untravel
    - RuLe
    - Episode X
    - Rockstar
    - Monstruo
    - KIRA
    - AIAIA
    - Vivarium
    - MAGIC
1. Maretu
    - magical doctor
    - wating to wake up
    - mind brand
    - stuck in up
    - Darling
    - brain revolution girl
    - MARETU | EVEN THOUGH I LOVED YOU
    - SIU
    - New Darling
    - White Happy
1. Yukigloom
    - Stupid homura kinnie
    - Cyberia
    - a Fallen angel's thesis
    - Insomniac.jpeg (feat. wúlf boi)
    - crinial nerve exam (GONE WRONG)
    - if i was a vampire
    - nostalgia (con Peachumari)
    - TOOL ASSISTED ABSTRACTION
    - SMOKE AND MIRRORS (YUKIGLOOM COVER)
    - flawless EXEcution!

    --- 
    # Algoritmo

El programa simulará el funcionamiento de una rockola utilizando una estructura `queue` para administrar las canciones que el usuario desea reproducir.

Para almacenar la información se utilizará una matriz de **11 × 10**, donde cada fila representa a un artista y cada columna representa una de sus canciones. De esta manera, se podrán almacenar hasta **10 artistas con 10 canciones cada uno**.

Además, se utilizará una `queue` para almacenar temporalmente las canciones que el usuario haya seleccionado y que serán reproducidas en el orden en que fueron agregadas.

## 1. Cargar las canciones

Al iniciar el programa, se mostrará un mensaje indicando que se están cargando las canciones.

Después, el programa almacenará en la matriz los nombres de los artistas y sus respectivas canciones.

Una vez terminada la carga, se mostrará el menú principal.

## 2. Mostrar el menú inicial

Si la cola se encuentra vacía, significa que todavía no hay ninguna canción pendiente de reproducción.

Por lo tanto, se mostrará un menú con solamente las siguientes opciones:

```text
1. Agregar canción a la cola
2. Salir
```

El programa verificará constantemente si la cola contiene canciones para determinar qué menú debe mostrar.

## 3. Agregar una canción

Cuando el usuario seleccione la opción de agregar una canción, el programa mostrará una lista con los artistas disponibles:

```text
1. Cavetown
2. Stomach Book
3. Set It Off
4. Nirvana
5. Linkin Park
...
10. Yukigloom
```

El usuario seleccionará uno de los artistas.

Después de seleccionar al artista, el programa mostrará las canciones disponibles de ese artista:

```text
1. Canción 1
2. Canción 2
3. Canción 3
...
10. Canción 10
```

El usuario seleccionará una canción y esta será agregada al final de la `queue`.

Por ejemplo, si la cola contiene:

```text
[Canción A] → [Canción B] → [Canción C]
```

y el usuario agrega `Canción D`, la cola quedará:

```text
[Canción A] → [Canción B] → [Canción C] → [Canción D]
```

Esto permite que las canciones se reproduzcan en el mismo orden en el que fueron agregadas.

## 4. Mostrar el menú de reproducción

Cuando exista al menos una canción en la cola, se mostrará un menú con las opciones:

```text
1. Agregar canción
2. Pausar
3. Siguiente
4. Eliminar
5. Anterior
6. Salir
```

Debajo del menú se mostrará la lista de canciones que actualmente se encuentran en la cola.

El menú se seguirá mostrando hasta que el usuario seleccione la opción de salir.

## 5. Reproducir la canción

La primera canción de la cola será considerada como la canción actual.

Para saber qué canción se está reproduciendo se utilizará una variable que indique la posición de la canción actual.

Por ejemplo:

```text
Canción actual = 0
```

significa que se está reproduciendo la primera canción.

Si el usuario selecciona **Siguiente**, la posición aumentará:

```text
Canción actual = canción actual + 1
```

De esta manera se pasará a la siguiente canción.

Si el usuario selecciona **Anterior**, la posición disminuirá:

```text
Canción actual = canción actual - 1
```

Antes de realizar cualquiera de estas operaciones, el programa deberá verificar que no se encuentre fuera de los límites de la cola.

## 6. Pausar

La opción de pausar permitirá detener temporalmente la reproducción de la canción actual.

Para esto se puede utilizar una variable booleana, por ejemplo:

```text
pausada = true
```

Cuando el usuario vuelva a seleccionar reproducir o continuar, la variable cambiará nuevamente:

```text
pausada = false
```

La canción actual no cambia al pausar; únicamente se modifica su estado de reproducción.

## 7. Siguiente canción

Cuando el usuario seleccione **Siguiente**, el programa comprobará si existe otra canción después de la canción actual.

Si existe, se aumentará la posición de la canción actual y se mostrará la siguiente canción.

Por ejemplo:

```text
[A] → [B] → [C]

             ↑
       canción actual
```

Al seleccionar siguiente:

```text
[A] → [B] → [C]

       ↑
 canción actual
```

Si ya se encuentra en la última canción, el programa deberá evitar que la posición aumente más allá del número de canciones disponibles.

## 8. Canción anterior

La opción **Anterior** funcionará de manera similar.

El programa comprobará si existe una canción antes de la actual.

Si existe, disminuirá la posición de la canción actual:

```text
[A] → [B] → [C]

       ↑
 canción actual
```

Al seleccionar anterior:

```text
[A] → [B] → [C]

 ↑
canción actual
```

Si la canción actual ya es la primera, el programa deberá evitar que la posición tome un valor negativo.

## 9. Eliminar canciones

La opción **Eliminar** permitirá modificar el contenido de la cola.

El usuario podrá elegir entre:

```text
1. Eliminar una canción
2. Eliminar todas las canciones
3. Cancelar
```

Si selecciona eliminar una canción, se mostrará la lista de canciones que actualmente están en la cola y el usuario podrá seleccionar cuál desea eliminar.

Si selecciona eliminar todas, la cola quedará vacía.

Después de eliminar una canción, el programa deberá actualizar la posición de la canción actual para evitar que apunte a una posición que ya no existe.

## 10. Actualizar la lista de canciones

La información de los artistas y canciones estará almacenada en la matriz.

El programa podrá permitir modificar una canción existente seleccionando primero al artista y posteriormente la posición de la canción que desea cambiar.

Por ejemplo:

```text
Artista: Cavetown
Canción seleccionada: 3
Nueva canción: Nueva canción
```

La posición correspondiente de la matriz será actualizada con el nuevo nombre.

Esto permitirá modificar el catálogo de canciones sin tener que cambiar directamente el código del programa.

## 11. Finalizar el programa

Cuando el usuario seleccione la opción **Salir**, el programa terminará su ejecución.

Antes de finalizar, se pueden mostrar las canciones que fueron reproducidas o simplemente mostrar un mensaje indicando que la rockola ha terminado.

### Resumen del funcionamiento

El funcionamiento general del programa será:

```text
Iniciar programa
      ↓
Cargar artistas y canciones
      ↓
¿La cola está vacía?
      ↓
   ┌──Sí──────────────────┐
   ↓                       │
Mostrar menú inicial       │
   ↓                       │
Agregar canción ───────────┘
   │
   ↓
¿Hay canciones en la cola?
   ↓
Mostrar menú de reproducción
   ↓
┌───────────────────────────────┐
│ Agregar canción               │
│ Pausar                        │
│ Siguiente                     │
│ Anterior                      │
│ Eliminar                      │
│ Salir                         │
└───────────────────────────────┘
   ↓
Repetir hasta seleccionar salir
   ↓
Finalizar programa
```

## Estructuras utilizadas

**Matriz:** almacenará los artistas y sus canciones. Cada fila representará un artista y cada columna una canción.

**Queue:** almacenará las canciones seleccionadas para su reproducción. Las canciones se agregarán al final de la cola y se procesarán siguiendo el orden en que fueron agregadas.

**Variable de posición:** indicará qué canción se encuentra seleccionada o reproduciéndose actualmente, permitiendo avanzar y retroceder entre las canciones.

**Variables booleanas:** podrán utilizarse para controlar estados como si la reproducción se encuentra pausada o activa.
