#pragma once
using namespace std;
template <class T>
class IComparador
{
public:
	virtual bool comparaMenor(T comp1, T comp2) = 0;
	virtual bool comparaMayor(T comp1, T comp2) = 0;
	virtual bool comparaMenorIgual(T comp1, T comp2) = 0;
	virtual bool comparaMayorIgual(T comp1, T comp2) = 0;
	virtual ~IComparador() {};
};