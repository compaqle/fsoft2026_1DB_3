#include <gtest/gtest.h>
#include "services/ProdutoService.h"
#include "exceptions/InvalidDataException.h"
#include "exceptions/NoDataException.h"

// limpar os produtos antes de cada teste
static void limparProdutos() {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Produto*>& produtos = repo.getProdutos();
    for (int i = 0; i < (int)produtos.size(); i++) {
        delete produtos[i];
    }
    produtos.clear();
}

// teste: criar um produto com dados normais
TEST(ProdutoServiceTest, CriarProdutoValido) {
    limparProdutos();

    ProdutoService service;

    // nao deve dar erro
    bool deu_erro = false;
    try {
        service.criarProduto("Arroz", 2.5, 10, 1);
    }
    catch (...) {
        deu_erro = true;
    }
    EXPECT_FALSE(deu_erro);

    // verificar se foi mesmo criado
    std::vector<ProdutoDTO> produtos = service.getProdutos();
    EXPECT_EQ(produtos.size(), 1);
    if (produtos.size() > 0) {
        EXPECT_EQ(produtos[0].nome, "Arroz");
        EXPECT_DOUBLE_EQ(produtos[0].preco, 2.5);
        EXPECT_EQ(produtos[0].stock, 10);
    }
}

// teste: criar produto sem nome deve falhar
TEST(ProdutoServiceTest, CriarProdutoNomeVazio) {
    limparProdutos();

    ProdutoService service;

    bool deu_erro_certo = false;
    try {
        service.criarProduto("", 2.5, 10, 1);
    }
    catch (InvalidDataException& e) {
        deu_erro_certo = true;
    }
    catch (...) {
        // ignorar outros erros
    }
    EXPECT_TRUE(deu_erro_certo);
}

// teste: criar produto com preco negativo deve falhar
TEST(ProdutoServiceTest, CriarProdutoPrecoNegativo) {
    limparProdutos();

    ProdutoService service;

    bool deu_erro_certo = false;
    try {
        service.criarProduto("Arroz", -1.0, 10, 1);
    }
    catch (InvalidDataException& e) {
        deu_erro_certo = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro_certo);
}

// teste: remover um produto que existe
TEST(ProdutoServiceTest, RemoverProdutoExistente) {
    limparProdutos();

    ProdutoService service;
    service.criarProduto("Arroz", 2.5, 10, 1);

    std::vector<ProdutoDTO> produtos = service.getProdutos();
    int id = produtos[0].id;

    bool deu_erro = false;
    try {
        service.removerProduto(id);
    }
    catch (...) {
        deu_erro = true;
    }
    EXPECT_FALSE(deu_erro);
}

// teste: remover um produto que nao existe deve falhar
TEST(ProdutoServiceTest, RemoverProdutoInexistente) {
    limparProdutos();

    ProdutoService service;

    bool deu_erro_certo = false;
    try {
        service.removerProduto(999);
    }
    catch (NoDataException& e) {
        deu_erro_certo = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro_certo);
}

// teste: editar produto com -1 mantem os valores antigos
TEST(ProdutoServiceTest, EditarProdutoMantemComMenosUm) {
    limparProdutos();

    ProdutoService service;
    service.criarProduto("Arroz", 2.5, 10, 1);

    std::vector<ProdutoDTO> produtos = service.getProdutos();
    int id = produtos[0].id;

    // -1 para manter o valor original
    service.editarProduto(id, "-1", -1, -1, -1);
    produtos = service.getProdutos();

    EXPECT_EQ(produtos[0].nome, "Arroz");
    EXPECT_DOUBLE_EQ(produtos[0].preco, 2.5);
}
