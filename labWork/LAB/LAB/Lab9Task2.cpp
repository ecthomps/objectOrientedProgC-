/*#include <iostream>
#include <iomanip>
#include <string>

using namespace std;



class Negative {
public:
    string what() {
        return message;
    }
    Negative() {
        message = "Negative Number\n";
    }
private:
    string message;
};

class OddNumber {
public:
    string what() {
        return message;
    }
    OddNumber() {
        message = "Odd Interger\n";
    }
private:
    string message;
};

class Power2 {
public:
    string what() {
        return message;
    }
    Power2() {
        message = "The integer is a power of 2\n";
    }
private:
    string message;
};


void foo(int a);

void bar(int a);

void bell(int a);

bool Power2a(int a);


void foo(int a) {

    if (a < 0) {
        throw Negative();
    } else {
        bar(a);
    }
}

void bar(int a) {

    if ((a % 2) != 0) {
        throw OddNumber();
    } else {
        bell(a);
    }
}

void bell(int a) {

    if (Power2a(a)) {
        throw Power2();
    } else {
        cout << "Ordinary Number\n";
    }
}

bool Power2a(int a) {

    if (a <= 0) {
        return false;
    }
    return ((a > 0) && (a&(a - 1)) == 0);
}

int main() {

    try {
        foo(10);
        //foo(-4);
        //foo(69);
        //foo(4);
    } catch (Negative except) {
        cout << except.what();
    } catch (OddNumber except) {
        cout << except.what();
    } catch (Power2 except) {
        cout << except.what();
    }

    return 0;
}*/