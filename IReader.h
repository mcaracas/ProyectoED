#pragma once
#include<vector>
using namespace std;

template<class T>
class IReader
{
public:
	virtual vector<T>* leerTodos() = 0;
	virtual ~IReader() = default;
};