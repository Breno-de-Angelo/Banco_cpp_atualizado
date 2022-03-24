#pragma once
//Declara Bibliotecas
#include "contacorrente.h"
#include "contapoupanca.h"
#include "relatorio.h"
class Executavel
{
private:
	ContaCorrente contaCorrente;
	ContaPoupanca contaPoupanca;
public:
	Executavel(double deposito1, double deposito2, double saque1, double saque2);
	~Executavel() {};
};

