#pragma once
#include <vector>
#include <string>
#include "../dto/PromocaoDTO.h"
#include "../repo/SupermercadoRepository.h"

class PromocaoService {
private:
    int proximoId;
    bool dataValida(const std::string& data) const;

public:
    PromocaoService();

    void criarPromocaoProduto(double percentagem, const std::string& data_inicio,
                              const std::string& data_fim, int id_produto);
    void criarPromocaoCategoria(double percentagem, const std::string& data_inicio,
                                const std::string& data_fim, int id_categoria);
    void removerPromocao(int id);
    std::vector<PromocaoDTO> getPromocoes() const;
};
