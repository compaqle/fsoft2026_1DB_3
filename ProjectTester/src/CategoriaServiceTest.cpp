#include <gtest/gtest.h>
#include "services/CategoriaService.h"
#include "exceptions/InvalidDataException.h"
#include "exceptions/NoDataException.h"

class CategoriaServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        SupermercadoRepository& repo = SupermercadoRepository::getInstance();
        std::vector<Categoria*>& categorias = repo.getCategorias();
        for (Categoria* c : categorias) {
            delete c;
        }
        categorias.clear();
    }
};

TEST_F(CategoriaServiceTest, CriarCategoriaValida) {
    CategoriaService service;
    EXPECT_NO_THROW(service.criarCategoria("Carnes", 0.23));

    auto categorias = service.getCategorias();
    ASSERT_EQ(categorias.size(), 1);
    EXPECT_EQ(categorias[0].nome, "Carnes");
}

TEST_F(CategoriaServiceTest, CriarCategoriaNomeVazio) {
    CategoriaService service;
    EXPECT_THROW(service.criarCategoria("", 0.23), InvalidDataException);
}

TEST_F(CategoriaServiceTest, CriarCategoriaIvaNegativo) {
    CategoriaService service;
    EXPECT_THROW(service.criarCategoria("Carnes", -1.0), InvalidDataException);
}

TEST_F(CategoriaServiceTest, RemoverCategoriaExistente) {
    CategoriaService service;
    service.criarCategoria("Carnes", 0.23);

    auto categorias = service.getCategorias();
    int id = categorias[0].id;

    EXPECT_NO_THROW(service.removerCategoria(id));
}

TEST_F(CategoriaServiceTest, RemoverCategoriaInexistente) {
    CategoriaService service;
    EXPECT_THROW(service.removerCategoria(999), NoDataException);
}

TEST_F(CategoriaServiceTest, EditarCategoria) {
    CategoriaService service;
    service.criarCategoria("Carnes", 0.23);

    auto categorias = service.getCategorias();
    int id = categorias[0].id;

    service.editarCategoria(id, "Peixe", -1);
    categorias = service.getCategorias();
    EXPECT_EQ(categorias[0].nome, "Peixe");
}
