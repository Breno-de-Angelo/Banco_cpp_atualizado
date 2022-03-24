#include "contapoupanca.h"
#include <iostream>

ContaPoupanca::ContaPoupanca(int conta, double saldo, double limite):ContaBancaria(conta,saldo),
limite(limite){}

//Saque na conta
bool ContaPoupanca::sacar(double valor)
{
	if ((saldo - valor) >= -1*limite) return ContaBancaria::sacar(valor);
	return false;
}

//Deposito na Conta
void ContaPoupanca::depositar(double valor)
{
	ContaBancaria::depositar(valor);
}

//Mostra os Dados
void ContaPoupanca::mostrarDados()
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Numero da conta: " << this->conta << std::endl;
	std::cout << "Saldo: " << this->saldo << std::endl;
	std::cout << "Limite: " << this->limite << std::endl;
	std::cout << "--------------------------------" << std::endl;
}
