#include "menu.h"
#include <iostream>

Menu::Menu():banco(Banco()){
    std::cout << "***************************************************" << std::endl;
    std::cout << "*                                                 *" << std::endl;
    std::cout << "*                  SEJA BEM VINDO                 *" << std::endl;
    std::cout << "*               AO SEU BANCO DIGITAL              *" << std::endl;
    std::cout << "*                                                 *" << std::endl;
    std::cout << "***************************************************\n\n\n" << std::endl;
    std::cout << std::endl;
    int opcao = 0;
    while (opcao != 5) {
        std::cout << "             Menu             \n" << std::endl;
        std::cout << "1.Criar conta" << std::endl;
        std::cout << "2.Selecionar conta" << std::endl;
        std::cout << "3.Remover conta" << std::endl;
        std::cout << "4.Gerar relatorio" << std::endl;
        std::cout << "5.Finalizar" << std::endl << std::endl;
        std::cout << "\nDigite a opcao acima desejada: ";
        std::cin >> opcao;
        switch (opcao)
        {
        case 1:
            Menu::criarConta();
            break;
        case 2:
            Menu::selecionarConta();
            break;
        case 3:
            Menu::removerConta();
            break;
        case 4:
            banco.mostrarDados();
            break;
        case 5:
            std::cout << "\nObrigado e volte sempre!" << std::endl;
            break;
        default:
            std::cout << "\nOpcao Invalida. Digite um numero de 1 a 5." << std::endl;
            break;
        }
    }
}

void Menu::criarConta(){
    int tipoConta = 0;
    bool escolhido = false;
    while (!escolhido)
    {
        std::cout << "\n         Criar conta          \n" << std::endl;
        std::cout << "1.Conta Corrente" << std::endl;
        std::cout << "2.Conta Poupanca" << std::endl << std::endl;
        std::cout << "3.Cancelar Operacao" << std::endl << std::endl;
        std::cout << "\nDigite a opcao acima desejada: ";
        std::cin >> tipoConta;
        switch (tipoConta) {
        case 1:
            escolhido = true;
            break;
        case 2:    
            escolhido = true;
            break;
        case 3:
            std::cout << "\nRetornando ao menu principal." << std::endl;
            return;
            break;
        default:
            std::cout << std::endl << "Opcao invalida." << std::endl << std::endl;
            break;
        }
    }

    int numeroConta = 0;
    double saldo = 0;
    ContaBancaria* conta;
    std::cout << "\nDigite o numero da conta: " << std::endl;
    std::cin >> numeroConta;
    conta= banco.procurarConta(numeroConta);
    while (conta != NULL) {
    std::cout << "\nNumero da conta ja existe." << std::endl;
    std::cout << "\nDigite o numero da conta: " << std::endl;
    std::cin >> numeroConta;
    conta = banco.procurarConta(numeroConta);
    }
    std::cout << "Digite o saldo da sua conta: " << std::endl;
    std::cin >> saldo;
    while (saldo < 0) {
    std::cout << "\nNao eh possivel abrir conta com saldo menor que 0." << std::endl;
    std::cout << "Digite o saldo da sua conta: " << std::endl;
    std::cin >> saldo;   
    }

    ContaBancaria* novaConta;
    if (tipoConta == 1) novaConta = criarContaCorrente(numeroConta, saldo);
    else novaConta = criarContaPoupanca(numeroConta, saldo);
    banco.inserir(novaConta);
    std::cout << "Conta criada com sucesso." << std::endl;
}

ContaBancaria* Menu::criarContaCorrente(int numeroConta, double saldo) {
    double taxaOperacao = 0;
    std::cout << "Insira a taxa de operacao da conta: ";
    std::cin >> taxaOperacao;
    while (taxaOperacao <= 0) {
        std::cout << "Nao eh possivel abrir conta com taxa de operacao menor ou igual a 0." << std::endl;
        std::cout << "Insira a taxa de operacao da conta: ";
        std::cin >> taxaOperacao;
    }
    return new ContaCorrente(numeroConta, saldo, taxaOperacao);
}

ContaBancaria* Menu::criarContaPoupanca(int numeroConta, double saldo) {
    double limite = 0;
    std::cout << "Insira limite da conta: ";
    std::cin >> limite;
    while (limite <= 0) {
        std::cout << "Nao eh possivel abrir conta com limite menor ou igual a 0." << std::endl;
        std::cout << "Insira o limite de operacao da conta: ";
        std::cin >> limite;
    }
    return new ContaPoupanca(numeroConta, saldo, limite);
}

