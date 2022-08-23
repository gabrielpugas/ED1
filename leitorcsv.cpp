#include<stdio.h>
#include<conio.h>
 
struct filme{
    char nome[60], classif[6];
    int ano, duracao;
    float gasto,renda,espec;
};
 
 
int main()
{
    filme reg;
    FILE *arq = fopen("Arquivo de Filmes.txt","r");
     
    fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
    while(!feof(arq))
    {
          printf("%s %d %s %.2f %.2f %d %.2f \n",reg.nome, reg.ano, reg.classif, reg.gasto, reg.renda, reg.duracao, reg.espec);
     
          fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
     
    }
    printf("%s %d %s %.2f %.2f %d %.2f \n",reg.nome, reg.ano, reg.classif, reg.gasto, reg.renda, reg.duracao, reg.espec);
    fclose(arq);
    getch();
}
