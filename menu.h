#pragma once
#include "banco.h"
#include "contacorrente.h"
#include "contapoupanca.h"

class Menu
{
private:
	Banco banco;
public:
	Menu();
	void criarConta();
	ContaBancaria* criarContaCorrente(int, double);
	ContaBancaria* criarContaPoupanca(int, double);
	void selecionarConta();
	void removerConta();
	void sacar(ContaBancaria*);
	void depositar(ContaBancaria*);
	void transferencia(ContaBancaria*);
};