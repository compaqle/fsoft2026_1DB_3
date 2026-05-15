#include "../../include/view/CategoriaView.h"
#include "../../include/view/Utils.h"
#include <iostream>
#include <string>

CategoriaView::CategoriaView() {}

void CategoriaView::mostrarMenuCategorias(CategoriaController& controller) {
    while (true) {
        std::cout << "\n--- GERIR CATEGORIAS ---" << std::endl;
        std::cout << "1. Criar Categoria" << std::endl;
        std::cout << "2. Listar Categorias" << std::endl;
        std::cout << "0. Voltar" << std::endl;

        int opcao = Utils::lerInt("\nOpcao: ");

        if (opcao == 0) {
            return;
        } else if (opcao == 1) {
            std::string nome = Utils::lerString("Nome da Categoria: ");
            double taxa_iva = Utils::lerDouble("Taxa de IVA (ex: 0.23 para 23%): ");

            controller.criarCategoria(nome, taxa_iva);
            std::cout << "Categoria criada com sucesso!" << std::endl;

        } else if (opcao == 2) {
            std::vector<Categoria>& lista = controller.getCategorias();
            if (lista.empty()) {
                std::cout << "\nNão existem categorias registadas." << std::endl;
            } else {
                std::cout << "\n--- LISTA DE CATEGORIAS ---" << std::endl;
                for (int i = 0; i < (int)lista.size(); i++) {
                    std::cout << "ID: " << lista[i].getId() 
                              << " | Nome: " << lista[i].getNome() 
                              << " | IVA: " << (lista[i].getTaxaIva() * 100) << "%" << std::endl;
                }
            }
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}
