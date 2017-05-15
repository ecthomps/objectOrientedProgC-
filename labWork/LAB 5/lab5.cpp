#include <iostream>
using namespace std;

class Vector
{
public:
	Vector(int s = 0)  // makes Size = s, 
		//allocates s space, 
		// makes all entries 0
	{
		size = s;
		entries = new int[s];
		for (int i = 0; i < s; i++)
			entries[i] = 0;
	}
	Vector(const Vector & rhs) // copy constructor
		// makes self a deep copy of rhs
	{
		size = rhs.size;
		entries = new int[rhs.size];
		for (int i = 0; i < size; i++)
			entries[i] = rhs.entries[i];
	}
	Vector operator = (const Vector & rhs)// makes self a deep copy of rhs
	{
		delete[] entries;
		size = rhs.size;
		entries = new int[rhs.size];
		for (int i = 0; i < size; i++)
			entries[i] = rhs.entries[i];
		return *this;
	}

	~Vector()     // default destructor
	{
		delete[] entries;
		size = 0;
	}
	int & operator[](int index) // if 0 <=pos<size
		// stores val at pos in entries
	{
		return entries[index];
	}
	int sz(){
		return size;
	}
private:
	int size;            //sets the # of elements used  
	int *entries;
};
ostream & operator<<(ostream & out, Vector  rhs){
	out << "[ ";
	for (int i = 0; i < rhs.sz() - 1; i++)
		out << rhs[i] << ',';
	if (rhs.sz() > 0)
		out << rhs[rhs.sz() - 1] << " ]";
	return out;
}

int main(){
	Vector test(10);
	Vector *vecPtr;
	Vector exam(5);
	for (int i = 0; i < test.sz(); i++){
		test[i] = i;
	}
	cout << "test initally is : ";
	cout << test << endl;

	cout << "empty Vector of length 5 is : ";
	cout << exam << endl;
	exam = test;
	cout << "after exam = test, exam  is : ";
	cout << exam << endl;
	{
		Vector sqrs(10);
		cout << "The squares are : ";
		for (int i = 0; i < sqrs.sz(); i++)
			sqrs[i] = i*i;
		vecPtr = &sqrs;
		cout << sqrs << endl;
	}
	cout << "trying to print an empty vector: ";
	cout << *vecPtr << endl;
	for (int i = 0; i < test.sz(); i++)
		test[i] = 10 - i;
	cout << "testing deep copy :\n";
	cout << "test is now : ";
	cout << test << endl;
	cout << "exam is now : ";
	cout << exam << endl;
	return 0;
}