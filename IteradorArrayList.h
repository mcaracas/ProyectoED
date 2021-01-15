#pragma once
template<class T>
class IteradorArrayList
{
private:
	T** arreglo;
	int cantidad;
	int posicionActual;

public:
	IteradorArrayList(T** arreglo, int cantidad)
	{
		this->arreglo = arreglo;
		this->cantidad = cantidad;
		this->posicionActual = 0;
	}
	bool haySiguiente()
	{
		if (this->posicionActual >= this->cantidad)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	T* actual()
	{
		if (this->haySiguiente()) {
			T* dato = this->arreglo[this->posicionActual];
			this->posicionActual++;
			return dato;
		}
		return nullptr;
	}
};