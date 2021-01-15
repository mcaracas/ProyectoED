#pragma once
template<class T>
class Nodo {
private :
	T elemento;
	Nodo* parent;
	Nodo* left;
	Nodo* right;
public:
	Nodo(T elemento , Nodo* parent = nullptr,Nodo* left= nullptr, Nodo* right=nullptr) {
		this->elemento = elemento;
	}
	
	T getElemento() const
	{
		return elemento;
	}

	void setElemento(T elemento)
	{
		this->elemento = elemento;
	}

	Nodo* getParent() const
	{
		return parent;
	}

	void setParent(Nodo* parent)
	{
		this->parent = parent;
	}

	Nodo* getLeft() const
	{
		return left;
	}

	void setLeft(Nodo* left)
	{
		this->left = left;
	}

	Nodo*getRight() const
	{
		return right;
	}

	void setRight(Nodo* right)
	{
		this->right = right;
	}

	virtual ~Nodo() = default;

};