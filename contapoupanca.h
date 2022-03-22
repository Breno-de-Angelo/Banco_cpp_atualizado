#pragma once
#include "contabancaria.h"
#include "imprimivel.h"

class ContaPoupanca :
    public ContaBancaria, public Imprimivel
{
private:
    double limite;
public:
    ContaPoupanca(int, double, double);
    virtual bool sacar(double);
    virtual void depositar(double);
    virtual void mostrarDados();
};

