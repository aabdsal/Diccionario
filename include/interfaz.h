#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <limits>
#include <sys/ioctl.h>
#include "Dictionary.h"
// añadir interfaz donde permita elegir al usuario que acciones realizar
void portada();
void opciones(Diccionario &dic);
void espaienBlanc(string &p, int l);

#endif