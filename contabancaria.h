#pragma once
class ContaBancaria
{
protected:
	int conta;
	double saldo;
public:
	ContaBancaria(int, double);
	int get_conta();
	virtual bool sacar(double) = 0;
	virtual void depositar(double) = 0;
	bool tranasferir(double, ContaBancaria*);
	virtual void mostrarDados() = 0;
};

