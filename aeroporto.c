//---------------{Bibliotecas Locais}---------------//
#include "biblioteca.h"
//---------------{Funções da Struct Avião}---------------//
Aviao cadastrar_aviao()
{
	Aviao av;
	printf("Insira o nome do aviao: \n");
	fgets(av.nome, 49, stdin);
	printf("Insira o numero do aviao: \n");
	scanf("%d", &av.num);
	getchar();
	
	return av;
}
//---------------{Funções da Fila Estática}---------------//
/*--------------->Criar Fila<---------------*/
void criar_fila(Fila *fila)
{
	fila->qtd_aviao = 0;
}
/*--------------->Manipular Fila<---------------*/
int add_na_fila(Fila *fila, Aviao aviao)
{
	if(fila_cheia(*fila) == true)
		return EXIT_FAILURE;
	fila->aviao[fila->qtd_aviao] = aviao;
	fila->qtd_aviao++;
	
	return EXIT_SUCCESS;
}
/*--------------->Remover da Fila<---------------*/
int remover_da_fila(Fila *fila, Pilha *galpao)
{
	if(fila_vazia(*fila) == true)
		return EXIT_FAILURE;
		
	int cont = 0;
	printf("Aviao decolado: %s\n\n", fila->aviao[cont].nome);
	while(cont < (fila->qtd_aviao-1)){
		fila->aviao[cont] = fila->aviao[(cont+1)];
		cont++;
	}
	fila->qtd_aviao--;
	
	return EXIT_SUCCESS;
}
/*--------------->Imprimir Fila<---------------*/
int imprimir_fila(Fila fila)
{
	if(fila_vazia(fila) == true)
		return EXIT_FAILURE;
	
	int cont = 0;

	printf("\n\n>Quantidade de avioes na fila: %d<\n\n", tamanho_da_fila(fila));	
	while(cont < fila.qtd_aviao)
	{
		printf("\n-----------------------------------\n");
		printf("Posicao do aviao: %d\n", cont);
		printf("Nome do aviao: %s", fila.aviao[cont].nome);
		printf("Numero do  aviao: %d", fila.aviao[cont].num);
		printf("\n-----------------------------------\n");
		cont++;
	}

	return EXIT_SUCCESS;
}
/*--------------->Ver primeiro aviao Fila<---------------*/
int ver_prim_aviao_da_fila(Fila fila)
{
	if(fila_vazia(fila) == true)
		return EXIT_FAILURE;
	
	printf("\n-------------------\n");
	printf("Primeiro aviao da fila: \n");
	printf("Nome: %s\n", fila.aviao[0].nome);
	printf("Numero: %d\n", fila.aviao[0].num);
	
	return EXIT_SUCCESS;
}
/*--------------->Tamanho da Fila<---------------*/
/*---------------[[Verifica se cheia]]---------------*/
bool fila_cheia(Fila fila)
{
	if(fila.qtd_aviao == (aviao_max))
	{
		printf("\n-----------------------------------\n");
		printf("Fila de avioes Cheia! Adicionando ao galpao....");
		printf("\n-----------------------------------\n");
		return true;
	}
	
	return false;
}
/*---------------[[Verifica se vazia]]---------------*/
bool fila_vazia(Fila fila)
{
	if(fila.qtd_aviao == 0)
	{
		printf("\n-----------------------------------\n");
		printf("Fila de avioes Vazia!\n\n");
		printf("\n-----------------------------------\n");
		return true;
	}
	
	return false;
}
/*---------------[[Retorna o tamanho da fila]]---------------*/
int tamanho_da_fila(Fila fila)
{
	return fila.qtd_aviao;
}
//---------------{Prototipos da Struct Pilha}---------------//
/*--------------->Criar Pilha<---------------*/
void criar_galpao(Pilha *galpao)
{
	galpao->topo = NULL;
	galpao->tam  = 0;
}
/*--------------->Manipular Pilha<---------------*/
int push(Pilha *galpao, Aviao aviao)
{
	No *novo = malloc(sizeof(No));
	if(novo)
	{
		novo->aviao = aviao;
		novo->prox = galpao->topo;
		galpao->topo = novo;
		galpao->tam++;
	} else
		{
			printf("Erro ao alocar memoria!\n\n");
			return EXIT_FAILURE;
		}
	return EXIT_SUCCESS;
}
Aviao pop(Pilha *galpao)
{
	Aviao remover;
	if(galpao_vazio(*galpao) == true)
		return remover;
	remover = galpao->topo->aviao;
	galpao->topo = galpao->topo->prox;
	galpao->tam--;
	
	return remover;
}
/*--------------->Imprimir Pilha<---------------*/
int imprimir_galpao(Pilha galpao)
{
	if(galpao_vazio(galpao) == true)
		return EXIT_FAILURE;
	
	int cont = 0;
	printf("\n\n>Quantidade de avioes no galpão: %d<\n\n", tamanho_do_galpao(galpao));	
	while(galpao.topo)
	{
		printf("\n-----------------------------------\n");
		printf("Posicao do aviao: %d\n", cont);
		printf("Nome do aviao: %s", galpao.topo->aviao.nome);
		printf("Numero do  aviao: %d", galpao.topo->aviao.num);
		printf("\n-----------------------------------\n");
		galpao.topo = galpao.topo->prox;
	}

  return EXIT_SUCCESS;
}
/*--------------->Ver ultimo aviao Pilha<---------------*/
int ver_ultimo_no_galpao(Pilha galpao)
{
	if(galpao_vazio(galpao) == true)
		return EXIT_FAILURE;
	while(galpao.topo->prox)
		galpao.topo = galpao.topo->prox;
	
	printf("-------->Ultimo aviao:<-------\n\n");
	printf("Nome %s\n", galpao.topo->aviao.nome);
	printf("Numero: %d\n", galpao.topo->aviao.num);
	printf("----------------------------\n");

  return EXIT_SUCCESS;
}
/*--------------->Tamanho da Pilha<---------------*/
/*---------------[[Verifica se vazia]]---------------*/
bool galpao_vazio(Pilha galpao)
{
	if(galpao.topo == NULL)
	{
		printf("Galpao vazio! Sem mais avioes para serem adicionados na Fila\n\n");
		return true;
	}
	return false;
}
/*---------------[[Retorna o tamanho da Pilha]]---------------*/
int tamanho_do_galpao(Pilha galpao)
{
	return galpao.tam;
}