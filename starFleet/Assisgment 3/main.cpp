#include <iostream>
#include "trekWars.hpp"
#include "../../../../../../../../../Program Files (x86)/Microsoft Visual Studio 14.0/VC/UnitTest/include/CppUnitTestAssert.h"

using namespace std;

int main() {
//    Ship ** fleet;
///*    UnitTest battleship1;*/
//    int numShip;
//    //cout<<"How many ships do you want ?";
//    //in>> numShip;
//    numShip = 6;
//
//    fleet = new Ship *[numShip];
//    fleet[0] = new Battle("Constitution", 2, 2, us);
//    fleet[1] = new Battle("BoatyMcBoatFace", 4, 2, them);
//    fleet[2] = new Repair("1000Falcon", 6, 2, them);
//    fleet[3] = new Corvette("DocMcStuffings", 28, 2, them);
//
//    fleet[4] = new Battle("BoatyMcBoatFace", 4, 4, us);
//    fleet[5] = new Corvette("Titanic", 6, 4, them);
//    fleet[6] = new Cruiser("1000 Falcon X2", 2, 2, them);
//
//
//    while (fleet[1]->getHealth() != 0) {    
//
//        fleet[0]->attack(fleet[1]);
//    }
//
//    cout << fleet[1]->status() << endl;
//
//    while (fleet[2]->getHealth() != 0) {
//
//        fleet[0]->attack(fleet[2]);
//    }
//    cout << fleet[2]->status() << endl;
//
//    fleet[1]->attack(fleet[0]);
//
//    cout << fleet[0]->status() << endl;
//    fleet[1]->move();
//    cout << fleet[1]->status() << endl;
/*
    battleship1.BattleShip_UnitTest();
    battleship1.CorvetteShip_UnitTest();
    battleship1.CruiserShip_UnitTest();
    battleship1.RepairShip_UnitTest();*/

/*    fleet[0] = new Battle("Constitution", 0, 0, us);
    fleet[1] = new Cruiser("Enterprize", 20, 20, chaotic);
    fleet[2] = new Corvette("1000Falcon", 0, 5, us);
    fleet[3] = new Repair("DocMcStuffings", 2, 2, them);
    fleet[4] = new Battle("BoatyMcBoatFace", 10, 10, chaotic);
    fleet[5] = new Cruiser("Titanic", 15, 15, us);
//    for (int i = 0; i < numShip; i++) cout << fleet[i]->status() << endl;

    for (int i = 0; i < numShip; i++) fleet[i]->move();

//    for (int i = 0; i < numShip; i++) cout << fleet[i]->status() << endl;

    for (int i = 0; i < numShip; i++)
        for (int j = 0; j < numShip; j++)
            if (i != j && fleet[i]->getHealth()>0) //<< cannot attack self, and dead do not attack

                fleet[i]->attack(fleet[j]);
                
                
    for (int i = 0; i < numShip; i++) 
        cout << fleet[i]->status() << endl;*/
/*
    int ships = 10;
    Ship **inABottle;
    inABottle = new Ship*[ships];
    inABottle[0] = new Battle("usBattleShip", 20, 20, us);
    inABottle[1] = new Battle("themBattleShip", 50, 50, them);
    inABottle[2] = new Cruiser("usCruiser", 10, 10, us);
    inABottle[3] = new Cruiser("themCruiser", 25, 25, them);
    inABottle[4] = new Corvette("usCorvette", 0, 0, us);
    inABottle[5] = new Corvette("themCorvette", 40, 40, them);
    inABottle[6] = new Repair("usRepair", 15, 15, us);
    inABottle[7] = new Repair("themRepair", 30, 30, them);
    inABottle[8] = new Battle("chaoticBattleShip", 20, 20, chaotic);
    inABottle[9] = new Cruiser("chaoticCruiser", 0, 0, chaotic);

    for (int turn = 1; turn <= 10; turn++) {
        for (int attackerIndex = 0; attackerIndex < ships; attackerIndex++) {
            for (int targetIndex = 0; targetIndex < ships; targetIndex++) {
                inABottle[attackerIndex]->attack(inABottle[targetIndex]);
            }
            inABottle[attackerIndex]->move();
        }
    }
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(0, inABottle[0]->getHealth());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(16, inABottle[0]->getX());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(16, inABottle[0]->getY());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(int(us), int(inABottle[0]->getAlign()));

    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(95, inABottle[1]->getHealth());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(40, inABottle[1]->getX());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(40, inABottle[1]->getY());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(int(them), int(inABottle[1]->getAlign()));

    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(0, inABottle[2]->getHealth());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(13, inABottle[2]->getX());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(16, inABottle[2]->getY());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(int(us), int(inABottle[2]->getAlign()));

    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(45, inABottle[3]->getHealth());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(35, inABottle[3]->getX());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(45, inABottle[3]->getY());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(int(them), int(inABottle[3]->getAlign()));

    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(0, inABottle[4]->getHealth());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(15, inABottle[4]->getX());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(15, inABottle[4]->getY());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(int(us), int(inABottle[4]->getAlign()));

    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(20, inABottle[5]->getHealth());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(90, inABottle[5]->getX());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(90, inABottle[5]->getY());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(int(them), int(inABottle[5]->getAlign()));

    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(0, inABottle[6]->getHealth());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(16, inABottle[6]->getX());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(17, inABottle[6]->getY());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(int(us), int(inABottle[6]->getAlign()));

    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(15, inABottle[7]->getHealth());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(40, inABottle[7]->getX());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(50, inABottle[7]->getY());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(int(them), int(inABottle[7]->getAlign()));

    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(59, inABottle[8]->getHealth());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(10, inABottle[8]->getX());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(10, inABottle[8]->getY());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(int(chaotic), int(inABottle[8]->getAlign()));

    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(4, inABottle[9]->getHealth());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(10, inABottle[9]->getX());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(20, inABottle[9]->getY());
    Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(int(chaotic), int(inABottle[9]->getAlign()));

*/





    return 0;
}