#include <gtest/gtest.h>
#include "services/PromocaoService.h"
#include "services/ProdutoService.h"
#include "services/CategoriaService.h"
#include "exceptions/InvalidDataException.h"
#include "exceptions/NoDataException.h"

// preparar o ambiente: limpar tudo e criar dados de teste
static void prepararAmbiente() {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();

    // limpar promocoes
    std::vector<Promocao*>& promocoes = repo.getPromocoes();
    for (int i = 0; i < (int)promocoes.size(); i++) {
        delete promocoes[i];
    }
    promocoes.clear();

    // limpar produtos
    std::vector<Produto*>& produtos = repo.getProdutos();
    for (int i = 0; i < (int)produtos.size(); i++) {
        delete produtos[i];
    }
    produtos.clear();

    // limpar categorias
    std::vector<Categoria*>& categorias = repo.getCategorias();
    for (int i = 0; i < (int)categorias.size(); i++) {
        delete categorias[i];
    }
    categorias.clear();

    // criar dados base
    CategoriaService cs;
    cs.criarCategoria("Carnes", 0.23);

    ProdutoService ps;
    ps.criarProduto("Arroz", 2.0, 100, 1);
}

// teste: criar promocao para um produto
TEST(PromocaoServiceTest, CriarPromocaoProdutoValida) {
    prepararAmbiente();

    PromocaoService service;

    bool deu_erro = false;
    try {
        service.criarPromocaoProduto(20, "2026-06-01", "2026-06-30", 1);
    }
    catch (...) {
        deu_erro = true;
    }
    EXPECT_FALSE(deu_erro);

    std::vector<PromocaoDTO> promocoes = service.getPromocoes();
    EXPECT_EQ(promocoes.size(), 1);
}

// teste: criar promocao para uma categoria
TEST(PromocaoServiceTest, CriarPromocaoCategoriaValida) {
    prepararAmbiente();

    PromocaoService service;

    bool deu_erro = false;
    try {
        service.criarPromocaoCategoria(15, "2026-06-01", "2026-06-30", 1);
    }
    catch (...) {
        deu_erro = true;
    }
    EXPECT_FALSE(deu_erro);

    std::vector<PromocaoDTO> promocoes = service.getPromocoes();
    EXPECT_EQ(promocoes.size(), 1);
}

// teste: percentagem acima de 100 ou abaixo de 0 deve falhar
TEST(PromocaoServiceTest, CriarPromocaoPercentagemInvalida) {
    prepararAmbiente();

    PromocaoService service;

    bool deu_erro1 = false;
    try {
        service.criarPromocaoProduto(150, "2026-06-01", "2026-06-30", 1);
    }
    catch (InvalidDataException& e) {
        deu_erro1 = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro1);

    bool deu_erro2 = false;
    try {
        service.criarPromocaoProduto(0, "2026-06-01", "2026-06-30", 1);
    }
    catch (InvalidDataException& e) {
        deu_erro2 = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro2);
}

// teste: formato de data errado deve falhar
TEST(PromocaoServiceTest, CriarPromocaoDataInvalida) {
    prepararAmbiente();

    PromocaoService service;

    bool deu_erro = false;
    try {
        service.criarPromocaoProduto(20, "01-06-2026", "2026-06-30", 1);
    }
    catch (InvalidDataException& e) {
        deu_erro = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro);
}

// teste: data de fim antes da data de inicio deve falhar
TEST(PromocaoServiceTest, CriarPromocaoDataFimAntesInicio) {
    prepararAmbiente();

    PromocaoService service;

    bool deu_erro = false;
    try {
        service.criarPromocaoProduto(20, "2026-06-30", "2026-06-01", 1);
    }
    catch (InvalidDataException& e) {
        deu_erro = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro);
}

// teste: criar promocao para produto que nao existe deve falhar
TEST(PromocaoServiceTest, CriarPromocaoProdutoInexistente) {
    prepararAmbiente();

    PromocaoService service;

    bool deu_erro = false;
    try {
        service.criarPromocaoProduto(20, "2026-06-01", "2026-06-30", 999);
    }
    catch (NoDataException& e) {
        deu_erro = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro);
}

// teste: remover uma promocao que existe
TEST(PromocaoServiceTest, RemoverPromocaoExistente) {
    prepararAmbiente();

    PromocaoService service;
    service.criarPromocaoProduto(20, "2026-06-01", "2026-06-30", 1);

    std::vector<PromocaoDTO> promocoes = service.getPromocoes();

    bool deu_erro = false;
    try {
        service.removerPromocao(promocoes[0].id);
    }
    catch (...) {
        deu_erro = true;
    }
    EXPECT_FALSE(deu_erro);
}

// teste: remover uma promocao que nao existe deve falhar
TEST(PromocaoServiceTest, RemoverPromocaoInexistente) {
    prepararAmbiente();

    PromocaoService service;

    bool deu_erro = false;
    try {
        service.removerPromocao(999);
    }
    catch (NoDataException& e) {
        deu_erro = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro);
}

// teste: editar percentagem de uma promocao, manter datas
TEST(PromocaoServiceTest, EditarPromocao) {
    prepararAmbiente();

    PromocaoService service;
    service.criarPromocaoProduto(20, "2026-06-01", "2026-06-30", 1);

    std::vector<PromocaoDTO> promocoes = service.getPromocoes();

    service.editarPromocao(promocoes[0].id, 30, "-1", "-1");
    promocoes = service.getPromocoes();

    EXPECT_DOUBLE_EQ(promocoes[0].percentagem, 30);
    EXPECT_EQ(promocoes[0].dataInicio, "2026-06-01");
}
