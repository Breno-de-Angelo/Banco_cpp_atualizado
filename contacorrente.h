#pragma once

//Declara Bibliotecas
#include "contabancaria.h"
#include "imprimivel.h"

// Declara a classe ContaCorrente
class ContaCorrente :
    public ContaBancaria, public Imprimivel
{
private:
    double taxaDeOperacao;
public:
    ContaCorrente(int, double, double);
    ~ContaCorrente(){};
    virtual bool sacar(double);
    virtual void depositar(double);
    virtual void mostrarDados();
};

