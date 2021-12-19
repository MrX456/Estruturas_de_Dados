#include <iostream>
using namespace std;

class Aluno{
    private:
    int ra;
    string nome;

    public:
    Aluno();
    Aluno(int ra, string nome);
    string getNome();
    int getRa();
};
