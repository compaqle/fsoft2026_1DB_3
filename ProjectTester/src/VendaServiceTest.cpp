#include <gtest/gtest.h>
#include "services/VendaService.h"
#include "services/ProdutoService.h"
#include "services/CategoriaService.h"
#include "services/ClienteService.h"
#include "exceptions/InvalidDataException.h"
#include "exceptions/NoDataException.h"

// preparar o ambiente: limpar tudo e criar dados de teste
static void prepararAmbiente() {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();

    // limpar vendas
    std::vector<Venda*>& vendas = repo.getVendas();
    for (int i = 0; i < (int)vendas.size(); i++) {
        delete vendas[i];
    }
    vendas.clear();

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

    // limpar clientes
    std::vector<Cliente*>& clientes = repo.getClientes();
    for (int i = 0; i < (int)clientes.size(); i++) {
        delete clientes[i];
    }
    clientes.clear();

    // criar dados base para os testes de vendas
    CategoriaService cs;
    cs.criarCategoria("Carnes", 0.23);

    ProdutoService ps;
    ps.criarProduto("Arroz", 2.0, 100, 1);

    ClienteService cls;
    cls.criarCliente(123456789, "Joao");
}

// teste: iniciar venda sem cliente (cliente generico)
TEST(VendaServiceTest, IniciarVendaSemCliente) {
    prepararAmbiente();

    VendaService service;

    bool deu_erro = false;
    try {
        service.iniciarVenda(0);
    }
    catch (...) {
        deu_erro = true;
    }
    EXPECT_FALSE(deu_erro);
    EXPECT_TRUE(service.temVendaAtiva());
}

// teste: iniciar venda com um cliente que existe
TEST(VendaServiceTest, IniciarVendaComCliente) {
    prepararAmbiente();

    VendaService service;

    bool deu_erro = false;
    try {
        service.iniciarVenda(123456789);
    }
    catch (...) {
        deu_erro = true;
    }
    EXPECT_FALSE(deu_erro);
    EXPECT_TRUE(service.temVendaAtiva());
}

// teste: iniciar venda com cliente inexistente deve falhar
TEST(VendaServiceTest, IniciarVendaClienteInexistente) {
    prepararAmbiente();

    VendaService service;

    bool deu_erro_certo = false;
    try {
        service.iniciarVenda(999999999);
    }
    catch (NoDataException& e) {
        deu_erro_certo = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro_certo);
}

// teste: adicionar item sem ter venda ativa deve falhar
TEST(VendaServiceTest, AdicionarItemSemVendaAtiva) {
    prepararAmbiente();

    VendaService service;

    bool deu_erro_certo = false;
    try {
        service.adicionarItem(1, 1);
    }
    catch (InvalidDataException& e) {
        deu_erro_certo = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro_certo);
}

// teste: adicionar quantidade maior que o stock deve falhar
TEST(VendaServiceTest, AdicionarItemComStockInsuficiente) {
    prepararAmbiente();

    VendaService service;
    service.iniciarVenda(0);

    bool deu_erro_certo = false;
    try {
        service.adicionarItem(1, 999);
    }
    catch (InvalidDataException& e) {
        deu_erro_certo = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro_certo);
}

// teste: cancelar uma venda ativa
TEST(VendaServiceTest, CancelarVenda) {
    prepararAmbiente();

    VendaService service;
    service.iniciarVenda(0);
    service.cancelarVenda();

    EXPECT_FALSE(service.temVendaAtiva());
}

// teste: consultar preco de um produto que existe
TEST(VendaServiceTest, ConsultarPrecoProdutoExistente) {
    prepararAmbiente();

    VendaService service;

    double preco = service.consultarPreco(1);
    EXPECT_GT(preco, 0.0);
}

// teste: consultar preco de produto inexistente deve falhar
TEST(VendaServiceTest, ConsultarPrecoProdutoInexistente) {
    prepararAmbiente();

    VendaService service;

    bool deu_erro_certo = false;
    try {
        service.consultarPreco(999);
    }
    catch (NoDataException& e) {
        deu_erro_certo = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro_certo);
}
