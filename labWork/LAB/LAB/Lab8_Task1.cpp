/*#include <iostream>
#include <string>
#include <algorithm>

using namespace  std;

const int MAXROW = 100;
template<class T> T maxfunc(T[MAXROW]);

template<class T>
T maxfunc(T info[MAXROW]) {
    T MAX;



    for (int i = 0; i < MAXROW; i++) {

        if (i == 0) {
            MAX = info[i];

        }

        if (info[i] > MAX) {
            MAX = info[i];
        }
    

    }

    return MAX;
}

int main() {
    int infoNumber[MAXROW] = { 4, 1, 13, 3, 2 };
    double infoNumber2[MAXROW] = { 1.1, 4.1, 8.1, 5.2, 2.3 };
    string infoString[MAXROW] = {"the", "student", "is", "in", "class"};

  
   
    int dataNumber = maxfunc<int>(infoNumber);
    double dataNumber2 = maxfunc<double>(infoNumber2);
    string dataString = maxfunc<string>(infoString);

    cout << "Integer largest number output: " << dataNumber << endl;
    cout << "Double largest number output: " << dataNumber2 << endl;
    cout << "String largest output: " << dataString << endl;

    return 0;

}*/