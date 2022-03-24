#pragma once
//Declara Bibliotecas
#include "contabancaria.h"
#include "imprimivel.h"

//Declara Classe Conta Poupanca
class ContaPoupanca :
    public ContaBancaria, public Imprimivel
{
private:
    double limite;
public:
    ContaPoupanca(int, double, double);
    ~ContaPoupanca(){};
    virtual bool sacar(double);
    virtual void depositar(double);
    virtual void mostrarDados();
};

