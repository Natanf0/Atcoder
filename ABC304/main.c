// Autor: Natan Ferreira
// Problema: https://vjudge.net/problem/AtCoder-abc304_c

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Pessoa{
	int x; 
	int y;
	int sabe; // booleano para saber se a pessoa sabe ou não da semana da computação.
}Pessoa;

double distancia(Pessoa p1, Pessoa p2){
	int dx = p1.x-p2.x;
	int dy = p1.y-p2.y;
	return (pow(dx,2)) + (pow(dy,2));
}

int main(){

	// ler as entradas
	int n, d;
    scanf("%d %d", &n, &d);
	d = pow(d,2);
	Pessoa* pessoas = (Pessoa*) malloc((sizeof(Pessoa)*n)); // alocando o vetor de pessoas cujas posições são lidas do stdin.
	Pessoa* pessoas_sabem = (Pessoa*) malloc((sizeof(Pessoa)*n)); // alocando um novo vetor para adicionar as pessoas que sabem.

	Pessoa* pessoaImpossivel = (Pessoa*) malloc(sizeof(Pessoa));
	pessoaImpossivel->x= pow(10,7);
	pessoaImpossivel->y=pow(10,7);
	pessoaImpossivel->sabe=1;

	scanf("%d %d", &pessoas[0].x, &pessoas[0].y); pessoas[0].sabe=1;
	pessoas_sabem[0] = pessoas[0];
	int c = 1;
	for(int i = 1; i<n; i++){
		scanf("%d %d", &pessoas[i].x, &pessoas[i].y ); 
		pessoas[i].sabe=0;
		if(distancia(pessoas[0], pessoas[i]) <= d){ // ouviu
			pessoas_sabem[c] = pessoas[i];
			pessoas[i]=*pessoaImpossivel;
			c+=1;
		}
	}
    
	for(int i = 1; i<c; i++){
		for(int j =1; j<n; j++){
			if(distancia(pessoas_sabem[i], pessoas[j])<=d){ // se a pessoa não sabe e ouve, adiciono no vetor
				pessoas_sabem[c]=pessoas[j];
				c+=1;
				pessoas[j]=*pessoaImpossivel;
			}
		}
	}

	for(int i=0; i<n; i++){
		(pessoas[i].sabe) ? printf("Yes\n") : printf("No\n");
	}	
}
