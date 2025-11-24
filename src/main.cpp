#include "Levenshtein.h"
#include "Dictionary.h"
#include "BST.h"
#include "interfaz.h"

int main(int argc, char const *argv[])
{
    try
    {
        portada();
        opciones();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
