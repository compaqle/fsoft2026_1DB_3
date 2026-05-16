#include "../../include/controller/Controller.h"
#include <iostream>

Controller::Controller(ProdutoService* produtoService, CategoriaService* categoriaService)
    : produtoService(produtoService), categoriaService(categoriaService) {
}

void Controller::run() {
    while (true) {
        int op = mainMenuView.mostrarMenuPrincipal();

        if (op == 0) {
            runAdmin();
        } else if (op >= 1) {
            runCaixa(op);
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}

void Controller::runAdmin() {
    while (true) {
        int op = adminView.mostrarMenuAdmin();

        if (op == 0) {
            return;
        } else if (op == 1) {
            runCatalogo();
        } else if (op == 2) {
            runCategorias();
        } else if (op == 3) {
            std::cout << "Gerir Clientes - em desenvolvimento" << std::endl;
        } else if (op == 4) {
            std::cout << "Ver Estatisticas - em desenvolvimento" << std::endl;
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}

void Controller::runCatalogo() {
    while (true) {
        int op = catalogoView.mostrarMenuCatalogo();

        if (op == 0) {
            return;
        } else if (op == 1) {
            std::string nome;
            double preco;
            int stock, id_categoria;
            catalogoView.getDadosCriarProduto(nome, preco, stock, id_categoria);
            produtoService->criarProduto(nome, preco, stock, id_categoria);
            catalogoView.printMensagem("Produto criado com sucesso!");
        } else if (op == 2) {
            catalogoView.printListaProdutos(produtoService->getProdutos());
        } else if (op == 3) {
            catalogoView.printMensagem("Editar Produto - em desenvolvimento");
        } else if (op == 4) {
            int id = catalogoView.getIdProduto();
            produtoService->removerProduto(id);
            catalogoView.printMensagem("Operacao concluida (se o ID existia, o produto foi removido).");
        } else {
            catalogoView.printMensagem("Opcao invalida. Tente novamente.");
        }
    }
}

void Controller::runCategorias() {
    while (true) {
        int op = categoriaView.mostrarMenuCategorias();

        if (op == 0) {
            return;
        } else if (op == 1) {
            std::string nome;
            double taxa_iva;
            categoriaView.getDadosCriarCategoria(nome, taxa_iva);
            categoriaService->criarCategoria(nome, taxa_iva);
            categoriaView.printMensagem("Categoria criada com sucesso!");
        } else if (op == 2) {
            categoriaView.printListaCategorias(categoriaService->getCategorias());
        } else {
            categoriaView.printMensagem("Opcao invalida. Tente novamente.");
        }
    }
}

void Controller::runCaixa(int idCaixa) {
    while (true) {
        int op = caixaView.mostrarMenuCaixa();

        if (op == 0) {
            return;
        } else if (op == 1) {
            std::cout << "Realizar Venda - em desenvolvimento" << std::endl;
        } else if (op == 2) {
            std::cout << "Consultar Preco - em desenvolvimento" << std::endl;
        } else if (op == 3) {
            std::cout << "Consultar Pontos Cliente - em desenvolvimento" << std::endl;
        } else {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }
}
