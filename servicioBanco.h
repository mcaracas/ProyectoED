#pragma once
#include <vector>
#include "Cliente.h"
#include "Arbol.h"
#include"ComparadorID.h"
class ServicioBanco {
private: 
ArbolBinario<Cliente>* tree;
ComparadorID* comp;
public :

ServicioBanco() {
	this->tree = new ArbolBinario<Cliente>();
	this->comp = new ComparadorID();
	this->tree->setComparador(comp);
}
void insertarEnArbol(vector<Cliente*>* cliente) {
	for (Cliente* cli: *cliente) {
		tree->insertar(*cli);
	}
}
ArbolBinario<Cliente>* getArbol() {
	return tree;
}

};