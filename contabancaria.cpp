#include "contabancaria.h"

ContaBancaria::ContaBancaria(int conta, double saldo):conta(conta),saldo(saldo){}

int ContaBancaria::get_conta() {
	return this->conta;
}

bool ContaBancaria::sacar(double valor)
{
	this->saldo -= valor;
	return true;
}

void ContaBancaria::depositar(double valor)
{
	this->saldo += valor;
}

bool ContaBancaria::tranasferir(double valor, ContaBancaria* contaRecebe) {
	if (sacar(valor)) {
		contaRecebe->depositar(valor);
		return 1;
	}
	return 0;
}