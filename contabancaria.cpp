#include "contabancaria.h"

ContaBancaria::ContaBancaria(int conta, double saldo):conta(conta),saldo(saldo){}

//retorna a conta
int ContaBancaria::get_conta() {
	return this->conta;
}

//Realiza o saque na conta
bool ContaBancaria::sacar(double valor)
{
	this->saldo -= valor;
	return true;
}

//Realiza o deposito da conta
void ContaBancaria::depositar(double valor)
{
	this->saldo += valor;
}

//Realiza a transferencia
bool ContaBancaria::transferir(double valor, ContaBancaria* contaRecebe) {
	if (sacar(valor)) {
		contaRecebe->depositar(valor);
		return 1;
	}
	return 0;
}