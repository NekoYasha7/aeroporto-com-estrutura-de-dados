//---------------{Constantes}---------------//
#define aviao_max 5
//---------------{Struct Avião}---------------//
typedef struct
{
	char nome[50];
	int num;
} Aviao;
//---------------{Struct Fila}---------------//
typedef struct
{
	Aviao aviao[aviao_max];
	int qtd_aviao;
} Fila;
//---------------{Struct Nó da Pilha}---------------//
typedef struct no
{
	Aviao aviao;
	struct no *prox;
} No;
//---------------{Struct Pilha}---------------//
typedef struct
{
	No *topo;
	int tam;	
} Pilha;
//---------------{Prototipos da Struct Avião}------------//
Aviao cadastrar_aviao();

//---------------{Prototipos da Fila Estática}---------------//
/*--------------->Criar Fila<---------------*/
void criar_fila(Fila *fila);
/*--------------->Manipular Fila<---------------*/
int add_na_fila(Fila *fila, Aviao aviao);
int remover_da_fila(Fila *fila, Pilha *galpao);
/*--------------->Imprimir Fila<---------------*/
int imprimir_fila(Fila fila);
/*--------------->Ver primeiro aviao Fila<---------------*/
int ver_prim_aviao_da_fila(Fila fila);
/*--------------->Tamanho da Fila<---------------*/
/*---------------[[Verifica se cheia]]---------------*/
bool fila_cheia(Fila fila);
/*---------------[[Verifica se vazia]]---------------*/
bool fila_vazia(Fila fila);
/*---------------[[Retorna o tamanho da fila]]---------------*/
int tamanho_da_fila(Fila fila);
//---------------{Prototipos da Struct Pilha}---------------//
/*--------------->Criar Pilha<---------------*/
void criar_galpao(Pilha *galpao);
/*--------------->Manipular Pilha<---------------*/
int push(Pilha *galpao, Aviao aviao);
Aviao pop(Pilha *galpao);
/*--------------->Imprimir Pilha<---------------*/
int imprimir_galpao(Pilha galpao);
/*--------------->Ver ultimo aviao Pilha<---------------*/
int ver_ultimo_no_galpao(Pilha galpao);
/*--------------->Tamanho da Pilha<---------------*/
/*---------------[[Verifica se cheia]]---------------*/
bool galpao_cheio(Pilha galpao);
/*---------------[[Verifica se vazia]]---------------*/
bool galpao_vazio(Pilha galpao);
/*---------------[[Retorna o tamanho da Pilha]]------------*/
int tamanho_do_galpao(Pilha galpao);