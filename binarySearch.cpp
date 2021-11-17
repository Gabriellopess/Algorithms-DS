#include <stdio.h>

int binarySearch(int *vet, int x, int inicial, int fim){
  int meio = 0;
  while(inicial <= fim){
    meio = (inicial + fim) / 2;
    if(vet[meio] < x){
      inicial = meio + 1;
    }
    if(x == vet[meio]){
      return meio;
    }
    if(vet[meio] > x){
      fim = meio - 1;
    }
  }
  return -1;
}

int main(void) {
  int vet[] = {4, 3, 5, 6, 7, 1};
  int tam  = 0, z = 6;
  tam = sizeof(vet)/sizeof(int);
  int x = 10;
  int ans = binarySearch(vet, x, 0, tam - 1);
  if(ans == -1) printf("Elemento %d nao existe no array\n", x);
  else printf("Elemento %d esta no index %d\n", x, ans);
  
  return 0;
}