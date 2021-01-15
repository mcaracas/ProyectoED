#pragma once
#include"IComparador.h"
#include"Cliente.h"

class ComparadorPrioridad : public IComparador<Cliente>
{
public:
	virtual bool comparaMenor(Cliente comp1, Cliente comp2) override;
	virtual bool comparaMayor(Cliente comp1, Cliente comp2) override;
	virtual bool comparaMenorIgual(Cliente comp1, Cliente comp2) override;
	virtual bool comparaMayorIgual(Cliente comp1, Cliente comp2) override;
};