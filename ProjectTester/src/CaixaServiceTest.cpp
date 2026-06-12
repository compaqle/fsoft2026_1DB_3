#include <gtest/gtest.h>
#include "services/CaixaService.h"
#include "exceptions/InvalidDataException.h"
#include "exceptions/NoDataException.h"

// limpar os caixas antes de cada teste
static void limparCaixas() {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Caixa*>& caixas = repo.getCaixas();
    for (int i = 0; i < (int)caixas.size(); i++) {
        delete caixas[i];
    }
    caixas.clear();
}

// teste: criar um caixa com dados normais
TEST(CaixaServiceTest, CriarCaixaValido) {
    limparCaixas();

    CaixaService service;

    bool deu_erro = false;
    try {
        service.criarCaixa("Andre");
    }
    catch (...) {
        deu_erro = true;
    }
    EXPECT_FALSE(deu_erro);

    std::vector<CaixaDTO> caixas = service.getCaixas();
    EXPECT_EQ(caixas.size(), 1);
    if (caixas.size() > 0) {
        EXPECT_EQ(caixas[0].nome, "Andre");
    }
}

// teste: criar caixa sem nome deve falhar
TEST(CaixaServiceTest, CriarCaixaNomeVazio) {
    limparCaixas();

    CaixaService service;

    bool deu_erro_certo = false;
    try {
        service.criarCaixa("");
    }
    catch (InvalidDataException& e) {
        deu_erro_certo = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro_certo);
}

// teste: remover um caixa que existe
TEST(CaixaServiceTest, RemoverCaixaExistente) {
    limparCaixas();

    CaixaService service;
    service.criarCaixa("Andre");

    std::vector<CaixaDTO> caixas = service.getCaixas();
    int id = caixas[0].id;

    bool deu_erro = false;
    try {
        service.removerCaixa(id);
    }
    catch (...) {
        deu_erro = true;
    }
    EXPECT_FALSE(deu_erro);
}

// teste: remover um caixa que nao existe deve falhar
TEST(CaixaServiceTest, RemoverCaixaInexistente) {
    limparCaixas();

    CaixaService service;

    bool deu_erro_certo = false;
    try {
        service.removerCaixa(999);
    }
    catch (NoDataException& e) {
        deu_erro_certo = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro_certo);
}

// teste: editar o nome de um caixa
TEST(CaixaServiceTest, EditarCaixa) {
    limparCaixas();

    CaixaService service;
    service.criarCaixa("Andre");

    std::vector<CaixaDTO> caixas = service.getCaixas();
    int id = caixas[0].id;

    service.editarCaixa(id, "Andre Silva");
    caixas = service.getCaixas();

    EXPECT_EQ(caixas[0].nome, "Andre Silva");
}

// teste: passar "-1" como nome mantem o nome original
TEST(CaixaServiceTest, EditarCaixaComMenosUm) {
    limparCaixas();

    CaixaService service;
    service.criarCaixa("Andre");

    std::vector<CaixaDTO> caixas = service.getCaixas();
    int id = caixas[0].id;

    service.editarCaixa(id, "-1");
    caixas = service.getCaixas();

    EXPECT_EQ(caixas[0].nome, "Andre");
}
