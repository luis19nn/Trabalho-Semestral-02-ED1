# Trabalho Semestral 02
Neste repositório, estão os dois exercícios feitos para o segundo trabalho semestral de Estrutura de Dados 1 do curso de Análise e Desenvolvimento de Sistemas da UFPR.

## Exercício 01
Desenvolver um programa em C que manipule expressões numéricas como segue o menu abaixo:
```
1. Transforma uma expressão Infixa em Pósfixa
2. Transforma uma expressão Infixa em Préfixa
3. Lê uma expressão e informa se a expressão é válida
4. Lê uma expressão e informa o resultado da expressão
5. Sair
```
<br>Requisitos:
- Deve ser aplicada a estrutura de dado pilha com alocação encadeada para calcular a expressão. Obs. pesquisar o algoritmo de cálculo de expressões com uso de pilha na internet ou livros de Estruturas de Dados.
- O usuário poderá utilizar as seguintes operações em suas expressões: `+, -, *, / e ^`. Além disso, as expressões podem conter parênteses para indicar prioridades de operações. Exemplo de expressão `-(5 + 8) * 7 – 2 ^ 3 / 5`.
- O programa deve ser implementado de forma modular, ou seja, implementação de funções com passagens de parâmetros.

## Exercício 02
Um hospital de cardiologia precisa de um sistema para efetuar o cadastro de pacientes que necessitam de doação de coração. Para cada paciente que é incluído no sistema deve ser informado o nome, telefone e o grau de urgência para transplante. O grau de urgência é definido na seguinte escala:<br>
`(5) Muito urgente; (4) Urgente; (3) Médio; (2) Pouco urgente; (1) Sem urgência.`
<br>
<br>Sempre que o hospital recebe um novo coração o sistema é consultado para obter o próximo paciente que deverá ser operado. O sistema informa o nome e o telefone do paciente. Também a qualquer momento é possível visualizar o tamanho da fila de espera. Observação: os dados não precisam ser persistidos em arquivos, podem ficar armazenados somente na memória. O sistema deve ter o seguinte menu:<br>
```
1. Cadastrar paciente (Nome, telefone e grau de urgência)
2. Buscar paciente (informar a posição do paciente na fila e o seu grau de urgência)
3. Próximo paciente a ser operado (retorna os dados do paciente e exclui da lista*)
4. Verificar tamanho da fila
5. Sair
```
<br>Ao excluir da lista o paciente que receberá a próxima doação de coração, seus dados devem ser gravados em um arquivo txt. Este arquivo armazenará os dados de todos os pacientes já transplantados. 
<br>Para tanto, uma Fila de Prioridade deve ser implementada. Existem diversas maneiras de se implementar uma fila de prioridade. Em qualquer implementação, o objetivo é acessar eficientemente o item de maior prioridade que se encontra na lista. As abordagens mais comuns são:
- Lista encadeada sem ordenação. Nesse caso, a inserção é feita no início da lista com custo temporal θ(1) e a remoção pode ocorrer em qualquer nó da lista com custo temporal θ(n). Ou seja, remoção requer uma busca sequencial na lista para encontrar o item com a maior prioridade.
- Lista encadeada ordenada. Supondo que uma lista encadeada seja mantida ordenada em ordem decrescente de prioridade, inserir um item requer que a posição de inserção seja encontrada para manter a lista ordenada a cada inserção e, portanto, o custo temporal dessa operação é θ(n). A remoção é sempre feita no início da lista com custo temporal θ(1).
- Lista indexada sem ordenação. Nesse caso, a inserção é feita ao final da lista com custo temporal θ(1) e a remoção pode ocorrer em qualquer posição da lista com custo temporal θ(n).
- Lista indexada ordenada. Remoção é uma operação com custo temporal θ(1) se a lista estiver em ordem crescente de prioridade, de modo que o elemento removido é sempre o último elemento da lista. Inserção requer que se encontre o local de inserção do item com custo θ(log n), se for usada busca binária. Mas, por outro lado, inserção também requer rearranjo dos elementos da lista, que é uma operação com custo temporal θ(n). Logo a combinação das duas operações tem custo θ(n).
- Árvore binária de busca balanceada. Nessa abordagem, inserção e remoção têm o mesmo custo temporal θ(log n). Por outro lado, essa é a opção com mais alto custo de implementação.
- Heap binário (ou apenas heap). Essa abordagem oferece várias vantagens, tais como simplicidade, rapidez e uso de pouco espaço de armazenamento. Além do mais, essa abordagem é muito fácil de implementar.
