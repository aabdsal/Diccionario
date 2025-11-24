#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <map>
#include <fstream>
#include "BST.h"
#include "Levenshtein.h"
#include <unistd.h>

using namespace std;

struct InfoPalabra {
    string definicion;
    int frecuencia;
};

struct Diccionario {
    BST *raiz = nullptr;
    unordered_map<string, InfoPalabra> hash;
};

void insertarPalabra(Diccionario &dic, const string &p, const string &d);
void buscarPalabra(Diccionario &dic, const string &p);
void borrarPalabra(Diccionario &dic, const string &p);
void inOrdenLev(BST *&dic, const string &p, vector <string> &listaSugerencias, int &mejorDistancia);
void leerArchivo(Diccionario &dic);
void mostrarTopBuscadas(Diccionario &dic, int N);

#endif