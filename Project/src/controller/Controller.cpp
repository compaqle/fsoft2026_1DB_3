#include "../../include/controller/Controller.h"
#include "../../include/exceptions/InvalidDataException.h"
#include "../../include/exceptions/NoDataException.h"

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
            mainMenuView.printMensagem("Opcao invalida. Tente novamente.");
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
            adminView.printMensagem("Gerir Clientes - em desenvolvimento");
        } else if (op == 4) {
            adminView.printMensagem("Ver Estatisticas - em desenvolvimento");
        } else {
            adminView.printMensagem("Opcao invalida. Tente novamente.");
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
            try {
                produtoService->criarProduto(nome, preco, stock, id_categoria);
                catalogoView.printMensagem("Produto criado com sucesso!");
            } catch (InvalidDataException& e) {
                catalogoView.printMensagem(e.what());
            }
        } else if (op == 2) {
            catalogoView.printListaProdutos(produtoService->getProdutos());
        } else if (op == 3) {
            catalogoView.printMensagem("Editar Produto - em desenvolvimento");
        } else if (op == 4) {
            int id = catalogoView.getIdProduto();
            try {
                produtoService->removerProduto(id);
                catalogoView.printMensagem("Produto removido com sucesso!");
            } catch (NoDataException& e) {
                catalogoView.printMensagem(e.what());
            }
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
            try {
                categoriaService->criarCategoria(nome, taxa_iva);
                categoriaView.printMensagem("Categoria criada com sucesso!");
            } catch (InvalidDataException& e) {
                categoriaView.printMensagem(e.what());
            }
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
            caixaView.printMensagem("Realizar Venda - em desenvolvimento");
        } else if (op == 2) {
            caixaView.printMensagem("Consultar Preco - em desenvolvimento");
        } else if (op == 3) {
            caixaView.printMensagem("Consultar Pontos Cliente - em desenvolvimento");
        } else {
            caixaView.printMensagem("Opcao invalida. Tente novamente.");
        }
    }
}
