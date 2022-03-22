#pragma once
#include "contabancaria.h"
#include "imprimivel.h"
class ContaCorrente :
    public ContaBancaria, public Imprimivel
{
private:
    double taxaDeOperacao;
public:
    ContaCorrente(int, double, double);
    virtual bool sacar(double);
    virtual void depositar(double);
    virtual void mostrarDados();
};

