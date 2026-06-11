#include <gtest/gtest.h>
#include "services/ProdutoService.h"
#include "exceptions/InvalidDataException.h"
#include "exceptions/NoDataException.h"

class ProdutoServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        SupermercadoRepository& repo = SupermercadoRepository::getInstance();
        std::vector<Produto*>& produtos = repo.getProdutos();
        for (Produto* p : produtos) {
            delete p;
        }
        produtos.clear();
    }
};

TEST_F(ProdutoServiceTest, CriarProdutoValido) {
    ProdutoService service;
    EXPECT_NO_THROW(service.criarProduto("Arroz", 2.5, 10, 1));

    auto produtos = service.getProdutos();
    ASSERT_EQ(produtos.size(), 1);
    EXPECT_EQ(produtos[0].nome, "Arroz");
    EXPECT_DOUBLE_EQ(produtos[0].preco, 2.5);
    EXPECT_EQ(produtos[0].stock, 10);
}

TEST_F(ProdutoServiceTest, CriarProdutoNomeVazio) {
    ProdutoService service;
    EXPECT_THROW(service.criarProduto("", 2.5, 10, 1), InvalidDataException);
}

TEST_F(ProdutoServiceTest, CriarProdutoPrecoNegativo) {
    ProdutoService service;
    EXPECT_THROW(service.criarProduto("Arroz", -1.0, 10, 1), InvalidDataException);
}

TEST_F(ProdutoServiceTest, RemoverProdutoExistente) {
    ProdutoService service;
    service.criarProduto("Arroz", 2.5, 10, 1);

    auto produtos = service.getProdutos();
    int id = produtos[0].id;

    EXPECT_NO_THROW(service.removerProduto(id));
    EXPECT_THROW(service.getProdutos(), NoDataException);
}

TEST_F(ProdutoServiceTest, RemoverProdutoInexistente) {
    ProdutoService service;
    EXPECT_THROW(service.removerProduto(999), NoDataException);
}

TEST_F(ProdutoServiceTest, EditarProdutoMantemComMenosUm) {
    ProdutoService service;
    service.criarProduto("Arroz", 2.5, 10, 1);

    auto produtos = service.getProdutos();
    int id = produtos[0].id;

    service.editarProduto(id, "-1", -1, -1, -1);
    produtos = service.getProdutos();
    EXPECT_EQ(produtos[0].nome, "Arroz");
    EXPECT_DOUBLE_EQ(produtos[0].preco, 2.5);
}
