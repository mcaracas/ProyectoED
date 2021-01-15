#pragma once
#include<fstream>
#include"IWriter.h"
#include"TransformadorCsv.h"

template<class T>
class CsvWriter : public IWriter<T>
{
private:
	fstream salida;
	ITransformadorCsv<T>* transformadorCsv;

	string generarRegistro(vector<string>* campos)
	{
		auto begin = campos->begin();
		auto end = campos->end();

		stringstream ss;

		if (begin != end)
		{
			ss << *begin++;
		}

		while (begin != end)
		{
			ss << ",";
			ss << *begin++;
		}

		ss << endl;
		return ss.str();
	}

public:
	CsvWriter(string rutaArchivo, ITransformadorCsv<T>* transformadorCsv)
	{
		this->transformadorCsv = transformadorCsv;
		this->salida.open(rutaArchivo, ios::out);
		if (!this->salida.good()) 
		{
			throw invalid_argument("Ruta del archivo no es valida o no hay permisos.");
		}
	}

	void escribir(T elemento) override
	{
		vector<string>* campos = this->transformadorCsv->toStringVector(elemento);
		this->salida << this->generarRegistro(campos);
		delete campos;
	}

	void escribirTodos(vector<T>* elementos) override
    {
		for (auto& actual : *elementos)
		{
			this->escribir(actual);
		}
	}	

	~CsvWriter()
	{
		this->salida.close();
		delete this->transformadorCsv;
	}
};