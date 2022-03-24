#pragma once
//Declara Bibliotecas
#include "imprimivel.h"
#include "contabancaria.h"
#include <vector>

//Cria Classe Banco
class Banco :
    public Imprimivel
{
private:
    std::vector<ContaBancaria*> contas;
public:
	Banco() {};
	~Banco();
	void inserir(ContaBancaria*);
	void remover(ContaBancaria*);
	ContaBancaria* procurarConta(int);
	virtual void mostrarDados();
};

