#ifndef BST_H
#define BST_H

#include <iostream>

struct BST // Binary Search tree
{
    std::string palabra;
    std::string definicion;
    BST *izquierdo;
    BST *derecho;

    BST(std::string palabra, std::string definicion){
        this->palabra = palabra;
        this->definicion = definicion;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};
// No puedes crear tipos de datos de strucutras fuera de una función

void insert(BST *&info, std::string palabra, std::string definicion);
void borrar(BST *&info, std::string palabra);
bool buscar(BST *&info, std::string palabra);
void imprimirInOrden(BST *&diccionario);
void imprimirRango(BST *&diccionario, std::string &desde, std::string &hasta);


/*void func(){
    BST *pepe;
    pepe->palabra = "tabunmuk";
}*/


#endif //BST_H
