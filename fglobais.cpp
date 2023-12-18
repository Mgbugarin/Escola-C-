#pragma warning (disable : 4996)

#include "fglobais.hpp"

std::string gera_matricula()
{
	std::stringstream str_converte;
	std::array  <int, 4> matricula;
	int i = 0;

	srand(time(NULL));

	do
	{
		int numero = rand() % 99;
		if (numero > 9 && numero < 100)
		{
			matricula[i] = numero;
			i++;
		}
	} while (i < 4);

	str_converte << matricula[0]
				 << matricula[1]
				 << matricula[2]
				 << matricula[3];

	return  str_converte.str();
}

std::string data_hora()
{
	time_t agora = time(0);
	tm* ltm = localtime(&agora);
	std::stringstream data;

	data << ltm->tm_mday
		<< "/"
		<< 1+ ltm->tm_mon
		<< "/"
		<< 1900 + ltm->tm_year
		<< " "
		<< ltm->tm_hour
		<< ":"
		<< ltm->tm_min
		<< ":"
		<< ltm->tm_sec;

	return data.str();
}

int menu_salvar()
{
	char opc;
	do {
		std::cout << "\n1 - Salvar		2 - Cancelar\n>";
		std::cin >> opc;
		std::cin.get();
		if (opc == '1')
			return 1;

		if (opc != '2')
			std::cout << "\nOpcao invalida, tente novamente.\n>";

	} while (opc != '2');
	std::cout << "\nOperação cancelada.\n";
	return 0;
}

//void* operator new(size_t bytes)
//{
//	std::cout << "Alocando " << bytes << " bytes" << std::endl;
//	return malloc(bytes);
//}
//
//void operator delete (void* ptr)
//{
//	std::cout << "Liberando: " << sizeof(ptr) <<  std::endl;
//	free(ptr);
//}