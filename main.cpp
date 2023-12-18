#include<iostream>

#include"Aluno.hpp"
#include"Professor.hpp"
#include"Turma.hpp"
#include"fglobais.hpp"
//#include<locale.h>
#include<clocale>



using namespace std;

int main()
{
	setlocale(LC_ALL, "");	//SetConsoleOutputCP(1252);				

	char opc;
	do
	{
		cout << "\n#########################\n\nSelecione uma opção:\n\n1 - Ambiente do Aluno\n2 - Ambiente do Professor\n3 - Ambiente de Turmas\n4 - Sair.\n\n#########################\n>";
		cin >> opc;
		std::cin.get();
		system("cls");

		switch (opc)
		{
		case '1':
			Aluno::menu_aluno();
			break;

		case '2':
			Professor::menu_professor();
			break;
		
		case '3':
			Turma::menu_turma();
			break;
			
		case '4':
			cout << "Finalizando..." << endl;
			break;

		default:
			cout << "Opcção inválida!";
			break;

		}
	} while (opc != '4');

	return 0;
}

