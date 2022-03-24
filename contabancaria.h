#pragma once

// Declara a classe ContaBancaria
class ContaBancaria
{
protected:
	int conta;
	double saldo;
public:
	ContaBancaria(int, double);
	virtual ~ContaBancaria(){};
	int get_conta();
	virtual bool sacar(double) = 0;
	virtual void depositar(double) = 0;
	bool transferir(double, ContaBancaria*);
	virtual void mostrarDados() = 0;
};