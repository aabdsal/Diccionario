#include "Dictionary.h"

void insertarPalabra(Diccionario &dic, string &p, string &d){
    dic.hash[p].definicion = d;
    if (!buscar(dic.raiz,p))
    {
        insert(dic.raiz, p, d);
        dic.hash[p].frecuencia = 0;
    } 
}

void inOrdenLev(BST *&dic, const string &pUsuario, vector <string> &listaSugerencias, int &mejorDistancia){
    if (dic == nullptr){return;}
    
    inOrdenLev(dic->izquierdo, pUsuario, listaSugerencias, mejorDistancia);

    vector <vector <int> > memo(pUsuario.size() + 1, vector<int>(dic->palabra.size() + 1, -1));

    int distancia = levenshtein(pUsuario, dic->palabra, pUsuario.size(), dic->palabra.size(), memo);
    if (distancia < mejorDistancia)
    {
        mejorDistancia = distancia;
        listaSugerencias.clear();
        listaSugerencias.push_back(dic->palabra);
    }
    else if(distancia == mejorDistancia){
        listaSugerencias.push_back(dic->palabra);
    }

    inOrdenLev(dic->derecho, pUsuario, listaSugerencias, mejorDistancia);
}

void buscarPalabra(Diccionario &dic, const string &p){
    auto it = dic.hash.find(p);
    if (it != dic.hash.end()) {
        cout << "Palabra encontrada" << endl;
        cout << "Definición: " << it->second.definicion << endl;
    }
    else{
        int mejorDistancia = INT_MAX;
        vector <string> listaSugerencias;
        inOrdenLev(dic.raiz, p, listaSugerencias, mejorDistancia);
        if (listaSugerencias.empty()) // 
        {
           cout << "No se encuentran sugerencias para tu palabra ❌" << endl;
        }
        else{
            cout << "¿quiza querías decir: ?";
            for (auto parecidas : listaSugerencias)
            {
                cout << parecidas << " ";
            }
            cout << "☺️" <<  endl;
        }
    }
    it->second.frecuencia++;
}
void borrarPalabra(Diccionario dic, const string &p){
    dic.hash.erase(p);
    if (buscar(dic.raiz, p))
    {
        borrar(dic.raiz, p);
        cout << "Palabra borrada del diccionario con éxito ✅" << endl;
    }
}

void leerArchivo(){
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
        string p, d;
        istringstream ss;

        ss >> p >> d;
        Diccionario dic;
        insertarPalabra(dic, p, d);
    }
    fichero.close();
}

void mostrarTopBuscadas(Diccionario &dic, int N) {
    // 1. Pasar del hash a un vector
    vector<pair<string, int>> v; // (palabra, frecuencia)

    for (const auto &par : dic.hash) {
        const string &palabra = par.first;
        int freq = par.second.frecuencia;
        v.push_back({palabra, freq});
    }

    if (v.empty()) {
        cout << "No hay palabras en el diccionario todavía.\n";
        return;
    }

    // 2. Ordenar por frecuencia descendente
    sort(v.begin(), v.end(),
         [](const auto &a, const auto &b) {
             return a.second > b.second; // mayor frecuencia primero
         });

    // 3. Imprimir las primeras N
    cout << "Palabras mas buscadas:\n";
    int limite = min(N, (int)v.size());
    for (int i = 0; i < limite; ++i) {
        cout << i + 1 << ". " << v[i].first
             << " (buscada " << v[i].second << " veces)\n";
    }
}
