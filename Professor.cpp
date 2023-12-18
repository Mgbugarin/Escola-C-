#include "Professor.hpp"

Professor::Professor()
{

}


void Professor::menu_professor()
{
	Professor professor;
	char opc;
	do
	{
		std::cout << "\n\nSelecione uma opcao:\n\n1 - Cadastrar novo profesor\n2 - Alterar dados do professor\n3 - Buscar professor\n4 - Sair.\n>";
		std::cin >> opc;
		std::cin.get();

		switch (opc)
		{
			case '1':
				Professor::cadastrar();
				break;

			case '2':
				// FUTUROAluno::alterar();
				break;

			case '3':
				professor = buscar();
				professor.exibe_professor();
				professor.edita_professor();
				break;

			case '4':
				std::cout << "Finalizado pelo usuário..." << std::endl;
				break;

			default:
				std::cout << "Opção inválida!";
				break;
		}
	} while (opc != '4');
}

Professor Professor::buscar() 
{
	std::vector<Professor> professores = carregar();
	
	if (professores.size() > 0)
	{
		std::string matricula;
		std::cout << "Informe a matricula do professor:\n>";
		std::cin >> matricula;
		for (int i = 0; i < professores.size(); i++)
		{
			if (matricula == professores[i].m_matricula)
			{
				std::cout << "\nMatrícula encontrada.\n\n";
				return professores[i];
			}
		}
		std::cout << "\nMatrícula não encontrada.\n";
		Professor professor_vazio;
		return professor_vazio;
	}
	else
		std::cout << "Não existem professores cadastrados no sistema.\n";
}

void Professor::exibe_professor() const
{
	if (m_matricula != "2")
		{
		std::cout << "Nome: " << m_nome << "\nMatricula: " << m_matricula << "\nDocumento: " << m_documento
			<<"\nData da matricula: " << m_datamat << std::endl;
	
		std::vector<Turma> turmas = Turma::carregar();
	
		std::cout << "Disciplina(s): ";
		for (int i = 0; i < turmas.size(); i++)
		{
			if (m_matricula == turmas[i].get_professor())
				std::cout << turmas[i].get_materia() << "\n";
		}
		std::cout << std::endl;
	}
}

void Professor::edita_professor()
{
	if (m_matricula != "2")
	{
		std::vector<Professor> professores = carregar();

		char opc;
		do
		{
			std::cout << "\nSelecione uma opção:\n" << "1 - Editar nome\n2 - Editar Documento\n3 - Excluir Professor\n4 - Sair\n>";
			std::cin >> opc;
			std::cin.get();

			switch (opc)
			{
				case '1':
					for (int i = 0; i < professores.size(); i++)
					{
						if (m_matricula == professores[i].m_matricula)
						{
							std::string novo_nome;
							std::cout << "Informe o novo nome:> ";
							std::getline (std::cin, novo_nome);
							professores[i].m_nome = novo_nome;
							salvar(professores);
							break;
						}
					}
					break;

				case '2':
					for (int i = 0; i < professores.size(); i++)
					{
						if (m_matricula == professores[i].m_matricula)
						{
							std::string novo_documento;
							std::cout << "Informe o novo documento:> ";
							std::getline(std::cin, novo_documento);
							professores[i].m_documento = novo_documento;
							salvar(professores);
							break;
						}
					}
					break;

				case '3':
					exclui_professor();
					break;

				case '4':
					std::cout << "\nFinalizado pelo usuário.\n";
					break;

				default:
					std::cout << "\nOpção inválida\n";
			}
		} while (opc != '5');
	}
}

void Professor::exclui_professor()
{
	std::vector<Professor> professores = carregar();
	for (int i = 0; i < professores.size(); i++)
	{
		if (m_matricula == professores[i].m_matricula)
		{
			professores.erase(professores.begin() + i);
			salvar(professores);
			std::cout << "\nProfessor excluído do sistema.\n";
			break;
		}
	}	
}

void Professor::cadastrar()
{
	Professor professor;

	std::cout << "#####Cadastro de novo professor#####\n\n";

	std::string entrada;

	std::cout << "Informe o nome do professor:> ";
	std::getline (std::cin , entrada);
	professor.set_nome(entrada);
	
	std::cout << "Informe o documento:> ";
	std::getline ( std::cin , entrada);
	professor.set_documento(entrada);					
	
	
	professor.insere_matricula();
	professor.insere_data();

	std::cout << "\nConfirme os dados:\n" << std::endl;
	professor.exibe_professor();

	std::vector<Professor> professores = carregar();
	professores.push_back(professor);
	
	if (menu_salvar() == 1)
		salvar(professores);
}

void Professor::salvar(std::vector<Professor> professores)
{	
	std::ofstream fout;
	fout.open("Professores.txt");
	if (fout.is_open())
	{
		fout << professores.size() << std::endl;

		for (int i = 0; i < professores.size(); i++)
		{
			fout << professores[i].m_nome << std::endl;
			fout << professores[i].m_matricula << std::endl;
			fout << professores[i].m_documento << std::endl;
			fout << professores[i].m_datamat << std::endl;
			fout << std::endl;
		}
		fout.close();
	}
	else 
		carregar();
}

std::vector<Professor> Professor::carregar()
{
	std::vector<Professor> lista_professores;

	std::ifstream fin;
	fin.open("Professores.txt");
	if (fin.is_open()) {
		Professor professor;
		
		int tam;
		fin >> tam;

		for (int i = 0; i < tam; i++)
		{
			std::getline(fin, professor.m_nome);
			std::getline(fin, professor.m_nome);
			std::getline(fin, professor.m_matricula);
			std::getline(fin, professor.m_documento);
			std::getline(fin, professor.m_datamat);

			lista_professores.push_back(professor);
		}
		fin.close();

		return lista_professores;
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
				fout.open("Professores.txt");
				std::cout << "Arquivo de dados criado.\n\n";
				return lista_professores;
			}
			else if (opc != '2')
				std::cout << "Opcao invalida, Digite novamente.\n\n>";
		} while (opc != '2');
	}
}
	



