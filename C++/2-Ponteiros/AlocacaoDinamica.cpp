#include <iostream>

using namespace std;

int main()
{
    //Declarando ponteiro de maneira dinamica
    int* intPointer;//ponteiro
    intPointer = new int; //alocação dinamica
    
    //vai mostrar o endereço de memória apontado do intPointer
    cout << intPointer;

    return 0;
}
