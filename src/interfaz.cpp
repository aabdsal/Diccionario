#include "interfaz.h"
using namespace std;

void portada()
{
    string blanc = "";
    espaienBlanc(blanc, 87);

    cout << endl << blanc << "**************************************************************************************" << blanc << endl;
    cout << blanc << "*                                                                                    *" << blanc << endl;
    cout << blanc << "*                                DICCIONARIO AUTOMÁTICO                              *" << blanc << endl;
    cout << blanc << "*                                                                                    *" << blanc << endl;
    cout << blanc << "**************************************************************************************" << blanc << endl;
    cout << blanc << "Hecho por Ali Abdelhamid" << endl << endl; 

}
void opciones(Diccionario &dic)
{
    string blanc = "";
    espaienBlanc(blanc, 87);

    cout << blanc << "                              ¿Que deseas hacer?" << endl;
    cout << blanc << "1: Buscar Palabra en el Diccionario.        2: Añadir entrada al diccionario." << blanc <<  endl;
    cout << blanc << "3: Añadir palabras desde un archivo.        4: Borrar Palabra del Diccionario." << blanc << endl;
    cout << blanc << "5: Mostrar todas las palabras guardadas.    6: Mostrar palabras más buscadas." << blanc << endl;
    cout << blanc << "7: Salir del programa." << endl << endl;
    
    cout << blanc << "Elige una: ";
    int n; 
    if(!(cin >> n))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Caracter no válido" << endl;
        opciones(dic);
    }
    
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

void espaienBlanc(string &p, int l)
{
    struct ttysize ts;
    ioctl(0, TIOCGSIZE, &ts);
    
    for (int i = 0; i < (int)(ts.ts_cols - l)/2; i++)
    {
        p+= " ";
    }
}




