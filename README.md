# Sistema de Gerenciamento Multiguichê Dinâmico (Atendimento V2.0)

Este projeto consiste em uma aplicação avançada em linha de comando desenvolvida em C++ para a disciplina de Estrutura de Dados 1, no curso de Tecnologia em Análise e Desenvolvimento de Sistemas do IFSP - Campus Cubatão.

O sistema evolui o conceito básico de filas para um modelo dinâmico complexo, onde múltiplos pontos de atendimento (guichês) operam de forma independente, controlando suas próprias filas de histórico de chamadas através do gerenciamento manual de ponteiros e alocação dinâmica de memória.

## Tecnologias Utilizadas

* Linguagem: C++
* Paradigma: Programação Estruturada e Orientada a Objetos (POO)
* Estruturas de Dados: Lista Encadeada Simples Dinâmica e Múltiplas Filas Dinâmicas (com ponteiros)
* Ambiente: Console Application

## Lógica e Regras de Negócio Implementadas

O software simula um ecossistema corporativo completo de distribuição de chamados:
* Alocação Dinâmica Pura: Ao contrário da versão anterior, esta arquitetura dispensa o uso de vetores estáticos, operando 100% via ponteiros (`new` e `delete`), o que confere ao sistema escalabilidade infinita de memória em tempo de execução.
* Composição de Estruturas (Estrutura Composta): Implementação de uma Lista Encadeada de guichês, onde cada nó (`struct Guiche`) possui, de forma encapsulada, uma Fila Dinâmica única de senhas finalizadas (`struct Fila`).
* Rastreabilidade e Isolamento: Permite buscar guichês específicos por identificador único (ID), direcionar a senha "da vez" da fila global para o histórico do guichê solicitante e listar individualmente o relatório de produtividade de cada terminal.
* Validações de Integridade: Impede a duplicação de IDs de guichês, intercepta chamados em filas vazias e bloqueia o desligamento da aplicação caso existam clientes aguardando atendimento na fila principal.

## Estrutura do Código

* NoFila: Estrutura que representa o nó básico de dados de uma senha e o ponteiro para o próximo da fila.
* Fila: Estrutura de controle que monitora os ponteiros de `inicio`, `fim` e a quantidade de elementos de uma fila dinâmica.
* Guiche: Estrutura que define um terminal de atendimento, guardando seu ID, sua fila própria de senhas e o ponteiro para o próximo guichê da lista.
* main: Centraliza o laço operacional (`do-while`), processando a lógica do menu interativo e a ponte de dados entre a triagem global e as subestruturas de atendimento.

## Como Executar o Projeto

1. Clone o repositório:
   ```bash
   git clone https://github.com
   ```
2. Certifique-se de ter um compilador C++ instalado (como GCC/G++).
3. Compile o arquivo principal:
   ```bash
   g++ main.cpp -o atendimento_v2
   ```
4. Execute o binário gerado:
   ```bash
   ./atendimento_v2
   ```
