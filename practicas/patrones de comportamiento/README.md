# 🧠 Semana 7 – Patrones de Comportamiento: Observer, Strategy, Command

> [!TIP]
> En esta unidad se abordan los **patrones de comportamiento**, que permiten gestionar la **comunicación entre objetos** y mejorar el **desacoplamiento** del sistema.

---

## 🎯 Objetivo
Implementar patrones de comportamiento que gestionen la comunicación entre objetos, optimizando la **interacción**, la **flexibilidad** y el **desacoplamiento** del software.

---

## 📘 Marco Teórico

### 👁️ Observer
> Mantiene la sincronización entre objetos. Cuando un objeto cambia de estado, sus observadores son notificados automáticamente.  
> 📍 Ejemplo: sistemas de notificación o suscripción.

### 🧮 Strategy
> Permite seleccionar algoritmos dinámicamente en tiempo de ejecución.  
> 📍 Ejemplo: elegir entre diferentes algoritmos de ordenamiento (burbuja, quicksort, merge sort).

### ⚙️ Command
> Encapsula operaciones dentro de objetos independientes, lo que facilita implementar funciones como *undo/redo* o *macros*.  
> 📍 Ejemplo: un editor de texto que permite “guardar” y “deshacer”.

---

## 🧩 Desarrollo Práctico

1. 💬 Crear un sistema de notificaciones **Observer** para usuarios de un chat.[Ver codigo](./1.cpp)
2. 🧠 Usar **Strategy** para elegir diferentes algoritmos de ordenamiento (*burbuja*, *quicksort*).[Ver codigo](./2.cpp)
3. 📝 Implementar **Command** para un editor de texto con comandos “guardar” y “deshacer”.[Ver codigo](./3.cpp)

---

## 📚 Trabajo de Investigación

- 🔸 Investigar cómo **Android LiveData** implementa el patrón *Observer*.  
- 🔸 Analizar el uso de *Strategy* en librerías de **IA** (ejemplo: selección de optimizadores en *PyTorch*).  
- 🔸 Explorar cómo *Command* se usa en **videojuegos** para gestionar acciones del jugador.
- Trabajo en Latex  [Ver en Overleaf](./https://www.overleaf.com/read/zrhjdwqpfsrm#be3bfd)
