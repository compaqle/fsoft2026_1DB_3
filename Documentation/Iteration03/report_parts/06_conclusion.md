# Conclusão

A terceira iteração concluiu o desenvolvimento do sistema de gestão de supermercado. Partindo da base estabelecida na IT2 (arquitetura MVC em camadas, 4 casos de uso implementados), esta iteração focou-se em completar a implementação de todos os casos de uso restantes e em garantir a qualidade do código através de testes unitários.

No total, o sistema final conta com 10 classes de domínio (Model), 6 classes de interface (View), 6 Services, 1 Repository com padrão Singleton, 7 DTOs, 6 Mappers e 4 classes de exceção. A arquitetura em camadas (View → Controller → Service → Repository) manteve-se consistente ao longo de todo o desenvolvimento, assegurando uma separação clara de responsabilidades.

Todos os 15 casos de uso identificados na análise de requisitos foram implementados: gestão de catálogo, categorias, clientes, caixas, promoções, vendas, consulta de preços, pontos de cliente e estatísticas. A interface por linha de comandos oferece navegação completa para os perfis de ADMIN e CAIXA.

Foram também implementados 40 testes unitários com o framework Google Test, organizados em 6 suites (uma por cada Service), cobrindo cenários de sucesso e de erro para todas as operações CRUD e para o fluxo de vendas.

A documentação foi atualizada para refletir o estado final do sistema, incluindo 8 diagramas de classes UML, diagramas de sequência para os casos de uso implementados e o diagrama de navegação da interface.
