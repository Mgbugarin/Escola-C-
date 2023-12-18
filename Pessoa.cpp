#include "Pessoa.hpp"


Pessoa::Pessoa()
{
}

void Pessoa::set_nome(std::string& entrada)
{
	m_nome = entrada;
}

void Pessoa::set_documento(std::string& entrada)
{
	m_documento = entrada;
}



std::string Pessoa::get_nome() const
{
	return m_nome;
}

std::string Pessoa::get_documento() const
{
	return m_documento;
}