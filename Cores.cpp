/* Algoritmos em Grafos
Autor: Rafael Alkmim Machado
Prof. Raquel Mini
Questao: Colorindo Grafos
*/


#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

  void construirGrafo();
  void preencherMatriz();
  void printarGrafo();
  bool testarAdjacencia();
  bool testarConectividade();
  bool verificarArestas();
  int grafo[1000][100];
  int testes,n,cor,vertices,arestas,novasArestas;
  int v1,v2,nCores,color;

int main() {

  std::cin >> testes;
  n = 1;

  while(n <= testes){
    construirGrafo();
  }

  return 0;
}

void construirGrafo(){

  std::cin >> vertices;
  std::cin >> arestas;
  std::cin >> novasArestas;
  std::cin >> nCores;

  //insere-se uma coluna extra na matriz de adjacencia para indicar qual eh a cor do vertice
  cor = vertices;

  preencherMatriz();

  //printarGrafo();

  //laco para preencher a cor dos vertices
  for (int i = 0; i < vertices; i++) {
    std::cin >> color;
    grafo[i][cor] = color;
  }

  //incluir arestas no grafo
  for (int i = 0; i < arestas; i++) {
    std::cin >> v1;
    std::cin >> v2;
    grafo[v1-1][v2-1] = 1;
    grafo[v2-1][v1-1] = 1;
  }

  //printarGrafo();

  int cont = 0;

  //verifica ate quando sera possivel sera possivel incluir novas arestas no grafo
  while(cont < novasArestas && testarAdjacencia()){
        cont++;
  }
  
  //verifica se todas as arestas desejadas foram inseridas e se o grafo eh conexo
    if(cont==novasArestas && testarConectividade())
      std::cout << "Y" << '\n';
    else
      std::cout << "N" << '\n';

  n++;

  std::cout << '\n';

}//construirGrafo

  //Metodo que preenche toda a Matriz de Adjacencia com Zeros
  //Utilizado no inicio de cada teste
  void preencherMatriz(){
    for (int i = 0; i < vertices; i++) {
      for (int j = 0; j < vertices+1; j++) {
        grafo[i][j] = 0;
      }
    }
  }

  //Metodo que printa na tela a Matriz de Adjacencia do Grafo
  void printarGrafo(){
    for (int i = 0; i < vertices; i++) {
      cout << "\n";
      for (int j = 0; j < vertices+1; j++) {
        cout << grafo[i][j] << " ";
      }
    }
    cout << "\n";
  }
  
  /*Metodo testarAdjacencia percorre a matriz de adjacencia do grafo e verifica se ha possibilidade de inserir uma aresta
  entre vertices de cores diferentes. Caso o grafo esteja completo ou so haja conectividade entre cores iguais, o retorno eh false.
  */
  bool testarAdjacencia(){
    for(int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++) {
          if( (grafo[i][j] + grafo[j][i] == 0) && (grafo[i][cor] != grafo[j][cor]) ){
              grafo[i][j] = 1;
              grafo[j][i] = 1;
              return true;
          }
        }
    }
    return false;
  }
  
  /*Metodo testarConectividade vai percorrendo toda a matriz de adjacencia do grafo
  e marcando os vertices conectados entre si. Caso uma aresta nao seja marcado, ela pertence a outro componente, o 
  que tornaria o grafo nao conexo. Nesse caso, o retorno eh false.
  */
  bool testarConectividade(){
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            if(grafo[i][j]==1){
                grafo[i][j] = -1;
                grafo[j][i] = -1; 
                i = j-1;
            }
        }
    }
    return verificarArestas();
  }
  
  
  /*Metodo que soma o peso das arestas do Grafo
  Determa quais vertices foram alcancados pelo metodo testarConectividade
  Retorna false se encontrar algum nao conectado, ou true se todos foram alcancados
  */
  bool verificarArestas(){
    int total = 0, linha = 0;
    for (int i = 0; i < vertices; i++) {
      for(int j = 0; j < vertices; j++){
          linha += grafo[i][j];
          total += grafo[i][j];
      }
      if(total > 0 || linha == 0){
        return false;
      }
      linha = 0; 
    }
    return true;
  }