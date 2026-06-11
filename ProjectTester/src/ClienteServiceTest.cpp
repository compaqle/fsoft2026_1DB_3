#include <gtest/gtest.h>
#include "services/ClienteService.h"
#include "exceptions/InvalidDataException.h"
#include "exceptions/NoDataException.h"
#include "exceptions/DuplicatedDataException.h"

class ClienteServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        SupermercadoRepository& repo = SupermercadoRepository::getInstance();
        std::vector<Cliente*>& clientes = repo.getClientes();
        for (Cliente* c : clientes) {
            delete c;
        }
        clientes.clear();
    }
};

TEST_F(ClienteServiceTest, CriarClienteValido) {
    ClienteService service;
    EXPECT_NO_THROW(service.criarCliente(123456789, "Joao"));

    auto clientes = service.getClientes();
    ASSERT_EQ(clientes.size(), 1);
    EXPECT_EQ(clientes[0].nome, "Joao");
    EXPECT_EQ(clientes[0].pontos, 0);
}

TEST_F(ClienteServiceTest, CriarClienteNifDuplicado) {
    ClienteService service;
    service.criarCliente(123456789, "Joao");
    EXPECT_THROW(service.criarCliente(123456789, "Maria"), DuplicatedDataException);
}

TEST_F(ClienteServiceTest, RemoverClienteExistente) {
    ClienteService service;
    service.criarCliente(123456789, "Joao");

    EXPECT_NO_THROW(service.removerCliente(123456789));
}

TEST_F(ClienteServiceTest, RemoverClienteInexistente) {
    ClienteService service;
    EXPECT_THROW(service.removerCliente(999999999), NoDataException);
}

TEST_F(ClienteServiceTest, EditarCliente) {
    ClienteService service;
    service.criarCliente(123456789, "Joao");

    service.editarCliente(123456789, "Joao Silva");
    auto clientes = service.getClientes();
    EXPECT_EQ(clientes[0].nome, "Joao Silva");
}
