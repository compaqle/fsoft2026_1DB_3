#include "../../include/view/PromocaoView.h"
#include "../../include/view/Utils.h"
#include <iostream>

int PromocaoView::mostrarMenuPromocoes() {
    std::cout << "\n--- GERIR PROMOCOES ---" << std::endl;
    std::cout << "1. Criar Promocao" << std::endl;
    std::cout << "2. Listar Promocoes" << std::endl;
    std::cout << "3. Remover Promocao" << std::endl;
    std::cout << "4. Editar Promocao" << std::endl;
    std::cout << "0. Voltar" << std::endl;
    return Utils::lerInt("\nOpcao: ");
}

int PromocaoView::mostrarMenuTipoPromocao() {
    std::cout << "\nTipo de promocao:" << std::endl;
    std::cout << "1. Promocao de Produto" << std::endl;
    std::cout << "2. Promocao de Categoria" << std::endl;
    return Utils::lerInt("Opcao: ");
}

void PromocaoView::getDadosCriarPromocao(double& percentagem, std::string& data_inicio,
                                          std::string& data_fim, int& id_alvo, int& tipo) {
    tipo = mostrarMenuTipoPromocao();
    percentagem = Utils::lerDouble("Percentagem de desconto (ex: 20 para 20%): ");
    data_inicio = Utils::lerString("Data de inicio (YYYY-MM-DD): ");
    data_fim = Utils::lerString("Data de fim (YYYY-MM-DD): ");
    if (tipo == 1) {
        id_alvo = Utils::lerInt("ID do Produto: ");
    }
    else {
        id_alvo = Utils::lerInt("ID da Categoria: ");
    }
}

void PromocaoView::getDadosEditarPromocao(double& percentagem, std::string& data_inicio,
                                           std::string& data_fim) {
    std::cout << "Insira os novos dados (ou -1 para manter o atual):" << std::endl;
    percentagem = Utils::lerDouble("Percentagem (-1 para manter): ");
    data_inicio = Utils::lerString("Data de inicio (-1 para manter): ");
    data_fim = Utils::lerString("Data de fim (-1 para manter): ");
}

int PromocaoView::getIdPromocao() {
    return Utils::lerInt("ID da promocao: ");
}

void PromocaoView::printListaPromocoes(const std::vector<PromocaoDTO>& lista) {
    std::cout << "\n--- LISTA DE PROMOCOES ---" << std::endl;
    if (lista.empty()) {
        std::cout << "Nenhuma promocao registada." << std::endl;
        return;
    }
    for (size_t i = 0; i < lista.size(); i++) {
        std::cout << "ID: " << lista[i].id
                  << " | Desconto: " << lista[i].percentagem << "%"
                  << " | Inicio: " << lista[i].dataInicio
                  << " | Fim: " << lista[i].dataFim;
        if (!lista[i].nomeProduto.empty()) {
            std::cout << " | Produto: " << lista[i].nomeProduto;
        }
        if (!lista[i].nomeCategoria.empty()) {
            std::cout << " | Categoria: " << lista[i].nomeCategoria;
        }
        std::cout << std::endl;
    }
}
