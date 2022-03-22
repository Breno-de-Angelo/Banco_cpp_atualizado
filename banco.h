#pragma once
#include "imprimivel.h"
#include "contabancaria.h"
#include <vector>
class Banco :
    public Imprimivel
{
private:
    std::vector<ContaBancaria*> contas;
public:
	void inserir(ContaBancaria*);
	void remover(ContaBancaria*);
	ContaBancaria* procurarConta(int);
	virtual void mostrarDados();
};

