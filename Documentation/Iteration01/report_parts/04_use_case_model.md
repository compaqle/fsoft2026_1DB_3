# Modelo de Casos de Uso

Nesta secção detalhamos as interações entre os atores e o sistema.

| ID | Caso de Uso | Ator(es) | Descrição Resumida |
| :--- | :--- | :--- | :--- |
| **UC01** | Gerir Catálogo | ADMIN | Permite criar, editar, listar e remover PRODUTOS. |
| **UC02** | Consultar Estatísticas | ADMIN | Gera relatórios de faturação e volume por CAIXA ou global. |
| **UC03** | Gerir Utilizadores | ADMIN | Permite o registo e remoção de contas de perfil 'CAIXA'. |
| **UC04** | Repor Stock | ADMIN | Incrementa a quantidade disponível de um PRODUTO existente. |
| **UC05** | Realizar VENDA | CAIXA | Inicia transação, adiciona itens, calcula total e regista pagamento. |
| **UC06** | Consultar Preço | CAIXA | Pesquisa e exibe o preço unitário de um PRODUTO pelo seu ID. |
| **UC07** | Consultar Info e Histórico | CAIXA | Exibe dados do funcionário e histórico detalhado de VENDAS. |
| **UC08** | Gerir CLIENTES | ADMIN | Permite o registo, edição e remoção de perfis de CLIENTE. |
| **UC09** | Associar CLIENTE | CAIXA | Durante a VENDA, permite ligar a transação a um CLIENTE. |
| **UC10** | Consultar Pontos do CLIENTE | CAIXA | Visualizar saldo de pontos e aplicação automática de desconto. |
| **UC11** | Gerir PROMOÇÕES | ADMIN | Permite criar, editar e apagar PROMOÇÕES temporárias. |
| **UC12** | Gerir CATEGORIAS | ADMIN | Agrupar PRODUTOS para fins de IVA e Descontos. |
| **UC13** | Selecionar Perfil | ADMIN, CAIXA | Identifica o utilizador e o seu papel para aceder ao sistema. |
| **UC14** | Sair do Perfil | ADMIN, CAIXA | Termina a sessão do utilizador atual. |
| **UC15** | Consultar RECIBO | CAIXA | Consultar e visualizar o RECIBO de uma VENDA terminada. |

## Especificações de Casos de Uso

### UC01: Gerir Catálogo
| Campo | Descrição |
| :--- | :--- |
| **Actor** | ADMIN |
| **Use case name** | Gerir Catálogo |
| **Description** | Permite ao ADMIN gerir os PRODUTOS (criar, editar, listar e remover). |
| **Precondition** | ADMIN autenticado no sistema. |
| **Postcondition** | Catálogo de PRODUTOS atualizado na base de dados. |
| **Main flow** | 1. O ADMIN solicita a gestão do catálogo. <br> 2. O sistema mostra as opções disponíveis (Criar, Editar, Listar, Remover). <br> 3. O ADMIN seleciona "Criar". <br> 4. O sistema solicita os dados (nome, preço, stock, categoria). <br> 5. O ADMIN introduz os dados. <br> 6. O sistema valida os dados, gera um ID automático e grava. <br> 7. O sistema confirma o sucesso da operação. |
| **Alternative path** | 3.a. O ADMIN seleciona "Editar": O sistema solicita o ID e novos dados. <br> 3.b. O ADMIN seleciona "Remover": O sistema solicita o ID e confirma a remoção. |
| **Exceptions** | N/A |

### UC02: Consultar Estatísticas
| Campo | Descrição |
| :--- | :--- |
| **Actor** | ADMIN |
| **Use case name** | Consultar Estatísticas |
| **Description** | Permite visualizar relatórios de faturação global ou por CAIXA. |
| **Precondition** | ADMIN autenticado no sistema. |
| **Postcondition** | N/A (Consulta). |
| **Main flow** | 1. O ADMIN solicita a consulta de estatísticas. <br> 2. O sistema solicita o filtro desejado (global ou por utilizador CAIXA). <br> 3. O ADMIN escolhe o filtro. <br> 4. O sistema gera e apresenta o relatório de faturação e volume de vendas. |
| **Alternative path** | N/A |
| **Exceptions** | N/A |

