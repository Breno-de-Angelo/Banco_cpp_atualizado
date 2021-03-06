#include "menu.h"
#include <iostream>

Menu::~Menu() {
    Banco* pBanco = &banco;
    delete pBanco;
}

Menu::Menu():banco(Banco()){
    //Inicializa interface do menu
    std::cout << "***************************************************" << std::endl;
    std::cout << "*                                                 *" << std::endl;
    std::cout << "*                  SEJA BEM VINDO                 *" << std::endl;
    std::cout << "*               AO SEU BANCO DIGITAL              *" << std::endl;
    std::cout << "*                                                 *" << std::endl;
    std::cout << "***************************************************" << std::endl;
    std::cout << std::endl;
    int opcao = 0;
    while (opcao != 5) {
        std::cout << "\n\n             Menu             " << std::endl;
        std::cout << "1.Criar conta" << std::endl;
        std::cout << "2.Selecionar conta" << std::endl;
        std::cout << "3.Remover conta" << std::endl;
        std::cout << "4.Gerar relatorio" << std::endl;
        std::cout << "5.Finalizar" << std::endl;
        std::cout << "\nDigite a opcao acima desejada: ";
        std::cin >> opcao;
        // O switch chama cada respectiva opcao caso ela for v?lida
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
            std::cout << "\n";
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

//Cria??o de Conta
void Menu::criarConta(){
    int tipoConta = 0;
    bool escolhido = false;
    while (!escolhido)
    {
        //Inicializa interface do menu
        std::cout << "\n\n         Criar conta          " << std::endl;
        std::cout << "1.Conta Corrente" << std::endl;
        std::cout << "2.Conta Poupanca" << std::endl;
        std::cout << "3.Cancelar Operacao" << std::endl;
        std::cout << "\nDigite a opcao acima desejada: ";
        std::cin >> tipoConta;
        // O switch chama cada respectiva opcao caso ela for v?lida
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
            std::cout << "\nOpcao invalida." << std::endl;
            break;
        }
    }

    int numeroConta = 0;
    double saldo = 0;
    ContaBancaria* conta;
    std::cout << "\nDigite o numero da conta: ";
    std::cin >> numeroConta;
    conta= banco.procurarConta(numeroConta);
    while (conta != NULL) {
    std::cout << "\nNumero da conta ja existe." << std::endl;
    std::cout << "\nDigite o numero da conta: ";
    std::cin >> numeroConta;
    conta = banco.procurarConta(numeroConta);
    }
    std::cout << "Digite o saldo da sua conta: ";
    std::cin >> saldo;
    while (saldo < 0) {
    std::cout << "\nNao eh possivel abrir conta com saldo menor que 0." << std::endl;
    std::cout << "Digite o saldo da sua conta: ";
    std::cin >> saldo;   
    }

    ContaBancaria* novaConta;
    if (tipoConta == 1) novaConta = criarContaCorrente(numeroConta, saldo);
    else novaConta = criarContaPoupanca(numeroConta, saldo);
    banco.inserir(novaConta);
    std::cout << "\nConta criada com sucesso." << std::endl;
}

//Cria conta Corrente
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

//Cria conta Poupanca
ContaBancaria* Menu::criarContaPoupanca(int numeroConta, double saldo) {
    double limite = 0;
    std::cout << "Insira limite da conta: ";
    std::cin >> limite;
    while (limite <= 0) {
        std::cout << "\nNao eh possivel abrir conta com limite menor ou igual a 0." << std::endl;
        std::cout << "Insira o limite de operacao da conta: ";
        std::cin >> limite;
    }
    return new ContaPoupanca(numeroConta, saldo, limite);
}

//Remove a Conta
void Menu::removerConta(){
    ContaBancaria* conta;
    int numeroConta = 0;
    std::cout << "Numero da conta: ";
    std::cin >> numeroConta;
    conta = banco.procurarConta(numeroConta);
    while (conta == NULL) {
        std::cout << "\nEssa conta nao existe. Digite numero de conta existente." << std::endl;
        std::cout << "Numero conta: ";
        std::cin >> numeroConta;
        conta = banco.procurarConta(numeroConta);
    }
    banco.remover(conta);
    std::cout << "\nConta removida com Sucesso." << std::endl;
}

//Seleciona a Conta
void Menu::selecionarConta(){
    ContaBancaria* conta;
    int numeroConta = 0;
    std::cout << "Numero da conta: ";
    std::cin >> numeroConta;
    conta = banco.procurarConta(numeroConta);
    if (conta == NULL) {
        std::cout << "Esta conta nao existe." << std::endl;
        return;
    }
    int opcao = 0;
    while (opcao != 5) {
        std::cout << "\n\n           Selecionar          " << std::endl;
        std::cout << "1.Sacar" << std::endl;
        std::cout << "2.Depositar" << std::endl;
        std::cout << "3.Transferencia" << std::endl;
        std::cout << "4.Gerar relatorio" << std::endl;
        std::cout << "5.Retornar ao menu anterior" << std::endl << std::endl;
        std::cout << "Digite a opcao acima desejada: ";
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
            std::cout << '\n';
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

//Opera??o de Saque na Conta
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

//Opera??o de Dep?sito na Conta
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

//Opera??o de Transferencia entre Contas
void Menu::transferencia(ContaBancaria* conta) {
    ContaBancaria* conta2;
    int numeroConta2 = 0;
    double transferencia = 0;
    std::cout << "Informe o numero da conta que recebera a transferencia: ";
    std::cin >> numeroConta2;
    conta2 = banco.procurarConta(numeroConta2);
    while (conta2 == NULL || conta2 == conta) {
        if (conta2 == NULL)  std::cout << "\nConta nao existe." << std::endl;
        else std::cout << "\nNao e possivel realizar transferencia para a propria conta." << std::endl;
        std::cout << "\nInforme o numero da conta que recebera a transferencia: ";
        std::cin >> numeroConta2;
        conta2 = banco.procurarConta(numeroConta2);
    }
    std::cout << "Digite o valor da transferencia: ";
    std::cin >> transferencia;
        
    while (transferencia <= 0) {
        std::cout << "\nNao eh possivel transferir valores menores ou iguais a 0.\n" << std::endl;
        std::cout << "Digite o valor da transferencia: ";
        std::cin >> transferencia;
    }
    if(conta->transferir(transferencia, conta2))
        std::cout << "\nTransferencia realizada com sucesso." << std::endl;
    else std::cout << "\nSaldo insuficiente para efetuar a transferencia." << std::endl;
}