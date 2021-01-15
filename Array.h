#include <iostream>
#include <sstream>
#include "IteradorArrayList.h"
using namespace std;
template<class T>
class ArrayList
{
private:
	T** datos;
	int capacidadActual;
	int cantidad;
	void asegurarCapacidad()
	{
		if (this->cantidad == this->capacidadActual)
		{
			// Se duplica la capacidad actual del arreglo.
			this->capacidadActual = capacidadActual * 2;
			T** nuevoArreglo = new T * [this->capacidadActual];

			// Se copian los elementos almacenados en el nuevo arreglo
			for (int i = 0; i < this->cantidad; i++)
			{
				nuevoArreglo[i] = this->datos[i];
			}

			// Se elimina el arreglo anterior y se actualiza el arreglo actual
			delete[] this->datos;
			this->datos = nuevoArreglo;

			// Se inicializan las nuevas posiciones libres
			for (int i = this->cantidad; i < this->capacidadActual; i++)
			{
				this->datos[i] = nullptr;
			}
		}
	}

public:
	ArrayList(int capacidadInicial)
	{
		this->capacidadActual = capacidadInicial;
		this->cantidad = 0;
		this->datos = new T * [this->capacidadActual];

		for (int i = 0; i < this->capacidadActual; i++)
		{
			this->datos[i] = nullptr;
		}
	}
	void insertarAlFinal(T* elemento)
	{
		asegurarCapacidad();
		this->datos[this->cantidad++] = elemento;
	}
	void insertarEnPosicion(T* elemento, int posicion)
	{
		if (posicion > this->cantidad)
		{
			cerr << "Posicion de insercion invalida" << endl;
			return;
		}

		asegurarCapacidad();
		for (int i = this->cantidad - 1; i >= posicion; i--)
		{
			this->datos[i + 1] = this->datos[i];
		}
		this->datos[posicion] = elemento;
		this->cantidad++;
	}
	void borrarEnPosicion(int posicion, bool liberarMemoria = false)
	{
		if (posicion >= this->cantidad)
		{
			cerr << "Posicion de eliminacion invalida" << endl;
			return;
		}

		if (liberarMemoria && this->datos[posicion])
		{
			delete this->datos[posicion];
		}

		for (int i = posicion; i < this->cantidad - 1; i++) {
			this->datos[i] = datos[i + 1];
		}

		this->datos[this->cantidad - 1] = nullptr;
		this->cantidad--;
	}
	T* consultarPorPosicion(int posicion)
	{
		if (posicion >= this->cantidad)
		{
			cerr << "Posicion invalida" << endl;
			return nullptr; // Posicion estaba fuera de los límites de la colección
		}

		return this->datos[posicion];
	}
	bool contiene(T* elemento)
	{
		for (int i = 0; i < this->cantidad; i++)
		{
			if (this->datos[i] == elemento)
				return true;
		}
		return false;
	}
	int getCantidad()
	{
		return this->cantidad;
	}
	void setCantidad(int cant)
	{
		this->cantidad = cant;
	}
	void liberarDatosInternos()
	{
		for (int i = 0; i < this->cantidad; i++)
		{
			if (this->datos[i])
			{
				delete this->datos[i];
				this->datos[i] = nullptr;
			}
		}

		this->cantidad = 0;
	}
	string toString()
	{
		stringstream s;
		for (int i = 0; i < this->cantidad; i++)
		{
			if (this->datos[i])
			{

				s << *this->datos[i] << endl;
			}
		}
		return s.str();
	}
	IteradorArrayList<T>* obtenerIterador()
	{
		return new IteradorArrayList(this->datos, this->cantidad);
	}
	~ArrayList()
	{
		delete[] this->datos;
	}
};