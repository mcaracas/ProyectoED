#include "MenuPrincipal.h"
#include <iostream>
using namespace std;
int main()
{
	try { 
		MenuPrincipal menu;
		menu.invocarMenu(); 
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		system("pause");
	}
}
