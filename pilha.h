#define MAXPILHA 10

struct TpPilha {
	int top;
	char c[MAXPILHA];	
};

void init (TpPilha &p);
void push (TpPilha &p, char elem);
char pop (TpPilha &p);
char full (int top);
char empty (int top);
char top (TpPilha p);
void show (TpPilha p);

void init (TpPilha &p) {
	p.top = -1;
}

void push (TpPilha &p, char elem) {
	p.c[++p.top] = elem;
}

char pop (TpPilha &p) {
	return p.c[p.top--];
}

char full (int top) {
	return top==MAXPILHA-1;
}

char empty (int top) {
	return top==-1;
}

char top (TpPilha p) {
	return p.c[p.top];
}

void show (TpPilha p) {	
	while(!empty)
		printf("\n%c",pop(p));
}

