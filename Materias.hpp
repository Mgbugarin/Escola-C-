#pragma once

enum class Materias : char // char nao obrigatorio, padrão é um inteiro // char é o tipo que ocupa menos espaço, class opicional, cria um escopo(::) torna o acesso mais seguro e intuitivo 
{
	prog_1 = 1, prog_2, BD_2, E_Dados, Mat, Org_1, Org_2  // O compilador relaciona cada elemento com um inteiro Ex: domingo =0, segunda = 1 etc
};