#pragma once
#include<iostream>
#include "Cliente.h"
#include "CsvReader.h"
#include "CsvWriter.h"
#include "IReader.h"
#include "IWriter.h"
#include "servicioBanco.h"
#include "HeapPriorityQueue.h"
#include"ComparadorPrioridad.h"
#include"ComparadorID.h"
#include <string>
#include <exception>
using namespace std;

class MenuPrincipal
{
private:
	IReader<Cliente*>* reader;
	vector<Cliente*>* cargarClientes;
	HPQ<Cliente>* hpqClientes;
	ServicioBanco* s1;
public:

	MenuPrincipal(){
		
		if (verificar()) {
			reader = new CsvReader<Cliente*>("Clientes.csv", new TransformadorCsvCliente());
			cargarClientes = reader->leerTodos();
			s1 = new ServicioBanco();
			s1->insertarEnArbol(cargarClientes);
			this->hpqClientes = new HPQ<Cliente>;
			//ComparadorID* compID = new ComparadorID();
			ComparadorPrioridad* compPrioridad = new ComparadorPrioridad();
			hpqClientes->setComparador(compPrioridad);
			//s1->getArbol()->setComparador(compID);
		}
	}
	void invocarMenu()
	{
		const char opcionSalida = '7';
		char opcion;
		do {
			opcion = mostrarOpciones();
			switch (opcion)
			{
			case '1':
				encolarTodosLosClientes();
				system("pause");
				break;
			case '2':
				encolarUnCliente();
				system("pause");
				break;
			case '3':
				atenderLosSiguientesCincoClientes();
				system("pause");
				break;
			case '4':
				mostrarElSiguienteCliente_A_ser_Atendido();
				system("pause");
				break;
			case '5':
				simulacion_De_Atencion_a_Clientes();
				system("pause");
				break;
			case '6':
				agregarUnClienteNuevo();
				system("pause");
				break;

			case opcionSalida:
				break;
			default:
				cerr << "Opcion invalida, digite otra vez" << endl;
				system("pause");
			}
		} while (opcion != opcionSalida);
	}

