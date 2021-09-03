#ifndef PILHA_H
#define PILHA_H

#include<iostream>
using namespace std;

template<class T>
class Pilha{
    private:
typedef int Dados;

struct Node{
    Dados dados;
    Node* prox;
   
};
 
 int max_tam;
 int topo;//erro pode estar aqui
 Node* NoTopo;

       public:
    Pilha(int capacidade){
       NoTopo = NULL;
       this->max_tam = capacidade;
       topo = 0;
 
    }

    ~Pilha(){
         delete NoTopo;
    }

    void empilha(Dados item){
        Node* NovoNo = new Node;
          
       if(topo == max_tam){
           throw "Stack overflow";
       }else{
          NovoNo->dados = item;
          NovoNo->prox = NoTopo;
          NoTopo = NovoNo;
          topo++;
       }
    }

    T desempilha(){

        if(topo == 0){
            throw "Stack underflow";
        }else{
            Node* NoTemp;
            NoTemp = NoTopo;
            Dados item = NoTopo->dados;
            NoTopo = NoTopo->prox;
            topo--;
            delete NoTemp;
            return item;
        }

    }

int tamanho(){
return topo;
}

};

#endif