/* Prototipo das funcoes
  tipo de dado armazenado na lista
  o ponteiro "lista"
*/

struct paciente
{
    int grauUrgencia;
    char phone[30];
    char nome[50];

};

// criando um ponteiro Lista
typedef struct elemento* Lista;

// equivalente a fopen() em arquivos, essa funcao eh que vai inicializar a minha lista
Lista* cria_lista();

//equivalente ao fclose() em arquivos
void libera_lista(Lista* li);

int lista_vazia(Lista* li);

int insere_lista_ordenada(Lista* li, struct paciente dados_Paciente);

int remove_lista_inicio(Lista* li);

int consulta_lista_value(Lista* li, struct paciente *dados_Paciente);

