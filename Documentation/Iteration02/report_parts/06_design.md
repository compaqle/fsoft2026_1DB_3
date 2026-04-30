# Design de Software

## Padrão Model-View-Controller (MVC)
Para garantir a organização e facilidade de manutenção, o sistema foi dividido em três camadas:

1.  **Model:** Contém as classes de dados (`Produto`, `Cliente`, `Pontos`, `Venda`). Estas classes não conhecem a interface do utilizador.
2.  **View:** Responsável por toda a interação com o utilizador via CLI (`std::cout` e `std::cin`).
3.  **Controller:** Faz a ponte entre as vistas e os dados, aplicando as regras de negócio.

## Arquitetura de Ficheiros
O projeto utiliza uma separação rigorosa entre declaração e implementação:
- **`include/`**: Ficheiros de cabeçalho (`.h`) com as definições das classes.
- **`src/`**: Ficheiros de implementação (`.cpp`) com a lógica dos métodos.
