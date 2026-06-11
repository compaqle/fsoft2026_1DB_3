#include <gtest/gtest.h>
#include "services/CaixaService.h"
#include "exceptions/InvalidDataException.h"
#include "exceptions/NoDataException.h"

class CaixaServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        SupermercadoRepository& repo = SupermercadoRepository::getInstance();
        std::vector<Caixa*>& caixas = repo.getCaixas();
        for (Caixa* c : caixas) {
            delete c;
        }
        caixas.clear();
    }
};

TEST_F(CaixaServiceTest, CriarCaixaValido) {
    CaixaService service;
    EXPECT_NO_THROW(service.criarCaixa("Andre"));

    auto caixas = service.getCaixas();
    ASSERT_EQ(caixas.size(), 1);
    EXPECT_EQ(caixas[0].nome, "Andre");
}

TEST_F(CaixaServiceTest, CriarCaixaNomeVazio) {
    CaixaService service;
    EXPECT_THROW(service.criarCaixa(""), InvalidDataException);
}

TEST_F(CaixaServiceTest, RemoverCaixaExistente) {
    CaixaService service;
    service.criarCaixa("Andre");

    auto caixas = service.getCaixas();
    int id = caixas[0].id;

    EXPECT_NO_THROW(service.removerCaixa(id));
}

TEST_F(CaixaServiceTest, RemoverCaixaInexistente) {
    CaixaService service;
    EXPECT_THROW(service.removerCaixa(999), NoDataException);
}

TEST_F(CaixaServiceTest, EditarCaixa) {
    CaixaService service;
    service.criarCaixa("Andre");

    auto caixas = service.getCaixas();
    int id = caixas[0].id;

    service.editarCaixa(id, "Andre Silva");
    caixas = service.getCaixas();
    EXPECT_EQ(caixas[0].nome, "Andre Silva");
}

TEST_F(CaixaServiceTest, EditarCaixaComMenosUm) {
    CaixaService service;
    service.criarCaixa("Andre");

    auto caixas = service.getCaixas();
    int id = caixas[0].id;

    service.editarCaixa(id, "-1");
    caixas = service.getCaixas();
    EXPECT_EQ(caixas[0].nome, "Andre");
}
