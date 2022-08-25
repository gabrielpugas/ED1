#include<stdio.h>
#include<conio.h>
#include<windows.h> 
#include<locale.h>

struct TpCidade {
	char nome[50];
	int populacao;
};

struct TpVendedor {
	int cod;
	char nome[20], mes[9];
	float vendas;
};

int validaArq(char par1[50]) {

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

void cadastraCidade(void) {
	TpCidade cidade;
	char op;
	
	do
	{
		FILE*Ptr = fopen ("cidades.dat","ab+");
		system("cls");
		printf("Qual cidade gostaria de cadastrar?\n");
		strupr(gets(cidade.nome));
//		strupr(cidade.nome);
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
			scanf("%d",&cidade.populacao);
			fwrite(&cidade,sizeof(TpCidade),1,Ptr);
			printf("\nCidade cadastrada com sucesso!\n");
			printf("\nDeseja adicionar outra cidade?(S/N)\n");
			fflush(stdin);
			op=toupper(getch());
		}
		fclose(Ptr);
	}
	while(op=='S');
	printf("\nPressione qualquer tecla para voltar ao menu anterior...");
	getch(); 
}

int buscaExaustiva(char nomeCidade[50]) {
	FILE*Ptr = fopen("cidades.dat","rb");
	TpCidade cidade;
	fread(&cidade,sizeof(TpCidade),1,Ptr);
	while(!feof(Ptr)&&!strcmp(cidade.nome,nomeCidade)==0)
		fread(&cidade,sizeof(TpCidade),1,Ptr);
	if(!feof(Ptr))
		return cidade.populacao;
	else
		return 0;
}

void ordenaPorNomeBouble() {
	TpCidade c1, c2;
	int qtde;
	
	FILE*ptr=fopen("cidades.dat","rb+");
	if(ptr!=NULL){
		fseek(ptr,0,2); qtde=ftell(ptr)/sizeof(TpCidade);
		
		for(int i=0;i<qtde-1;i++) {
			for(int j=i+1;j<qtde;j++) {
				fseek(ptr,sizeof(TpCidade)*i,0);
				fread(&c1,sizeof(TpCidade),1,ptr);
				fseek(ptr,sizeof(TpCidade)*j,0);
				fread(&c2,sizeof(TpCidade),1,ptr);
				if(strcmp(c1.nome,c2.nome)>0) {
					fseek(ptr,sizeof(TpCidade)*i,0);
					fwrite(&c2,sizeof(TpCidade),1,ptr);
					fseek(ptr,sizeof(TpCidade)*j,0);
					fwrite(&c1,sizeof(TpCidade),1,ptr);	
				}
			}
		}		
	}
	else
		printf("Arquivo vazio! Nada para ordenar.\n");
		
	fclose(ptr);
	printf("Arquivo ordenado pelo nome das cidades.\n");
}

void ordenaPorPopulacaoDecrescente() {
	TpCidade c1, c2;
	int qtde;
	
	FILE*ptr=fopen("cidades.dat","rb+");
	if(ptr!=NULL){
		fseek(ptr,0,2); qtde=ftell(ptr)/sizeof(TpCidade);
		
		for(int i=0;i<qtde-1;i++) {
			for(int j=i+1;j<qtde;j++) {
				fseek(ptr,sizeof(TpCidade)*i,0);
				fread(&c1,sizeof(TpCidade),1,ptr);
				fseek(ptr,sizeof(TpCidade)*j,0);
				fread(&c2,sizeof(TpCidade),1,ptr);
				if(c1.populacao<c2.populacao) {
					fseek(ptr,sizeof(TpCidade)*i,0);
					fwrite(&c2,sizeof(TpCidade),1,ptr);
					fseek(ptr,sizeof(TpCidade)*j,0);
					fwrite(&c1,sizeof(TpCidade),1,ptr);	
				}
			}
		}		
	}
	else
		printf("Arquivo vazio! Nada para ordenar.\n");
		
	fclose(ptr);
	printf("Arquivo ordenado pelo número de habitantes, de forma decrescente.\n");
}

