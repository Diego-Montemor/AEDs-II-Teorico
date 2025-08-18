#include <iostream>

using namespace std;

typedef struct {
    int chave;
} Registro;

int busca(Registro L[], int x , int n){
    int i = 0 , 
        pos = 0;
    while (i <= n){
        if(L[i].chave == x){
            pos = i + 1;
            break;
        }else i++;
    }
    return pos;
}

int busca2(Registro L[], int x, int n){
    int i = 0;
    L[n + 1].chave = x;
    while(L[i].chave != x){
        i++;
    }

    if (i != n + 1) {
        return i + 1;   
    } else {
        return 0;       
    }
}

int buscaOrd(Registro L[], int x, int n){
    int i = 0;
    L[n + 1].chave = x;
    while(L[i].chave < x){
        i++;
    }

    if (i == n + 1 or L[i].chave != x) {
        return 0;   
    } else {
        return i + 1;       
    }
}

int buscaBinaria(Registro L[], int x, int n){
    int inf = 0,
        sup = n,
        buscaBin = 0;
    while(inf <= sup){
        int meio = (inf + sup)/2;
        if(L[meio].chave == x){
            buscaBin = meio;
            break;
        }else if(L[meio].chave < x){
            inf = meio + 1;
        }else sup = meio - 1;
    }
    return buscaBin + 1;
}


int main() {
    Registro L[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b1, b2, bo, bb;
    cout << "Digite um numero para buscar pela funcao busca1: ";
    cin >> b1;
    b1 = busca(L,b1,10);
    cout << "Digite um numero para buscar pela funcao busca2: ";
    cin >> b2;
    b2 = busca2(L,b2,10);
    cout << "Digite um numero para buscar pela funcao busca ordenada: ";
    cin >> bo;
    bo = buscaOrd(L,bo,10);

    cout << "Digite um numero para buscar pela funcao busca binaria: ";
    cin >> bb;
    bb = buscaBinaria(L, bb, 10);

    cout << "Busca 1: " << b1 << "\nBusca 2: " << b2  << "\nBusca ordenada: " << bo << "\nBusca Binaria: " << bb << endl;



    return 0;
}