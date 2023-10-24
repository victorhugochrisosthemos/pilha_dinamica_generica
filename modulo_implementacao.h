#ifndef MODULO_IMPLEMENTACAO_H_INCLUDED
#define MODULO_IMPLEMENTACAO_H_INCLUDED

using namespace std;

template<typename T>
struct Nodo{
    T elemento;
    Nodo<T>* proximo;
};

template<typename T>
struct PilhaDinamicaGenerica{
    Nodo<T>* topo;
    int cardinalidade;
};

//Cria uma pilha
template<typename T>
void criar(PilhaDinamicaGenerica<T> &pilha){
    pilha.cardinalidade = 0;
    pilha.topo = NULL;
}

//Destroi uma pilha
template<typename T>
void destruir(PilhaDinamicaGenerica<T> &pilha){
    Nodo<T>* atual = pilha.topo;
    while(atual != NULL){
        Nodo<T>* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
    pilha.topo = NULL;
    pilha.cardinalidade = 0;
}

//Verifica se uma pilha est� vazia
template<typename T>
bool ehVazia(PilhaDinamicaGenerica<T> pilha){
    return pilha.cardinalidade == 0;
}

//Recupera o numero de elementos da pilha
template<typename T>
int numeroElementos(PilhaDinamicaGenerica<T> pilha){
    return pilha.cardinalidade;
}

//Verifica se um determinado elemento est� na pilha
template<typename T>
bool existeElemento(PilhaDinamicaGenerica<T> pilha, T elemento){
    Nodo<T>* atual = pilha.topo;
    while(atual != NULL){
        if(atual->elemento == elemento){
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

//Recupera o topo da pilha
template<typename T>
T topo(const PilhaDinamicaGenerica<T> pilha){
    if(ehVazia(pilha)){
        throw "PILHA VAZIA!";
    }
    return pilha.topo->elemento;
}

// Inserir (empilhar) um elemento no topo da pilha
template<typename T>
void empilhar(PilhaDinamicaGenerica<T> &pilha, T elemento){
    Nodo<T>* novoNodo = new Nodo<T>;
    novoNodo->elemento = elemento;
    novoNodo->proximo = pilha.topo;
    pilha.topo = novoNodo;
    pilha.cardinalidade++;
}

// Retirar (desempilhar) um elemento do topo da pilha
template<typename T>
void desempilhar(PilhaDinamicaGenerica<T> &pilha){
    if(ehVazia(pilha)){
        throw "UNDERFLOW";
    }
    Nodo<T>* nodoRemovido = pilha.topo;
    pilha.topo = pilha.topo->proximo;
    delete nodoRemovido;
    pilha.cardinalidade--;
}

// Exibir os elementos da pilha
template<typename T>
void mostrar(PilhaDinamicaGenerica<T> pilha){
    Nodo<T>* atual = pilha.topo;
    while(atual != NULL){
        cout << atual->elemento << " ";
        atual = atual->proximo;
    }
    cout << endl;
}

#endif // MODULO_IMPLEMENTACAO_H_INCLUDED
