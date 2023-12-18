#pragma once
#include<iostream>
#include"Pessoa.hpp"
#include "fglobais.hpp"


class Funcionario : public Pessoa
{
protected:
	//Pessoa m_funcionario;
	std::string m_matricula;
	std::string m_datamat;
	
public:

	Funcionario();
	void insere_matricula();
	void insere_data();


	std::string get_matricula() const;
	std::string get_datamat() const;
};

