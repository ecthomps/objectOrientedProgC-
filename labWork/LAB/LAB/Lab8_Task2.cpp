/*
#include <iostream>
#include <string>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

template <class a>
class A {

    a valuea;
public:

    A() {

    }
    a getValuea() const {
        return valuea;
    }
    void setValuea(a x) {
        valuea = x;
    }
    A(A & a) {
        valuea = a.getValuea();
    }

};

template <class b>
class B :public A <b>
{

    b valueb;

public:

    int year, month, day;
   B (int year, int month, int day)
        :year{ year }, month{ month }, day{ day } {
        // should check here.
    }

    B() : A() {

    }
    b getValueb() const {
        return valueb;
    }
    void setValueb(b x) {
        valueb = x;
    };

    B(B & b){
    valueb = b.getValueb();
    }


};


int main() {
    B <float> dataFloat1;
    B <float> dataFloat2;
    dataFloat1.setValuea(1.34);
    dataFloat2.setValueb(3.14);
    cout << dataFloat1.getValuea() << ", " << dataFloat2.getValueb() << endl;

    B <int> datainteger1;
    B <int> datainteger2;
    datainteger1.setValuea(1);
    datainteger2.setValueb(3);
    cout << datainteger1.getValuea() << ", " << datainteger2.getValueb() << endl;

    B <char> datachar1;
    B <char> datachar2;
    datachar1.setValuea('a');
    datachar2.setValueb('c');
    cout << datachar1.getValuea() << ", " << datachar2.getValueb() << endl;

    B <string> datastring1;
    B <string> datastring2;
    datastring1.setValuea("good");
    datastring2.setValueb("morning");
    cout << datastring1.getValuea() << ", " << datastring2.getValueb() << endl;


    Date date1 = { 27,10,2014 };

    B<Date> a;


    a.setValuea(date1);

    cout << " ", a.getValuea();

    

    



    return 0;
}
*/
