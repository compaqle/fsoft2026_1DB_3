#include "../../include/view/CatalogoView.h"
#include "../../include/view/Utils.h"
#include <iostream>
#include <string>

CatalogoView::CatalogoView() {}

void CatalogoView::mostrarMenuCatalogo(CatalogoController& controller) {
    while (true) {
        std::cout << "\n--- GERIR CATALOGO ---" << std::endl;
        std::cout << "1. Criar Produto" << std::endl;
        std::cout << "2. Listar Produtos" << std::endl;
        std::cout << "3. Editar Produto" << std::endl;
        std::cout << "4. Remover Produto" << std::endl;
        std::cout << "0. Voltar" << std::endl;

        int opcao = Utils::lerInt("\nOpcao: ");

        if (opcao == 0) {
            return;
        } else if (opcao == 1) {
            std::string nome = Utils::lerString("Nome: ");
            double preco_base = Utils::lerDouble("Preco base: ");
            int stock = Utils::lerInt("Stock: ");
            int id_categoria = Utils::lerInt("ID Categoria: ");

            controller.criarProduto(nome, preco_base, stock, id_categoria);
            std::cout << "Produto criado com sucesso!" << std::endl;

        } else if (opcao == 2) {
            std::vector<Produto>& lista = controller.getProdutos();
            if (lista.empty()) {
                std::cout << "\nO catalogo esta vazio." << std::endl;
            } else {
                std::cout << "\n--- LISTA DE PRODUTOS ---" << std::endl;
                for (int i = 0; i < (int)lista.size(); i++) {
                    std::cout << "ID: " << lista[i].getId() 
                              << " | Nome: " << lista[i].getNome() 
                              << " | Preco: " << lista[i].getPrecoBase() 
                              << " | Stock: " << lista[i].getStock() << std::endl;
                }
            }
        } else if (opcao == 3) {
            std::cout << "Editar Produto - em desenvolvimento" << std::endl;
        } else if (opcao == 4) {
            int id = Utils::lerInt("ID do produto a remover: ");
            controller.removerProduto(id);
            std::cout << "Operacao concluida (se o ID existia, o produto foi removido)." << std::endl;
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}

void CatalogoView::listarProduto(Produto& p) {
}
