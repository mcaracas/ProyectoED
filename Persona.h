#pragma once
#include<iostream>
#include<sstream>
using namespace std;


class Persona
{
private:
	string nombre;
	int edad;

public:
	Persona(string nombre, int edad)
	{
		this->nombre = nombre;
		this->edad = edad;
	}

    string getNombre() const { return nombre; }
    void setNombre(string nombre) { this->nombre = nombre; }

    int getEdad() const { return edad; }
    void setEdad(int edad) { this->edad = edad; }

	string toString()
	{
		stringstream s;
		s << "Nombre: " << this->nombre << endl;
		s << "Edad: " << this->edad << endl;
		return s.str();
	}

};