# Análise de Requisitos

## 2.1. User Stories

### Administrador (Admin)
- **US01:** Como Administrador, eu quero criar novos produtos para que possa atualizar o catálogo do supermercado.
- **US02:** Como Administrador, eu quero apagar produtos do sistema para que artigos descontinuados deixem de constar na base de dados.
- **US03:** Como Administrador, eu quero listar todos os produtos existentes para que possa consultar o inventário atual.
- **US04:** Como Administrador, eu quero aceder a estatísticas globais dos caixas para avaliar o desempenho da equipa.
- **US05:** Como Administrador, eu quero gerir os registos de caixas (adicionar/apagar) para controlar quem tem acesso ao sistema de vendas.
- **US06:** Como Administrador, eu quero comprar stock para produtos existentes para garantir a disponibilidade de artigos.

### Caixa
- **US07:** Como Caixa, eu quero listar produtos e consultar preços para informar corretamente os clientes.
- **US08:** Como Caixa, eu quero realizar vendas (registando produtos e quantidades) para processar as compras dos clientes.
- **US09:** Como Caixa, eu quero concluir vendas com diferentes métodos de pagamento e emitir recibos para documentar a transação.
- **US10:** Como Caixa, eu quero consultar o meu histórico e info individual para monitorizar o meu desempenho.
- **US11:** Como Administrador, eu quero gerir o registo de Clientes (criar/editar/apagar) para manter a base de dados de fidelização atualizada.
- **US12:** Como Caixa, eu quero associar uma venda a um Cliente (via NIF ou ID) para que este possa acumular pontos.
- **US13:** Como Caixa, eu quero consultar o saldo de pontos de um Cliente para informar o cliente sobre benefícios disponíveis.
- **US14:** Como Cliente, eu quero utilizar os meus pontos acumulados como desconto numa venda para reduzir o valor total a pagar.
- **US15:** Como Administrador, eu quero criar e gerir Promoções (percentagem, data início, data fim) para incentivar as vendas.
- **US16:** Como Administrador, eu quero associar Promoções a Produtos específicos ou a Categorias inteiras.
- **US17:** Como Caixa, eu quero que o sistema aplique automaticamente os descontos ativos no momento da venda sem intervenção manual.

## 2.2. Requisitos Funcionais (RF)
Os Requisitos Funcionais descrevem o comportamento detalhado do sistema:

- **RF01:** O sistema deve permitir a criação de um novo PRODUTO (nome, preço), gerando um `id` único automaticamente.
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
- **RF14:** O sistema deve permitir o resgate de pontos para descontos diretos no valor total da VENDA.
- **RF15:** O sistema deve permitir a criação de PROMOÇÕES com intervalo de datas (início e fim) e percentagem de desconto.
- **RF16:** O sistema deve validar se uma PROMOÇÃO está ativa (data atual dentro do intervalo) antes de aplicar o desconto.
- **RF17:** O sistema deve permitir associar uma PROMOÇÃO a um PRODUTO ou a uma CATEGORIA de produtos.
- **RF18:** O sistema deve garantir que, no caso de múltiplas promoções aplicáveis, apenas a mais vantajosa para o cliente é aplicada.

## 2.3. Requisitos Não Funcionais (FURPS+)

### Functionality (F)
- **RNF01 (Segurança e Controlo de Acesso):** O sistema deve restringir o acesso às funcionalidades de gestão apenas ao Administrador, através da seleção de perfil.
- **RNF02 (Persistência de Dados):** O sistema deve garantir o armazenamento global de dados em ficheiros locais (CSV ou Binário), sendo rigorosamente proibido o uso de SGBDs externos.

### Usability (U)
- **RNF03 (Estrutura de Menus):** O sistema deve limitar a navegação a um máximo de 3 níveis de profundidade de menus, acessíveis por seleção numérica única (0-9).
- **RNF04 (Tempo de Aprendizagem):** Um utilizador sem formação prévia deve ser capaz de concluir uma venda (UC05) em menos de 180 segundos utilizando apenas as instruções presentes no ecrã.

### Reliability (R)
- **RNF05 (Recuperação de Erro):** O sistema deve validar todos os tipos de dados de entrada (ex: carateres em campos numéricos) e solicitar nova introdução em menos de 500ms, sem perda do estado da transação ativa.
- **RNF06 (Integridade de Dados):** O sistema deve garantir que 100% das transações concluídas são registadas no ficheiro de persistência antes de libertar a memória da venda ativa.

### Performance (P)
- **RNF07 (Tempo de Resposta):** Operações de pesquisa de produtos no inventário (UC06) e carregamento de ficheiros de persistência devem ser executadas num tempo de resposta inferior a 1,0 segundo.
- **RNF08 (Eficiência de Memória):** A aplicação não deve exceder um consumo de 128MB de memória RAM durante a execução de operações críticas de listagem.

### Supportability (S)
- **RNF09 (Padrão Arquitetural):** A implementação deve respeitar a separação MVC, onde 0% da lógica de negócio reside nas classes de View e 0% das operações de I/O (`std::cout`/`std::cin`) residem nas classes de Model.
- **RNF10 (Acoplamento):** As classes de Domínio devem ser independentes do meio de persistência escolhido, permitindo a substituição do formato CSV por Binário sem alterar a lógica de negócio.
- **RNF11 (Portabilidade/Build):** O projeto deve ser compilável através de CMake (versão 3.10 ou superior) em ambiente Linux (GCC/Clang) e Windows (MSVC).

### + (Restrições de Implementação)
- **RNF12 (Norma da Linguagem):** O código fonte deve ser compatível com a norma C++17 (ISO/IEC 14882:2017).
