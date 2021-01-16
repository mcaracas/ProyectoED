#pragma once
#include"Array.h"
#include"IComparador.h"
#include<iostream>
#include<algorithm> 
using namespace std;
template<class T>
class HPQ
{
private:
	ArrayList<T>* lista;
    int cantidad = 0;
    IComparador<T>* comp;

public:
    void setCantidad(int cantidad) {
        this->cantidad = cantidad;
    }
    int getCantidad() {
        return this->cantidad;
    }
	HPQ()
	{
		this->lista = new ArrayList<T> (16);
	}
	HPQ(ArrayList<T>* lista, IComparador<T>* comp)
	{
		this->lista = lista;
	}
	~HPQ()
	{

	}
    int parent(int i)
    {

        return (i - 1) / 2;
    }

    void setComparador(IComparador<T>* comp)
    {
        this->comp = comp;
    }


    int leftChild(int i)
    {

        return ((2 * i) + 1);
    }


    int rightChild(int i)
    {

        return ((2 * i) + 2);
    }

  
    void shiftUp(int i)
    {

        while (i > 0 && comp->comparaMenor(*this->lista->consultarPorPosicion(parent(i)), *this->lista->consultarPorPosicion(i)))
        {

            swap(*this->lista->consultarPorPosicion(parent(i)), *this->lista->consultarPorPosicion(i));

            i = parent(i);
        }
    }


    void shiftDown(int i)
    {
        int maxIndex = i;


        int l = leftChild(i);

        if (l < getLista()->getCantidad() && comp->comparaMayor(*this->lista->consultarPorPosicion(l), *this->lista->consultarPorPosicion(maxIndex))) {

            maxIndex = l;
        }


        int r = rightChild(i);

        if (r < getLista()->getCantidad() && comp->comparaMayor(*this->lista->consultarPorPosicion(r), *this->lista->consultarPorPosicion(maxIndex))) {
            maxIndex = r;
        }

        if (i != maxIndex) {
            swap(*this->lista->consultarPorPosicion(i), *this->lista->consultarPorPosicion(maxIndex));
            shiftDown(maxIndex);
        }
    }


    void insert(T p)
    {
        T* s = new T(p);
        int i = this->lista->getCantidad();
        this->lista->insertarAlFinal(s);
        shiftUp(i);
        this->cantidad++;
    }


    T extractMax()
    {
        T result = *this->lista->consultarPorPosicion(0);


        *this->lista->consultarPorPosicion(0) = *this->lista->consultarPorPosicion(this->lista->getCantidad()-1); //eso si pasa?
        this->getLista()->setCantidad(this->getLista()->getCantidad() - 1);


        shiftDown(0);
        this->cantidad--;
        return result;
    }


    void changePriority(int i, T p)
    {
        T oldp = *this->lista->consultarPorPosicion(i);
        *this->lista->consultarPorPosicion(i) = p;

        if (p > oldp) {
            shiftUp(i);
        }
        else {
            shiftDown(i);
        }
    }

    T getMax()
    {
        return *this->lista->consultarPorPosicion(0);
    }


    void remove(int i)
    {
        T* elemento = new T(getMax());
        this->lista->borrarEnPosicion(i);
        this->lista->insertarEnPosicion(elemento, i);

        shiftUp(i);
        this->cantidad--;
 
        extractMax();
    }
    ArrayList<T>* getLista() const
    {
        return this->lista;
    }
    
};