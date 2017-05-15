/*
Name        : Eranus Thompson & Joel Fernandes
Description : A program that loads items into air planes and trains
from containers that have been unloaded from ships. It calculates
the total time it takes workers to load both the train and planes.
The time to load a train is 2 minutes * train number, from the
dock to a train and back. The time to load a plane is 10 minutes *
plane number, from the dock to a plane and back.
*/

#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>

using namespace std;

const int MAX = 5;

void loadTrain(int numT, int trainItem, queue <int>& trainQue);
void loadPlane(int numT, int planeItem, queue <int>& planeQue);
void calcTrain(queue <int> trainQue, stack <int> trainStack, int trainItems,
	vector <int>& trainTime, int curTime, vector <int> t_Items);
void calcPlane(queue <int> planeQue, int planeItems, vector <int>& planeTime,
	int curTime, vector <int> p_Items);
void printTrainTime(vector <int> trainTime);
void printPlaneTime(vector <int> planeTime);

int main() {

	int numTrains, numPlanes, numTrainItems, numPlanesItems;
	int items2Trains, items2Planes, curTime = 0;

	vector <int> numItems_T, numItems_P;
	vector <int> time_T, time_P;
	stack <int> trainItems;
	queue <int> queTrains;
	queue <int> planeItems;

	//Reading the number of trains, planes, and items to trains
	//and planes
	cin >> numTrains >> numPlanes >> numTrainItems >> numPlanesItems;

	//reading num of items 4 each trains
	for (int i = 0; i < numTrains; i++) {

		cin >> items2Trains;
		numItems_T.push_back(items2Trains);
	}

	//reading num of items 4 each planes
	for (int i = 0; i < numPlanes; i++) {

		cin >> items2Planes;
		numItems_P.push_back(items2Planes);
	}

	loadTrain(numTrainItems, items2Trains, queTrains);
	loadPlane(numPlanesItems, items2Planes, planeItems);

	//initializing the num of time 4 each train
	for (int i = 0; i < numTrains; i++) {

		time_T.push_back(0);
	}

	calcTrain(queTrains, trainItems, items2Trains, time_T, curTime, numItems_T);

	//initializing the num of time 4 each planes
	for (int i = 0; i < numPlanes; i++) {
		time_P.push_back(0);
	}

	calcPlane(planeItems, items2Planes, time_P, curTime, numItems_P);

	if (numTrains > 0 && numTrains < 100 && numTrainItems > 0) {

		printTrainTime(time_T);
	}
	cout << endl;

	if (numPlanes > 0 && numPlanes < 10 && numPlanesItems > 0) {

		printPlaneTime(time_P);
	}
	cout << endl;

	return 0;
}

void loadTrain(int numT, int trainItem, queue <int>& trainQue) {
	/*
	pre condition  : numT > 0 && numT < 100
	post condition : queing up each items into trainQue
	*/

	for (int i = 0; i < numT; i++) {

		cin >> trainItem;
		trainQue.push(trainItem);
	}
}

void loadPlane(int numP, int planeItem, queue <int>& planeQue) {
	/*
	pre condition  : numP > 0 && numT < 10
	post condition : queing up each items into planeQue
	*/

	for (int i = 0; i < numP; i++) {

		cin >> planeItem;
		planeQue.push(planeItem);
	}
}

void calcTrain(queue <int> trainQue, stack <int> trainStack, int trainItems,
	vector <int>& trainTime, int curTime, vector <int> t_Items) {
	/*
	pre condition  : !trainQue.empty(), trainTime >= 0,
	curTime >= 0, t_Items >= 0
	post condition : returns the total time for each train
	*/

	while (!trainQue.empty()) {	//stacking up each items 2 trains while the
								//queue isn't empty
		for (int i = 0; i < MAX; i++) {
			if (!trainQue.empty()) {
				trainItems = trainQue.front();
				trainQue.pop();
				trainStack.push(trainItems);
			}
		}

		while (!trainStack.empty()) {	//calculating the total time 4 each train

			trainItems = trainStack.top();
			trainStack.pop();

			t_Items[trainItems - 1]--;
			if (t_Items[trainItems - 1] == 0) {

				trainTime[trainItems - 1] = curTime + (2 * trainItems) / 2;
			}

			curTime += 2 * trainItems;
		}
	}
}

void calcPlane(queue <int> planeQue, int planeItems, vector <int>& planeTime,
	int curTime, vector <int> p_Items) {
	/*
	pre condition  : !planeQue.empty(), planeTime >= 0,
	curTime >= 0, p_Items >= 0
	post condition : returns the total time for each plane
	*/

	while (!planeQue.empty()) {	//calculating the total time 4 each plane

		planeItems = planeQue.front();
		planeQue.pop();

		p_Items[planeItems - 1]--;
		if (p_Items[planeItems - 1] == 0) {

			planeTime[planeItems - 1] = curTime + (10 * planeItems) / 2;
		}

		curTime += 10 * planeItems;
	}
}

void printTrainTime(vector <int> trainTime) {
	/*
	pre condition  : trainTime >= 0
	post condition : prints the total time for each train
	*/

	for (int i = 0; i < trainTime.size(); i++) {

		cout << trainTime[i] << " ";
	}
}

void printPlaneTime(vector <int> planeTime) {
	/*
	pre condition  : planeTime >= 0
	post condition : prints the total time for each plane
	*/

	for (int i = 0; i < planeTime.size(); i++) {

		cout << planeTime[i] << " ";
	}
}