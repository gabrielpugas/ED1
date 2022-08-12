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


int main () {
	setlocale(LC_ALL, "Portuguese");
    char op, par1[50];

    do{
        printf("Este é o exercicio de revisao da disciplina Estrutura de Dados 1,\ne sera a ultima vez que vou cursar essa materia!\n");
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
			case 'A':   printf("Qual o nome do arquivo que quer validar se existe?\n");
					    gets(par1);
					    if(validaArq(par1))
					  		printf("O nome digitado eh um nome de arquivo valido!\n");
					    else {
							printf("O nome digitado NAO eh um nome de arquivo valido! Deseja criar o arquivo? (S/N)");
					  		fflush(stdin); op = toupper(getch());
					  		if(op=='S'){
					  			FILE*Ptr = fopen(par1,"w"); 
								printf("\nArquivo criado com sucesso...");
								fclose(Ptr);
							  }
							else printf("\nPressione qualquer tecla...")  ;
					    }
						getch(); system("cls"); break;
						
			case 'B':   printf("Qual cidade gostaria de cadastrar?\n");
						par1 = gets();
						if(!ValidaCidade(par1))
							printf("Essa cidade já está cadastrada. Gostaria de adicionar outra cidade? (S/N)");
						
						getch(); system("cls"); break;
			case 'C':   printf("teste");
						getch(); system("cls"); break;
			case 'D':   printf("teste");
						getch(); system("cls"); break;
			case 'E':   printf("teste");
						getch(); system("cls"); break;
			case 'F':   printf("teste");
						getch(); system("cls"); break;
		}
		
        
    }
    while(op!=27);
}
