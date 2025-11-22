#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct BST // Binary Search tree
{
    int frecuencia = 0;
    string palabra;
    string definicion;
    BST *izquierdo;
    BST *derecho;

    BST(string palabra, string definicion){
        this->palabra = palabra;
        this->definicion = definicion;
        frecuencia++;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};
// No puedes crear tipos de datos de strucutras fuera de una función

void insert(BST *&info, string palabra, string definicion);
void borrar(BST *&info, string palabra);
void buscar(BST *&info, string palabra);
void imprimirInOrden(BST *&diccionario);
void imprimirRango(BST *&diccionario, string &desde, string &hasta);


/*void func(){
    BST *pepe;
    pepe->palabra = "tabunmuk";
}*/


#endif //BST_H
