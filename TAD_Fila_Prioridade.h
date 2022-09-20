#define MAXFILA 10

struct TpElemento {
	char elemento;
	int prioridade
};

struct TpFilaP {
	int inicio, fim;
	TpElemento fila[MAXFILA];
};

void inicializar(TpFilaP &f);
void inserir(TpFilaP &f, TpElemento e);
TpElemento retirar(TpFilaP &f);
int vazia(TpFilaP f);
int cheia(TpFilaP f);
TpElemento retornaInicio(TpFilaP f);
TpElemento retornaFim(TpFilaP f);
void exibirFila(TpFilaP f);

void inicializar(TpFilaP &f) {
	f.inicio = 0;
	f.fim = -1;
}

void inserir(TpFilaP &f, TpElemento e) {
	TpElemento aux;
	f.fila[++f.fim] = e;
	for(i=f.fim; i>0 && f.fila[i-1].prioridade > e.prioridade; i--) {
		aux = f.fila[i-1];
		f.fila[i-1] = f.fila[i];
		f.fila[i] = aux;
	}	
}

TpElemento retirar(TpFilaP &f) {
	TpElemento aux = f.fila[0];
	for(int i=0; i<f.fim; i++)
		f.fila[i] = f.fila[i+1];
	f.fim--;
	return aux;
}

int vazia(int f.fim) {
	return f.fim==-1;
}

int cheia(TpFilaP f) {
	return f.fim==MAXFILA-1;
}

TpElemento retornaInicio(TpFilaP f) {
	return f.fila[f.inicio];
}

TpElemento retornaFim(TpFilaP f) {
	return f.fila[f.fim];
}

void exibirFila(TpFilaP f) {
	TpElemento aux;
	while(!vazia(f)) {
		aux = retirar(f);
		printf("\nElemento: %c\tPrioridade: %d",aux.elemento, aux.prioridade);		
	}
}