### UC03: Gerir Utilizadores
| Campo | Descrição |
| :--- | :--- |
| **Actor** | ADMIN |
| **Use case name** | Gerir Utilizadores |
| **Description** | Permite o registo e remoção de contas de perfil 'CAIXA'. |
| **Precondition** | ADMIN autenticado no sistema. |
| **Postcondition** | Lista de utilizadores autorizados é atualizada. |
| **Main flow** | 1. O ADMIN solicita a gestão de utilizadores. <br> 2. O sistema mostra as opções (Registar, Remover). <br> 3. O ADMIN seleciona "Registar". <br> 4. O ADMIN introduz os dados do novo CAIXA (nome, etc.). <br> 5. O sistema valida os dados e cria a conta de perfil 'CAIXA'. <br> 6. O sistema confirma a criação com sucesso. |
| **Alternative path** | 3.a. O ADMIN seleciona "Remover": O sistema solicita o ID do CAIXA e remove a conta. |
| **Exceptions** | N/A |

### UC04: Repor Stock
| Campo | Descrição |
| :--- | :--- |
| **Actor** | ADMIN |
| **Use case name** | Repor Stock |
| **Description** | Incrementa a quantidade disponível de um PRODUTO existente. |
| **Precondition** | ADMIN autenticado no sistema. |
| **Postcondition** | Stock do PRODUTO é incrementado. |
| **Main flow** | 1. O ADMIN pesquisa o PRODUTO pelo seu ID. <br> 2. O sistema apresenta os dados atuais do PRODUTO. <br> 3. O ADMIN introduz a quantidade a adicionar ao stock. <br> 4. O sistema atualiza o valor do stock na base de dados. <br> 5. O sistema confirma le novo valor total de stock. |
| **Alternative path** | N/A |
| **Exceptions** | N/A |

### UC05: Realizar VENDA
| Campo | Descrição |
| :--- | :--- |
| **Actor** | CAIXA |
| **Use case name** | Realizar VENDA |
| **Description** | Processa uma transação de venda de PRODUTOS a um cliente. |
| **Precondition** | CAIXA autenticado no sistema. |
| **Postcondition** | VENDA registada, stock atualizado e RECIBO emitido. |
| **Main flow** | 1. O CAIXA inicia uma nova VENDA. <br> 2. O CAIXA introduz o ID e quantidade de cada PRODUTO. <br> 3. O sistema valida o item, calcula o subtotal e apresenta-o. <br> 4. O CAIXA termina a introdução de itens. <br> 5. O sistema calcula o total final (aplicando taxas e promoções). <br> 6. O CAIXA regista o pagamento. <br> 7. O sistema finaliza a VENDA e emite o RECIBO. |
| **Alternative path** | 6.a. O CAIXA cancela a VENDA: O sistema descarta os dados e liberta o stock reservado. |
| **Exceptions** | N/A |

### UC06: Consultar Preço
| Campo | Descrição |
| :--- | :--- |
| **Actor** | CAIXA |
| **Use case name** | Consultar Preço |
| **Description** | Pesquisa e exibe o preço unitário de um PRODUTO pelo seu ID. |
| **Precondition** | CAIXA autenticado no sistema. |
| **Postcondition** | N/A (Consulta). |
| **Main flow** | 1. O CAIXA introduz o ID do PRODUTO. <br> 2. O sistema pesquisa o ID. <br> 3. O sistema apresenta o nome e o preço unitário do PRODUTO. |
| **Alternative path** | N/A |
| **Exceptions** | N/A |

### UC07: Consultar Info e Histórico
| Campo | Descrição |
| :--- | :--- |
| **Actor** | CAIXA |
| **Use case name** | Consultar Info e Histórico |
| **Description** | Exibe dados do utilizador CAIXA e o histórico de VENDAS realizadas. |
| **Precondition** | CAIXA autenticado no sistema. |
| **Postcondition** | N/A (Consulta). |
| **Main flow** | 1. O CAIXA solicita o seu histórico. <br> 2. O sistema apresenta os dados do perfil (ID, nome) e o total faturado. <br> 3. O sistema apresenta a lista detalhada das VENDAS efetuadas por ele. |
| **Alternative path** | N/A |
| **Exceptions** | N/A |

