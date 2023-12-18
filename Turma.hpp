#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<typeinfo>
#include<array>

#include"Aluno.hpp"
#include"Professor.hpp"
#include"fglobais.hpp"

class Turma
{
	std::string  m_tnumero;
	std::string m_materia;
	std::string m_professor;
	std::array <std::string , 5> m_inscritos;
	int m_qtdinscritos;


public:

	Turma();

	void set_turma(std::string entrada);
	void set_professor(std::string entrada);

	void seleciona_materia();

	std::string get_turma() const;
	std::string get_materia() const;
	std::string get_professor() const;
	std::array<std::string, 5> get_inscritos() const;
	int get_qtdinscritos() const;
	
	void exibe_turma() const;
	void listar_inscritos() const;
	static void menu_turma();
	static Turma buscar();
	static void listar_turmas();
	void exclui_turma();
	void edita_turma();
	void insere_aluno();
	void remove_aluno();
	void insere_professor();
	void remove_professor();
	static void cadastrar();
	static void salvar(std::vector<Turma> turmas);
	static std::vector<Turma> carregar();
};