void Menu::removerConta(){
    ContaBancaria* conta;
    int numeroConta = 0;
    std::cout << "Numero da conta: " << std::endl;
    std::cin >> numeroConta;
    conta = banco.procurarConta(numeroConta);
    while (conta == NULL) {
        std::cout << "\nEssa conta nao existe. Digite numero de conta existente.  " << std::endl;
        std::cout << "\nNumero conta: ";
        std::cin >> numeroConta;
        conta = banco.procurarConta(numeroConta);
    }
    banco.remover(conta);
    std::cout << std::endl << "\nConta removida com Sucesso." << std::endl;
}

void Menu::selecionarConta(){
    ContaBancaria* conta;
    int numeroConta = 0;
    std::cout << "Numero da conta: " << std::endl;
    std::cin >> numeroConta;
    conta = banco.procurarConta(numeroConta);
    if (conta == NULL) {
        std::cout << "Esta conta nao existe." << std::endl;
        return;
    }
    int opcao = 0;
    while (opcao != 5) {
        std::cout << "\n           Selecionar          \n" << std::endl;
        std::cout << "\n1.Sacar" << std::endl;
        std::cout << "\n2.Depositar" << std::endl;
        std::cout << "\n3.Transferencia" << std::endl;
        std::cout << "\n4.Gerar relatorio" << std::endl;
        std::cout << "\n5.Retornar ao menu anterior" << std::endl << std::endl;
        std::cout << "\nDigite a opcao acima desejada: ";
        std::cin >> opcao;
        switch (opcao)
        {
        case 1:
            Menu::sacar(conta);
            break;
        case 2:
            Menu::depositar(conta);
            break;
        case 3:
            Menu::transferencia(conta);
            break;
        case 4:
            conta->mostrarDados();
            break;
        case 5:
            std::cout << "\nRetornando ao menu anterior." << std::endl;
            return;
            break;
        default:
            std::cout << "\nOpcao Invalida. Digite um numero de 1 a 5." << std::endl;
            break;
        }
    }
}

void Menu::sacar(ContaBancaria* conta) {
    double saque = 0;
    std::cout << "Insira o valor que deseja sacar: ";
    std::cin >> saque;
    while (saque <= 0) {
        std::cout << "Nao eh possivel sacar valores menores ou iguais a 0." << std::endl;
        std::cout << "Insira o valor que deseja sacar: ";
        std::cin >> saque;
    }
    if(conta->sacar(saque)) std::cout << "Saque efetuado com sucesso." << std::endl;
    else std::cout << "Saldo insuficiente para efetuar o saque." << std::endl;
}

void Menu::depositar(ContaBancaria* conta) {
    double deposito = 0;
    std::cout << "Insira o valor do deposito: ";
    std::cin >> deposito;
    while (deposito <= 0) {
        std::cout << "Nao eh possivel depositar valores menores ou iguais a 0." << std::endl;
        std::cout << "Insira o valor que deseja depositar: ";
        std::cin >> deposito;
    }
    conta->depositar(deposito);
    std::cout << "Deposito efetuado com sucesso." << std::endl;
}

void Menu::transferencia(ContaBancaria* conta) {
    ContaBancaria* conta2;
    int numeroConta2 = 0;
    double transferencia = 0;
    std::cout << "\nInforme o numero da conta que recebera a transferencia.\n " << std::endl;
    std::cout << "Numero da conta: " << std::endl;
    std::cin >> numeroConta2;
    conta2 = banco.procurarConta(numeroConta2);
    while (conta2 == NULL) {
        std::cout << "\n conta nao existe.\n" << std::endl;
        std::cout << "\nInforme o numero da conta que recebera a transferencia.\n " << std::endl;
        std::cout << "Numero da conta: " << std::endl;
        std::cin >> numeroConta2;
        conta2 = banco.procurarConta(numeroConta2);
    }
    std::cout << "\nDigite o valor da transferencia: " << std::endl;
    std::cin >> transferencia;
        
    while (transferencia <= 0) {
        std::cout << "\nNao eh possivel transferir valores menores ou iguais a 0." << std::endl;
        std::cout << "Digite o valor da transferencia: ";
        std::cin >> transferencia;
    }
    if(conta->tranasferir(transferencia, conta2))
        std::cout << "\nTransferencia realizada com sucesso." << std::endl;
    else std::cout << "\nSaldo insuficiente para efetuar a transferencia." << std::endl;
}