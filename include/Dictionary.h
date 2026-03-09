#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <map>
#include <fstream>
#include "BST.h"
#include "Levenshtein.h"
#include <unistd.h>


struct InfoPalabra {
    std::string definicion;
    int frecuencia;
};

struct Diccionario {
    BST *raiz = nullptr;
    std::unordered_map<std::string, InfoPalabra> hash;
};

void insertarPalabra(Diccionario &dic, const std::string &p, const std::string &d);
void buscarPalabra(Diccionario &dic, const std::string &p);
void borrarPalabra(Diccionario &dic, const std::string &p);
void inOrdenLev(BST *&dic, const std::string &p, std::vector <std::string> &listaSugerencias, int &mejorDistancia);
void leerArchivo(Diccionario &dic);
void mostrarTopBuscadas(Diccionario &dic, int N);

#endif