# 📚 Diccionario Automático en C++

Proyecto de consola en C++ que implementa un **diccionario interactivo** usando estructuras de datos y algoritmos clásicos:

- 🌳 Árbol de búsqueda binaria (BST)
- 🧩 `unordered_map` (hash)
- 🧠 Programación dinámica (distancia de Levenshtein)
- 📈 Conteo de frecuencias para mostrar las palabras más consultadas

---

## 🧾 Objetivo del proyecto

Practicar:

- Estructuras de datos (BST + hash).
- Algoritmos de búsqueda y borrado en árboles.
- Programación dinámica con distancia de Levenshtein para sugerencias.
- Organización de un proyecto C++ con `src/`, `include/`, `bin/`, `data/` y `Makefile`.

---

## 🗂️ Estructura del proyecto

```text
AutoDiccionario/
├─ src/
│  ├─ main.cpp
│  ├─ BST.cpp
│  ├─ Dictionary.cpp
│  ├─ Levenshtein.cpp
│  └─ interfaz.cpp
├─ include/
│  ├─ BST.h
│  ├─ Dictionary.h
│  ├─ Levenshtein.h
│  └─ interfaz.h
├─ data/
│  └─ palabras.txt        # fichero de ejemplo
├─ bin/
│  └─ main                # ejecutable generado
└─ Makefile