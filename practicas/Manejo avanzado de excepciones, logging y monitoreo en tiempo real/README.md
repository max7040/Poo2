# 🧩 Práctica Semana 9 – Manejo avanzado de excepciones, logging y monitoreo en tiempo real

> [!TIP]
> En esta práctica se aplican técnicas avanzadas de **manejo de excepciones**, **registro de eventos (logging)** y **monitoreo en tiempo real** usando *C++*.

---

## 📚 Curso
**Programación Orientada a Objetos II**
---

## 🎯 Objetivos

- Implementar **jerarquías de excepciones personalizadas** en *C++*.  
- Integrar un sistema de **logging** para registrar eventos críticos y de depuración.  
- Simular un **monitoreo en tiempo real** con registro de errores y métricas del sistema.

---

## 🧠 Marco Teórico

### ⚠️ Excepciones personalizadas
> Permiten representar errores específicos con mayor semántica que `std::exception`.  
> 📍 Ejemplo: crear clases como `DivisionPorCeroException` o `EntradaInvalidaException` para diferenciar tipos de error.

### 🧾 Logging
> Es el registro estructurado de eventos del sistema, útil para **depuración, auditoría y análisis de errores**.  
> 📍 En *C++* se puede implementar manualmente con archivos de texto o con librerías como **spdlog**, **Boost.Log** o **log4cpp**.

### 📈 Monitoreo en tiempo real
> Implica capturar métricas, errores y estados de ejecución mientras el programa está en marcha.  
> 📍 Se puede combinar con herramientas externas (como *Grafana*, *Kibana* o *Prometheus*) para análisis visual.

---

## ⚙️ Desarrollo Práctico

1. 🔹 Compilar y ejecutar el programa.  
2. 🔹 Verificar que el archivo **`system.log`** se genere con los errores registrados.  
3. 🔹 Simular distintos errores (*división entre cero, valores negativos, entradas no numéricas*).  
4. 🔹 Implementar un ciclo que divida una lista de números y registre errores de forma continua (*monitoreo en tiempo real*).

---

## 🧩 Trabajo de Investigación

1. 📘 Investigar y documentar **3 librerías profesionales de logging** en *C++* (ejemplo: `spdlog`, `Boost.Log`, `log4cpp`).  
2. ⚙️ Explicar cómo se integran con **herramientas de monitoreo en tiempo real** (*Grafana*, *Kibana*, *Prometheus*).  
3. 📝 Adjuntar un **informe en Word** con comparaciones y ejemplos de uso.
