#define MAXFILA

struct TpFila {
	int fim;
	char fila[MAXFILA];
};

void inicializar (TpFila f) {
	f.fim = -1;
}

char filaVazia (int fim) {
	return fim == -1;
}

char filaCheia (int fim) {
	return fim == MAXFILA-1;
}

void inserir (TpFila &f, char elemento) {
	f.fila[++f.fim] = elemento;
}

char elementoInicio (TpFila f) {
	return f.fila[0];
}

char elementoFim (TpFila f) {
	return f.fila[f.fim];
}

void exibirFila (TpFila F) {
	while(!FilaVazia(f.fim))
		printf("%c\t",retirar(f));
}

char Retirar(TpFila &f) {
	char aux;
	aux = f.fila[0];
	for (int i=0; i < f.fim; i++)
		f.fila[i] = f.fila[i+1];
	f.fim--;
	return aux;
}
