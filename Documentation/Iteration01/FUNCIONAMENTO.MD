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
- **US07:** Como Administrador, eu quero gerir o registo de Clientes (criar/editar/apagar) para fidelização.
- **US08:** Como Administrador, eu quero gerir Promoções (datas e percentagens) para dinamizar vendas.
- **US09:** Como Administrador, eu quero gerir Categorias de produtos para organizar o inventário e aplicar taxas.

### 1.2. Papel: Caixa
- **US10:** Como Caixa, eu quero listar produtos e consultar preços para informar corretamente os clientes.
- **US11:** Como Caixa, eu quero realizar vendas (registando produtos e quantidades) para processar as compras dos clientes.
- **US12:** Como Caixa, eu quero concluir vendas com diferentes métodos de pagamento e emitir recibos para documentar a transação.
- **US13:** Como Caixa, eu quero consultar o meu histórico e info individual para monitorizar o meu desempenho.
- **US14:** Como Caixa, eu quero associar uma venda a um Cliente para que este possa acumular ou usar pontos.
- **US15:** Como Caixa, eu quero consultar o saldo de pontos de um Cliente para informar sobre benefícios.
- **US16:** Como Caixa, eu quero que o sistema aplique automaticamente descontos de promoções ativas.
- **US17:** Como Caixa, eu quero consultar o detalhe de recibos de vendas passadas para esclarecer dúvidas dos clientes.

---

## 2. Requisitos Funcionais (Modelo de Casos de Uso)
Os requisitos funcionais especificam o comportamento do sistema para satisfazer as necessidades acima.

| ID | Caso de Uso | Ator(es) | Descrição Resumida |
| :--- | :--- | :--- | :--- |
| **UC01** | Gerir Catálogo | Admin | Permite criar, listar e remover produtos. |
| **UC02** | Consultar Estatísticas | Admin | Gera relatórios de faturação global ou por caixa. |
| **UC03** | Gerir Utilizadores | Admin | Permite o registo e remoção de contas de perfil 'Caixa'. |
| **UC04** | Repor Stock | Admin | Incrementa a quantidade disponível de um produto. |
| **UC05** | Gerir Clientes | Admin | Permite o registo, edição e remoção de perfis de Cliente. |
| **UC06** | Gerir Promoções | Admin | Criação e gestão de descontos temporais. |
| **UC07** | Gerir Categorias | Admin | Agrupamento de produtos para fins de IVA e Descontos. |
| **UC08** | Realizar Venda | Caixa | Inicia transação, adiciona itens e regista pagamento. |
| **UC09** | Consultar Preço | Caixa | Pesquisa e exibe o preço unitário de um produto. |
| **UC10** | Ver Info Própria | Caixa | Exibe dados do funcionário e total de vendas. |
| **UC11** | Associar Cliente | Caixa | Permite ligar a transação a um Cliente registado. |
| **UC12** | Consultar Pontos | Caixa | Visualizar saldo de pontos do Cliente. |
| **UC13** | Consultar Recibo | Caixa | Visualizar o detalhe de uma venda efetuada. |
| **UC14** | Selecionar Perfil | Admin, Caixa | Identifica o utilizador e o seu papel. |
| **UC15** | Sair do Perfil | Admin, Caixa | Termina a sessão do utilizador atual. |
