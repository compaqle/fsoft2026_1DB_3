# Especificação do Sistema (Funcionamento)

Este documento separa as Necessidades de Negócio (User Stories) da Especificação Funcional do Sistema (Casos de Uso), conforme as regras de Engenharia de Requisitos de FSOFT.

---

## 1. Necessidades de Negócio (User Stories)
As User Stories descrevem as necessidades dos stakeholders e o valor que esperam obter do sistema.

### 1.1. Papel: Administrador (Admin)
- **US01:** Como Administrador, eu quero criar novos produtos para que possa atualizar o catálogo do supermercado.
- **US02:** Como Administrador, eu quero apagar produtos do sistema para que artigos descontinuados deixem de constar na base de dados.
- **US03:** Como Administrador, eu quero listar todos os produtos existentes para que possa consultar o inventário atual.
- **US04:** Como Administrador, eu quero aceder a estatísticas globais dos caixas para avaliar o desempenho da equipa.
- **US05:** Como Administrador, eu quero gerir os registos de caixas (adicionar/apagar) para controlar quem tem acesso ao sistema de vendas.
- **US06:** Como Administrador, eu quero comprar stock para produtos existentes para garantir a disponibilidade de artigos.

### 1.2. Papel: Caixa
- **US07:** Como Caixa, eu quero listar produtos e consultar preços para informar corretamente os clientes.
- **US08:** Como Caixa, eu quero realizar vendas (registando produtos e quantidades) para processar as compras dos clientes.
- **US09:** Como Caixa, eu quero concluir vendas com diferentes métodos de pagamento e emitir recibos para documentar a transação.
- **US10:** Como Caixa, eu quero consultar o meu histórico e info individual para monitorizar o meu desempenho.

---

## 2. Requisitos Funcionais (Modelo de Casos de Uso)
Os requisitos funcionais especificam o comportamento do sistema para satisfazer as necessidades acima.

| ID | Caso de Uso | Ator(es) | Descrição Resumida |
| :--- | :--- | :--- | :--- |
| **UC01** | Gerir Catálogo | Admin | Permite criar, listar e remover produtos (com ID automático). |
| **UC02** | Consultar Estatísticas | Admin | Gera relatórios de faturação e volume por caixa ou global. |
| **UC03** | Gerir Utilizadores | Admin | Permite o registo e remoção de contas de perfil 'Caixa'. |
| **UC04** | Repor Stock | Admin | Incrementa a quantidade disponível de um produto existente. |
| **UC05** | Realizar Venda | Caixa | Inicia transação, adiciona itens, calcula total e regista pagamento. |
| **UC06** | Consultar Preço | Caixa | Pesquisa e exibe o preço unitário de um produto pelo seu ID. |
| **UC07** | Ver Info Própria | Caixa | Exibe dados do funcionário logado e o seu total de vendas. |

---

## 3. Requisitos Não Funcionais (FURPS+)

### 3.1. Funcionalidade (+)
*   **Persistência:** O sistema deve armazenar os dados em ficheiros de texto/csv (PRODUTOS.txt, CAIXAS.txt, VENDAS.txt).
*   **Autenticação:** O sistema deve validar as credenciais no login para atribuir o menu correto (Admin ou Caixa).

### 3.2. Usabilidade (U)
*   **Interface CLI:** O sistema deve apresentar menus numerados e intuitivos via consola.

### 3.3. Fiabilidade (R)
*   **Tratamento de Exceções:** O sistema deve lançar e tratar exceções de domínio (ex: `ProductNotFoundException`) sem encerrar o programa.

### 3.4. Performance (P)
*   **Tempo de Resposta:** As operações de listagem e procura de ID devem ser executadas em menos de 1 segundo (considerando volumes de dados escolares).

---

## 4. Glossário (Rigor T5)
*   **CAIXA:** Funcionário operador do sistema de vendas; também termo para o terminal de venda (POS).
*   **PRODUTO:** Artigo unitário inventariável com ID, Nome, Preço e Stock.
*   **RECIBO:** Comprovativo textual de uma venda concluída.
*   **VENDA:** Registo transacional de um conjunto de produtos associados a um pagamento.
