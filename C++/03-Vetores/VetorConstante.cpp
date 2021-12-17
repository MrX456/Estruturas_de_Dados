#include <iostream>

using namespace std;

//É recomendavel definir o tamanho de um vetor com uma constante
const int NUM_ELEM = 10;
    
int main()
{
    int vetor[NUM_ELEM];
    
    //Inserindo elementos
    for(int i = 0; i < NUM_ELEM; i++) 
    {
        vetor[i] = 2 * i;
    }
    
    cout << "\n" << "Vetor" << endl;

    for(int i = 0; i < NUM_ELEM; i++) 
    {
        cout << vetor[i] << " ";
    }
    
    return 0;
   
}
