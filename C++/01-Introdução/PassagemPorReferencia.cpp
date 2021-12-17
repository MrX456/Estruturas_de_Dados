#include <iostream>

using namespace std;

//Passagem de parametro por referencia: variavel possui seu valor
//original alterado

void trocaReferencia(int &a, int &b) 
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 2;
    int b = 3;
    
    cout << "Antes : a = " << a << " b = " << b << endl;
    trocaReferencia(a, b);
    cout << "Depois : a = " << a << " b = " << b << endl;

    return 0;
}