### UC08: Gerir CLIENTES
| Campo | Descrição |
| :--- | :--- |
| **Actor** | ADMIN |
| **Use case name** | Gerir CLIENTES |
| **Description** | Permite o registo, edição e remoção de perfis de CLIENTE. |
| **Precondition** | ADMIN autenticado no sistema. |
| **Postcondition** | Base de dados de CLIENTES atualizada. |
| **Main flow** | 1. O ADMIN solicita gestão de CLIENTES. <br> 2. O sistema mostra as opções (Registar, Editar, Remover). <br> 3. O ADMIN seleciona "Registar". <br> 4. O ADMIN introduz o NIF e o nome do CLIENTE. <br> 5. O sistema valida o NIF, inicializa o saldo de pontos a zero e guarda o perfil. <br> 6. O sistema confirma o sucesso da operação. |
| **Alternative path** | 3.a. O ADMIN seleciona "Editar": O sistema permite mudar o nome do CLIENTE. <br> 3.b. O ADMIN seleciona "Remover": O sistema apaga o perfil do CLIENTE. |
| **Exceptions** | N/A |

### UC09: Associar CLIENTE
| Campo | Descrição |
| :--- | :--- |
| **Actor** | CAIXA |
| **Use case name** | Associar CLIENTE |
| **Description** | Durante uma VENDA, associa o CLIENTE à transação. |
| **Precondition** | VENDA em curso. |
| **Postcondition** | CLIENTE associado à VENDA. |
| **Main flow** | 1. O CAIXA solicita a associação de um CLIENTE. <br> 2. O CAIXA introduz o NIF do CLIENTE. <br> 3. O sistema valida o NIF e apresenta o nome correspondente. <br> 4. O sistema liga o CLIENTE à VENDA atual. |
| **Alternative path** | N/A |
| **Exceptions** | N/A |

### UC10: Consultar Pontos do CLIENTE
| Campo | Descrição |
| :--- | :--- |
| **Actor** | CAIXA |
| **Use case name** | Consultar Pontos do CLIENTE |
| **Description** | Permite visualizar o saldo de pontos atual de um CLIENTE. |
| **Precondition** | CAIXA autenticado no sistema. |
| **Postcondition** | N/A (Consulta). |
| **Main flow** | 1. O CAIXA introduz o NIF do CLIENTE. <br> 2. O sistema pesquisa o perfil correspondente. <br> 3. O sistema apresenta o saldo de pontos atual do CLIENTE. |
| **Alternative path** | N/A |
| **Exceptions** | N/A |

### UC11: Gerir PROMOÇÕES
| Campo | Descrição |
| :--- | :--- |
| **Actor** | ADMIN |
| **Use case name** | Gerir PROMOÇÕES |
| **Description** | Permite criar e configurar regras de desconto temporárias. |
| **Precondition** | ADMIN autenticado no sistema. |
| **Postcondition** | Base de dados de PROMOÇÕES atualizada. |
| **Main flow** | 1. O ADMIN solicita a gestão de PROMOÇÕES. <br> 2. O sistema mostra as opções (Criar, Remover). <br> 3. O ADMIN seleciona "Criar". <br> 4. O ADMIN define a percentagem de desconto e as datas de vigência. <br> 5. O ADMIN associa a PROMOÇÃO a um PRODUTO ou CATEGORIA específica. <br> 6. O sistema valida e guarda a regra de desconto. |
| **Alternative path** | 3.a. O ADMIN seleciona "Remover": O sistema apaga a regra de promoção selecionada. |
| **Exceptions** | N/A |

### UC12: Gerir CATEGORIAS
| Campo | Descrição |
| :--- | :--- |
| **Actor** | ADMIN |
| **Use case name** | Gerir CATEGORIAS |
| **Description** | Permite agrupar PRODUTOS para fins de IVA e descontos. |
| **Precondition** | ADMIN autenticado no sistema. |
| **Postcondition** | Lista de CATEGORIAS atualizada. |
| **Main flow** | 1. O ADMIN solicita a gestão de categorias. <br> 2. O sistema apresenta as opções (Criar, Listar). <br> 3. O ADMIN seleciona "Criar". <br> 4. O ADMIN introduz o nome da nova CATEGORIA e a respetiva taxa de IVA. <br> 5. O sistema valida os dados e cria a CATEGORIA. <br> 6. O sistema confirma a criação com sucesso. |
| **Alternative path** | N/A |
| **Exceptions** | N/A |

