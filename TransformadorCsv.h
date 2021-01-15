#pragma once
#include<vector>
#include<string>
#include "Persona.h"
#include "Cliente.h"
using namespace std;

template<class T>
class ITransformadorCsv
{
public:
	virtual vector<string>* toStringVector(T elemento) = 0;
	virtual T fromStringVector(vector<string>* vector) = 0;
	virtual ~ITransformadorCsv() = default;
};

class TransformadorCsvPersona : public ITransformadorCsv<Persona*>
{
public:
	vector<string>* toStringVector(Persona* elemento) override
	{
		vector<string>* campos = new vector<string>();
		campos->push_back(elemento->getNombre());
		campos->push_back(to_string(elemento->getEdad()));
		return campos;
	}

	Persona* fromStringVector(vector<string>* vector) override
	{
		return new Persona(vector->at(0), stoi(vector->at(1)));
	}
};
class TransformadorCsvCliente : public ITransformadorCsv<Cliente*>
{
public:
	bool si_no(string s) {
		return (s == "Yes") ? true : false;
	}
	vector<string>* toStringVector(Cliente* elemento) override
	{
		vector<string>* campos = new vector<string>();
		campos->push_back(elemento->getNombre());
		campos->push_back(to_string(elemento->getId()));
		campos->push_back((elemento->getConnino()) ? "Yes" : "no");
		campos->push_back((elemento->getEmbarazada()) ? "Yes" : "no");
		campos->push_back((elemento->getAdultomayor()) ? "Yes" : "no");
		campos->push_back(to_string(elemento->getCategoria()));
		return campos;
	}

	Cliente* fromStringVector(vector<string>* vector) override
	{
	
		return new Cliente(vector->at(0), stoll(vector->at(1)),si_no(vector->at(2)), si_no(vector->at(3)), si_no(vector->at(4)),stoi(vector->at(5)));
	}
};