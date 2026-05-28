#include "../../include/controller/Controller.h"
#include "../../include/exceptions/InvalidDataException.h"
#include "../../include/exceptions/NoDataException.h"
#include "../../include/exceptions/DuplicatedDataException.h"
#include "../../include/view/Utils.h"

Controller::Controller(ProdutoService* produtoService, CategoriaService* categoriaService, ClienteService* clienteService)
    : produtoService(produtoService), categoriaService(categoriaService), clienteService(clienteService) {
}

void Controller::run() {
    while (true) {
        int op = view.menuPrincipal();
        if (op == -1) {
            return;
        }
        if (op == 0) {
            runAdmin();
        } else if (op >= 1) {
            runCaixa(op);
        } else {
            view.printMensagem("Opcao invalida. Tente novamente.");
        }
    }
}

void Controller::runAdmin() {
    while (true) {
        int op = view.menuAdmin();

        if (op == 0) {
            return;
        } else if (op == 1) {
            runCatalogo();
        } else if (op == 2) {
            runCategorias();
        } else if (op == 3) {
            runClientes();
        } else if (op == 4) {
            view.printMensagem("Ver Estatisticas - em desenvolvimento");
        } else {
            view.printMensagem("Opcao invalida. Tente novamente.");
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

            view.printMensagem("\n--- Categorias Disponiveis ---");
            categoriaView.printListaCategorias(categoriaService->getCategorias());
            view.printMensagem("------------------------------");
            
            catalogoView.getDadosCriarProduto(nome, preco, stock, id_categoria);
            try {
                produtoService->criarProduto(nome, preco, stock, id_categoria);
                view.printMensagem("Produto criado com sucesso!");
            } catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            }
        } else if (op == 2) {
            catalogoView.printListaProdutos(produtoService->getProdutos());
        } else if (op == 3) {
            catalogoView.printListaProdutos(produtoService->getProdutos());
            int id = catalogoView.getIdProdutoEditar();
            
            view.printMensagem("\n--- Categorias Disponiveis ---");
            categoriaView.printListaCategorias(categoriaService->getCategorias());
            view.printMensagem("------------------------------");
            
            view.printMensagem("Insira os novos dados (ou -1 para manter o atual):");
            std::string nome = Utils::lerString("Nome (-1 para manter): ");
            double preco = Utils::lerDouble("Preco base (-1 para manter): ");
            int stock = Utils::lerInt("Stock (-1 para manter): ");
            int id_categoria = Utils::lerInt("ID Categoria (-1 para manter): ");
            
            try {
                produtoService->editarProduto(id, nome, preco, stock, id_categoria);
                view.printMensagem("Produto editado com sucesso!");
            } catch (NoDataException& e) {
                view.printMensagem(e.what());
            } catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            }
        } else if (op == 4) {
            catalogoView.printListaProdutos(produtoService->getProdutos());
            int id = catalogoView.getIdProduto();
            try {
                produtoService->removerProduto(id);
                view.printMensagem("Produto removido com sucesso!");
            } catch (NoDataException& e) {
                view.printMensagem(e.what());
            }
        } else {
            view.printMensagem("Opcao invalida. Tente novamente.");
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
                view.printMensagem("Categoria criada com sucesso!");
            } catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            }
        } else if (op == 2) {
            categoriaView.printListaCategorias(categoriaService->getCategorias());
        } else if (op == 3) {
            categoriaView.printListaCategorias(categoriaService->getCategorias());
            int id = categoriaView.getIdCategoriaEditar();
            
            view.printMensagem("Insira os novos dados (ou -1 para manter o atual):");
            std::string nome = Utils::lerString("Nome (-1 para manter): ");
            double taxa_iva = Utils::lerDouble("Taxa de IVA (-1 para manter): ");
            
            try {
                categoriaService->editarCategoria(id, nome, taxa_iva);
                view.printMensagem("Categoria editada com sucesso!");
            } catch (NoDataException& e) {
                view.printMensagem(e.what());
            } catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            }
        } else {
            view.printMensagem("Opcao invalida. Tente novamente.");
        }
    }
}

void Controller::runClientes() {
    while (true) {
        int op = clienteView.mostrarMenuClientes();

        if (op == 0) {
            return;
        } else if (op == 1) {
            int nif;
            std::string nome;
            clienteView.getDadosCriarCliente(nif, nome);
            try {
                clienteService->criarCliente(nif, nome);
                view.printMensagem("Cliente criado com sucesso!");
            } catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            } catch (DuplicatedDataException& e) {
                view.printMensagem(e.what());
            }
        } else if (op == 2) {
            clienteView.printListaClientes(clienteService->getClientes());
        } else if (op == 3) {
            clienteView.printListaClientes(clienteService->getClientes());
            int nif = clienteView.getNifCliente("editar");
            
            std::string novoNome = Utils::lerString("Novo nome (-1 para manter): ");
            
            try {
                clienteService->editarCliente(nif, novoNome);
                view.printMensagem("Cliente editado com sucesso!");
            } catch (NoDataException& e) {
                view.printMensagem(e.what());
            } catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            }
        } else if (op == 4) {
            clienteView.printListaClientes(clienteService->getClientes());
            int nif = clienteView.getNifCliente("remover");
            try {
                clienteService->removerCliente(nif);
                view.printMensagem("Cliente removido com sucesso!");
            } catch (NoDataException& e) {
                view.printMensagem(e.what());
            }
        } else {
            view.printMensagem("Opcao invalida. Tente novamente.");
        }
    }
}

void Controller::runCaixa(int idCaixa) {
    while (true) {
        int op = view.menuCaixa();

        if (op == 0) {
            return;
        } else if (op == 1) {
            view.printMensagem("Realizar Venda - em desenvolvimento");
        } else if (op == 2) {
            view.printMensagem("Consultar Preco - em desenvolvimento");
        } else if (op == 3) {
            view.printMensagem("Consultar Pontos Cliente - em desenvolvimento");
        } else {
            view.printMensagem("Opcao invalida. Tente novamente.");
        }
    }
}
