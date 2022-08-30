
#define MAXPILHA 10

struct TpPilha {
	int topo;
	char c[MAXPILHA];	
};

void inicializar (TpPilha &p);
void inserir (TpPilha &p, char elem);
char retirar (TpPilha &p);
char cheia (int topo);
char vazia (int topo);
char topo (TpPilha p);
void exibir (TpPilha p);


void inicializar (TpPilha &p) {
	p.topo = -1;
}

void inserir (TpPilha &p, char elem) {
	p.c[++p.topo] = elem;
}

char retirar (TpPilha &p) {
	return p.c[p.topo--];
}

char cheia (int topo) {
	return topo==MAXPILHA-1;
}

char vazia (int topo) {
	return topo<MAXPILHA-1;
}

char topo (TpPilha p) {
	return p.c[p.topo];
}

void exibir (TpPilha p) {
	for(int i=1; i<MAXPILHA; i++)
		printf("%c\n",retirar(p))
}

