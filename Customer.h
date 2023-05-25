#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

using namespace std;

class Person{
public:
    QString name= "";
    QString  sex = "";
    QString person_count = "0";
    QString  start_time ="0";
    QString  duration = "0";
    QString comment = "";

    //Person(const string _name, int _phoneNum, bool _isMale, int _person_count, double _start_time, int _duration, const string _comment);
};

#endif // CUSTOMER_H
