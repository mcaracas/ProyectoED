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
	/** @return the next smallest number */
	T next() {
		Nodo<T>* curr = st.top();
		st.pop();
		if (curr->getRight() && curr->getRight()!= nullptr) {
			fillStack(curr->getRight());
		}
		return curr->getElemento();
	}
	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !st.empty();
	}
};