#include "banco.h"
#include <iostream>

Banco::~Banco() {
	for (auto it : contas) {
		delete it;
	}
	contas.clear();
}

// Inseri conta bancaria no vetor
void Banco::inserir(ContaBancaria* conta){
	contas.push_back(conta);
}

// Remove conta bancaria no vetor
void Banco::remover(ContaBancaria* conta) {
	int i;
	for (i = 0; i < contas.size(); i++) {
		if (conta->get_conta() == contas[i]->get_conta()) {
			contas.erase(contas.begin() + i);
			delete conta;
			return;
		}
	}
}

// Procura conta bancaria no vetor
ContaBancaria* Banco::procurarConta(int conta) {
	for (auto it : contas) {
		if (conta == it->get_conta()) return it;
	}
	return NULL;
}

// Mostra os dados da conta
void Banco::mostrarDados() {
	for (auto it : contas) {
		std::cout << std::endl;
		it->mostrarDados();
	}
}
