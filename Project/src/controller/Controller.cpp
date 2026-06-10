#include "../../include/controller/Controller.h"
#include "../../include/exceptions/InvalidDataException.h"
#include "../../include/exceptions/NoDataException.h"
#include "../../include/exceptions/DuplicatedDataException.h"
#include "../../include/view/Utils.h"
#include <sstream>
#include <iomanip>

Controller::Controller(ProdutoService* produtoService, CategoriaService* categoriaService, ClienteService* clienteService, CaixaService* caixaService, VendaService* vendaService)
    : produtoService(produtoService), categoriaService(categoriaService), clienteService(clienteService), caixaService(caixaService), vendaService(vendaService) {
}

void Controller::run() {
    while (true) {
        int op = view.menuPrincipal(caixaService->getCaixas());
        
        if (op == -1) {
            return;
        }
        else if (op == -2) {
            view.printMensagem("Opcao invalida. Tente novamente.");
            continue;
        }

        if (op == 0) {
            runAdmin();
        }
        else {
            runCaixa(op);
        }
    }
}

void Controller::runAdmin() {
    while (true) {
        int op = view.menuAdmin();

        if (op == 0) {
            return;
        }
        else if (op == 1) {
            runCatalogo();
        }
        else if (op == 2) {
            runCategorias();
        }
        else if (op == 3) {
            runClientes();
        }
        else if (op == 4) {
            runCaixas();
        }
        else if (op == 5) {
            view.printMensagem("Ver Estatisticas - em desenvolvimento");
        }
        else {
            view.printMensagem("Opcao invalida. Tente novamente.");
        }
    }
}

