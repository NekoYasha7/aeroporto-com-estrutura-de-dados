//---------------{Bibliotecas Locais}---------------//
#include "biblioteca.h"
//---------------{Prótotipos do menu}---------------//
bool opcoes_do_menu(Fila *fila, Pilha *galpao);
void executa_opcao(Fila *fila, Pilha *galpao, int op);
bool verifica_op(int op);
//---------------{Função principal}---------------//
int main(void)
{
	Fila fila;
	criar_fila(&fila);
	Pilha galpao;
	criar_galpao(&galpao);
	
  while(opcoes_do_menu(&fila, &galpao) == true);
	
	printf("Programa encerrado!\n\n");
	system("pause");
	return EXIT_SUCCESS;
}
//---------------{Funções do menu}---------------//
bool opcoes_do_menu(Fila *fila, Pilha *galpao)
{
  int op;
	printf(
		"\t0 - Encerrar o programa\n"
		"\t1 - Ver quantidade de avioes na fila\n"
		"\t2 - Autorizar decolagem de aviao\n"
		"\t3 - Ver informacoes de avioes na fila de espera\n"
		"\t4 - Adicionar Aviao\n"
		"\t5 - Ver avioes no galpao\n"
		"\t6 - Ver ultimo aviao do galpao\n"
		"\t7 - Remover aviao do galpao\n"
		"\t8 - Ver primeiro aviao da Fila\n"
	);
	scanf("%d", &op);
	getchar(); 

  executa_opcao(fila, galpao, op);

  return verifica_op(op);
}
void executa_opcao(Fila *fila, Pilha *galpao, int op)
{
	Aviao aviao;
	switch(op)
	{
		case 1:
			printf("\n----------------------\n");
			printf("\nNumero de avioes na fila: %d\n", tamanho_da_fila(*fila));
			printf("\n----------------------\n");
		break;
		case 2:
			remover_da_fila(fila, galpao);
			add_na_fila(fila, pop(galpao));
		break;
		case 3:
			imprimir_fila(*fila);
		break;
		case 4:
			printf("--------->Preencher dados do aviao<------\n\n");
			aviao = cadastrar_aviao();
		  if(add_na_fila(fila, aviao) == 1)
				push(galpao, aviao);
		break;
		case 5:
			imprimir_galpao(*galpao);
		break;
		case 6:
			ver_ultimo_no_galpao(*galpao);
		break;
		case 7:
			pop(galpao);
		break;
		case 8:
			ver_prim_aviao_da_fila(*fila);
		break;
		default:
			if(op != 0)
				printf("Opcao invalida!\n\n");
	}
}
bool verifica_op(int op)
{
  if(op == 0) return false;
  return true;
}