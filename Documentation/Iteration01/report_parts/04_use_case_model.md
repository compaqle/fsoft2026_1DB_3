# Modelo de Casos de Uso

Nesta secção detalhamos as interações entre os atores e o sistema.

![Diagrama de Casos de Uso](../diagramas/usecase_diagram.png)

| ID | Caso de Uso | Ator(es) | Descrição Resumida |
| :--- | :--- | :--- | :--- |
| **UC01** | Gerir Catálogo | Admin | Permite criar, listar e remover produtos (com ID automático). |
| **UC02** | Consultar Estatísticas | Admin | Gera relatórios de faturação e volume por caixa ou global. |
| **UC03** | Gerir Utilizadores | Admin | Permite o registo e remoção de contas de perfil 'Caixa'. |
| **UC04** | Repor Stock | Admin | Incrementa a quantidade disponível de um produto existente. |
| **UC05** | Realizar Venda | Caixa | Inicia transação, adiciona itens, calcula total e regista pagamento. |
| **UC06** | Consultar Preço | Caixa | Pesquisa e exibe o preço unitário de um produto pelo seu ID. |
| **UC07** | Ver Info Própria | Caixa | Exibe dados do funcionário logado e o seu total de vendas. |

## Diagramas de Sequência de Sistema (SSD)
Os SSDs detalham as trocas de mensagens entre o Ator e o Sistema (tratado como caixa preta) para os fluxos principais.

### UC05: Realizar Venda
![SSD Realizar Venda](../diagramas/ssd_venda.png)

*(Inserir aqui diagrama SSD para UC01)*
