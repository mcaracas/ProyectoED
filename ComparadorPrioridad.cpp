#include "ComparadorPrioridad.h"

bool ComparadorPrioridad::comparaMenor(Cliente comp1, Cliente comp2)
{
    return comp1.calcularPrioridad(comp1) < comp2.calcularPrioridad(comp2);
}

bool ComparadorPrioridad::comparaMayor(Cliente comp1, Cliente comp2)
{
    return comp1.calcularPrioridad(comp1) > comp2.calcularPrioridad(comp2);
}

bool ComparadorPrioridad::comparaMenorIgual(Cliente comp1, Cliente comp2)
{
    return comp1.calcularPrioridad(comp1) <= comp2.calcularPrioridad(comp2);
}

bool ComparadorPrioridad::comparaMayorIgual(Cliente comp1, Cliente comp2)
{
    return comp1.calcularPrioridad(comp1) >= comp2.calcularPrioridad(comp2);
}