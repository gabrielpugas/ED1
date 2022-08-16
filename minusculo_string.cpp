#include<stdio.h>
#include<ctype.h>
#include<string.h>

void maiusculo(char nomeArquivo[50])
{
	FILE*PtrArq = fopen(nomeArquivo,"r");
	
	char c[60];
	if(PtrArq!=NULL)
	{
		FILE*PtrMaiusculo = fopen("Maiusculo2.txt","w");
		fgets(c,80,PtrArq);
		while (!feof(PtrArq))
		{
			fputs(strupr(c),PtrMaiusculo);
			fgets(c,80,PtrArq);
		}
		fclose(PtrMaiusculo);
	}
	else
		printf("Erro de abertura.");
	fclose(PtrArq);
}

int main(void)
{
	maiusculo("minusculo.cpp");
	return 1;
}
