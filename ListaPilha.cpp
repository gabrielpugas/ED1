#include<stdio.h>
#include<conio.h>
#include<windows.h> 
#include<locale.h>
#include "pilha.h"

TpPilha concatenarPilha(TpPilha p1, TpPilha &p2) {
	TpPilha aux;
	
	while(!empty(p2.top)) {
		aux = pop(&p2);
	}
	while(!empty(aux.top)) {
		p1 = pop(&aux);
	}
	return p1;
}

int main () {
	TpPilha p1, p2;
	concatenarPilha(p1, p2);	
	return 0;
}
