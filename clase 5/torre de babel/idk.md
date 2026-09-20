## ejemplo de lo que deberia salir en consola 
```

        =|=               |                |
       ==|==              |                |
      ===|===             |                |
     ====|====            |                |
    =====|=====           |                |
   ======|======          |                |
  =======|=======         |                |       
‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
```
### para hacer funcional esto podrias usar esto:
```c++
 <<setw(ammount)
```
### ejemplo de uso con un codigo que hice:

```c++
cout<<
        "╔════════════════════════════════╦══════════════╗\n"<<
        "║  listar productos              ║ precio       ║\n"<<
        "╠════════════════════════════════╬══════════════╣\n";
        for (int i = 0; i < (amount); i++)
        {
            cout<< "║" << " " <<setw(31) <<NameP[i]<< "║"<< " " <<setw(13) <<PriceofP[i]<< "║"<<endl;
        }
        cout<<
        "╚════════════════════════════════╩══════════════╝\n";a
```
### la salida es esta:
```
╔════════════════════════════════╦══════════════╗
║  listar productos              ║ precio       ║
╠════════════════════════════════╬══════════════╣
║                   Pasta termica║          45.5║
║             alchol isopropilico║         12.99║
║                       microfono║         89.99║
║                         monitor║        215.75║
║                           mouse║          39.9║
╚════════════════════════════════╩══════════════╝
```

---
# Como usar el "setw" en c++ (explicado gemini)

El manipulador **`setw`** (proviene de *Set Width* o "Establecer Ancho") sirve para **darle un tamaño fijo a una columna** en la terminal. Es la herramienta ideal cuando necesitas alinear texto, números o armar tablas limpias en la consola.

---

### 1. 🛠️ El Requisito Obligatorio
Para poder usar `setw`, siempre debes incluir la librería de manipulación de entrada/salida al inicio de tu código:

```cpp
#include <iomanip> // 👈 ¡No la olvides!
```

---

### 2. ⚡ Las 3 Reglas de Oro de `setw`

1. **Es de un solo uso:** `setw` **solo afecta al elemento que tiene inmediatamente a la derecha**. Si quieres aplicarlo a tres palabras seguidas, tienes que escribir `setw` tres veces.
2. **Alineación por defecto:** Todo lo que metas en un `setw` se alineará automáticamente a la **derecha**.
3. **No corta el texto:** Si defines un ancho de 5 (`setw(5)`), pero tu palabra mide 8 letras, C++ **no la va a recortar**. Mostrará la palabra completa y tu tabla se desalineará. ¡Asegúrate de dar el ancho suficiente!

---

### 3. 💻 Código de Ejemplo Paso a Paso

Copia este código y pruébalo. Mira cómo usamos `setw` antes de cada dato para obligarlos a medir lo mismo:

```cpp
#include <iostream>
#include <iomanip> // Librería necesaria

using namespace std;

int main() {
    // 1. Encabezados de la tabla (Ancho de 15 para Producto, 10 para Precio)
    cout << setw(15) << "PRODUCTO" << setw(10) << "PRECIO" << endl;
    cout << "-----------------------------------" << endl;
    
    // 2. Filas de datos
    // "Manzanas" se dibuja en un espacio de 15 caracteres; "1.50" en uno de 10.
    cout << setw(15) << "Manzanas" << setw(10) << "1.50" << endl;
    cout << setw(15) << "Leche" << setw(10) << "2.20" << endl;
    cout << setw(15) << "Pescado fresco" << setw(10) << "15.00" << endl;
    
    return 0;
}
```

---

### 4. 🚀 Trucos Avanzados (Para complementar)

Si quieres llevar tus tablas al siguiente nivel, puedes combinar `setw` con estos dos comandos:

#### A) `left` y `right` (Cambiar la alineación)
Si no quieres que el texto se alinee a la derecha, escribe `left` antes de tus variables. Esto se queda activo para todo el código hasta que vuelvas a escribir `right`.

```cpp
// Alinea el texto a la izquierda dentro de sus 15 espacios
cout << left << setw(15) << "Manzanas" << right << setw(10) << "1.50" << endl;
```

#### B) `setfill('carácter')` (Rellenar espacios vacíos)
Por defecto, `setw` llena el espacio sobrante con espacios en blanco. Con `setfill` puedes cambiarlo por puntos, guiones o lo que quieras:

```cpp
// Rellena el vacío con puntos en lugar de espacios
cout << left << setw(20) << setfill('.') << "Internet" << "CONECTADO" << endl;

// Resultado en consola:
// Internet............CONECTADO
```