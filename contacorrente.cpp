#include "contacorrente.h"
#include <iostream>

ContaCorrente::ContaCorrente(int conta, double saldo, double taxaDeOperacao):ContaBancaria(conta,saldo),
taxaDeOperacao(taxaDeOperacao) {}

//Saque da conta
bool ContaCorrente::sacar(double valor)
{
	valor += valor * this->taxaDeOperacao;
	if (saldo-valor >= 0) return ContaBancaria::sacar(valor);
	return 0;
}

//Deposito da conta
void ContaCorrente::depositar(double valor)
{
	valor -= valor * this->taxaDeOperacao;
	ContaBancaria::depositar(valor);
}

//Mostra os Dados
void ContaCorrente::mostrarDados()
{	
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Numero da conta: " << this->conta << std::endl;
	std::cout << "Saldo: " << this->saldo << std::endl;
	std::cout << "Taxa de operacao: " << this->taxaDeOperacao << std::endl;
	std::cout << "--------------------------------" << std::endl;
}