void Controller::runCatalogo() {
    while (true) {
        int op = catalogoView.mostrarMenuCatalogo();

        if (op == 0) {
            return;
        }
        else if (op == 1) {
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
            }
            catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else if (op == 2) {
            catalogoView.printListaProdutos(produtoService->getProdutos());
        }
        else if (op == 3) {
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
            }
            catch (NoDataException& e) {
                view.printMensagem(e.what());
            }
            catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else if (op == 4) {
            catalogoView.printListaProdutos(produtoService->getProdutos());
            int id = catalogoView.getIdProduto();
            try {
                produtoService->removerProduto(id);
                view.printMensagem("Produto removido com sucesso!");
            }
            catch (NoDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else {
            view.printMensagem("Opcao invalida. Tente novamente.");
        }
    }
}

void Controller::runCategorias() {
    while (true) {
        int op = categoriaView.mostrarMenuCategorias();

        if (op == 0) {
            return;
        }
        else if (op == 1) {
            std::string nome;
            double taxa_iva;
            categoriaView.getDadosCriarCategoria(nome, taxa_iva);
            try {
                categoriaService->criarCategoria(nome, taxa_iva);
                view.printMensagem("Categoria criada com sucesso!");
            }
            catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else if (op == 2) {
            categoriaView.printListaCategorias(categoriaService->getCategorias());
        }
        else if (op == 3) {
            categoriaView.printListaCategorias(categoriaService->getCategorias());
            int id = categoriaView.getIdCategoriaEditar();
            
            view.printMensagem("Insira os novos dados (ou -1 para manter o atual):");
            std::string nome = Utils::lerString("Nome (-1 para manter): ");
            double taxa_iva = Utils::lerDouble("Taxa de IVA (-1 para manter): ");
            
            try {
                categoriaService->editarCategoria(id, nome, taxa_iva);
                view.printMensagem("Categoria editada com sucesso!");
            }
            catch (NoDataException& e) {
                view.printMensagem(e.what());
            }
            catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else if (op == 4) {
            categoriaView.printListaCategorias(categoriaService->getCategorias());
            int id = categoriaView.getIdCategoria();
            try {
                categoriaService->removerCategoria(id);
                view.printMensagem("Categoria removida com sucesso!");
            }
            catch (NoDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else {
            view.printMensagem("Opcao invalida. Tente novamente.");
        }
    }
}

void Controller::runClientes() {
    while (true) {
        int op = clienteView.mostrarMenuClientes();

        if (op == 0) {
            return;
        }
        else if (op == 1) {
            int nif;
            std::string nome;
            clienteView.getDadosCriarCliente(nif, nome);
            try {
                clienteService->criarCliente(nif, nome);
                view.printMensagem("Cliente criado com sucesso!");
            }
            catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            }
            catch (DuplicatedDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else if (op == 2) {
            clienteView.printListaClientes(clienteService->getClientes());
        }
        else if (op == 3) {
            clienteView.printListaClientes(clienteService->getClientes());
            int nif = clienteView.getNifCliente("editar");
            
            std::string novoNome = Utils::lerString("Novo nome (-1 para manter): ");
            
            try {
                clienteService->editarCliente(nif, novoNome);
                view.printMensagem("Cliente editado com sucesso!");
            }
            catch (NoDataException& e) {
                view.printMensagem(e.what());
            }
            catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else if (op == 4) {
            clienteView.printListaClientes(clienteService->getClientes());
            int nif = clienteView.getNifCliente("remover");
            try {
                clienteService->removerCliente(nif);
                view.printMensagem("Cliente removido com sucesso!");
            }
            catch (NoDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else {
            view.printMensagem("Opcao invalida. Tente novamente.");
        }
    }
}

void Controller::runCaixas() {
    while (true) {
        int op = caixaView.mostrarMenuCaixas();

        if (op == 0) {
            return;
        }
        else if (op == 1) {
            std::string nome;
            caixaView.getDadosCriarCaixa(nome);
            try {
                caixaService->criarCaixa(nome);
                view.printMensagem("Caixa registado com sucesso!");
            }
            catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else if (op == 2) {
            caixaView.printListaCaixas(caixaService->getCaixas());
        }
        else if (op == 3) {
            caixaView.printListaCaixas(caixaService->getCaixas());
            int id = caixaView.getIdCaixa();
            try {
                caixaService->removerCaixa(id);
                view.printMensagem("Caixa removida com sucesso!");
            }
            catch (NoDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else {
            view.printMensagem("Opcao invalida. Tente novamente.");
        }
    }
}

void Controller::runCaixa(int idCaixa) {
    while (true) {
        int op = view.menuCaixa();

        if (op == 0) {
            return;
        }
        else if (op == 1) {
            runRealizarVenda(idCaixa);
        }
        else if (op == 2) {
            catalogoView.printListaProdutos(produtoService->getProdutos());
            int id_produto = Utils::lerInt("ID do produto: ");
            try {
                double preco = vendaService->consultarPreco(id_produto);
                std::ostringstream oss;
                oss << "Preco final (com IVA e descontos): " << std::fixed << std::setprecision(2) << preco << "E";
                view.printMensagem(oss.str());
            }
            catch (NoDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else if (op == 3) {
            int nif = Utils::lerInt("NIF do cliente: ");
            std::vector<ClienteDTO> clientes = clienteService->getClientes();
            bool encontrado = false;
            for (size_t i = 0; i < clientes.size(); i++) {
                if (std::stoi(clientes[i].nif) == nif) {
                    std::ostringstream oss;
                    oss << "Cliente: " << clientes[i].nome << " | Pontos: " << clientes[i].pontos;
                    view.printMensagem(oss.str());
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                view.printMensagem("Cliente com NIF " + std::to_string(nif) + " nao encontrado.");
            }
        }
        else {
            view.printMensagem("Opcao invalida. Tente novamente.");
        }
    }
}

void Controller::runRealizarVenda(int idCaixa) {
    view.printMensagem("\n--- Nova Venda ---");
    view.printMensagem("(NIF 0 = sem cliente)");
    int nif = Utils::lerInt("NIF do cliente: ");

    try {
        vendaService->iniciarVenda(nif);
    }
    catch (NoDataException& e) {
        view.printMensagem(e.what());
        return;
    }
    catch (InvalidDataException& e) {
        view.printMensagem(e.what());
        return;
    }

    while (true) {
        int op = vendaView.mostrarMenuVenda();

        if (op == 0) {
            vendaService->cancelarVenda();
            view.printMensagem("Venda cancelada.");
            return;
        }
        else if (op == 1) {
            catalogoView.printListaProdutos(produtoService->getProdutos());
            int id_produto = Utils::lerInt("ID do produto: ");
            int quantidade = Utils::lerInt("Quantidade: ");
            try {
                vendaService->adicionarItem(id_produto, quantidade);
                view.printMensagem("Produto adicionado a venda.");
            }
            catch (NoDataException& e) {
                view.printMensagem(e.what());
            }
            catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else if (op == 2) {
            try {
                VendaDTO vendaAtual = vendaService->getVendaAtiva();
                vendaView.printItensVendaAtual(vendaAtual);
            }
            catch (InvalidDataException& e) {
                view.printMensagem(e.what());
                continue;
            }
            int id_produto = Utils::lerInt("ID do produto a remover: ");
            try {
                vendaService->removerItem(id_produto);
                view.printMensagem("Produto removido da venda.");
            }
            catch (NoDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else if (op == 3) {
            try {
                VendaDTO vendaAtual = vendaService->getVendaAtiva();
                vendaView.printItensVendaAtual(vendaAtual);
            }
            catch (InvalidDataException& e) {
                view.printMensagem(e.what());
            }
        }
        else if (op == 4) {
            int metodo_op = vendaView.getMetodoPagamento();

            std::string metodo;
            if (metodo_op == 1) {
                metodo = "Numerario";
            }
            else if (metodo_op == 2) {
                metodo = "Cartao de Credito";
            }
            else if (metodo_op == 3) {
                metodo = "Cartao de Debito";
            }
            else if (metodo_op == 4) {
                metodo = "MB Way";
            }
            else {
                metodo = "Numerario";
            }

            try {
                VendaDTO recibo = vendaService->concluirVenda(metodo, idCaixa);
                vendaView.printRecibo(recibo);
                view.printMensagem("Venda concluida com sucesso!");
            }
            catch (InvalidDataException& e) {
                view.printMensagem(e.what());
                continue;
            }
            catch (NoDataException& e) {
                view.printMensagem(e.what());
                continue;
            }
            return;
        }
        else {
            view.printMensagem("Opcao invalida. Tente novamente.");
        }
    }
}
