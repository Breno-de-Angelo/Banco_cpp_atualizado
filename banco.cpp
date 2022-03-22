#include "banco.h"

void Banco::inserir(ContaBancaria* conta){
	contas.push_back(conta);
}

void Banco::remover(ContaBancaria* conta) {
	int i;
	for (i = 0; i < contas.size(); i++) {
		if (conta->get_conta() == contas[i]->get_conta()) {
			contas.erase(contas.begin() + i);
			return;
		}
	}
}

ContaBancaria* Banco::procurarConta(int conta) {
	for (auto it : contas) {
		if (conta == it->get_conta()) return it;
	}
	return NULL;
}

void Banco::mostrarDados() {
	for (auto it : contas) {
		it->mostrarDados();
	}
}
