/* Algoritmos em Grafos
Autor: Rafael Alkmim Machado
Prof. Raquel Mini
Questao: Cadeia Alimentar
*/


#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

  int vertices,arestas,v1,v2;
  void construirGrafo();

int main() {

    construirGrafo();

  return 0;
}

void construirGrafo(){

  std::cin >> vertices;
  int grafo[vertices][vertices];
  std::cin >> arestas;

  //preenche a Matriz com zeros, indicando nenhuma adjacencia inicialmente
  for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
      grafo[i][j] = 0;
    }
  }

  //estabelece a relacao de adjacencia entre os vertices que serao informados no laco
    for (int i = 0; i < arestas; i++) {
      std::cin >> v1;
      std::cin >> v2;
      grafo[v1-1][v2-1] = 1;
    }

  bool bolada = false;

  //testa os caminhos de adjacencia entre os vertices para saber se a cadeia alimentar eh bolada ou nao
  for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
          if (grafo[i][j]==1 && grafo[j][i]==1) {
                cout << "Bolada";
                bolada = true;
                i = vertices;
                j = vertices;
          }//if
        }//for

  }//for

  if(!bolada)
    cout << "Nao Bolada";

}//construirGrafo
