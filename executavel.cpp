#include "executavel.h"

Executavel::Executavel(double deposito1, double deposito2, double saque1, double saque2):
contaCorrente(ContaCorrente(0,0,0.05)), contaPoupanca(ContaPoupanca(1,0,100)){
	contaCorrente.depositar(deposito1);
	contaCorrente.sacar(saque1);
	contaPoupanca.depositar(deposito2);
	contaPoupanca.sacar(saque2);
	Relatorio* ponteiroRelatorio = new Relatorio();
	Imprimivel* ponteiroConta;
	ponteiroConta = &contaCorrente;
	ponteiroRelatorio->gerarRelatorio(ponteiroConta);
	ponteiroConta = &contaPoupanca;
	ponteiroRelatorio->gerarRelatorio(ponteiroConta);
}
