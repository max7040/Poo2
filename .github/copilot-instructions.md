## Contexto rápido

Repositorio "Poo2" — colección de ejercicios en C++ organizados por capítulos (`capitulo7/`, `capitulo8/`, `capitulo9/`). El código está orientado a ejemplos didácticos de POO en C++ (clases, herencia, vectores, manejo de cadenas C, estructuras). Los ejecutables de ejemplo (compilados) están en `capitulo9/output/`.

## Objetivo del agente

Ayudar a editar y mejorar ejercicios en C++ (corrección de errores simples, refactor ligero, documentar, añadir validaciones). No hay un framework complejo: se trabaja con archivos .cpp independientes que contienen `main()` y clases de ejemplo.

## Estructura relevante

- `capitulo9/` : archivos `9-1.cpp` ... `9-8.cpp`, y `9-p1.cpp`..`9-p3.cpp` — ejercicios individuales, cada uno compilable y con un `main()` de prueba.
- `capitulo9/output/` : binarios compilados (ej. `9-1.exe`) — indican cómo se espera que se ejecuten los programas.
- `.vscode/settings.json` : asociaciones de archivos mínimas (no afecta compilación).

## Convenciones detectables (útiles para el agente)

- Cada archivo .cpp suele ser autónomo y contiene su propio `main()` y pruebas ligeras (imprime en consola). Evitar cambios que rompan `main()` sin proveer un equivalente de prueba.
- Uso mixto de estilos: clases con std::string y vectores en algunos archivos (`9-p1.cpp`), uso de arreglos C y funciones de `<cstring>` en otros (`9-p2.cpp`, `9-p3.cpp`). Mantener coherencia cuando se refactorice una unidad concreta, pero no imponer cambios globales.
- Comentarios en español explican intenciones y correcciones (por ejemplo conversión grados->radianes en `9-1.cpp`). Conservar/actualizar esos comentarios al corregir lógica.

## Flujo de trabajo para cambios rápidos (qué comandos ejecutar)

El proyecto no incluye un Makefile ni un build system; cada ejercicio se compila por separado. Recomendación para Windows PowerShell (usuario preferido):

```powershell
# Compilar un archivo de ejemplo (g++ requerido en PATH)
g++ -std=c++17 -O2 -Wall -Wextra -o capitulo9\output\9-1.exe capitulo9\9-1.cpp

# Ejecutar el binario
.
capitulo9\output\9-1.exe
```

Si `g++` no está disponible, sugerir instalar MinGW o usar Visual Studio/CL. Ajustar `-std` si hay macros C++ antiguas.

## Patrones y ejemplos concretos a usar en sugerencias

- Conversión unidades: `9-1.cpp` muestra la necesidad de convertir grados a radianes antes de `sin()` — busca llamadas a trigonometría y corrige unidades.
- Constructores múltiples: `9-p1.cpp` demuestra sobrecarga de constructores; al añadir funciones nuevas, mantener la semántica de los constructores y sus mensajes de depuración.
- Mezcla C/C++: `9-p2.cpp` y `9-p3.cpp` usan `char[]`, `strcpy`, `printf` y `cin.getline`. Cuando propongas modernizaciones, presenta una versión alternativa que use `std::string` y `std::getline` y deja la versión original intacta o documenta el cambio.

## Reglas para ediciones automáticas (prioridad y límites)

1. No eliminar o renombrar `main()` de archivos existentes sin proporcionar un binario de prueba alternativo.
2. Para correcciones lógicas pequeñas (p.ej., conversión de unidades, condición de verificación de fechas), aplicar el cambio directamente en el archivo con un comentario que explique el motivo.
3. Para refactorizaciones (p.ej., migrar `char[]` a `std::string`), crear una versión alternativa en el mismo directorio con sufijo `_modern.cpp` y dejar el original como referencia.
4. Evitar cambios que requieran dependencias externas o configuración de build adicional.

## Qué buscar en revisiones de PRs

- Mensajes de constructor/ destructor impresos en consola son parte del comportamiento esperado (ver `9-p1.cpp`). No eliminarlos sin confirmación.
- Validaciones de entrada: muchas funciones leen desde `cin`. Asegurar que las lecturas limpian el buffer (`cin.ignore()`) donde sea necesario.
- Uso de constantes: fechas y PI se definen localmente (ej. `ANIO_ACTUAL`, `PI`). Si propones mover a un header, documenta el impacto y añade include guards.

## Ejemplos concretos (referencias a líneas/files)

- Corrige conversión radianes en `capitulo9/9-1.cpp` (línea con comentario "CORRECCIÓN CRUCIAL").
- Al modificar vectores en `capitulo9/9-p1.cpp`, conservar la lógica que limita a 5 cursos (`NUM_CURSOS`) y el relleno con ceros.
- Preservar el manejo de buffer y llamadas a `cin.getline` en `capitulo9/9-p3.cpp` al refactorizar entrada de cadenas.

## Limitaciones y preguntas pendientes

- No hay tests automáticos; validar localmente compilando y ejecutando el `.exe` generado.
- No hay convenciones de formato obligatorias (clang-format/clang-tidy ausentes). Mantén estilo existente.

---

Si quieres, aplico estas reglas ahora para generar o actualizar archivos concretos (p.ej., añadir `9-1_modern.cpp` con mejoras) — dime qué archivo quieres que edite primero o si deseas que fusione este contenido con uno existente.
