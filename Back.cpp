/* Algoritmos em Grafos
Alunos: 
Rafael Alkmim Machado
Raiana Pereira
Prof. Raquel Mini
Questao: Back to the Future
*/


#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

  int grafo[100][100];
  int n,testes,cidade,rotas,preco,cid1,cid2;
  int amigos,vagas,instancia;

  void construirGrafo();
  void preencherMatriz();
  void printarGrafo();
  int caminhoDireto(int,int);
  int encontrarRotas(int,int);
  int pesquisarPreco(int);
  int menorPreco();


int main() {

  instancia = 1;
  while(instancia <= 3){
    preencherMatriz();
    construirGrafo();
    std::cout << "\n";
  }

  return 0;
}

void construirGrafo(){

  int valor;

    std::cin >> cidade;
    std::cin >> rotas;
    
    //preenche o grafo com as rotas disponiveis     
    for (int i = 0; i < rotas; i++) {
      std::cin >> cid1;
      std::cin >> cid2;
      std::cin >> preco;
      grafo[cid1-1][cid2-1] = preco;
      grafo[cid2-1][cid1-1] = preco;
    }

    std::cin >> amigos;
    std::cin >> vagas;

    //Caso ha um caminho direto mais viavel em termos de preco, a verificacao eh feita pelo n de vagas e disponibilidade financeira
    if(menorPreco()==0){
      valor = caminhoDireto(amigos,vagas);
      valor += encontrarRotas(amigos,vagas);
    } else {
      valor = encontrarRotas(amigos,vagas);
    }

      std::cout << "Instancia " << instancia << "\n";
      instancia++;
      std::cout << "\n";
      if(valor < amigos || valor > pow(10,15))
        std::cout << "impossivel" << "\n";
      else
        std::cout << valor << "\n";

      valor = 0;

      std::cout << "\n" << "\n";

}//construirGrafo

  //Metodo utilizado para encontrar quais sao as rotas possiveis para chegar ate a cidade N
  int encontrarRotas(int amigos, int vagas){

    int valor = 0,menor = amigos,line,aux;
    for (size_t i = 0; i < cidade-1; i++) {
      for (size_t j = 0; j < cidade-1; j++) {
        if(grafo[i][j] > 0){
          if(pesquisarPreco(j) > 0 && pesquisarPreco(j) < menor){
            menor = pesquisarPreco(j);
            line = j;
            aux = i;
          }//if
        }//if
      }//for
    }//for

    menor += grafo[aux][line];
    valor = menor;
    //a rota escolhida eh a q fornece valor mais baixo
    grafo[aux][line] = 0;
    grafo[line][aux] = 0;
    grafo[cidade-1][line] = 0;
    grafo[line][cidade-1] = 0;

    if(amigos < vagas)
        valor = amigos * menor;
    else
        valor = vagas * menor;

    return valor;
  }

  /*Metodo utilizado somente nos casos em que ha uma passagem viavel da cidade 1 ate a cidade N, por valor mais baixo
  que seria uma viagem por varias rotas */
  int caminhoDireto(int amigos, int vagas){
    int valor = 0;
    for (int i = 0; i < cidade; i++) {
        if(grafo[i][cidade-1] > 0){
            valor = grafo[i][cidade-1];
            grafo[i][cidade-1] = 0;
            grafo[cidade-1][i] = 0;
            i = cidade;
            if(amigos < vagas)
                valor = amigos * valor;
            else
                valor = vagas * valor;
        }
    }
    return valor;
  }

  //Metodo que retorna o valor do Preco da passagem
  int pesquisarPreco(int i){
    return grafo[i][cidade-1];
  }

  //Metodo que retorna em qual cidade fica localizada a passagem de menor preco
  int menorPreco(){
    int menor = amigos;
    int line;
    for (size_t i = 0; i < cidade; i++) {
      if(grafo[i][cidade-1]>0 && grafo[i][cidade-1]< menor){
        menor = grafo[i][cidade-1];
        line = i;
      }
    }
    return line;
  }

  /*Metodo que preenche toda a Matriz de Adjacencia com Zeros
  Utilizado no inicio de cada teste */
  void preencherMatriz(){
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        grafo[i][j] = 0;
      }
    }
  }

  //Metodo que printa na tela a Matriz de Adjacencia do Grafo
  void printarGrafo(){
    for (int i = 0; i < cidade; i++) {
      cout << "\n";
      for (int j = 0; j < cidade; j++) {
        cout << grafo[i][j] << " ";
      }
    }
    cout << "\n";
  }