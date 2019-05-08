/* Algoritmos em Grafos
Autor: Rafael Alkmim Machado
Prof. Raquel Mini
Questao: Resgate em Queda Livre
*/


#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int grafo[(int)pow(10,4)][(int)pow(10,4)];
int nMatriz = sizeof(grafo)/pow(630,2);
int cdn[500][2];
void construirGrafo();
void preencherMatriz();
void construirCaminho(int);
int menorCaminho(int);
void printarGrafo();
float pesoAresta(int,int,int,int);

int main() {

  preencherMatriz();
  construirGrafo();

return 0;
}

void construirGrafo(){

  int testes,nPessoas,linha,coluna;

  std::cin >> testes;
  int n = 0;
  int k = 0;

  while(n < testes){

      std::cin >> nPessoas;
      int coordenadas[nPessoas][2];
      float distancia = 0;

      for(int i = 0; i < nPessoas; i++){
              std::cin >> linha;
              std::cin >> coluna;
              grafo[linha][coluna] = 1;
              coordenadas[i][0] = linha;
              coordenadas[i][1] = coluna;
      }

      for (int i = 0; i < nPessoas-1; i++) {
        distancia += pesoAresta(coordenadas[i][1],coordenadas[i+1][1],coordenadas[i][0],coordenadas[i+1][0]);
      }

      construirCaminho(nPessoas);
      int menorTeia = menorCaminho(nPessoas);

      if(distancia < menorTeia){
        std::cout.precision(2);
        std::cout << std::fixed << menorTeia;
        cout << "\n" << "\n";
      } else{
        std::cout.precision(2);
        std::cout << std::fixed << distancia;
        cout << "\n" << "\n";
      }

      //printarGrafo();

      n++;

      preencherMatriz();

  }//while


}//construirGrafo

//Metodo para calcular peso da aresta baseado na distancia entre os vertices
float pesoAresta(int linhaV1,int linhaV2,int colunaV1, int colunaV2){
      return (sqrt((pow((colunaV1-colunaV2),2) + (pow((linhaV1-linhaV2),2))))/100);
}

//Metodo que percorre todo o grafo e coleta as coordenadas dos vertices
void construirCaminho(int nPessoas){
  int k = 0;
  for (int i = 0; k < nPessoas && i < nMatriz; i++) {
    for (int j = 0; k < nPessoas && j < nMatriz; j++) {
       if(grafo[i][j]==1){
         cdn[k][0] = i;
         cdn[k][1] = j;
         k++;
       }
    }
  }
}

//Metodo que faz isso das coordenadas dos vertices para calcular qual o menor peso possivel das arestas
int menorCaminho(int nPessoas){
  int menor = nMatriz;
  int total = 0;
  for (int i = 0; i < nPessoas; i++) {
    int aux = pesoAresta(cdn[i][1],cdn[i+1][1],cdn[i][0],cdn[i+1][0]);
      if(aux < menor)
        menor = aux;
    total += menor;
  }
  return total;
}

//Metodo que preenche toda a Matriz de Adjacencia com Zeros
//Utilizado no inicio de cada teste
void preencherMatriz(){
  for (int i = 0; i < nMatriz; i++) {
    for (int j = 0; j < nMatriz; j++) {
      grafo[i][j] = 0;
    }
  }
}

//Metodo que printa na tela a Matriz de Adjacencia do Grafo
void printarGrafo(){
  for (int i = 0; i < nMatriz; i++) {
    cout << "\n";
    for (int j = 0; j < nMatriz; j++) {
      cout << grafo[i][j] << " ";
    }
  }
  cout << "\n";
}
