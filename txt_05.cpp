#include<stdio.h>
#include<windows.h>

struct TpAposta {
	int num, dezenas[7];
	char data[11];
};

void cadApostas (void) {
	TpAposta r;
	FILE*PtrAp = fopen("Apostas.txt","a");
	//if(fscanf(PtrAp,"%d",&r.num)==feof(PtrAp))
	//	fprintf(PtrAp,"%Aposta\tData\t1\t2\t3\t4\t5\t6\t7\n");
	system("cls");
	printf("%d",ftell(PtrAp));
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

int main () {
	cadApostas();
	return 1;
}
