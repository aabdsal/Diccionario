#include "Dictionary.h"

using namespace std;

void insertarPalabra(Diccionario &dic, const string &p, const string &d)
{
    dic.hash[p].definicion = d;
    if (!buscar(dic.raiz,p))
    {
        insert(dic.raiz, p, d);
        dic.hash[p].frecuencia = 0;
    } 
}

void inOrdenLev(BST *&dic, const string &pUsuario, vector <string> &listaSugerencias, int &mejorDistancia)
{
    if (dic == nullptr)
    {
        return;
    }
    
    inOrdenLev(dic->izquierdo, pUsuario, listaSugerencias, mejorDistancia);

    vector <vector <int> > memo(pUsuario.size() + 1, vector<int>(dic->palabra.size() + 1, -1));

    int distancia = levenshtein(pUsuario, dic->palabra, pUsuario.size(), dic->palabra.size(), memo);
    if (distancia < mejorDistancia)
    {
        mejorDistancia = distancia;
        listaSugerencias.clear();
        listaSugerencias.push_back(dic->palabra);
    }
    else if(distancia == mejorDistancia)
    {
        listaSugerencias.push_back(dic->palabra);
    }

    inOrdenLev(dic->derecho, pUsuario, listaSugerencias, mejorDistancia);
}

void buscarPalabra(Diccionario &dic, const string &p)
{
    
    if (dic.hash.find(p) != dic.hash.end()) 
    {
        cout << "Palabra encontrada" << endl;
        cout << "Definición: " << dic.hash[p].definicion << endl;
        dic.hash[p].frecuencia++;
    }
    else
    {        
        int mejorDistancia = INT_MAX;
        vector <string> listaSugerencias;
        inOrdenLev(dic.raiz, p, listaSugerencias, mejorDistancia);
        if (listaSugerencias.empty()) // 
        {
           cout << "No se encuentran sugerencias para tu palabra ❌" << endl;
        }
        else
        {
            cout << "Quiza querías decir:";
            for (auto parecidas : listaSugerencias)
            {
                cout << parecidas << " ";
            }
            cout << "☺️" <<  endl;
        }
    }
}
void borrarPalabra(Diccionario &dic, const string &p)
{
    dic.hash.erase(p);
    if (buscar(dic.raiz, p))
    {
        borrar(dic.raiz, p);
        cout << "Palabra borrada del diccionario con éxito ✅" << endl;
    }
}

void leerArchivo(Diccionario &dic)
{
    string fich;
    cout << "Dime el nombre del fichero: ";
    cin >> fich;

    ifstream fichero(fich);
    if (!fichero.is_open())
    {
        throw runtime_error("No se ha podido abrir el archivo");
    }
    fich.clear();

    while (getline(fichero, fich))
    {
        if (fich.empty())
        {
            continue;
        }
        
        size_t i = fich.find(' ');

        string p, d;
        p = fich.substr(0, i);
        d = fich.substr(i + 1);

        insertarPalabra(dic, p, d);
    }
    fichero.close();
}

void mostrarTopBuscadas(Diccionario &dic, int N) 
{

    vector<pair<string, int>> v;

    for (const auto &par : dic.hash) 
    {
        const string &palabra = par.first;
        int freq = par.second.frecuencia;
        v.push_back({palabra, freq});
    }

    if (v.empty()) 
    {
        cout << "No hay palabras en el diccionario todavía.\n";
        return;
    }

    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {return a.second > b.second;});

    cout << "Palabras mas buscadas:\n";
    
    int limite = min(N, (int)v.size());

    for (int i = 0; i < limite; ++i) 
    {

        if(v[i].second != 0)
        {
            cout << i + 1 << ". " << v[i].first << " (buscada " << v[i].second << " veces)\n";
        }      
    }
}
