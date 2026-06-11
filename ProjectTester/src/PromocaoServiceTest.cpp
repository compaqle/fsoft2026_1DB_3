#include <gtest/gtest.h>
#include "services/PromocaoService.h"
#include "services/ProdutoService.h"
#include "services/CategoriaService.h"
#include "exceptions/InvalidDataException.h"
#include "exceptions/NoDataException.h"

class PromocaoServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        SupermercadoRepository& repo = SupermercadoRepository::getInstance();

        std::vector<Promocao*>& promocoes = repo.getPromocoes();
        for (Promocao* p : promocoes) delete p;

        std::vector<Produto*>& produtos = repo.getProdutos();
        for (Produto* p : produtos) delete p;

        std::vector<Categoria*>& categorias = repo.getCategorias();
        for (Categoria* c : categorias) delete c;

        promocoes.clear();
        produtos.clear();
        categorias.clear();

        CategoriaService cs;
        cs.criarCategoria("Carnes", 0.23);

        ProdutoService ps;
        ps.criarProduto("Arroz", 2.0, 100, 1);
    }
};

TEST_F(PromocaoServiceTest, CriarPromocaoProdutoValida) {
    PromocaoService service;
    EXPECT_NO_THROW(service.criarPromocaoProduto(20, "2026-06-01", "2026-06-30", 1));
    auto promocoes = service.getPromocoes();
    ASSERT_EQ(promocoes.size(), 1);
}

TEST_F(PromocaoServiceTest, CriarPromocaoCategoriaValida) {
    PromocaoService service;
    EXPECT_NO_THROW(service.criarPromocaoCategoria(15, "2026-06-01", "2026-06-30", 1));
    auto promocoes = service.getPromocoes();
    ASSERT_EQ(promocoes.size(), 1);
}

TEST_F(PromocaoServiceTest, CriarPromocaoPercentagemInvalida) {
    PromocaoService service;
    EXPECT_THROW(service.criarPromocaoProduto(150, "2026-06-01", "2026-06-30", 1), InvalidDataException);
    EXPECT_THROW(service.criarPromocaoProduto(0, "2026-06-01", "2026-06-30", 1), InvalidDataException);
}

TEST_F(PromocaoServiceTest, CriarPromocaoDataInvalida) {
    PromocaoService service;
    EXPECT_THROW(service.criarPromocaoProduto(20, "01-06-2026", "2026-06-30", 1), InvalidDataException);
}

TEST_F(PromocaoServiceTest, CriarPromocaoDataFimAntesInicio) {
    PromocaoService service;
    EXPECT_THROW(service.criarPromocaoProduto(20, "2026-06-30", "2026-06-01", 1), InvalidDataException);
}

TEST_F(PromocaoServiceTest, CriarPromocaoProdutoInexistente) {
    PromocaoService service;
    EXPECT_THROW(service.criarPromocaoProduto(20, "2026-06-01", "2026-06-30", 999), NoDataException);
}

TEST_F(PromocaoServiceTest, RemoverPromocaoExistente) {
    PromocaoService service;
    service.criarPromocaoProduto(20, "2026-06-01", "2026-06-30", 1);
    auto promocoes = service.getPromocoes();
    EXPECT_NO_THROW(service.removerPromocao(promocoes[0].id));
}

TEST_F(PromocaoServiceTest, RemoverPromocaoInexistente) {
    PromocaoService service;
    EXPECT_THROW(service.removerPromocao(999), NoDataException);
}

TEST_F(PromocaoServiceTest, EditarPromocao) {
    PromocaoService service;
    service.criarPromocaoProduto(20, "2026-06-01", "2026-06-30", 1);
    auto promocoes = service.getPromocoes();

    service.editarPromocao(promocoes[0].id, 30, "-1", "-1");
    promocoes = service.getPromocoes();
    EXPECT_DOUBLE_EQ(promocoes[0].percentagem, 30);
    EXPECT_EQ(promocoes[0].dataInicio, "2026-06-01");
}
