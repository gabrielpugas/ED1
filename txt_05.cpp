#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<locale.h>

struct TpAposta {
	int num, dezenas[7];
	char data[11];
};

void cadApostas (void) {
	TpAposta r;
	FILE*PtrAp = fopen("Apostas.txt","a");

	system("cls");
	printf("\nCadastro de Apostas\n");
	printf("Numero da aposta: "); scanf("%d",&r.num);
	while (r.num>0){
		printf("Data [dd/mm/aaaa]: "); fflush(stdin); gets(r.data);
		for(int i=0;i<7;i++){
			printf("\nDezena[%d]:",i+1);
			scanf("%d",&r.dezenas[i]);
		}
		fprintf(PtrAp,"%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",r.num,r.data,r.dezenas[0],r.dezenas[1],r.dezenas[2],r.dezenas[3],r.dezenas[4],r.dezenas[5],r.dezenas[6]);
		printf("\nNumero da aposta: "); scanf("%d",&r.num);
	}
	printf("%d",ftell(PtrAp));
	fclose(PtrAp);
}

void resultados (char arquivo[12], int resultados[5]) {
	FILE*ptr=fopen(arquivo,"r");
	TpAposta r;
	
	fclose(ptr);
}

char menu (void) {
	system("cls");
	printf("Este é o exercicio de revisão da disciplina Estrutura de Dados 1,\ne será a última vez que vou cursar essa matéria!\n");
    printf("\nMenu Inicial\n");
	printf("A - Inserir apostas\n");
    printf("B - Resultados\n");
//    printf("C - \n");
//    printf("D - Ordenar o Arquivo pelo Nome da Cidade\n");
//    printf("E - Exibir o conteúdo do Arquivo\n");
//    printf("F - Ordenar o Arquivo de forma decrescente pela População\n");
	printf("\nESC - Sair\n\n");
    printf("Selecione uma das opções acima:");
    fflush(stdin);
	return toupper(getch());
}

int main () {
	char op;
	setlocale(LC_ALL, "Portuguese");

	op=menu();
	while(op!=27){
		switch(op){
			case 'A':{system("cls");
				cadApostas();
				break;
			}
			case 'B':{system("cls");
				int sorteados[5];
				for(int i=0;i<5;i++) {
					printf("Digite o %d número sorteado: ",i+1); scanf("%d",&sorteados[i]);
				}
				resultados("Apostas.txt",sorteados);
				getch();
				break;
			}
		}
		op=menu();
		
	}
	
	return 1;
}
