#pragma once
#include<iostream>
#include<vector>
#include<fstream>



#include "Pessoa.hpp"
#include"Turma.hpp"
#include "fglobais.hpp"


class Aluno final : public Pessoa
{
	//Pessoa m_aluno;
	std::string m_graduacao;
	std::string m_matricula;
	std::string m_datamat;

public:

	Aluno();

	void insere_matricula();
	void insere_data();
	void seleciona_graduacao();

	std::string get_matricula() const;
	std::string get_datamat() const;
	std::string get_curso() const;

	static void menu_aluno();
	static Aluno buscar();
	void exibe_aluno() const;
	void edita_aluno();
	void exclui_aluno();
	static void cadastrar();
	static void salvar(std::vector<Aluno> alunos);
	static std::vector<Aluno> carregar();
};

