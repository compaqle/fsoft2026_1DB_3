#include <gtest/gtest.h>
#include "services/CategoriaService.h"
#include "exceptions/InvalidDataException.h"
#include "exceptions/NoDataException.h"

// limpar as categorias antes de cada teste
static void limparCategorias() {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Categoria*>& categorias = repo.getCategorias();
    for (int i = 0; i < (int)categorias.size(); i++) {
        delete categorias[i];
    }
    categorias.clear();
}

// teste: criar uma categoria com dados normais
TEST(CategoriaServiceTest, CriarCategoriaValida) {
    limparCategorias();

    CategoriaService service;

    bool deu_erro = false;
    try {
        service.criarCategoria("Carnes", 0.23);
    }
    catch (...) {
        deu_erro = true;
    }
    EXPECT_FALSE(deu_erro);

    // confirmar que ficou guardada
    std::vector<CategoriaDTO> categorias = service.getCategorias();
    EXPECT_EQ(categorias.size(), 1);
    if (categorias.size() > 0) {
        EXPECT_EQ(categorias[0].nome, "Carnes");
    }
}

// teste: criar categoria sem nome deve falhar
TEST(CategoriaServiceTest, CriarCategoriaNomeVazio) {
    limparCategorias();

    CategoriaService service;

    bool deu_erro_certo = false;
    try {
        service.criarCategoria("", 0.23);
    }
    catch (InvalidDataException& e) {
        deu_erro_certo = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro_certo);
}

// teste: criar categoria com iva negativo deve falhar
TEST(CategoriaServiceTest, CriarCategoriaIvaNegativo) {
    limparCategorias();

    CategoriaService service;

    bool deu_erro_certo = false;
    try {
        service.criarCategoria("Carnes", -1.0);
    }
    catch (InvalidDataException& e) {
        deu_erro_certo = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro_certo);
}

// teste: remover uma categoria que existe
TEST(CategoriaServiceTest, RemoverCategoriaExistente) {
    limparCategorias();

    CategoriaService service;
    service.criarCategoria("Carnes", 0.23);

    std::vector<CategoriaDTO> categorias = service.getCategorias();
    int id = categorias[0].id;

    bool deu_erro = false;
    try {
        service.removerCategoria(id);
    }
    catch (...) {
        deu_erro = true;
    }
    EXPECT_FALSE(deu_erro);
}

// teste: remover uma categoria que nao existe deve falhar
TEST(CategoriaServiceTest, RemoverCategoriaInexistente) {
    limparCategorias();

    CategoriaService service;

    bool deu_erro_certo = false;
    try {
        service.removerCategoria(999);
    }
    catch (NoDataException& e) {
        deu_erro_certo = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro_certo);
}

// teste: editar categoria - mudar o nome, manter o iva
TEST(CategoriaServiceTest, EditarCategoria) {
    limparCategorias();

    CategoriaService service;
    service.criarCategoria("Carnes", 0.23);

    std::vector<CategoriaDTO> categorias = service.getCategorias();
    int id = categorias[0].id;

    service.editarCategoria(id, "Peixe", -1);
    categorias = service.getCategorias();

    EXPECT_EQ(categorias[0].nome, "Peixe");
}
