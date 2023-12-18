#include "Funcionario.hpp"

Funcionario::Funcionario()
{
	m_matricula = '2';
}

void Funcionario::insere_matricula()
{
	m_matricula += gera_matricula();
	std::cout << "Matricula gerada: " << m_matricula << std::endl;
}

void Funcionario::insere_data()
{
	m_datamat = data_hora();
}


std::string Funcionario::get_matricula() const
{
	return m_matricula;
}

std::string Funcionario::get_datamat() const
{
	return m_datamat;
}


 