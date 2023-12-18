#pragma once

#include<iostream>
#include<string>
#include "fglobais.hpp"

class Pessoa
{
protected:
	std::string m_nome;
	std::string m_documento;
	
public:

	Pessoa();

	void set_nome(std::string& entrada);
	void set_documento(std::string& entrada);


	std::string get_nome() const;
	std::string get_documento() const;
};

