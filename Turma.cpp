#include "Turma.hpp"

	Turma::Turma()
{
	m_tnumero = "1";

	m_qtdinscritos = 0;
	
	for (int i = 0; i < m_inscritos.size(); i++)
		m_inscritos[i] = "Vaga";
}

	void Turma::set_turma(std::string entrada)
	{
		m_tnumero = entrada;
	}

	void Turma::set_professor(std::string entrada)
	{
		m_professor = entrada;
	}

	void Turma::seleciona_materia()
	{
		std::cout << "Selecione uma matéria: \n"
			<< "1 - prog-1\n2 - prog-2\n3 - SQL\n4 - E-Dados\n5 - Mat\n6 - Org-1\n7 - Org-2\n>";
		
		char opc;

			std::cin >> opc;
			if (opc == '1')
				m_materia = "prog-1";	
			else if (opc == '2')
				m_materia = "prog-2";
			else if (opc == '3')
				m_materia = "SQL";
			else if (opc == '4')
				m_materia = "E-Dados";
			else if (opc == '5')
				m_materia = "Mat";
			else if (opc == '6')
				m_materia = "Org-1";
			else if (opc == '7')
				m_materia = "Org-2";
			else
			{
				std::cout << "Opção inválida, Matéria não informada:\n>";
				m_materia = "Não informado";
			}
	}


	std::string Turma::get_turma() const
	{
		return  m_tnumero;
	}

	std::string Turma::get_materia() const
	{
		return m_materia;
	}

	std::string Turma::get_professor() const
	{
		return m_professor;
	}

	std::array<std::string, 5> Turma::get_inscritos() const
	{
		return m_inscritos;
	}

	int Turma::get_qtdinscritos() const
	{
		return m_qtdinscritos;
	}

	
	void Turma::menu_turma()
	{
		char opc;
		do
		{
			std::cout << "\nSelecione uma opção:\n\n1 - Cadastrar nova turma\n2 - Editar turma\n3 - Buscar turma\n4 - Listar todas as turmas\n5 - Sair.\n>";
			Turma turma;
			std::cin >> opc;
			std::cin.get();

			switch (opc)
			{
				case '1':
					cadastrar();
					break;

				case '2':
					// FUTUROAluno::alterar();
					break;

				case '3':
					turma = buscar(); // corrigir em outras classes, add turma nao encontrada, remover do exibir
					turma.exibe_turma();
					turma.edita_turma();
					break;

				case '4':
					listar_turmas();
					break;

				case '5':
					std::cout << "Finalizado pelo usuário." << std::endl;
					break;

				default:
					std::cout << "Opção inválida!";
					break;
			}
		} while (opc != '5');
	}

	void Turma::listar_turmas()
	{
		std::cout << std::endl;
		std::vector<Turma> turmas = carregar();
		if (turmas.size() > 0)
		{
			for (Turma turma : turmas)							//for (int i = 0; i < turmas.size(); i++)
				std::cout << "Turma: " << turma.get_turma() << " - " << turma.get_materia() << std::endl;
		}
		else
			std::cout << "\nNão existem turmas cadastradas no sistema.\n";
	}

	Turma Turma::buscar()
	{
		std::vector<Turma> turmas = carregar();

		if (turmas.size() > 0)
		{
			std::string numero;
			std::cout << "\nInforme o número da turma:\n>";
			std::cin >> numero;

			for (int i = 0; i < turmas.size(); i++)
			{
				if (numero == turmas[i].m_tnumero)
				{
					std::cout << "\nTurma encontrada.\n\n";
					return turmas[i];
				}
			}
			std::cout << "\nTurma não encontrada.\n";
			Turma turma_vazia;
			return turma_vazia;
		}
		else
			std::cout << "Não existem turmas cadastradas no sistema.\n";	
	}

	void Turma::exibe_turma() const
	{
		if (m_tnumero != "1")
		{
			std::cout << "Numero: " <<  m_tnumero << "\nMateria: " << m_materia << "\nProfessor: " << m_professor
					  << "\nQuantidade de alunos: " << m_qtdinscritos << std::endl;
		listar_inscritos();
		}
	}

	void Turma::edita_turma()
	{
		if (m_tnumero != "1")
		{
			std::vector<Turma> turmas = carregar();

			char opc;
			do
			{
				std::cout << "\nSelecione uma opção:\n" << "1 - Adicionar Professor\n2 - Remover Professor\n3 - Adicionar aluno\n4 - Remover aluno\n5 - Sair\n>";
				std::cin >> opc;
				std::cin.get();

				switch (opc)
				{
					case '1':
						insere_professor();
						break;

					case '2':
						remove_professor();
						break;

					case '3':
						insere_aluno();
						break;

					case '4':
						remove_aluno();
						break;

					case '5':
						std::cout << "\nFinalizado pelo usuário.\n";
						break;

					default:
						std::cout << "\nOpção inválida\n";
				}
			} while (opc != '5');
		}
	}

	void Turma::exclui_turma()
	{
		std::vector<Turma> turmas = carregar();

		for ( int i = 0; i < turmas.size(); i++)
		{
			if (m_tnumero == turmas[i].m_tnumero)
			{
				turmas.erase(turmas.begin() + i);
				salvar(turmas);
				break;
			}	
		}
		std::cout << "\nTurma excluída do sistema.\n";
	}
	
	void Turma::listar_inscritos() const
	{
		std::vector <Turma> turmas = carregar();

		std::cout << "\nAlunos matriculados:\n";

		for (int i = 0; i < turmas.size(); i++)
		{
			if ( m_tnumero == turmas[i]. m_tnumero)
			{
				for (int y = 0 ; y < turmas[i].m_inscritos.size() ; y++)
					std::cout << turmas[i].m_inscritos[y] << std::endl;
			}
		}
	}

	void Turma::insere_professor()
	{
		Professor professor;
		professor = Professor::buscar();
		professor.exibe_professor();

		if (professor.get_matricula() != "2")
		{
			m_professor = professor.get_matricula();
		
			std::vector<Turma> turmas = carregar();

			for (int i = 0; i < turmas.size(); i++)
			{
				if (m_tnumero == turmas[i].m_tnumero)
				{
					turmas[i].m_professor = m_professor;
					salvar(turmas);
					std::cout << "\nProfessor adicionado.\n";
				}
			}		
		}
	}

	void Turma::remove_professor()
	{
			std::vector<Turma> turmas = carregar();

			for (int i = 0; i < turmas.size(); i++)
			{
				if (m_tnumero == turmas[i].m_tnumero)
				{
					turmas[i].m_professor = "Vaga";
					salvar(turmas);
					std::cout << "\nProfessor removido da turma.\n";
					break;
				}
			}
	}

	void Turma::insere_aluno()
	{
		Aluno aluno;
		aluno = Aluno::buscar();
		aluno.exibe_aluno();
		if (aluno.get_matricula() != "1") // aluno encontrado
		{
			if (m_inscritos.back() == "Vaga") // existe vaga?
			{
				for (int i = 0; i < m_inscritos.size(); i++)
				{
					if (m_inscritos[i] == "Vaga")													// insere matricula na turma
					{
						m_inscritos[i] = aluno.get_matricula();
						m_qtdinscritos++;
						break;
					}
				}
	
				std::vector<Turma> turmas = carregar();

				for (int i = 0; i < turmas.size(); i++)
				{
					if (m_tnumero == turmas[i].m_tnumero) // busca turma e insere
					{
						turmas[i].m_inscritos = m_inscritos;
						turmas[i].m_qtdinscritos = m_qtdinscritos;
						salvar(turmas);
						std::cout << "\nAluno adicionado." << std::endl;
						break;
					}
				}
			}
			else
				std::cout << "\nTurma atingiu o limite de alunos inscritos.\n";
		}	
	}

	void Turma::remove_aluno()
	{
		Aluno aluno;
		aluno = Aluno::buscar();
		aluno.exibe_aluno();

		if (aluno.get_matricula() != "1") // aluno encontrado
		{
			std::vector<Turma> turmas = carregar();

			for (int i = 0; i < turmas.size(); i++)
			{
				for (int y = 0; y < turmas[i].m_inscritos.size(); y++)
				{
					if (aluno.get_matricula() == turmas[i].m_inscritos[y])
					{
						turmas[i].m_inscritos[y] = "Vaga";	
						turmas[i].m_qtdinscritos--;
						salvar(turmas);
						std::cout << "\nAluno removido da turma.\n";
						break;	
					}	
				}
			}
		}
	}

	void Turma::cadastrar()
	{
		Turma turma;
		std::cout << "#####Cadastrar nova Turma#####\n\n";

		std::string entrada;

		std::cout << "Informe o número da turma:> ";
		std::getline( std::cin , entrada);
		turma.set_turma(entrada);

		turma.seleciona_materia();

		turma.insere_professor();
		
		std::cout << "\nTurma criada, Confirme os dados:\n" << std::endl;
		turma.exibe_turma();

		std::vector<Turma> turmas = carregar();
		turmas.push_back(turma);
		
		if (menu_salvar() == 1)
			salvar(turmas);
	}

	void Turma::salvar(std::vector<Turma> turmas)
	{
		std::ofstream fout;
		fout.open("Turmas.txt");
		if (fout.is_open())
		{
			fout << turmas.size() << std::endl;
			
			for (int i = 0; i < turmas.size(); i++)
			{
				fout << turmas[i]. m_tnumero << std::endl;
				fout << turmas[i].m_materia << std::endl;
				fout << turmas[i].m_professor << std::endl;
				fout << turmas[i].m_qtdinscritos << std::endl;
				for (int y = 0; y < turmas[i].m_inscritos.size(); y++)
					fout << turmas[i].m_inscritos[y] << std::endl;
				fout << std::endl;
			}
			fout.close();
		}
		else 
			carregar();
	}

	std::vector<Turma> Turma::carregar() 
	{
		std::vector<Turma> lista_turmas;
		
		std::ifstream fin;
		fin.open("Turmas.txt");
		if (fin.is_open()) 
		{
			Turma turma;
			int tam = 0;
			fin >> tam;
			if (tam != 0)
			{
				for (int i = 0; i < tam ; i++)
				{
					fin.get();
					std::getline(fin, turma. m_tnumero);
					std::getline(fin, turma.m_materia);
					std::getline(fin, turma.m_professor);
					fin >> turma.m_qtdinscritos;
					fin.get();
					for (int y = 0; y < turma.m_inscritos.size(); y++)
						std::getline(fin, turma.m_inscritos[y]);
						
					lista_turmas.push_back(turma);
				}
				return lista_turmas;
			}
			fin.close();
		}
		else
		{
			std::cout << "\nArquivo de dados não encontrado! Deseja iniciar novo arquivo?\n\n1 - Sim\n2 - Não" << std::endl;
			
			char opc;
			do
			{
				std::cin >> opc;
				if (opc == '1')
				{
					std::ofstream fout;
					fout.open("Turmas.txt");
					std::cout << "Arquivo de dados criado.\n\n";
					return lista_turmas;
				}
				else if (opc != '2')
					std::cout << "Opcao invalida, Digite novamente.\n\n>";
			} while (opc != '2');
		}
	}