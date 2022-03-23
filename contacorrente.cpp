#include "contacorrente.h"
#include "iostream"
using namespace std;

ContaCorrente::ContaCorrente(int conta, double saldo, double taxaDeOperacao):ContaBancaria(conta,saldo),
taxaDeOperacao(taxaDeOperacao) {}

bool ContaCorrente::sacar(double valor)
{
	valor += valor * this->taxaDeOperacao;
	if (saldo-valor >= 0) return ContaBancaria::sacar(valor);
	return 0;
}

void ContaCorrente::depositar(double valor)
{
	valor -= valor * this->taxaDeOperacao;
	ContaBancaria::depositar(valor);
}

void ContaCorrente::mostrarDados()
{
	cout << "Numero da conta: " << this->conta << endl;
	cout << "Saldo: " << this->saldo << endl;
	cout << "Taxa de operacao: " << this->taxaDeOperacao << endl;
}