#include "../include/BST.h"

using namespace std;

void insert(BST *&info, string palabra, string definicion)
{
    if (info == nullptr)
    {
        info = new BST(palabra, definicion);
        return;
    }
    
    if (palabra > info->palabra) // ordenamos de menor a mayor de izquierda a derecha
    {
        insert(info->derecho, palabra, definicion);
    } 
    else
    {
        insert(info->izquierdo, palabra, definicion);
    }
}

void borrar(BST *&info, string palabra){ // las palabras se ordenan de menor a mayor, de izquierda a derecha
    if (info == nullptr)
    {
        return;
    }
    
    if (palabra == info->palabra)
    { 

        if (info->izquierdo == nullptr && info->derecho == nullptr) // Caso donde no hay hijos
        {
            delete info;
            info = nullptr;
        }
        else if (info -> izquierdo == nullptr) // Caso para cuando hay un hijo o a la izquierda o la derecha
        {
            BST *aux = info->derecho;
            delete info;
            info = aux;
        }
        else if (info->derecho == nullptr)
        {
            BST *aux = info->izquierdo;
            delete info;
            info = aux;
        }
        else  //Caso para cuando hay 2 hijos, uno debera de hacer del padre de otro
        {
            // Recorrido predecesor en inOrden
            BST *aux = info->izquierdo;
            while (aux->derecho != nullptr){aux = aux->derecho;}

            info->palabra = aux->palabra;
            info->definicion = aux->definicion;
            borrar(info->izquierdo,aux->palabra);
        }
        
        return ;
    }
    else if (palabra > info->palabra) // el operador > ya mira si una palabra es mayor que otra por orden alfabetico
    {
        borrar(info->derecho, palabra);
    } 
    else
    {
        borrar(info->izquierdo, palabra);
    }   
}
bool buscar(BST *&info, string palabra)
{
    if (info == nullptr) 
    {    
        return false;
    }
    
    if(palabra == info->palabra)
    {
        return true;
    }

    if (palabra > info->palabra) // ordenamos de menor a mayor de izquierda a derecha
    { 
        return buscar(info->derecho, palabra);
    } 
    else
    {
        return buscar(info->izquierdo, palabra);
    }
}

void imprimirInOrden(BST *&diccionario) // Así imprimiremos las palabras en orden alfabetico
{ 
    if (diccionario == nullptr)
    {
        return;
    }
    
    imprimirInOrden(diccionario->izquierdo);
    cout << "Palabra: " << diccionario->palabra << " Definición: " << diccionario->definicion << endl << endl;
    imprimirInOrden(diccionario->derecho);
}

void imprimirRango(BST *&diccionario, const string &desde, const string &hasta)
{

    if (diccionario == nullptr)
    {
        return;
    }

    imprimirRango(diccionario->izquierdo, desde, hasta);

    if (diccionario->palabra >= desde && diccionario->palabra <= hasta) // los operadores ya controlan
    {
        cout << "Palabra: " << diccionario->palabra << " Definición: " << diccionario->definicion << endl << endl;
    }

    imprimirRango(diccionario->derecho, desde, hasta);
}