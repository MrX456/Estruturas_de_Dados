#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main()
{
    //verificar se uma string é palindromo
    bool palindrome =  true;

    char character;
    char stackChar;
    char queueChar;

    Stack stack;
    Queue queue;

    cout << "Adicione uma string" << endl;
    cin.get(character);

    while(character != '\n')
    {
        stack.push(character);
        queue.enqueue(character);
        cin.get(character);
    }

    while(palindrome && !queue.isEmpty())
    {
        stackChar = stack.pop();
        queueChar = queue.dequeue();
        //Comparar caractter da pilha com o da fila, se forem diferentes
        if(stackChar != queueChar)
            palindrome = false;
    }

    if(palindrome)
        cout << "String e palindromo" << endl;
    else
        cout << "String nao e palindromo" << endl;

    return 0;
}
