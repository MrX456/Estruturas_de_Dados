#ifndef ALUNO_H
#define ALUNO_H
#include <string>

using namespace std;

class Aluno
{
    public:
        Aluno();
        Aluno(int ra, string nome);
        string getNome() const;
        int getRA() const;

    private:
        int ra;
        string nome;
};

#endif // ALUNO_H
