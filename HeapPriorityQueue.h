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

    // Function to return the index of the 
    // left child of the given node 
    int leftChild(int i)
    {

        return ((2 * i) + 1);
    }

    // Function to return the index of the 
    // right child of the given node 
    int rightChild(int i)
    {

        return ((2 * i) + 2);
    }

    // Function to shift up the node in order 
    // to maintain the heap property 
    void shiftUp(int i)
    {
        //while (i > 0 && *this->lista->consultarPorPosicion(parent(i)) < *this->lista->consultarPorPosicion(i)) {
        while (i > 0 && comp->comparaMenor(*this->lista->consultarPorPosicion(parent(i)), *this->lista->consultarPorPosicion(i)))
        {
            // Swap parent and current node 
            swap(*this->lista->consultarPorPosicion(parent(i)), *this->lista->consultarPorPosicion(i));

            // Update i to parent of i  
            i = parent(i);
        }
    }

    // Function to shift down the node in 
    // order to maintain the heap property 
    void shiftDown(int i)
    {
        int maxIndex = i;

        // Left Child 
        int l = leftChild(i);

        if (l < getLista()->getCantidad() && comp->comparaMayor(*this->lista->consultarPorPosicion(l), *this->lista->consultarPorPosicion(maxIndex))) {
            //comp->comparaMayor(*this->lista->consultarPorPosicion(l), *this->lista->consultarPorPosicion(maxIndex)
            maxIndex = l;
        }

        // Right Child 
        int r = rightChild(i);

        if (r < getLista()->getCantidad() && comp->comparaMayor(*this->lista->consultarPorPosicion(r), *this->lista->consultarPorPosicion(maxIndex))) {
            maxIndex = r;
        }

        // If i not same as maxIndex 
        if (i != maxIndex) {
            swap(*this->lista->consultarPorPosicion(i), *this->lista->consultarPorPosicion(maxIndex));
            shiftDown(maxIndex);
        }
    }

    // Function to insert a new element 
    // in the Binary Heap 
    void insert(T p)
    {
        T* s = new T(p);
        int i = this->lista->getCantidad();
        //this->lista->insertarEnPosicion(s, i);
        this->lista->insertarAlFinal(s);
        // Shift Up to maintain heap property 
        shiftUp(i);
        this->cantidad++;
    }

    // Function to extract the element with 
    // maximum priority 
    T extractMax()
    {
        T result = *this->lista->consultarPorPosicion(0);

        // Replace the value at the root 
        // with the last leaf 
        *this->lista->consultarPorPosicion(0) = *this->lista->consultarPorPosicion(this->lista->getCantidad()-1); //eso si pasa?
        this->getLista()->setCantidad(this->getLista()->getCantidad() - 1);

        // Shift down the replaced element 
        // to maintain the heap property 
        shiftDown(0);
        this->cantidad--;
        return result;
    }

    // Function to change the priority 
    // of an element 
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

    // Function to get value of the current 
    // maximum element 
    T getMax()
    {
        return *this->lista->consultarPorPosicion(0);
    }

    // Function to remove the element 
    // located at given index 
    void remove(int i)
    {
        T* elemento = new T(getMax()); //que hace esto??
        this->lista->borrarEnPosicion(i);
        this->lista->insertarEnPosicion(elemento, i);
        // Shift the node to the root 
        // of the heap 
        shiftUp(i);
        this->cantidad--;
        // Extract the node 
        extractMax();
    }
    ArrayList<T>* getLista() const
    {
        return this->lista;
    }
    
};