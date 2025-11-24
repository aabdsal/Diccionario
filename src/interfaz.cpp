#include "interfaz.h"
using namespace std;

void portada(){
    cout << endl << "************************************************************************************************" << endl;
    cout << "************************************************************************************************" << endl;
    cout << "*************************** Diccionario Automático *********************************************" << endl;
    cout << "************************************************************************************************" << endl;
    cout << "************************************************************************************************" << endl;
    cout << "Made by Ali Abdelhamid" << endl << endl; 

}
void opciones(Diccionario &dic){
    
    cout << endl << "¿Que deseas hacer?☺️" << endl;
    cout << "1: Buscar Palabra en el Diccionario.       2: Añadir entrada al diccionario." << endl;
    cout << "3: Añadir palabras desde un archivo.       4: Borrar Palabra del Diccionario." << endl;
    cout << "5: Mostrar todas las palabras guardadas.    6: Mostrar palabras más buscadas." << endl;
    cout << "7: Salir del programa." << endl << endl;
    
    cout << "Elige una: ";
    int n; cin >> n;
    string p, definicion;

    switch(n)
    {
    case 1:
        cout << "Dime la palabra a buscar: ";
        cin >> p;
        buscarPalabra(dic, p);
        break;
    
    case 2:
        cout << "Dime la palabra a añadir: " ;
        cin >> p;
        cin.ignore();
        cout << endl << "Definición: ";
        getline(cin, definicion);
        insertarPalabra(dic, p, definicion);
        cout << "Palabra insertada con éxito ✅" << endl;
        break;
    
    case 3:
        leerArchivo(dic);
        cout << "Fichero insertado con éxito ✅" << endl;
        break;
    
    case 4:
        cout << "Dime la palabra a borrar: ";
        cin >> p;
        borrarPalabra(dic, p);
        break;
    
    case 5:
        imprimirInOrden(dic.raiz);
        break;
    
    case 6:
        mostrarTopBuscadas(dic, 5);
        break;
    case 7:
        return;
    default:
        cout << "Número inválido" << endl;
        break;
    }
    opciones(dic);
}







