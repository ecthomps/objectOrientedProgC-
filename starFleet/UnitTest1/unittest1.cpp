#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Assisgment 3/trekWars.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
            // TODO: Your test code here
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
            Assert::AreEqual(0, inABottle[0]->getHealth());
            Assert::AreEqual(16, inABottle[0]->getX());
            Assert::AreEqual(16, inABottle[0]->getY());
            Assert::AreEqual(int(us), int(inABottle[0]->getAlign()));

            Assert::AreEqual(95, inABottle[1]->getHealth());
            Assert::AreEqual(40, inABottle[1]->getX());
            Assert::AreEqual(40, inABottle[1]->getY());
            Assert::AreEqual(int(them), int(inABottle[1]->getAlign()));

            Assert::AreEqual(0, inABottle[2]->getHealth());
            Assert::AreEqual(13, inABottle[2]->getX());
            Assert::AreEqual(16, inABottle[2]->getY());
            Assert::AreEqual(int(us), int(inABottle[2]->getAlign()));

            Assert::AreEqual(45, inABottle[3]->getHealth());
            Assert::AreEqual(35, inABottle[3]->getX());
            Assert::AreEqual(45, inABottle[3]->getY());
            Assert::AreEqual(int(them), int(inABottle[3]->getAlign()));

            Assert::AreEqual(0, inABottle[4]->getHealth());
            Assert::AreEqual(15, inABottle[4]->getX());
            Assert::AreEqual(15, inABottle[4]->getY());
            Assert::AreEqual(int(us), int(inABottle[4]->getAlign()));

            Assert::AreEqual(20, inABottle[5]->getHealth());
            Assert::AreEqual(90, inABottle[5]->getX());
            Assert::AreEqual(90, inABottle[5]->getY());
            Assert::AreEqual(int(them), int(inABottle[5]->getAlign()));

            Assert::AreEqual(0, inABottle[6]->getHealth());
            Assert::AreEqual(16, inABottle[6]->getX());
            Assert::AreEqual(17, inABottle[6]->getY());
            Assert::AreEqual(int(us), int(inABottle[6]->getAlign()));

            Assert::AreEqual(15, inABottle[7]->getHealth());
            Assert::AreEqual(40, inABottle[7]->getX());
            Assert::AreEqual(50, inABottle[7]->getY());
            Assert::AreEqual(int(them), int(inABottle[7]->getAlign()));

            Assert::AreEqual(59, inABottle[8]->getHealth());
            Assert::AreEqual(10, inABottle[8]->getX());
            Assert::AreEqual(10, inABottle[8]->getY());
            Assert::AreEqual(int(chaotic), int(inABottle[8]->getAlign()));

            Assert::AreEqual(4, inABottle[9]->getHealth());
            Assert::AreEqual(10, inABottle[9]->getX());
            Assert::AreEqual(20, inABottle[9]->getY());
            Assert::AreEqual(int(chaotic), int(inABottle[9]->getAlign()));
		}

	};
}