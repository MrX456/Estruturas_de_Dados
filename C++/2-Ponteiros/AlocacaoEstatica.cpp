#include <iostream>

using namespace std;

int main()
{
    //Declarando variavel e ponteiro
    int alpha;
    int* intPointer;//ponteiro
    
    //Inicializando ponteiro de forma estática(alocação de memória)
    intPointer = &alpha;
    
    //vai mostrar o endereço de memória de alpha
    cout << intPointer;

    return 0;
}
