#include "menu.h"
#include <memory>

//Chama a fun��o principal e Instancia o Menu
int main() {
	std::unique_ptr<Menu> pMenu = std::make_unique<Menu>();
	system("pause");
	return 0;
}