#include <iostream>
#include <cstddef>

using namespace std;

int main()
{

    //Ponteiros apontando para o vazio(use cstddef)
    bool* truth = NULL;
    float* money = NULL;
    
    //Agora inicializar Ponteiros
    truth = new bool;
    money = new float;
    
    //Armazaenar valores nos endereços apontados(use *)
    *truth = true;
    *money = 33.46;
    
    float* myMoney = new float; //inicializado mas aponta para um enderço qualquer
    
    //1
    *myMoney = *money; //Pega o conteúdo armazenado no endereço apontado por money e armazena em myMoney(uso de *)
    
    //Mostrando conteudos dos endereços(use *)
    cout << *money << endl;
    cout << *myMoney << endl;
    
    //2
    //myMoney aponta para money mas o endereço apontado anteriormente coninua alocado(vazamento de memoria)
    //myMoney = money; ERRADO
    
    //primeiro desaloque o endereço anterior
    //delete myMoney;
    //myMoney = money; CORRETO

    return 0;
}
