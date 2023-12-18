#include "Aluno.hpp"



Aluno::Aluno()
{
	m_matricula = "1";
}

void Aluno::insere_matricula()
{
	m_matricula += gera_matricula();
	std::cout << "\nMatricula gerada: " << m_matricula << std::endl;
}

void Aluno::insere_data()
{
	m_datamat = data_hora();
}

void Aluno::seleciona_graduacao()
{
	std::cout << "\nSelecione a Graduação: \n"
		<< "\n1 - Análise de Sistemas\n2 - Cìência da Computação\n3 - Desenvolvimento de Software\n" << std::endl;
	std::cout << "(Qualquer valor diferente das opções preencherá o curso como não informado)\n>";
	char opc;

	std::cin >> opc;
	if (opc == '1')
		m_graduacao = "Análise de Sistemas";
	else if (opc == '2')
		m_graduacao = "Cìência da Computação";
	else if (opc == '3')
		m_graduacao = "Desenvolvimento de Software";
		
	else
	{
		std::cout << "Opção inválida, Curso não informado:\n>";
		m_graduacao = "Não informado";
	}
}


std::string Aluno::get_matricula() const
{
	return m_matricula;
}

std::string Aluno::get_datamat() const
{
	return m_datamat;
}

std::string Aluno::get_curso() const
{
	return m_graduacao;
}


void Aluno::menu_aluno()
{
	Aluno aluno;
	char opc;
	do
	{
		std::cout << "\n#########################\n\nSelecione uma opção:\n\n1 - Cadastrar novo aluno\n2 - Adicionar turma\n3 - Buscar aluno\n4 - Voltar\n\n#########################\n>";
		std::cin >> opc;
		std::cin.get();
		system("cls");

		switch (opc)
		{
		case '1':
			Aluno::cadastrar();
			system("pause");
			system("cls");
			break;

		case '2':
			/*Turma::insere_aluno();*/
			break;

		case '3':
			aluno = buscar();
			aluno.exibe_aluno();
			aluno.edita_aluno();
			system("pause");
			system("cls");
			break;

		case '4':
			break;

		default:
			std::cout << "Opcão inválida!";
			break;
		}
	} while (opc != '4');
}

Aluno Aluno::buscar()
{
	std::vector<Aluno> alunos = carregar();

	if (alunos.size() > 0)
	{
		std::string matricula;
		std::cout << "\nInforme a matricula do aluno:\n";
		std::cin >> matricula;
		for (int i = 0; i < alunos.size(); i++)
		{
			if (matricula == alunos[i].m_matricula)
			{
				std::cout << "\nMatricula encontrada.\n\n";
				return alunos[i];
			}
		}
		std::cout << "\nMatrícula não encontrada.\n";
		Aluno aluno_vazio;
		/*system("pause");
		system("cls");*/
		return aluno_vazio;
	}
	else
		std::cout << "Não existem professores cadastrados no sistema.\n";	
}

void Aluno::exibe_aluno() const
{
	if (m_matricula != "1")
	{
		std::cout << "Nome: " << m_nome << "\nMatricula: " << m_matricula << "\nDocumento: " << m_documento
				  << "\nCurso: " << m_graduacao << "\nData da matricula: " << m_datamat << std::endl;
			
		std::vector<Turma> turmas = Turma::carregar();

		std::cout << "turma(s): ";
		for (int i = 0; i < turmas.size(); i++)
		{
			for (int y = 0; y < turmas[i].get_inscritos().size(); y++)
			{
				if (m_matricula == turmas[i].get_inscritos()[y])
					std::cout << turmas[i].get_turma() << " ";
			}
		}
		std::cout << std::endl;
	}
}

