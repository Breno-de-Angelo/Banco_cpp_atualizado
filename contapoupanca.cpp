#include "contapoupanca.h"
#include "iostream"
using namespace std;

ContaPoupanca::ContaPoupanca(int conta, double saldo, double limite):ContaBancaria(conta,saldo),
limite(limite){}

bool ContaPoupanca::sacar(double valor)
{
	if ((saldo - valor) >= -1*limite) return ContaBancaria::sacar(valor);
	return false;
}

void ContaPoupanca::depositar(double valor)
{
	ContaBancaria::depositar(valor);
}

void ContaPoupanca::mostrarDados()
{
	cout << "Numero da conta: " << this->conta << endl;
	cout << "Saldo: " << this->saldo << endl;
	cout << "Limite: " << this->limite << endl;
}
