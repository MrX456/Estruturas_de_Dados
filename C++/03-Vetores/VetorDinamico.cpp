#include <iostream>

using namespace std;
   
int main()
{
    int num_elem;
    cout << "Digite o tamanho do vetor : ";
    cin >> num_elem;
    
    //Alocação dinamica de um vetor
    int* c = new int[num_elem];
    
    //Inserindo valores
    for(int i = 0; i < num_elem; i++) 
    {
        c[i] = 2 * i;
    }
    
    cout << "\n" << "Vetor" << endl;

    for(int i = 0; i < num_elem; i++) 
    {
        cout << c[i] << " ";
    }
    
    //Com o a alocação foi dinamica vamos desalocar a memória
    delete [] c;
    
    return 0;
   
}