### UC13: Selecionar Perfil
| Campo | Descrição |
| :--- | :--- |
| **Actor** | ADMIN, CAIXA |
| **Use case name** | Selecionar Perfil |
| **Description** | Permite ao utilizador identificar-se e aceder ao menu correspondente. |
| **Precondition** | Sistema no menu de seleção inicial. |
| **Postcondition** | Utilizador autenticado e menu de funções ativo. |
| **Main flow** | 1. O utilizador seleciona o seu perfil (ADMIN ou um CAIXA específico) de uma lista apresentada. <br> 2. O sistema verifica as permissões do perfil. <br> 3. O sistema apresenta o menu de operações adequado ao papel selecionado. |
| **Alternative path** | N/A |
| **Exceptions** | N/A |

### UC14: Sair do Perfil
| Campo | Descrição |
| :--- | :--- |
| **Actor** | ADMIN, CAIXA |
| **Use case name** | Sair do Perfil |
| **Description** | Termina a sessão do utilizador atual. |
| **Precondition** | Utilizador com perfil ativo no sistema. |
| **Postcondition** | Sessão terminada e sistema regressa ao menu de seleção inicial. |
| **Main flow** | 1. O utilizador seleciona a opção "Sair" ou "Logout". <br> 2. O sistema limpa os dados de sessão atuais. <br> 3. O sistema regressa ao menu de seleção de perfil inicial. |
| **Alternative path** | N/A |
| **Exceptions** | N/A |

### UC15: Consultar RECIBO
| Campo | Descrição |
| :--- | :--- |
| **Actor** | CAIXA |
| **Use case name** | Consultar RECIBO |
| **Description** | Permite visualizar o detalhe de uma venda efetuada anteriormente. |
| **Precondition** | CAIXA autenticado no sistema. |
| **Postcondition** | N/A (Consulta). |
| **Main flow** | 1. O CAIXA seleciona uma venda do seu histórico recente. <br> 2. O sistema pesquisa os dados da transação. <br> 3. O sistema gera e apresenta o RECIBO detalhado no ecrã. |
| **Alternative path** | N/A (Happy case assumido). |
| **Exceptions** | N/A (Happy case assumido). |

## Diagramas de Sequência de Sistema (SSD)

Os SSDs detalham as trocas de mensagens entre o Ator e o Sistema (tratado como caixa preta) para o cenário principal de cada Caso de Uso.

### UC01: Gerir Catálogo (Cenário de Criação)
![SSD UC01](../diagramas/uc01.png)

### UC02: Consultar Estatísticas
![SSD UC02](../diagramas/uc02.png)

### UC03: Gerir Utilizadores (Cenário de Registo)
![SSD UC03](../diagramas/uc03.png)

### UC04: Repor Stock
![SSD UC04](../diagramas/uc04.png)

### UC05: Realizar VENDA
![SSD UC05](../diagramas/uc05.png)

### UC06: Consultar Preço
![SSD UC06](../diagramas/uc06.png)

### UC07: Consultar Histórico
![SSD UC07](../diagramas/uc07.png)

### UC08: Gerir CLIENTES (Cenário de Registo)
![SSD UC08](../diagramas/uc08.png)

### UC09: Associar CLIENTE
![SSD UC09](../diagramas/uc09.png)

### UC10: Consultar Pontos
![SSD UC10](../diagramas/uc10.png)

### UC11: Gerir PROMOÇÕES (Cenário de Criação)
![SSD UC11](../diagramas/uc11.png)

### UC12: Gerir CATEGORIAS (Cenário de Criação)
![SSD UC12](../diagramas/uc12.png)

### UC13: Selecionar Perfil
![SSD UC13](../diagramas/uc13.png)

### UC14: Sair do Perfil
![SSD UC14](../diagramas/uc14.png)

### UC15: Consultar RECIBO
![SSD UC15](../diagramas/uc15.png)
