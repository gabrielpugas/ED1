#include<stdio.h>
#include<conio.h>
#include<windows.h> 


int validaArq(char par1[50]) {
	FILE*PtrArq;
	if(fopen(par1,"r"))
		return 1;
	else
		return 0; 
}


int main () {
    char op, par1[50];

    do{
        printf("Este eh o exercicio de revisao da disciplina Estrutura de Dados 1,\ne sera a ultima vez que vou cursar essa materia!\n");
        printf("\nMenu Inicial\n");
		printf("A - Validar a existencia do Arquivo de Dados 'Cidades.dat'\n");
        printf("B - Cadastrar cidades\n");
        printf("C - Consultar a Populacao a partir do uso de uma Busca Exaustiva que recebe o Nome da Cidade por parametro\n");
        printf("D - Ordenar o Arquivo pelo Nome da Cidade\n");
        printf("E - Exibir o conteudo do Arquivo\n");
        printf("F - Ordenar o Arquivo de forma decrescente pela Populacao\n");
		printf("\nESC - Sair\n\n");
        printf("Selecione uma das opcoes acima:");
        fflush(stdin);
		op=toupper(getch());
		system("cls");
		
		switch(op){
			case 'A': printf("Qual o nome do arquivo que quer validar se existe?\n");
					  gets(par1);
					  if(validaArq(par1))
					  	printf("O nome digitado eh um nome de arquivo valido!\n");
					  else
					  	printf("O nome digitado NAO eh um nome de arquivo valido!");
						getch(); system("cls"); break;
			case 'B': printf("teste"); getch(); system("cls"); break;
			case 'C': printf("teste"); getch(); system("cls"); break;
			case 'D': printf("teste"); getch(); system("cls"); break;
			case 'E': printf("teste"); getch(); system("cls"); break;
			case 'F': printf("teste"); getch(); system("cls"); break;
		}
		
        
    }
    while(op!=27);
}
