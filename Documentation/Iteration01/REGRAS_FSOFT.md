# Guia de Boas Práticas e Regras Estritas do Projeto FSOFT

Este documento detalha as normas rigorosas de arquitetura, codificação e documentação para o projeto de Fundamentos de Desenvolvimento de Software (FSOFT), baseadas nos materiais teóricos e no projeto exemplo do docente.

---

## 1. Arquitetura do Sistema: O Padrão MVC

O projeto deve seguir estritamente o padrão **Model-View-Controller**. A separação de responsabilidades é o critério de avaliação mais crítico.

### 1.1. Model (Camada de Domínio e Dados)
*   **Regra de Ouro:** Proibido o uso de `iostream` (`std::cout`, `std::cin`) ou qualquer forma de I/O dentro das classes do Model.
*   **Responsabilidade:** Contém a lógica de negócio, os dados e a integridade da informação.
*   **Comunicação de Erros:** Deve usar **Exceções** (`try-throw-catch`) para sinalizar erros de negócio (ex: "ID duplicado", "Produto não encontrado"). Nunca imprimir mensagens de erro diretamente.
*   **Classes Contentoras (Containers):** Para cada entidade (ex: `Product`), deve existir uma classe contentora (ex: `ProductContainer`) que gere a lista de objetos, as pesquisas, as adições e remoções.

### 1.2. View (Camada de Interface)
*   **Regra de Ouro:** Proibido conter lógica de negócio ou processamento de dados.
*   **Responsabilidade:** Única camada que comunica com o utilizador (`std::cout`, `std::cin`).
*   **Funcionamento:** Recebe dados brutos ou objetos do Controller para exibir, e captura inputs do utilizador para devolver ao Controller.
*   **Menus:** Deve implementar menus intuitivos e claros.

### 1.3. Controller (A Orquestra)
*   **Responsabilidade:** Mediar a interação entre a View e o Model.
*   **Ciclo de Vida:** Contém os loops principais da aplicação. Chama a View para obter um comando, processa-o através do Model e volta a chamar a View para mostrar o resultado ou capturar o próximo passo.
*   **Tratamento de Exceções:** É no Controller que os blocos `try-catch` devem residir para capturar exceções lançadas pelo Model e informar a View para exibir a mensagem de erro adequada ao utilizador.

---

## 2. Modelagem de Domínio (UML)

As regras de notação no Relatório Técnico (TR) são extremamente específicas:

*   **ENTIDADES:** Sempre em **MAIÚSCULAS** (ex: `PRODUTO`, `VENDA`).
*   **Atributos:** Sempre em **minúsculas** (ex: `nome`, `preco`).
*   **Proibido:** 
    *   Indicar tipos de dados (int, string) no diagrama de domínio.
    *   Incluir IDs ou Chaves Primárias (estas pertencem à implementação da Base de Dados, não ao domínio do problema).
*   **Relacionamentos:** Devem ter multiplicidade (1:1, 1..*, etc.) e nomes de verbos que descrevam a relação.

---

## 3. Requisitos Não Funcionais (Modelo FURPS+)

Todos os requisitos devem ser classificados segundo o modelo FURPS+:

1.  **F (Functionality):** Capacidades funcionais, segurança, persistência de dados.
2.  **U (Usability):** Estética, consistência da UI, documentação de utilizador.
3.  **R (Reliability):** Frequência de falhas, capacidade de recuperação, tratamento de erros (exceções).
4.  **P (Performance):** Tempos de resposta, consumo de recursos (deve ser **quantificável**, ex: "Resposta em menos de 1s").
5.  **S (Supportability):** Portabilidade (funcionar em Linux/Windows), extensibilidade do código.
6.  **+ (Plus):** Requisitos de implementação, interface física, etc.

---

## 4. Padrões de Codificação C++

Baseado no exemplo `SchoolApplication`:

*   **Header Guards:** Todos os ficheiros `.h` devem ter `#ifndef`, `#define`, `#endif` para evitar inclusões múltiplas.
*   **Encapsulamento:** Todos os atributos de classe devem ser `private`. O acesso é feito via `getters` e `setters`.
*   **Nomenclatura:**
    *   **Classes:** PascalCase (ex: `InventoryManager`).
    *   **Métodos/Variáveis:** camelCase (ex: `addProduct()`, `productName`).
    *   **Ficheiros:** Devem corresponder ao nome da classe (ex: `Student.h` e `Student.cpp`).
*   **Ponteiros e Referências:**
    *   Usar referências constantes (`const T&`) para passar objetos grandes e evitar cópias desnecessárias.
    *   Usar ponteiros (`T*`) para representar associações opcionais ou quando o objeto pode ser nulo.
*   **Destrutores:** Implementar sempre que houver alocação dinâmica de memória para evitar *memory leaks*.

---

## 5. Persistência de Dados

*   Os dados devem ser guardados em ficheiros (Texto ou Binário) para que não se percam ao fechar a aplicação.
*   A lógica de leitura/escrita deve estar no Model (ou numa classe de persistência específica), mas nunca deve imprimir mensagens na consola se houver um erro de ficheiro; deve lançar uma exceção.

---

## 6. Documentação (Relatório Técnico)

*   **Formato:** Deve seguir rigorosamente o template **LNCS (Lecture Notes in Computer Science)**.
*   **Linguagem:** Deve ser formal, técnica e sem ambiguidades.
*   **User Stories:** Devem seguir o formato: *"Como [Papel], eu quero [Ação], para que [Benefício]"*. Cada User Story deve ter critérios de aceitação claros e testáveis.
*   **Glossário (Regras T5):**
    *   Deve estar em **ordem alfabética**.
    *   Termos devem estar no **singular** (ex: `venda` e não `vendas`).
    *   Incluir abreviaturas (ex: `POS`, `IVA`).
    *   Termos com o mesmo significado devem ser ambos listados ou referenciados.
*   **System Sequence Diagram (SSD):**
    *   Trata o sistema como uma **caixa preta** (black box).
    *   Mostra apenas as interações entre o **Ator** e o **Sistema**.
    *   Não mostra lógica interna, classes do model ou bases de dados.
    *   Essencial para definir o protocolo de comunicação entre o utilizador e o software.

---

## 7. Critérios de Avaliação (Resumo)

*   **TR (Technical Report) [10%]:** Qualidade da modelação e rigor da escrita.
*   **CODE [60%]:** Qualidade da implementação C++, ausência de bugs, cumprimento do MVC.
*   **PRG (Progress) [20%]:** Evolução demonstrada em cada aula laboratorial.
*   **PRES (Presentation) [10%]:** Domínio individual do código e das decisões de design.

> **Nota Crítica:** Aplicações que não compilam ou que não estão num repositório Git público/partilhado com o docente **não serão avaliadas**.
