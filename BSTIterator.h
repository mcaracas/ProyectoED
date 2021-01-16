#include "Nodo.h"
#include<stack>
#pragma once
using namespace std;
template<class T >
class BSTIterator {
public:
	stack <Nodo<T>*> st;
	void fillStack(Nodo<T>* node) {
		while (node) {
			st.push(node);
			node = node->getLeft();
		}
	}
	BSTIterator(Nodo<T>* root) {
		fillStack(root);
	}

	T next() {
		Nodo<T>* curr = st.top();
		st.pop();
		if (curr->getRight() && curr->getRight()!= nullptr) {
			fillStack(curr->getRight());
		}
		return curr->getElemento();
	}

	bool hasNext() {
		return !st.empty();
	}
};