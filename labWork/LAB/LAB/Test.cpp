#include <iostream>
#include <vector>
using namespace std;
void printVec(vector<int> vec) {
	for (auto x : vec) {
		cout << x << " ";
	}
	cout << endl;
}
void selectionSort(vector<int> & vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[i] > vec[j])   // 1 + 2 + 3 + ... n = n(n+1)/2 = O(n^2)
				swap(vec[i], vec[j]);
		}
		printVec(vec);
	}
}
int main() {
	vector<int> vec = { 10, 5, 3, 2, 4, 8, 7, 1, 6, 9 };
	selectionSort(vec);
	return 0;
}
