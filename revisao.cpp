#include<stdio.h>
#include<conio.h>
#include<windows.h> 
#include<locale.h>

struct TpCidade {
	char nome[50];
	int populacao;
};

int validaArq(char par1[50]) {
	FILE*PtrArq;
	if(fopen(par1,"r"))
		return 1;
	else
		return 0; 
}

int validaCidade(char nomeCidade[50]) {
	FILE*Ptr = fopen("cidades.dat","rb");
	TpCidade cidade;
	int valida = 1;
	while(!feof(Ptr))
	{
		fread(&cidade,sizeof(TpCidade),1,Ptr);
		if(strcmp(nomeCidade,cidade.nome)==0)
			valida = 0;
	}
	fclose(Ptr);
	return valida;
}

int buscaExaustiva(char nomeCidade[50]) {
	FILE*Ptr = fopen("cidades.dat","rb");
	TpCidade cidade;
	fread(&cidade,sizeof(TpCidade),1,Ptr);
	while(!feof(Ptr)&&!strcmp(cidade.nome,nomeCidade))
		fread(&cidade,sizeof(TpCidade),1,Ptr);
	if(!feof(Ptr))
		return cidade.populacao;
	else
		return 0;
}


int main () {
	setlocale(LC_ALL, "Portuguese");
    char op, par1[50];
    int resultado, i;

    do{
        printf("Este é o exercicio de revisão da disciplina Estrutura de Dados 1,\ne será a última vez que vou cursar essa matéria!\n");
        printf("\nMenu Inicial\n");
		printf("A - Validar a existência do Arquivo de Dados 'Cidades.dat'\n");
        printf("B - Cadastrar cidades\n");
        printf("C - Consultar a População a partir do uso de uma Busca Exaustiva que recebe o Nome da Cidade por parâmetro\n");
        printf("D - Ordenar o Arquivo pelo Nome da Cidade\n");
        printf("E - Exibir o conteúdo do Arquivo\n");
        printf("F - Ordenar o Arquivo de forma decrescente pela População\n");
		printf("\nESC - Sair\n\n");
        printf("Selecione uma das opções acima:");
        fflush(stdin);
		op=toupper(getch());
		system("cls");
		
		switch(op){
			case 'A':   {			
						printf("Qual o nome do arquivo que quer validar se existe?\n");
					    gets(par1);
					    if(validaArq(par1))
					  		printf("O nome digitado é um nome de arquivo válido!\n");
					    else {
							printf("O nome digitado NÃO é um nome de arquivo válido! Deseja criar o arquivo? (S/N)");
					  		fflush(stdin); op = toupper(getch());
					  		if(op=='S'){
					  			FILE*Ptr = fopen(par1,"wb");
								printf("\nArquivo criado com sucesso...");
								fclose(Ptr);
							  }
							else printf("\nPressione qualquer tecla para voltar ao menu anterior...");
					    }
						getch(); system("cls"); break;
			}
			case 'B':   {
						op = 'S';
						TpCidade cidade; int *pop;
						while(op=='S')
						{
							FILE*Ptr = fopen ("cidades.dat","ab+");
							system("cls");
							printf("Qual cidade gostaria de cadastrar?\n");
							gets(cidade.nome);
							strupr(cidade.nome);
							while(!validaCidade(cidade.nome)&&op!='N') {
								printf("Essa cidade já está cadastrada. Gostaria de adicionar outra cidade? (S/N)\n");
								fflush(stdin); op = toupper(getch());
								if(op=='S'){
									system("cls");
									printf("Qual cidade gostaria de cadastrar?\n");
									gets(cidade.nome);
									strupr(cidade.nome);
								  }
							}
							if(validaCidade(cidade.nome)!=0){
								printf("\nQuantos habitantes tem em %s?\n",cidade.nome);
								pop = &cidade.populacao;
								scanf("%d",pop);
								fwrite(&cidade,sizeof(TpCidade),1,Ptr);
								printf("\nCidade cadastrada com sucesso!\n");
								printf("\nDeseja adicionar outra cidade?(S/N)\n");
								fflush(stdin);
								op=toupper(getch());
							}
							fclose(Ptr);
						}
						
						printf("\nPressione qualquer tecla para voltar ao menu anterior...");
						getch(); system("cls"); break;
			}
			case 'C':   {
						do{
							printf("Qual o nome da cidade que deseja saber o número de habitantes?\n");
							gets(par1); strupr(par1);
							resultado = buscaExaustiva(par1);
							if(resultado>0)
								printf("Existem %d habitantes em %s.\n",resultado, par1);
							else
								printf("Cidade não cadastrada!\n");
							printf("\nDeseja pesquisar a população de outra cidade?(S/N)\n");
							fflush(stdin);
							op=toupper(getch());
						}while(op=='S');
						printf("\nPressione qualquer tecla para voltar ao menu ...");
						getch(); system("cls");
						break;
			}
			case 'D':   {
						printf("teste"); getch(); system("cls");
						break;
			}
			case 'E':   {
						printf("teste"); getch(); system("cls");
						break;
			}
			case 'F':   {
						printf("teste"); getch(); system("cls");
						break;
			}
		}
		
        
    }
    while(op!=27);
}
