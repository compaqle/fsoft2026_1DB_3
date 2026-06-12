# Testes Unitários

Os testes unitários foram implementados com o framework Google Test. O projeto de testes contém 40 testes organizados em 6 suites, uma por cada Service.

## Estrutura dos Testes

| Suite | Ficheiro | Testes |
|-------|----------|--------|
| ProdutoServiceTest | `test_ProdutoService.cpp` | 6 |
| CategoriaServiceTest | `test_CategoriaService.cpp` | 6 |
| ClienteServiceTest | `test_ClienteService.cpp` | 5 |
| CaixaServiceTest | `test_CaixaService.cpp` | 6 |
| VendaServiceTest | `test_VendaService.cpp` | 8 |
| PromocaoServiceTest | `test_PromocaoService.cpp` | 9 |
| **Total** | | **40** |

## Cobertura de Testes

Cada suite cobre cenários de sucesso e de erro:

- **ProdutoService:** Criar produto válido, criar com nome vazio, criar com preço negativo, remover existente, remover inexistente, editar com -1.
- **CategoriaService:** Criar categoria válida, criar com nome vazio, criar com IVA negativo, remover existente, remover inexistente, editar.
- **ClienteService:** Criar cliente válido, criar com NIF duplicado, remover existente, remover inexistente, editar.
- **CaixaService:** Criar caixa válido, criar com nome vazio, remover existente, remover inexistente, editar, editar com -1.
- **VendaService:** Iniciar venda sem cliente, iniciar com cliente, iniciar com cliente inexistente, adicionar item sem venda ativa, adicionar com stock insuficiente, cancelar venda, consultar preço existente, consultar preço inexistente.
- **PromocaoService:** Criar promoção de produto, criar de categoria, percentagem inválida, data inválida, data fim antes de início, produto inexistente, remover existente, remover inexistente, editar.

## Execução

```bash
cd Project/build
cmake .. && make supermercado_tester
./supermercado_tester
```

Resultado: 40/40 testes passam.
