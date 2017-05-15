/*
    Lab 3
    Pre/Post conditions
    Test plans
*/

// Task 1

#include <iostream>
using namespace std;
const double epsilon = .001;
double fabs(double x){
	if (x > 0) return x;
	return -x;
}


double squareRoot(double x){
/*
    pre: x >= 0
    post : returns y such that |y*y - x| < epsilon
*/
	double xn = fabs(x/2);
    bool neg = false;
    if (x < 0) {
    	neg = true;
    	x = fabs(x);
	}
	while (fabs(xn*xn - x)> epsilon){
		xn = (xn + x/xn)/2.;
	}
	if (neg)
	   return -xn;
	else
	   return xn;
}
/*
      Reason 4        Input            Expected      Actual 
      the test                         output        output
      -----------------------------------------------------
      Test min
      value 0           0                0              0
      ----------------------------------------------------
      perfect sqare     4               2              2
      ---------------------------------------------------
      start value
      is too low        1              1              1.0003
	  --------------------------------------------------- 
	  non perfect
	    square          11            3.31           3.31672
	  --------------------------------------------------- 
*/

// Task 2
double quad(double a, double b, double c){
/*
   pre : a != 0,  b*b - 4*a*c >= 0
   post: returns r where r is the largest value such that a*r*r + b*r + c = 0
*/
	double r1;
	return (-b + squareRoot(b*b - 4.*a*c))/(2*a);
}
/*
      Reason 4        Input            Expected      Actual 
      the test      (a, b, c)           output        output
      -----------------------------------------------------
      two roots      1 0 -4              2               2       
      ----------------------------------------------------
      double root    1 4 4              -2               -2
      ---------------------------------------------------
      negative
      coefficients   -5 0 -2
	  --------------------------------------------------- 
	no real
      roots          1 2 4            crash            crash 
	  --------------------------------------------------- 
*/


int main(){
	double sqrVals[] = {0, 4, 1, 11};
	double a[]={1, 1, -5, 1};
	double b[]={0, 4, 0, 2};
	double c[]={-4, 4,-2, 3};
	for (int i = 0; i < 4; i++)
	   cout<< sqrVals[i]<<" square root is "<< squareRoot(sqrVals[i])<<endl;
	for (int i = 0; i < 4; i++)
	   cout<<"the largest root for "<<a[i]<<"x^2 + "<<b[i]<<"x + "<<c[i]<<" = "
	       <<quad(a[i],b[i],c[i])<<endl;
	return 0;
}
