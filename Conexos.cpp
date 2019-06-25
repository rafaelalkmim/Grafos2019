/* Algoritmos em Grafos
Autor: Rafael Alkmim Machado
Prof. Raquel Mini
Questao: Componentes Conexos
*/


#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

  int grafo[26][26]; //matriz de adjacencia com o maximo de 26 letras do alfabeto
  int n,testes,vertices,arestas;
  char v1,v2;

  void construirGrafo();
  void preencherMatriz();
  int somarPeso(int);
  void printarGrafo();

int main() {

  std::cin >> testes;
  n = 1;

  while(n <= testes){
    preencherMatriz();
    construirGrafo();
  }

  return 0;
}

void construirGrafo(){

  std::cin >> vertices;
  std::cin >> arestas;

  //array utilizado para salvar quais vertices ja foram visitados
  int visitados[vertices];

  for (int i = 0; i < arestas; i++) {
    std::cin >> v1;
    std::cin >> v2;
    grafo[v1-97][v2-97] = 1; //insere as arestas na matriz de adjacencia
    grafo[v2-97][v1-97] = 1; 
  }

  //printarGrafo();

  std::cout << "Case #" << n << ":";

  int j = 0;
  int lines = 0;
  int k = 0;
  int aux = 0;

  for (int i = 0; i < vertices; i++) {
     if(somarPeso(i)>=0){ //somarPeso >= 0 significa que ainda ha alguma aresta do vertice que nao foi visitada
        std::cout << "\n";
        v1 = i+97;
        std::cout << v1 << ',';
        lines++;
        visitados[k] = v1;  //inclui aresta no array de visitados
        k++;
        for (j = 0; j < vertices; j++) {
          if (grafo[i][j]==1) { //procura conexoes do vertice
            v2 = j+97;
            std::cout << v2 << ',';
            visitados[k] = v2; //inclui aresta no array de visitados
            k++;
            aux++;
          }//if
        }//for
        for (size_t i = 0; i < aux+1; i++) {
          for (size_t j = 0; j < aux+1; j++) {
              /*caso a aresta ja tenha sido visitada, marca como -1 para que nao seja considerada novamente
              em uma nova iteracao */
            grafo[visitados[i]-97][visitados[j]-97] = -1; 
          }//for
        }//for
      //printarGrafo();
  }//if
      for (size_t i = 0; i < aux+1; i++) {
        visitados[i] = 0; //reseta array de visitados para nova iteracao
      }//for

      aux=0;
      k=0;

  }//for

  std::cout << "\n" << lines << " " << "connected components" << "\n";
  n++;
  cout << "\n";

}//construirGrafo

  //Metodo que soma o peso das arestas do Grafo
  //Recebe como parametro um vertice e verifica o peso de suas conexoes
  int somarPeso(int v){
    int total = 0;
    for (int i = 0; i < vertices; i++) {
      total += grafo[v][i];
    }
    return total;
  }

  //Metodo que preenche toda a Matriz de Adjacencia com Zeros
  //Utilizado no inicio de cada teste
  void preencherMatriz(){
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        grafo[i][j] = 0;
      }
    }
  }

  //Metodo que printa na tela a Matriz de Adjacencia do Grafo
  void printarGrafo(){
    for (int i = 0; i < vertices; i++) {
      cout << "\n";
      for (int j = 0; j < vertices; j++) {
        cout << grafo[i][j] << " ";
      }
    }
    cout << "\n";
  }