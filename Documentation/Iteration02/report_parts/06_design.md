# Design de Software

## Arquitetura Física

![Arquitetura Física](../diagramas/design/physical_architecture.drawio.png)

## Arquitetura Lógica

![Arquitetura Lógica](../diagramas/design/logical_architecture.drawio.png)

## Organização do Código

![Organização do Código](../diagramas/design/code_organization.drawio.png)

## Diagrama de Classes do Modelo (Design Class Diagram)

![Diagrama de Classes do Modelo](../diagramas/design/model_class_diagram.drawio.png)

## Diagrama de Classes das Exceções

![Diagrama de Classes das Exceções](../diagramas/design/exceptions_class_diagram.drawio.png)

## Diagrama de Classes das Views

![Diagrama de Classes das Views](../diagramas/design/views_class_diagram.drawio.png)

## Diagrama de Classes do Controller, Services e Repository

![Diagrama de Classes do Controller, Services e Repository](../diagramas/design/controllers_services_class_diagram.drawio.png)

## Padrão Model-View-Controller (MVC)
Para garantir a organização e facilidade de manutenção, o sistema foi dividido em três camadas:

1.  **Model:** Contém as classes de dados (`Produto`, `Cliente`, `Ponto`, `Venda`). Estas classes não conhecem a interface do utilizador.
2.  **View:** Responsável por toda a interação com o utilizador via CLI (`std::cout` e `std::cin`).
3.  **Controller:** Faz a ponte entre as vistas e os dados, aplicando as regras de negócio.

## Arquitetura de Ficheiros
O projeto utiliza uma separação rigorosa entre declaração e implementação:
- **`include/`**: Ficheiros de cabeçalho (`.h`) com as definições das classes.
- **`src/`**: Ficheiros de implementação (`.cpp`) com a lógica dos métodos.
