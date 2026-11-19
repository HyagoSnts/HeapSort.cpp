/*
	Name: HeapSort.cpp 
	Author: Hyago Santos 
	Date: 10/11/26 10:52
	Description: programa para implementar o 
				metodo de ordenação heap sort
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void heapfy(int *, int, int);
void heapsort(int *, int);
void swap(int *, int *);
void imprimir(int *);
int tam;

main()
{
	clock_t inicio, fim;
	double tempoDecorrido;
	
	//int vet[] = {23, 12, 17, -2, 20, 24, 157, 50, 81, 53};
	int vet[10000];
	int i;
	tam = sizeof(vet)/sizeof(int);
	
	//gereçaõ radom de elementos
	srand(time(NULL)); //planta a semente aleatoria de acordo com o tempo
	for(i=0; i<tam; i++)
		vet[i] = rand()%10000;
	
	puts("Vetor original: ");
	imprimir(vet);
	
	inicio = clock();
	
	heapsort(vet,tam);
	puts("\nVetor ordewnado pelo heap sort:");
	imprimir(vet);
	
	fim = clock();
		
	tempoDecorrido = ((double)fim-inicio/CLOCKS_PER_SEC)/1000;
	printf("\n\nTEMPO DECORRIDO: %.3f", tempoDecorrido);
}
//função principal que monta a arvore e submete
//a função recursiva
void heapsort(int *V, int n)
{
	//1. constroi um maxheap
	for(int i = n/2-1; i >= 0; i--)
		heapfy(V, n, i);
		
	//2. troca a raiz com o ultimo elemento e reduz a arvore (heap)
	for(int i = n-1; i>0; i--)
	{
		//move o elemento ataul (maior - MAX heap)
		//para o fim do array
		swap(&V[0], &V[i]);
		//invoca
		heapfy(V, i, 0);
	}
}

void imprimir(int vet[])
{
	for(int i=0; i<tam; i++)
		printf("%d|", vet[i]);
	puts("");
}

void swap(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;	
}

void heapfy(int *V, int n, int i)
{
	//imprimir(vet);
	int maior = i; //maior da raiz
	int esq = 2 * i + 1; // filho da esquerda
	int dir = 2 * i + 2; // filho da direita
	
	//se o filho da esquerda e maior que o pai
	if(esq < n && V[esq] > V[maior])
		maior = esq;
	
	if(dir < n && V[dir] > V[maior])
		maior = dir;
		
	if(maior != i)
	{
		swap(&V[i], &V[maior]);
		//invoca recursivamente heapfy
		//na sub-arvore afetada
		heapfy(V, n, maior);
	}
}


