#include "../../include/services/PromocaoService.h"
#include "../../include/mappers/PromocaoMapper.h"
#include "../../include/exceptions/InvalidDataException.h"
#include "../../include/exceptions/NoDataException.h"
#include "../../include/model/Promocao.h"
#include "../../include/model/Produto.h"
#include "../../include/model/Categoria.h"
#include <regex>

PromocaoService::PromocaoService() {
    proximoId = 1;
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Promocao*>& promocoes = repo.getPromocoes();
    for (size_t i = 0; i < promocoes.size(); i++) {
        if (promocoes[i]->getId() >= proximoId) {
            proximoId = promocoes[i]->getId() + 1;
        }
    }
}

bool PromocaoService::dataValida(const std::string& data) const {
    // Formato esperado: YYYY-MM-DD
    if (data.size() != 10) return false;
    if (data[4] != '-' || data[7] != '-') return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (data[i] < '0' || data[i] > '9') return false;
    }
    return true;
}

void PromocaoService::criarPromocaoProduto(double percentagem, const std::string& data_inicio,
                                            const std::string& data_fim, int id_produto) {
    if (percentagem <= 0 || percentagem > 100) {
        throw InvalidDataException("Percentagem invalida: " + std::to_string(percentagem));
    }
    if (!dataValida(data_inicio)) {
        throw InvalidDataException("Data de inicio invalida (use YYYY-MM-DD): " + data_inicio);
    }
    if (!dataValida(data_fim)) {
        throw InvalidDataException("Data de fim invalida (use YYYY-MM-DD): " + data_fim);
    }
    if (data_fim < data_inicio) {
        throw InvalidDataException("Data de fim nao pode ser anterior a data de inicio.");
    }

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    Produto* produto = NULL;
    std::vector<Produto*>& produtos = repo.getProdutos();
    for (size_t i = 0; i < produtos.size(); i++) {
        if (produtos[i]->getId() == id_produto) {
            produto = produtos[i];
            break;
        }
    }
    if (produto == NULL) {
        throw InvalidDataException("Produto: id = " + std::to_string(id_produto) + " (nao encontrado)");
    }

    Promocao* p = new Promocao(proximoId, percentagem, data_inicio, data_fim, produto, NULL);
    repo.getPromocoes().push_back(p);
    proximoId++;
    repo.guardarPromocoes();
}

void PromocaoService::criarPromocaoCategoria(double percentagem, const std::string& data_inicio,
                                              const std::string& data_fim, int id_categoria) {
    if (percentagem <= 0 || percentagem > 100) {
        throw InvalidDataException("Percentagem invalida: " + std::to_string(percentagem));
    }
    if (!dataValida(data_inicio)) {
        throw InvalidDataException("Data de inicio invalida (use YYYY-MM-DD): " + data_inicio);
    }
    if (!dataValida(data_fim)) {
        throw InvalidDataException("Data de fim invalida (use YYYY-MM-DD): " + data_fim);
    }
    if (data_fim < data_inicio) {
        throw InvalidDataException("Data de fim nao pode ser anterior a data de inicio.");
    }

    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    Categoria* categoria = NULL;
    std::vector<Categoria*>& categorias = repo.getCategorias();
    for (size_t i = 0; i < categorias.size(); i++) {
        if (categorias[i]->getId() == id_categoria) {
            categoria = categorias[i];
            break;
        }
    }
    if (categoria == NULL) {
        throw InvalidDataException("Categoria: id = " + std::to_string(id_categoria) + " (nao encontrada)");
    }

    Promocao* p = new Promocao(proximoId, percentagem, data_inicio, data_fim, NULL, categoria);
    repo.getPromocoes().push_back(p);
    proximoId++;
    repo.guardarPromocoes();
}

void PromocaoService::removerPromocao(int id) {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Promocao*>& promocoes = repo.getPromocoes();
    for (size_t i = 0; i < promocoes.size(); i++) {
        if (promocoes[i]->getId() == id) {
            delete promocoes[i];
            promocoes.erase(promocoes.begin() + i);
            repo.guardarPromocoes();
            return;
        }
    }
    throw NoDataException("Promocao: id = " + std::to_string(id) + " (nao encontrada)");
}

std::vector<PromocaoDTO> PromocaoService::getPromocoes() const {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Promocao*>& promocoes = repo.getPromocoes();
    std::vector<PromocaoDTO> dtos;
    for (size_t i = 0; i < promocoes.size(); i++) {
        dtos.push_back(PromocaoMapper::toDTO(*promocoes[i]));
    }
    return dtos;
}