void Aluno::edita_aluno()
{
	if (m_matricula != "1")
	{
		std::vector<Aluno> alunos = carregar();

		char opc;
		do
		{
				std::cout << "\nSelecione uma opção:\n" << "1 - Alterar nome\n2 - Alterar graduação\n3 - Excluir aluno\n4 - Voltar\n\n>";
				std::cin >> opc;
				std::cin.get();

				switch (opc)
				{
					case '1':
						for (int i = 0; i < alunos.size(); i++)
						{
							if (m_matricula == alunos[i].m_matricula)
							{
								std::string novo_nome;
								std::cout << "Informe o novo nome:> ";
								std::getline(std::cin, novo_nome);
								alunos[i].m_nome = novo_nome;
								salvar(alunos);
								break;
							}
						}
					break;

					case '2':
						for (int i = 0; i < alunos.size(); i++)
						{
							if (m_matricula == alunos[i].m_matricula)
							{
								seleciona_graduacao();
								alunos[i].m_graduacao = m_graduacao;
								salvar(alunos);
								break;
							}
						}
					break;

					case '3':
						exclui_aluno();
						break;

					case '4':
					break;

					default:
						std::cout << "Opção inválida.";
					break;
				}
		} while (opc != '4');
		//system("cls");
	}
}

void Aluno::exclui_aluno()
{
	std::vector<Aluno> alunos = carregar();
	for(int i = 0; i < alunos.size(); i++)
	{
		if (m_matricula == alunos[i].m_matricula)
		{
			alunos.erase(alunos.begin() + i);
			salvar(alunos);
			std::cout << "\nAluno excluído do sistema.\n";
			break;
		}
	}
}

void Aluno::cadastrar()
{
	Aluno aluno;

	std::cout << "#####Cadastrar novo aluno#####\n\n";

	std::string entrada;

	std::cout << "Informe o nome do aluno:> ";
	std::getline (std::cin , entrada);
	aluno.set_nome(entrada);

	std::cout << "\nInforme o documento:> ";
	std::getline(std::cin, entrada);
	aluno.set_documento(entrada);

	aluno.seleciona_graduacao();
	aluno.insere_matricula();
	aluno.insere_data();

	std::cout << "\nConfirme os dados:\n" << std::endl;
	aluno.exibe_aluno();

	std::vector<Aluno> alunos = carregar();
	alunos.push_back(aluno);
	
	if (menu_salvar() == 1)
		salvar(alunos);
}

void Aluno::salvar(std::vector<Aluno> alunos)
{
	std::ofstream fout;
	fout.open("Alunos.txt");
	if (fout.is_open())
	{
		fout << alunos.size() << std::endl;

		for (int i = 0; i < alunos.size(); i++)
		{
			fout << alunos[i].m_nome << std::endl;
			fout << alunos[i].m_documento << std::endl;
			fout << alunos[i].m_matricula << std::endl;
			fout << alunos[i].m_graduacao << std::endl;
			fout << alunos[i].m_datamat << std::endl;
			fout << std::endl;
		}
		fout.close();
	}
	else 
		carregar();
}

std::vector<Aluno> Aluno::carregar()
{
	std::vector<Aluno> lista_alunos;
	
	std::ifstream fin;
	fin.open("alunos.txt");
	if (fin.is_open()) {
		Aluno aluno;
		
		int tam;
		fin >> tam;

		for (int i = 0; i < tam; i++)
		{
			std::getline(fin, aluno.m_nome);
			std::getline(fin, aluno.m_nome);
			std::getline(fin, aluno.m_documento);
			std::getline(fin, aluno.m_matricula);
			std::getline(fin, aluno.m_graduacao);
			std::getline(fin, aluno.m_datamat);

			lista_alunos.push_back(aluno);
		}
		fin.close();

		return lista_alunos;
	}

	else
	{
		std::cout << "\nArquivo de dados nao encontrado! Deseja iniciar novo arquivo?\n\n1 - Sim\n2 - Nao" << std::endl;
		char opc;
		do
		{
			std::cin >> opc;
			if (opc == '1')
			{
				std::ofstream fout;
				fout.open("Alunos.txt");
				std::cout << "Arquivo de dados criado.\n\n";
				return lista_alunos;
			}
			else if (opc != '2')
				std::cout << "Opcao invalida, Digite novamente.\n\n>";
		} while (opc != '2');
	}
}