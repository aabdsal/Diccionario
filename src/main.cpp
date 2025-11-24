#include "interfaz.h"

int main(int argc, char const *argv[])
{
    try
    {
        portada();
        Diccionario dic;
        opciones(dic);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
