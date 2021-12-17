#include <iostream>

using namespace std;

int main()
{
    //Na declaração de um vetor informamos seu tamanho
    int c[5];
    
    //Inserindo elementos
    c[0] = 2;
    c[1] = 4;
    c[2] = 6;
    c[3] = 8;
    c[4] = 9;

    cout << "Vetor A" << endl;
    
    //Todo vetor começa com indice 0 portanto as posiçoes deste vetor vão de 0 a 4
    //Para percorrer o vetor usamos o loço for
    for(int i = 0; i < 5; i++) 
    {
        cout << c[i] << " ";
    }
    
    cout << "\n" << "Vetor B" << endl;
    
    //Também podemos declarar e inicializar um vetor imediatamanete
    int d[5] = {1, 2, 3, 4, 5};
    
    for(int i = 0; i < 5; i++) 
    {
        cout << d[i] << " ";
    }
    
    cout << "\n" << "Vetor C" << endl;
    
    //Não precisamos informar o tamanho do vetor mas não é recomendado
    int e[] = {2, 6, 7};
    
    for(int i = 0; i < 3; i++) 
    {
        cout << e[i] << " ";
    }
    
    return 0;
   
}
