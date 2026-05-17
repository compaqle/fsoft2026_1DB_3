# Conclusão

A segunda iteração foi dedicada ao design e à implementação do sistema. Usamos o padrão MVC estendido em mais camadas(Services, Exceptions, repo etc), o que nos permitiu organizar o código de forma clara e com responsabilidades bem definidas. No total, resultaram desta fase 10 classes de domínio (Model), 4 classes de interface (View), 2 Services, 1 Repository com padrão Singleton, 7 DTOs, 2 Mappers e 4 classes de exceção. Todo este design foi documentado através de 8 diagramas UML, um por cada aspeto relevante da arquitetura.
Do ponto de vista da implementação, conseguimos concluir 4 dos 15 casos de uso identificados na iteração anterior: Gerir Catálogo (UC01), Gerir Categorias (UC07), Selecionar Perfil (UC14) e Sair do Perfil (UC15). Aproveitámos também para rever os diagramas de sequência, tornando-os mais detalhados e de acordo com o fluxo real do sistema, mostrando a informação que percorre as camadas, da View até ao Repository, passando pelo Controller e pelo Service.
Para a próxima iteração, o objetivo é implementar os casos de uso que ainda faltam, com especial foco na gestão de Vendas, Clientes e Promoções. E realizar os testes unitários, utilizando o framework Google Test. 


