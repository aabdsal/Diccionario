#include "../include/Levenshtein.h"
#include <iostream>
#include <string>

using namespace std;

// implementar programacion dinamica
int levenshtein(const string &from, const string &to, int i, int j, vector <vector <int> > &memo){

    if (i == 0){return j;}
    if(j == 0){return i;}

    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    
    int cost = (from[i] == to[j]) ? 0 : 1;

    int borrar = levenshtein(from, to, i, j -1, memo) + 1;
    int insertar = levenshtein(from, to, i - 1, j, memo) + 1;
    int sustituir = levenshtein(from, to, i - 1, j - 1, memo) + cost;

    memo[i][j] = min(borrar,min(insertar,sustituir));
    return memo[i][j];
    
}

