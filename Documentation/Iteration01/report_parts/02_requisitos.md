# Análise de Requisitos

## User Stories

### Administrador (ADMIN)
- **US01:** Como ADMIN, eu quero criar novos PRODUTOS para poder atualizar o catálogo do supermercado.
- **US02:** Como ADMIN, eu quero apagar PRODUTOS do sistema para que os PRODUTOS que já não existam deixem de estar na base de dados.
- **US03:** Como ADMIN, eu quero listar todos os PRODUTOS existentes para que possa consultar o inventário.
- **US04:** Como ADMIN, eu quero aceder a estatísticas globais dos CAIXAS para avaliar o desempenho do supermercado.
- **US05:** Como ADMIN, eu quero gerir os registos de CAIXAS (adição/remoção) para controlar quem tem acesso ao sistema de VENDAS.
- **US06:** Como ADMIN, eu quero comprar stock para PRODUTOS existentes para garantir que não falta PRODUTOS.
- **US11:** Como ADMIN, eu quero gerir o registo de CLIENTES (criar/editar/apagar) para manter a base de dados de fidelização atualizada.
- **US15:** Como ADMIN, eu quero criar e gerir PROMOÇÕES (percentagem, data início, data fim) para incentivar as VENDAS.
- **US16:** Como ADMIN, eu quero associar PROMOÇÕES a PRODUTOS específicos ou a CATEGORIAS inteiras para incentivar as VENDAS de PRODUTOS específicos ou CATEGORIAS inteiras.

### CAIXA
- **US07:** Como CAIXA, eu quero listar PRODUTOS e consultar preços para informar os CLIENTES.
- **US08:** Como CAIXA, eu quero realizar VENDAS (registando PRODUTOS e quantidades) para processar as compras dos CLIENTES.
- **US09:** Como CAIXA, eu quero concluir VENDAS com diferentes métodos de pagamento e emitir RECIBOS para documentar a transação.
- **US10:** Como CAIXA, eu quero consultar o meu histórico e informação individual para saber o meu desempenho.
- **US12:** Como CAIXA, eu quero associar uma VENDA a um CLIENTE (via NIF ou ID) para que este possa acumular pontos de fidelização.
- **US13:** Como CAIXA, eu quero consultar o saldo de pontos de um CLIENTE para informar o CLIENTE sobre benefícios disponíveis.
- **US17:** Como CAIXA, eu quero que o sistema aplique automaticamente os descontos ativos no momento da VENDA sem intervenção manual.

## Requisitos Funcionais (RF)
- **RF01:** O sistema deve permitir a criação de um novo PRODUTO (nome, preço), criando um `id` único automaticamente.
- **RF02:** O sistema deve permitir a remoção de um PRODUTO pelo seu `id`.
- **RF03:** O sistema deve listar todos os PRODUTOS com os seus respetivos detalhes e stock.
- **RF04:** O sistema deve permitir o registo e remoção de utilizadores com perfil de CAIXA.
- **RF05:** O sistema deve calcular estatísticas de performance (faturação e volume) por CAIXA e globais.
- **RF06:** O sistema deve gerir o ciclo de vida de uma VENDA (iniciar, adicionar itens, cancelar, concluir).
- **RF07:** O sistema deve validar a disponibilidade de stock durante o registo de itens na VENDA.
- **RF08:** O sistema deve registar o método de pagamento e emitir um RECIBO textual após a conclusão da venda.
- **RF09:** O sistema deve identificar o utilizador e restringir acesso a funcionalidades baseadas no papel (Admin/Caixa).
- **RF10:** O sistema deve garantir a persistência de dados em ficheiros externos.
- **RF11:** O sistema deve permitir a gestão de CLIENTES (NIF, Nome, Pontos), garantindo que o NIF é único.
- **RF12:** O sistema deve permitir associar um CLIENTE a uma VENDA em curso.
- **RF13:** O sistema deve calcular e atribuir pontos ao CLIENTE após uma venda concluída (ex: 1 ponto por cada 10€).
- **RF14:** O sistema deve aplicar automaticamente o resgate de pontos para descontos no valor total da VENDA, caso o CLIENTE possua saldo suficiente.
- **RF15:** O sistema deve permitir a criação de PROMOÇÕES com intervalo de datas (início e fim) e percentagem de desconto.
- **RF16:** O sistema deve validar se uma PROMOÇÃO está ativa (data atual dentro do intervalo) antes de aplicar o desconto.
- **RF17:** O sistema deve permitir associar uma PROMOÇÃO a um PRODUTO ou a uma CATEGORIA de produtos.
- **RF18:** O sistema deve garantir que, no caso de mais de uma promoções aplicáveis, apenas a que desconte mais dinheiro para o cliente é aplicada.

## Requisitos Não Funcionais (FURPS+)

### Functionality (F)
- **RNF02 (Persistência de Dados):** O sistema deve garantir que o armazenamento de dados será em ficheiros CSV locais.

### Usability (U)
- **RNF03 (Estrutura de Menus):** O sistema deve permitir uma navegação por menus na CLI, por seleção numérica (0-9).

### Reliability (R)
- **RNF05 (Recuperação de Erro):** O sistema deve verificar os tipos de dados de entrada (ex: carateres em campos numéricos) e pedir uma nova introdução caso o tipo de dado esteja errado, sem perder o estado da transação ativa.
- **RNF06 (Integridade de Dados):** O sistema deve garantir que todas as transações que forem concluídas devem ser registadas num ficheiro.

### Performance (P)
- **RNF08 (Eficiência de Memória):** A aplicação não deve consumir mais de 1GB de memória RAM durante a execução.

### Supportability (S)
- **RNF11 (Portabilidade/Build):** O projeto deve ser compilável através de CMake (versão 3.10 ou superior) em ambiente Linux (GCC/Clang) e Windows (MSVC).

### + (Restrições de Implementação)
- **RNF12 (Norma da Linguagem):** O código fonte deve ser compatível com a norma C++17 (ISO/IEC 14882:2017).
