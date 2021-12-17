#ifndef TIME_H
#define TIME_H


class Time
{
 //Membros privados
 private:
     int hour;
     int minute;
     int second;

 //Membros publicos
 public:
    Time(int hour = 0, int minute = 0, int second = 0); //Construtor
    //getters e setters
    int getHour() const;
    void setHour(int hour);
    int getMinute() const;
    void setMinute(int minute);
    int getSecond() const;
    void setSecond(int second);
    //métodos adicinais
    void print() const;
    void nextSecond();
};

#endif // TIME_H