	~MenuPrincipal()
	{
		s1->getArbol()->from_Tree_ToVector(s1->getArbol()->getRoot());
		vector<Cliente*>* guardarClientes = nullptr;
		guardarClientes = s1->getArbol()->getVector();

		if ((guardarClientes->size()) > (cargarClientes->size())) {
			IWriter<Cliente*>* writer = new CsvWriter<Cliente*>("Clientes.csv", new TransformadorCsvCliente());
			writer->escribirTodos(guardarClientes);
			delete writer;
			cout << "Cambios guardados con exito." << endl;
			system("pause");
		}else {
			system("Color 1F");
			cout << "Sin cambios." << endl;
			system("pause");
		}
		delete guardarClientes;
		delete cargarClientes;
		delete reader;
	}

private:
	char mostrarOpciones()
	{
		char opcion;
		system("cls");
		cout << "Menu Principal - Seleccionar una opcion:" << endl;
		cout << "1) Encolar Todos los Clientes" << endl;
		cout << "2) Encolar un Cliente " << endl;
		cout << "3) Atender los siguientes 5 clientes" << endl;
		cout << "4) Mostrar el siguiente cliente a ser atendido  " << endl;
		cout << "5) Simulacion de atencion de clientes " << endl;
		cout << "6) Agregar un cliente nuevo  " << endl;
		cout << "7) Salir  " << endl;
		cin >> opcion;
		system("cls");
		return opcion;
	}
	void encolarTodosLosClientes() {
		BSTIterator<Cliente>* ite =this->s1->getArbol()->obtenerIterador();
		while (ite->hasNext()) {
			this->hpqClientes->insert(ite->next());
		}
		if (hpqClientes != nullptr) {
			cout << "Clientes encolados con exito" << endl;
		}else {
			throw invalid_argument("Ha ocurrido un error al encolar los clientes al heap\n");
		}
	}
	void encolarUnCliente() 
	{
		Cliente clienteAux = Cliente();
		long long id;
		cout << "Digite el id del cliente a buscar" << endl;
		cin >> id;
		//cliente.setId(id);
		BSTIterator<Cliente>* ite = this->s1->getArbol()->obtenerIterador();
		while (ite->hasNext()) {
			Cliente cliente = ite->next();
			if (cliente.getId() == id) //recorre arbol BST
			{
				clienteAux = cliente; //si encuentra cliente con nombre lo iguala a la variable
				//falta manejar excepcion si no lo encuentra
			}
		}


		//cliente = (s1->getArbol()->buscaRecur(cliente, s1->getArbol()->getRoot()))->getElemento();
		hpqClientes->insert(clienteAux);
	}
	void atenderLosSiguientesCincoClientes() {
		if (hpqClientes->getCantidad()>0) {
			cout << "Los proximos cinco clientes a atender son: " << endl;
			for (int i = 0; i < 5; i++) {
				

				cout << hpqClientes->extractMax();
				///HAY QUE MANEJAR OTRA EXCEPCION
			}
		}
		else {
			cerr << "No hay personas en la cola\n";
		}

	}
	void mostrarElSiguienteCliente_A_ser_Atendido() {
		if (hpqClientes->getCantidad() > 0) {
			cout << hpqClientes->extractMax();
		}else {
			cerr << "No hay clientes que atender \n";
		}
	}
	void simulacion_De_Atencion_a_Clientes() {
		if (hpqClientes->getCantidad() > 0) {
			cout << "Simulacion de atencion de clientes: ";
			int i = 0;
			while (i < hpqClientes->getLista()->getCantidad()) {
				cout << *hpqClientes->getLista()->consultarPorPosicion(i) << " ";
				//hpqClientes->remove(i); //con esto se vacia la cola
				hpqClientes->extractMax();
				i++;
			}
			//cout << hpqClientes->getCantidad() << endl;
		}else {
			cerr << "No hay cola por el momento\n";
		}
	}
	void agregarUnClienteNuevo() {
		string nombre, texto = ""; double id; bool cnNinos, embarazada, adMayor; int categoria;
		cout << "Digite el nombre "<<endl ;
		cin.ignore();
		getline(cin, nombre);
		fflush(stdin);
		cout << "Digite el Id " << endl;
		id = leerDouble();
		cout << "Viene con Ninos Si o No" << endl;
		cin >> texto;
		cnNinos = verificarBooleanos(texto);
		cout << "Esta Embarazada o Emabarazado? Si o No" << endl;
		cin >> texto;
		embarazada = verificarBooleanos(texto);
		cout << "Es adulto mayor ? Si o No" << endl;
		cin >> texto;
		adMayor = verificarBooleanos(texto);
		cout << "Digite el numero correspondiente a su categoria de usuario: " << endl;
		cout << "Categoria 1- Premium" << endl;
		cout << "Categoria 2- Oro" << endl;
		cout << "Categoria 3- Normal" << endl;
		categoria = leerEntero();	
		this->s1->getArbol()->insertar(Cliente(nombre, id, cnNinos, embarazada, adMayor, categoria));
	}
	bool verificarBooleanos(string texto) {
		if ((texto == "Yes") || (texto == "yes") || (texto == "Si") || (texto == "si") || (texto == "SI") || (texto == "YES")) {
			return true;
		}else {
			return false;
		}
	}
	int leerEntero() {
		int n;
		while (true) {
			if (cin >> n) {
				cin.clear();
				cin.ignore(1024, '\n');
				return n;
			}else {
				cerr << "Debe ingresar un valor numerico valido " << endl;
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}
	}
	double leerDouble() {
		double n;
		while (true) {
			if (cin >> n) {
				cin.clear();
				cin.ignore(1024, '\n');
				return n;
			}
			else {
				cerr << "Debe ingresar un valor numerico valido " << endl;
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}
	}
	bool verificar() {
		if (ifstream("Clientes.csv")) {
			return true;
		}else {
			throw invalid_argument("''Clientes.csv'' no existe.\nVerifique la ruta o la existencia del archivo.");
		}
	}
};