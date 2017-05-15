/*
#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

void quadEquation(double a, double b, double c) {

    string finderror;

    if (a == 0){
        finderror += " Cannot divide by zero\n";
    }
    else if (a < 0){
        finderror +=  "A cannot be negative\n";

    }
    if (b*b <= 4 * a*c) {

        finderror += "B squared can not be smaller than 4AC\n";
    }

    if(!finderror.empty())
        throw runtime_error(finderror);


}


void quadEquation(double a, double b, double c);

int main() {
    /*
    pre : a != 0,  b*b - 4*a*c >= 0
    post: catch error before excuted
    #1#
    double a, b, c;
    double input1, input2;
    try{
    cout << "Input values for A, B and C: " << endl;
    cin >> a >> b >> c;
    quadEquation(a, b, c);

    input1 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);

    input2 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);

    cout << "Frist root: " << input1 << endl;

    cout << "Second root: " << input2 << endl;

    }

    catch(exception & er)
    {
        cout << "Issue Found:\n" << er.what();

    }

    return 0;

 
}
*/
