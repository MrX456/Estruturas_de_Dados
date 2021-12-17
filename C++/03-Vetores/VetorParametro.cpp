#include <iostream>

using namespace std;

//Vamos passar vetores como parametro e verificar alterações
void modificaVetorSyntaxe1(int b[], int num_elem) 
{
   for(int i = 0; i < num_elem;i++) 
   {
       b[i] = b[i] * 2;
   }
}

void modificaVetorSyntaxe2(int* b, int num_elem) 
{
   for(int i = 0; i < num_elem;i++) 
   {
       b[i] = b[i] * 2;
   }
}

int main()
{
    //Inicializando um vetor dinamico(estatico funcionaria igual)
    int num_elem = 10;
    int *vetor = new int[num_elem];
    
    for(int i = 0; i < num_elem; i++)
    {
        vetor[i] = i + 1;
    }
    
    cout << "Vetor original" << endl;
    
    for(int i = 0; i < num_elem; i++)
    {
        cout << vetor[i] << " ";
    }
    
    cout << "\n";
    
    modificaVetorSyntaxe1(vetor, num_elem);
    
    cout << "Sintaxe 1" << endl;
    
    for(int i = 0; i < num_elem; i++)
    {
        cout << vetor[i] << " ";
    }
    
    cout << "\n";
    
    modificaVetorSyntaxe2(vetor, num_elem);
    
    cout << "Sintaxe 2" << endl;
    
    for(int i = 0; i < num_elem; i++)
    {
        cout << vetor[i] << " ";
    }
    
    //Os valores do vetor sofreram alterações após os métodos
    
    return 0;
   
}
