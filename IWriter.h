#pragma once
#include<vector>
using namespace std;

template<class T>
class IWriter
{
public:
	virtual void escribir(T elemento) = 0;
	virtual void escribirTodos(vector<T>* elementos) = 0;
	virtual ~IWriter() = default;
};