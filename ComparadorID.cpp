#include "ComparadorID.h"

bool ComparadorID::comparaMenor(Cliente comp1, Cliente comp2)
{
    return comp1.getId() < comp2.getId();
}

bool ComparadorID::comparaMayor(Cliente comp1, Cliente comp2)
{
    return comp1.getId() > comp2.getId();
}

bool ComparadorID::comparaMenorIgual(Cliente comp1, Cliente comp2)
{
    return comp1.getId() <= comp2.getId();
}

bool ComparadorID::comparaMayorIgual(Cliente comp1, Cliente comp2)
{
    return comp1.getId() >= comp2.getId();
}