#include <iostream>
#include "Time.h" //Incluir  classe criada

using namespace std;

int main()
{
    //Criando objeto time utilizando construtor
    Time t1(23, 59, 59);
    t1.print();

    t1.setHour(12);
    t1.setMinute(30);
    t1.setSecond(15);
    t1.print();
    cout << "Hour: " << t1.getHour() << endl;
    cout << "Hour: " << t1.getMinute() << endl;
    cout << "Hour: " << t1.getSecond() << endl;

    return 0;
}
