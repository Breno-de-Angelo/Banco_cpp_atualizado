#include "relatorio.h"
#include "imprimivel.h"

Relatorio::Relatorio(){}

void Relatorio::gerarRelatorio(Imprimivel* imprimivel)
{
	imprimivel->mostrarDados();
}
