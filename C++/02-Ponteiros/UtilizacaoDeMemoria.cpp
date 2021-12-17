#include <iostream>

using namespace std;

int main()
{

    int* intPointer;//ponteiro
    intPointer = new int; //alocação dinamica
    //Obter conteudo armazenado no endereço apontado por intPointer
    int anotherInt = *intPointer;
    
    cout << anotherInt << endl;
    
    //Alterar o conteudo do endereço apontado por intPointer
    *intPointer = 25;
    
    cout << *intPointer; //Para acessar o conteúdo use * ou será mostrado o endereço de memória

    return 0;
}
