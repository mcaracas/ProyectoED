#include "Nodo.h"
#include "BSTIterator.h"
#include"IComparador.h"
#pragma once
template<class T>
class ArbolBinario {
private :
	Nodo<T>* raiz;
	int cant;
	vector<T*>* list = new vector<T*>();
	IComparador<T>* comparador;
public:
	ArbolBinario (Nodo<T>* raiz = nullptr, int cant = 0, IComparador<T>* comparador = nullptr) {
		
	}
	int getCantidad() const {
		return this->cant;
	}
	void setCantidad(int cantidad) {
		this->cant = cant;
	}
	int size() {
		return this->cant;
	}
	bool empty() {
		return (size() == 0) ? true : false;
	}
	bool isRoot(Nodo<T>* nodo) {
		return (raiz == nodo) ? true : false;
	}
	Nodo<T>* getRoot() {
		return this->raiz;
	}
	void setComparador(IComparador<T>* comparador)
	{
		this->comparador = comparador;
	}
	bool isExternal(Nodo<T>* nodo) {
		if (this->nodo->getLeft() == nullptr && this->nodo->getRight() == nullptr) {
			return true;
		}
		else return false;
	}

	void insertar(T elemento ) {
		
		
		//Primer caso Arbol Vacio..
		if (this->raiz== nullptr) {
			this->raiz = new Nodo<T>(elemento);
			
		}
		else {
			insertarRecursivo(raiz,elemento);

		}
		setCantidad(getCantidad() + 1);
	}
	void insertarRecursivo(Nodo<T>* nodo,T elemento) 
	{
		//if (elemento < nodo->getElemento()) {
		if (comparador->comparaMenor(elemento, nodo->getElemento())) 
		{ 
			if (nodo->getLeft()==nullptr) 
			{
				Nodo<T>* nuevo = new Nodo<T>(elemento,nodo,nullptr,nullptr);
				nodo->setLeft(nuevo);
			}
			else 
			{
				insertarRecursivo(nodo->getLeft(), elemento);
			}
		}
		else 
		{
			if (comparador->comparaMayorIgual(elemento, nodo->getElemento())) 
			{
				if (nodo->getRight() == nullptr) 
				{
					Nodo<T>* nuevo = new Nodo<T>(elemento, nodo, nullptr, nullptr);
					nodo->setRight(nuevo);
				}
				else 
				{
					insertarRecursivo(nodo->getRight(), elemento);
				}
			}
		}
	}
	Nodo<T>* buscaRecur(T valor ,Nodo<T>* leaf) {
		if (leaf != nullptr) {
			if (valor == leaf->getElemento()) {
				return leaf;
			}
			else {
				//if (valor < leaf->getElemento()) {
				//comparador->comparaMenor(elemento, nodo->getElemento())
				if (comparador->comparaMenor(valor, leaf->getElemento())) 
				{
					return buscaRecur(valor, leaf->getLeft());
				}
				else {
					return buscaRecur(valor, leaf->getRight());
				}
			}
		}
		return nullptr;
	}
	void destruyeArbol(Nodo<T>* nodo) {
		if (nodo != nullptr) {
			destruyeArbol(nodo->getLeft());
			destruyeArbol(nodo->getRight());
			delete nodo;
			nodo = nullptr;
			
		}
	}
	void from_Tree_ToVector(Nodo<T>* t){
		if (t == nullptr)
			return;
		from_Tree_ToVector(t->getLeft());
		T* dummie = new T();
		*dummie = t->getElemento();
		setVector(dummie);
		from_Tree_ToVector(t->getRight());
	}
	static T getDummie(Nodo<T>* t) {
		if (t == nullptr)
			return T();
		getDummie(t->getLeft());
		
		return t->getElemento();
		
		getDummie(t->getRight());
	}
	void setVector(T* cliente) {
		list->push_back(cliente);
	}
	vector<T*>* getVector() {
		return list;
	}
	BSTIterator<T>* obtenerIterador() {
		return new BSTIterator<T>(this->getRoot());
	}

	~ArbolBinario() {
		destruyeArbol(raiz);
		raiz = nullptr;
	}
};