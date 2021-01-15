#pragma once
#include<fstream>
#include<string>
#include"IReader.h"
#include"TransformadorCsv.h"

template<class T>
class CsvReader : public IReader<T>
{
private:
	fstream entrada;
	ITransformadorCsv<T>* transformadorCsv;

	vector<string>* generarCampos(string registroActual)
	{
		vector<string>* campos = new vector<string>();
		string valor;
		istringstream iss(registroActual);
		while (getline(iss, valor, ','))
		{
			campos->push_back(valor);
		}
		return campos;
	}

public:
	CsvReader(string rutaArchivo, ITransformadorCsv<T>* transformadorCsv)
	{
		this->transformadorCsv = transformadorCsv;
		this->entrada.open(rutaArchivo, ios::in);
		if (!entrada.good())
		{
			throw invalid_argument("Ruta del archivo no es valida o no hay permisos.");
		}
	}

	vector<T>* leerTodos()
	{
		string registroActual;
		vector<T>* objetos = new vector<T>();
		while (getline(this->entrada, registroActual))
		{
			vector<string>* campos = this->generarCampos(registroActual);
			objetos->push_back(this->transformadorCsv->fromStringVector(campos));
			delete campos;
		}
		return objetos;
	}

	~CsvReader()
	{
		delete this->transformadorCsv;
	}
};