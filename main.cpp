#include "contapoupanca.h"
#include "contacorrente.h"
#include "relatorio.h"
#include "executavel.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
	unique_ptr<Executavel> pExecutavel = make_unique<Executavel>(100, 100, 200, 200);
	system("pause");
	return 0;
}