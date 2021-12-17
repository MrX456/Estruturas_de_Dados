#include <iostream>

using namespace std;

//Passagem de parametro por valor: variavel possui seu valor
//original inalterado

void trocaValor(int a, int b) 
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
    trocaValor(a, b);
    cout << "Depois : a = " << a << " b = " << b << endl;

    return 0;
}