void exibirArquivoCidades() {
	FILE*ptr=fopen("cidades.dat","rb");
	TpCidade c;
	
	if(ptr!=NULL) {
		printf("Cidade\tPopulação\n");
		fread(&c,sizeof(c),1,ptr);
		while(!feof(ptr)) {
			printf("%s\t%d\n",c.nome,c.populacao);
			fread(&c,sizeof(c),1,ptr);
		}
	}
	else
		printf("Erro de abertura do arquivo.\n");
	fclose(ptr);
}

void consultaPopulacao(void) {
	char par1[20], par2[20], op;
	int resultado;
	do{
		system("cls");
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
		getch();
}

void criarArquivoVendas() {
	FILE*ptr=fopen("vendas.dat","ab");
	fclose(ptr);
	printf("Arquivo criado ou já existe!\n\nPressione qualquer tecla para voltar ao menu principal...");
}

void incluirVendedores() {
	TpVendedor v;
	char op='S';
	
	FILE*ptr=fopen("vendas.dat","ab+");
	while(op=='S'){
		system("cls");
		printf("Insira as informações do vendedor\n");
		printf("\nNome: "); fflush(stdin); strupr(gets(v.nome));
		printf("\nCod: "); scanf("%d",&v.cod);
		printf("\nMês: "); fflush(stdin); strupr(gets(v.mes));
		printf("\nValor das vendas: R$"); scanf("%f",&v.vendas);
		fwrite(&v,sizeof(TpVendedor),1,ptr);
		printf("\n\nDeseja adicionar outro vendedor? (S/N):");
		op=toupper(getch());
	}	
	fclose(ptr)	;
}

void exibirArquivoVendas() {
	FILE*ptr=fopen("vendas.dat","rb");
	TpVendedor v;
	
	if(ptr!=NULL) {
		printf("Cod\t   Nome            Mês             Vendas\n");
		fread(&v,sizeof(v),1,ptr);
		while(!feof(ptr)) {
			printf("%d\t   %s\t   %s\t   R$%.2f\n",v.cod,v.nome,v.mes,v.vendas);
			fread(&v,sizeof(v),1,ptr);
		}
	}
	else
		printf("Erro de abertura do arquivo.\n");
	fclose(ptr);
}

char menu (void) {
	system("cls");
	printf("Este é o exercicio de revisão da disciplina Estrutura de Dados 1,\ne será a última vez que vou cursar essa matéria!\n");
    printf("\nMenu Inicial\n");
    printf("\nExercício 1_________________________________________________\n");
	printf("A - Validar a existência do Arquivo de Dados 'Cidades.dat'\n");
    printf("B - Cadastrar cidades\n");
    printf("C - Consultar a População a partir do uso de uma Busca Exaustiva que recebe o Nome da Cidade por parâmetro\n");
    printf("D - Ordenar o Arquivo pelo Nome da Cidade\n");
    printf("E - Exibir o conteúdo do arquivo CIDADES.DAT\n");
    printf("F - Ordenar o Arquivo de forma decrescente pela População\n");
    printf("\nExercício 2_________________________________________________\n");
    printf("G - Criar arquivo VENDAS.DAT\n");
    printf("H - Cadastrar vendedores\n");
    printf("I - Exibir o conteúdo do arquivo VENDAS.DAT\n");
	printf("\nESC - Sair\n\n");
    printf("Selecione uma das opções acima:");
    fflush(stdin);
	return toupper(getch());
}

int main () {
	setlocale(LC_ALL, "Portuguese");
    char op, par1[50];
    int resultado, i;
	
	op=menu();
    while(op!=27){		
		switch(op) {
			case 'A':   {
						system("cls");			
						printf("Qual o nome do arquivo que deseja validar?\n");
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
						cadastraCidade();
						system("cls"); break;
			}
			case 'C':   {
						system("cls");
						consultaPopulacao();
						break;
			}
			case 'D':   {
						system("cls");
						ordenaPorNomeBouble();
						getch();
						break;
			}
			case 'E':   {
						system("cls");
						exibirArquivoCidades(); getch();
						break;
			}
			case 'F':   {
						system("cls");
						ordenaPorPopulacaoDecrescente(); getch();
						break;
			}
			case 'G':	{
				system("cls");
				criarArquivoVendas(); getch();
				break;
			}
			case 'H':{
				system("cls");
				incluirVendedores();
				break;
			}
			case 'I':{
				system("cls");
				exibirArquivoVendas(); getch();
				break;
			}
			
		}
		
    op=menu();
    }
}
