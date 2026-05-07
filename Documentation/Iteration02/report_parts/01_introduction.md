# Introdução

O objetivo deste projeto é criar uma aplicação para gerir um supermercado, a aplicação vai ter um ADMIN, CAIXAs e CLIENTEs.

O ADMIN é responsável por gerir o catálogo da loja, incluindo criar, editar, listar e remover PRODUTOs. Tem também a habilidade de gerir CATEGORIAs de PRODUTOs, configurar PROMOÇÕEs temporárias com percentagens de desconto e intervalos de datas, e repor níveis de stock a PRODUTOs que já existem. Adicionalmente, o ADMIN irá gerir contas de CAIXA (criando-as e removendo-as), gerir a base de dados de CLIENTEs (registando, editando, listando e removendo CLIENTEs), e consultar estatísticas de desempenho globais e por CAIXA, como a faturação e o volume de VENDAs.

O CAIXA pode iniciar e processar VENDAs, adicionando PRODUTOs e quantidades, aplicando descontos automáticos de PROMOÇÕEs ativas e concluindo transações com diferentes métodos de pagamento. Pode também associar um CLIENTE a uma VENDA em curso através do seu NIF, consultar o quantidade de PONTOS atual de um CLIENTE e visualizar o seu próprio histórico de desempenho e total faturado. Após concluir uma VENDA, o sistema irá gerar um RECIBO com os detalhes dos PRODUTOs, totais e método de pagamento utilizado.

Os CLIENTEs registados no sistema acumularão PONTOS de fidelização com base nas suas compras (ex: 1 ponto por cada 10€ gastos). Estes PONTOS poderão ser utilizados para descontos em compras futuras. O sistema armazenará os dados do CLIENTE, incluindo o seu NIF, nome e quantidade de PONTOS de fidelização associado.

Este relatório inclui histórias de utilizador, requisitos funcionais e não funcionais (utilizando o modelo FURPS+), o modelo de domínio, especificações e diagramas de casos de uso, e o design de software baseado no padrão Model-View-Controller (MVC). A aplicação será desenvolvida em C++17 utilizando programação orientada a objetos, com persistência de dados através de ficheiros CSV externos.
