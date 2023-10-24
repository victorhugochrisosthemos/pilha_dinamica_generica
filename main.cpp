#include <iostream>
#include "modulo_implementacao.h"

using namespace std;

int main()
{
    PilhaDinamicaGenerica<int> pilha;

    criar(pilha);
    cout << "Pilha criada! ";

    empilhar(pilha, 100);
    empilhar(pilha, 700);
    empilhar(pilha, 500);
    empilhar(pilha, 900);
    empilhar(pilha, 300);

    cout << "Pilha: ";
    mostrar(pilha);

    if (ehVazia(pilha)) {
        cout << "A pilha esta vazia." << endl;
    } else {
        cout << "A pilha nao esta vazia." << endl;
    }

    cout << "Quantidade de elementos: " << numeroElementos(pilha) << endl;

    int elementoTopo = topo(pilha);
    cout << "Topo da pilha: " << elementoTopo << endl;

    int elementoProcurado = 200;
    if (existeElemento(pilha, elementoProcurado)) {
        cout << "O elemento " << elementoProcurado << " esta na pilha." << endl;
    } else {
        cout << "O elemento " << elementoProcurado << " nao esta na pilha." << endl;
    }


    cout << "Desempilhando..." << endl;
    desempilhar(pilha);

    cout << "Pilha: ";
    mostrar(pilha);

    cout << "Destruindo pilha... " << endl;
    destruir(pilha);
    cout << "Pilha destruida!";

    return 0;
}
