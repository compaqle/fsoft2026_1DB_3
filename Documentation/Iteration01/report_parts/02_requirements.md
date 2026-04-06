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
- **RF09:** O sistema deve autenticar utilizadores e restringir acesso a funcionalidades baseadas no papel (Admin/Caixa).
- **RF10:** O sistema deve garantir a persistência de dados em ficheiros externos.

## 2.3. Requisitos Não Funcionais (FURPS+)

### Usability (U)
- **RNF01 (Estrutura de Menus):** O sistema deve limitar a navegação a um máximo de 3 níveis de profundidade de menus, acessíveis por seleção numérica única (0-9).
- **RNF02 (Tempo de Aprendizagem):** Um utilizador sem formação prévia deve ser capaz de concluir uma venda (UC05) em menos de 180 segundos utilizando apenas as instruções presentes no ecrã.

### Reliability (R)
- **RNF03 (Recuperação de Erro):** O sistema deve validar todos os tipos de dados de entrada (ex: carateres em campos numéricos) e solicitar nova introdução em menos de 500ms, sem perda do estado da transação ativa.
- **RNF04 (Integridade de Dados):** O sistema deve garantir que 100% das transações concluídas são registadas no ficheiro de persistência antes de libertar a memória da venda ativa.

### Performance (P)
- **RNF05 (Tempo de Resposta):** Operações de pesquisa de produtos no inventário (UC06) e carregamento de ficheiros de persistência devem ser executadas num tempo de resposta inferior a 1,0 segundo.
- **RNF06 (Eficiência de Memória):** A aplicação não deve exceder um consumo de 128MB de memória RAM durante a execução de operações críticas de listagem.

### Supportability (S)
- **RNF07 (Padrão Arquitetural):** A implementação deve respeitar a separação MVC, onde 0% da lógica de negócio reside nas classes de View e 0% das operações de I/O (`std::cout`/`std::cin`) residem nas classes de Model.
- **RNF08 (Acoplamento):** As classes de Domínio devem ser independentes do meio de persistência escolhido, permitindo a substituição do formato CSV por Binário sem alterar a lógica de negócio.

### + (Restrições de Implementação)
- **RNF09 (Norma da Linguagem):** O código fonte deve ser compatível com a norma C++17 (ISO/IEC 14882:2017).
- **RNF10 (Persistência):** Os dados devem ser obrigatoriamente armazenados em ficheiros locais (CSV ou Binário), sendo proibido o uso de SGDBs externos.
- **RNF11 (Build System):** O projeto deve ser compilável através de CMake (versão 3.10 ou superior) em ambiente Linux (GCC/Clang) e Windows (MSVC).
