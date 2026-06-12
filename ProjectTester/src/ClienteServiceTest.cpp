#include <gtest/gtest.h>
#include "services/ClienteService.h"
#include "exceptions/InvalidDataException.h"
#include "exceptions/NoDataException.h"
#include "exceptions/DuplicatedDataException.h"

// limpar os clientes antes de cada teste
static void limparClientes() {
    SupermercadoRepository& repo = SupermercadoRepository::getInstance();
    std::vector<Cliente*>& clientes = repo.getClientes();
    for (int i = 0; i < (int)clientes.size(); i++) {
        delete clientes[i];
    }
    clientes.clear();
}

// teste: criar um cliente com dados normais
TEST(ClienteServiceTest, CriarClienteValido) {
    limparClientes();

    ClienteService service;

    bool deu_erro = false;
    try {
        service.criarCliente(123456789, "Joao");
    }
    catch (...) {
        deu_erro = true;
    }
    EXPECT_FALSE(deu_erro);

    std::vector<ClienteDTO> clientes = service.getClientes();
    EXPECT_EQ(clientes.size(), 1);
    if (clientes.size() > 0) {
        EXPECT_EQ(clientes[0].nome, "Joao");
        EXPECT_EQ(clientes[0].pontos, 0);
    }
}

// teste: criar dois clientes com o mesmo nif deve falhar
TEST(ClienteServiceTest, CriarClienteNifDuplicado) {
    limparClientes();

    ClienteService service;
    service.criarCliente(123456789, "Joao");

    bool deu_erro_certo = false;
    try {
        service.criarCliente(123456789, "Maria");
    }
    catch (DuplicatedDataException& e) {
        deu_erro_certo = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro_certo);
}

// teste: remover um cliente que existe
TEST(ClienteServiceTest, RemoverClienteExistente) {
    limparClientes();

    ClienteService service;
    service.criarCliente(123456789, "Joao");

    bool deu_erro = false;
    try {
        service.removerCliente(123456789);
    }
    catch (...) {
        deu_erro = true;
    }
    EXPECT_FALSE(deu_erro);
}

// teste: remover um cliente que nao existe deve falhar
TEST(ClienteServiceTest, RemoverClienteInexistente) {
    limparClientes();

    ClienteService service;

    bool deu_erro_certo = false;
    try {
        service.removerCliente(999999999);
    }
    catch (NoDataException& e) {
        deu_erro_certo = true;
    }
    catch (...) {
    }
    EXPECT_TRUE(deu_erro_certo);
}

// teste: editar o nome de um cliente
TEST(ClienteServiceTest, EditarCliente) {
    limparClientes();

    ClienteService service;
    service.criarCliente(123456789, "Joao");

    service.editarCliente(123456789, "Joao Silva");
    std::vector<ClienteDTO> clientes = service.getClientes();

    EXPECT_EQ(clientes[0].nome, "Joao Silva");
}
