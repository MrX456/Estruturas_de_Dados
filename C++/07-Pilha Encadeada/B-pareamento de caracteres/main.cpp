#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    ItemType character;
    Stack stack;
    ItemType stackItem;

    //Verificando uso de ([{}])
    cout << "Adicione uma string." << endl;
    cin.get(character);

    bool isMatched = true;

    while(isMatched && character != '\n')
    {
        if(character == '{' || character == '(' || character == '[')
        {
            stack.push(character);
        }
        if(character == '}' || character == ')' || character == ']')
        {
            if(stack.isEmpty())
            {
                //pilha vazia = bem formada
                isMatched = false;
            }
            else
            {
                stackItem = stack.pop();
                isMatched = (
                             (character == '}' && stackItem == '{')
                             || (character == ')' && stackItem == '(')
                             || (character == ']' && stackItem == '[')
                             );
            }
        }
        cin.get(character);
    }

    if(isMatched && stack.isEmpty())
    {
        cout << "Bem formado" << endl;
    }
    else
    {
        cout << "Mal formado" << endl;
    }

    return 0;
}
