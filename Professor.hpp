#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<string>

#include"Funcionario.hpp"
#include"Turma.hpp"



class Professor final :  public Funcionario
{
	//Funcionario m_professor;
		
public:

	Professor();

	static Professor buscar();
	void exibe_professor() const;
	void exclui_professor();
	void edita_professor();
	static void menu_professor();
	static void cadastrar();
	static void salvar(std::vector<Professor> professores);
	static std::vector<Professor> carregar();
};

