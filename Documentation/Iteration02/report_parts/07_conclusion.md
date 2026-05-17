# Conclusão

A segunda iteração foi dedicada ao design e à implementação do sistema. A principal decisão arquitetural foi adotar um padrão MVC estendido em camadas, o que nos permitiu organizar o código de forma clara e com responsabilidades bem definidas. No total, resultaram desta fase 10 classes de domínio (Model), 4 classes de interface (View), 2 Services, 1 Repository com padrão Singleton, 7 DTOs, 2 Mappers e 4 classes de exceção. Todo este design foi documentado através de 8 diagramas UML, um por cada aspeto relevante da arquitetura.
Do ponto de vista da implementação, conseguimos concluir 4 dos 15 casos de uso identificados na iteração anterior: Gerir Catálogo (UC01), Gerir Categorias (UC07), Selecionar Perfil (UC14) e Sair do Perfil (UC15). Aproveitámos também para rever os diagramas de sequência, tornando-os mais detalhados e fiéis ao fluxo real do sistema — mostrando concretamente como a informação percorre as camadas, da View até ao Repository, passando pelo Controller e pelo Service.
Para a próxima iteração, o objetivo é implementar os casos de uso que ainda faltam, com especial foco na gestão de Vendas, Clientes e Promoções. Será igualmente a altura de introduzir testes unitários, utilizando o framework Google Test. 


