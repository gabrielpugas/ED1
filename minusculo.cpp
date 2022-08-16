#include<stdio.h>
#include<ctype.h>

void maiusculo(char nomeArquivo[50])
{
	FILE*PtrArq = fopen(nomeArquivo,"r");
	int linha=0, letra=0, espaco=0;
	char c;
	if(PtrArq!=NULL)
	{
		FILE*PtrMaiusculo = fopen("Maiusculo.txt","w");
		c = fgetc(PtrArq);
		while (!feof(PtrArq))
		{
			if(c=='\n')
				linha++;
			if((c>65&&c<90)||(c>97&&c<122))
				letra++;
			if(c==32)
				espaco++;
			fputc(toupper(c),PtrMaiusculo);
			c = fgetc(PtrArq);
			
		}
		fclose(PtrMaiusculo);
	}
	else
		printf("Erro de abertura.");
	fclose(PtrArq);
	printf("linhas: %d\n",linha);
	printf("espacos: %d\n",espaco);
	printf("letras: %d\n",letra);
}

int main(void)
{
	maiusculo("minusculo.cpp");
	return 1;
}
