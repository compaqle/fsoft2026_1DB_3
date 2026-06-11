#include <gtest/gtest.h>
#include "services/VendaService.h"
#include "services/ProdutoService.h"
#include "services/CategoriaService.h"
#include "services/ClienteService.h"
#include "exceptions/InvalidDataException.h"
#include "exceptions/NoDataException.h"

class VendaServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        SupermercadoRepository& repo = SupermercadoRepository::getInstance();

        std::vector<Venda*>& vendas = repo.getVendas();
        for (Venda* v : vendas) delete v;

        std::vector<Produto*>& produtos = repo.getProdutos();
        for (Produto* p : produtos) delete p;

        std::vector<Categoria*>& categorias = repo.getCategorias();
        for (Categoria* c : categorias) delete c;

        std::vector<Cliente*>& clientes = repo.getClientes();
        for (Cliente* c : clientes) delete c;

        vendas.clear();
        produtos.clear();
        categorias.clear();
        clientes.clear();

        CategoriaService cs;
        cs.criarCategoria("Carnes", 0.23);

        ProdutoService ps;
        ps.criarProduto("Arroz", 2.0, 100, 1);

        ClienteService cls;
        cls.criarCliente(123456789, "Joao");
    }
};

TEST_F(VendaServiceTest, IniciarVendaSemCliente) {
    VendaService service;
    EXPECT_NO_THROW(service.iniciarVenda(0));
    EXPECT_TRUE(service.temVendaAtiva());
}

TEST_F(VendaServiceTest, IniciarVendaComCliente) {
    VendaService service;
    EXPECT_NO_THROW(service.iniciarVenda(123456789));
    EXPECT_TRUE(service.temVendaAtiva());
}

TEST_F(VendaServiceTest, IniciarVendaClienteInexistente) {
    VendaService service;
    EXPECT_THROW(service.iniciarVenda(999999999), NoDataException);
}

TEST_F(VendaServiceTest, AdicionarItemSemVendaAtiva) {
    VendaService service;
    EXPECT_THROW(service.adicionarItem(1, 1), InvalidDataException);
}

TEST_F(VendaServiceTest, AdicionarItemComStockInsuficiente) {
    VendaService service;
    service.iniciarVenda(0);
    EXPECT_THROW(service.adicionarItem(1, 999), InvalidDataException);
}

TEST_F(VendaServiceTest, CancelarVenda) {
    VendaService service;
    service.iniciarVenda(0);
    service.cancelarVenda();
    EXPECT_FALSE(service.temVendaAtiva());
}

TEST_F(VendaServiceTest, ConsultarPrecoProdutoExistente) {
    VendaService service;
    double preco = service.consultarPreco(1);
    EXPECT_GT(preco, 0.0);
}

TEST_F(VendaServiceTest, ConsultarPrecoProdutoInexistente) {
    VendaService service;
    EXPECT_THROW(service.consultarPreco(999), NoDataException);
}
