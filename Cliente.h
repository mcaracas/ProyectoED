#include<iostream>
#include <sstream>
using namespace std;
#pragma once
class Cliente {
private:
	string nombre;
	long long id;
	bool con_nino, embarazada, adulto_mayor;
	int categoria;
public:
	Cliente(string nombre= "", long long id = long long() , bool con_nino = false ,bool embarazada = false,bool adulto_mayor=false, int categoria = 0) {
		this->nombre = nombre;
		this->id = id;
		this->con_nino = con_nino;
		this->embarazada = embarazada;
		this->adulto_mayor = adulto_mayor;
		this->categoria = categoria;

	}

    string getNombre() const { return nombre; }
    void setNombre(string nombre) { this->nombre = nombre; }

	long long getId() const { return id; }
    void setId(long long id) { this->id = id; }

    bool getConnino() const { return con_nino; }
    void setConnino(bool connino) { con_nino = connino; }

    bool getEmbarazada() const { return embarazada; }
    void setEmbarazada(bool embarazada) { this->embarazada = embarazada; }

    bool getAdultomayor() const { return adulto_mayor; }
    void setAdultomayor(bool adultomayor) { adulto_mayor = adultomayor; }

    int getCategoria() const { return categoria; }
	string si_no(bool statment)const {
		return (statment) ? "Yes" : "No";
	}
    void setCategoria(int categoria) { this->categoria = categoria; }
	string toString() const{
		stringstream ss;
		ss << "Nombre: " << getNombre() << endl;
		ss << "Id: " << getId() << endl;
		ss << "Con nino: " << si_no(getConnino()) << endl;
		ss << "Embarazada: " << si_no(getEmbarazada()) << endl;
		ss << "Adulto Mayor: " << si_no(getAdultomayor()) << endl;
		ss << "Categoria: " << getCategoria()<<endl;
		return ss.str();
	}
	int calcularPrioridad(const Cliente& cli1) const {
		int res = 0;

		if (cli1.getConnino()) {
			res += 20;
		}
		if (cli1.getEmbarazada()) {
			res += 25;
		}
		if (cli1.getAdultomayor()) {
			res += 35;
		}
		switch (cli1.getCategoria()) {
		case 1:
			res += 20;
			break;
		case 2:
			res += 10;
			break;
		case 3:
			res += 0;
			break;
		}
		return res;
	}



	

};

inline
ostream& operator<<(ostream& out, const Cliente& cli)
{
	out << cli.toString();
	return out;
}
inline
bool  operator==(const Cliente& c2, const Cliente& c1) {
	return (c2.getId() == c1.getId());

}