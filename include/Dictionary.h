#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include "BST.h"
#include "Levenshtein.h"

using namespace std;

struct InfoPalabra {
    string definicion;
    int frecuencia;
};

struct Diccionario {
    BST *raiz;
    unordered_map<string, InfoPalabra> hash;
};

void insertarPalabra(Diccionario &dic, const string &p, const string &d);
void buscarPalabra(Diccionario &dic, const string &p);
void borrarPalabra(Diccionario dic, const string &p);
void inOrdenLev(BST *&dic, const string &p, vector <string> &listaSugerencias, int &mejorDistancia);
void leerArchivo();
void mostrarTopBuscadas(Diccionario &dic, int N);

#endif