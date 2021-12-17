#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    char caracter;
    Stack stack;
    char stackItem;

    cout << "Adicione uma string." << endl;
    cin.get(caracter);

    //Isto vai inverter a string digitada pois sempre é removido o elemento no topo da pilha
    //bem como cada elemento é adicionado no topo também
    while(caracter != '\n')
    {
        stack.push(caracter);
        cin.get(caracter);
    }

    while(!stack.isEmpty())
    {
        stackItem = stack.pop();
        cout << stackItem;
    }

    cout << endl;

    return 0;
}
