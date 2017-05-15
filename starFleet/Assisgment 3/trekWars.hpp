#ifndef  trekWars_hpp
#define trekWars_hpp

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum Alignment {us, them, chaotic};

class Ship{

private:
    string name;
    Alignment align;
    int xLoc;
    int yLoc;
    int range;
    int currHealth;
    int attackPower;
    int maxHealth;

    string virtual getType(){ return "Ship";}
protected:
    void setX(int x) { xLoc += x;}
    void setY(int y) { yLoc += y;}

public:

    Ship();
    Ship(string name1, int xLoc1, int yLoc1, Alignment align1, int maxHealth1, int range1, int attackPower1):
    name(name1), xLoc(xLoc1), yLoc(yLoc1), align(align1), maxHealth(maxHealth1), range(range1), attackPower(attackPower1), currHealth(maxHealth1){}

    void virtual attack(Ship *target) = 0;
    
    int getX(){
        return xLoc;
    }

    int getY(){
        return yLoc;
    }

    Alignment getAlign(){
        return align;
    }

    void virtual move(){

         if (currHealth < maxHealth){
            currHealth++;
        }
    }

    void changeAlign(){
    if (align != chaotic){
        align = (align == us) ? them : us;  // ? them > us ? us > them
        }
    }

    void accessDamage( int amt){
        currHealth -= amt;
    }

    int getRange(){
        return range;
    }

    int getHealth(){

       return currHealth;
       
    }

    int getAttackPower(){
    return attackPower;
    }

    virtual string status(){
        currHealth = (currHealth < 0) ? 0 : currHealth;
        return "Name " + name +
               "\nType " + getType() +
               "\nHealth: " + to_string(currHealth) +
               "\nLocation: (" + to_string(xLoc) + " ," + to_string(yLoc) + ")\n";
    }

    int getRangeBtwShip(Ship *target) {

        return static_cast<int>((sqrt(pow(getX() - target->getX(), 2) + pow(getY() - target->getY(), 2))));
        //floor & cieling ????
    }

    void setHealthToMax(){
        currHealth = maxHealth;
    }

};




class Battle : public Ship {
private:
    int torpedoes;

public:
    Battle() : Ship() {}
    Battle(string name1, int xLoc1, int yLoc1, Alignment align1) : 
    Ship(name1, xLoc1, yLoc1, align1, 100, 10, 10 ), torpedoes(10) {}

    void attack(Ship *target) {

       if (target->getHealth() > 0  && this->getHealth() > 0){
        if ((getAlign() == chaotic || (getAlign() + target->getAlign()) == 1) &&
            getRangeBtwShip(target) <= getRange()) {
                if(torpedoes){
                    target->accessDamage(2 * getAttackPower());
                    torpedoes--;
                }
                else{
                    target->accessDamage(getAttackPower());
                }
            }
        }
    }


    string status() {
        return Ship::status() + "Torpedoes: " + to_string(torpedoes) + "\n";
    }
    void move() {
        if (this->getHealth() > 0){
        setX(-1);
        setY(-1);
        }
    }

     string getType(){
        return "Battle ship";
    }
};

class Cruiser:public Ship{
public:
    Cruiser(string name1, int xLoc1, int yLoc1, Alignment align1) :
        Ship(name1, xLoc1, yLoc1, align1,50, 50 , 5) {}


    Cruiser(string name1, int xLoc1, int yLoc1, Alignment align1, int maxHealth1, int range1) :
        Ship(name1, xLoc1, yLoc1, align1, maxHealth1, range1, 5) {}

    void attack(Ship *target) {
        if (target->getHealth() > 0 && this->getHealth() > 0) {
        if (getAlign() == chaotic || (getAlign() + target->getAlign()) == 1 &&
            getRangeBtwShip(target) <= getRange()) {
            target->accessDamage(getAttackPower());
            }
        }
    }

    void move() {
       if(this->getHealth() > 0){
        setX(1);
        setY(2);
       }
    }

     string getType() {
        return "Cruiser ship";
    }

};

class Corvette :public Ship {
public:
    Corvette(string name1, int xLoc1, int yLoc1, Alignment align1) :
        Ship(name1, xLoc1, yLoc1, align1, 20, 25, 0) {}

    void attack(Ship *target) {
     if (target->getHealth() <= 0 && this->getHealth() > 0) {
        if (getRangeBtwShip(target) <= getRange()) {
            target->changeAlign();
        }
    }
  }
    void move() {
  if (this->getHealth() > 0){
        setX(5);
        setY(5);
        }
    }

    string getType() {
        return "Corvette ship";
    }

};

class Repair :public Cruiser {
public:
    Repair(string name1, int xLoc1, int yLoc1, Alignment align1) :
        Cruiser(name1, xLoc1, yLoc1, align1,20, 25)  {}
    


    void attack(Ship *target) {
      if (target->getHealth() <= 0 && this->getHealth() > 0) {
        if (((getAlign() == target->getAlign())) &&
            getRangeBtwShip(target) <= getRange()) {
            target->setHealthToMax();
        }
      }
    }
 
    string getType() {
        return "Repair ship";
    }

};

//Unit Testing
class UnitTest {
public:
    bool BattleShip_UnitTest() const;                       // Battleship unit test
    bool CruiserShip_UnitTest() const;                      // Cruiser unit test
    bool CorvetteShip_UnitTest() const;                     // Corvette unit test
    bool RepairShip_UnitTest() const;                       // Repair unit test

};

inline bool UnitTest::BattleShip_UnitTest() const {
    Ship ** fleet;
    int numShip;
    numShip = 8;

    /* ========================== Battle Ship Unit Test 1 ========================== */
    // Move and attack within range with two battleship.
    fleet = new Ship *[numShip];
    fleet[0] = new Battle("Constitution", 2, 2, us);
    fleet[1] = new Battle("BoatyMcBoatFace", 4, 2, them);

    fleet[0]->move();
    fleet[1]->move();
    fleet[0]->attack(fleet[1]);
    fleet[1]->attack(fleet[0]);

/*   Name Constitution
     Type Battle ship
     Health: 80
     Location: (1 ,1)
     Torpedoes :  9
    
     Name BoatyMcBoatFace
     Type Battle ship
     Health: 80
     Location: (3 ,1)
     Torpedoes :  9
*/

    if(fleet[0]->getHealth() != 80 || fleet[0]->getX() != 1 || fleet[0]->getY() != 1 || fleet[0]->getRange() != 10 ||
        fleet[1]->getHealth() != 80 || fleet[1]->getX() != 3 || fleet[1]->getY() != 1 || fleet[1]->getRange() != 10){
        cout << "Battle ship of Unit Test 1 Failed." << endl;
        return false;
    }
    /* ========================== Battle Ship Unit Test 2 ========================== */
    // Move and attack out of range with two battleship.
    fleet[2] = new Battle("1000Falcon", 2, 2, us);
    fleet[3] = new Battle("DocMcStuffings", 13, 2, them);

    fleet[2]->move();
    fleet[3]->move();
    fleet[2]->attack(fleet[3]);
    fleet[3]->attack(fleet[2]);

/*  Name 1000Falcon
    Type Battle ship
    Health: 100
    Location: (1 ,1)
    Torpedoes: 10

    Name DocMcStuffings
    Type Battle ship
    Health: 100
    Location: (12 ,1)
    Torpedoes: 10
*/
    
    if (fleet[2]->getHealth() != 100 || fleet[2]->getX() != 1 || fleet[2]->getY() != 1 || fleet[2]->getRange() != 10 ||
        fleet[3]->getHealth() != 100 || fleet[3]->getX() != 12 || fleet[3]->getY() != 1 || fleet[3]->getRange() != 10) {
        cout << "Battle ship of Unit Test 2 Failed." << endl;
        return false;
    }
    /* ========================== Battle Ship Unit Test 3 ========================== */
    // BoatyMcBoatFace attack Titanic, Titanic attack allies and chaotic (cannot attack your allies and chaotic).
    fleet[4] = new Battle("BoatyMcBoatFace", 4, 4, chaotic);
    fleet[5] = new Battle("Titanic",6, 4, us);
    fleet[6] = new Battle("1000 Falcon X2", 2, 2, us);

    fleet[4]->attack(fleet[5]);
    fleet[5]->attack(fleet[4]);
    fleet[5]->attack(fleet[6]);
/*  Name Titanic
    Type Battle ship
    Health: 80
    Location: (6 ,4)
    Torpedoes: 10

    Name BoatyMcBoatFace
    Type Battle ship
    Health: 100
    Location: (4 ,4)
    Torpedoes: 9

    Name 1000Falcon X2
    Type Battle ship
    Health: 100
    Location: (2 , 2)
    Torpedoes: 10
*/
    if (fleet[5]->getHealth() != 80 || fleet[5]->getX() != 6 || fleet[5]->getY() != 4 || fleet[5]->getRange() != 10 ||
        fleet[4]->getHealth() != 100 || fleet[4]->getX() != 4 || fleet[4]->getY() != 4 || fleet[4]->getRange() != 10 ||
        fleet[6]->getHealth() != 100 || fleet[6]->getX() != 2 || fleet[6]->getY() != 2 || fleet[6]->getRange() != 10) {
        cout << "Battle ship of Unit Test 3 Failed." << endl;
        return false;
    }

    /* ========================== Battle Ship Unit Test 4 ========================== */
    // BoatyMcBoatFace use all Torpedoes on Titanic & 1000 Falcon X2 and the frist shot on next ship does 10 dmg.
    fleet[4] = new Battle("BoatyMcBoatFace", 4, 4, chaotic);
    fleet[5] = new Battle("Titanic", 6, 4, us);
    fleet[6] = new Battle("1000 Falcon X2", 2, 2, us);
    fleet[7] = new Battle("1000 Falcon X3", 4, 2, us);

    while (fleet[5]->getHealth() != 0) {    // 5 Torpedoes used until Titanic dies

        fleet[4]->attack(fleet[5]);
    }
    while (fleet[6]->getHealth() != 0) {    // 5 Torpedoes used until 1000 Falxon X2 dies

        fleet[4]->attack(fleet[6]);         // Attack once to see the 10 damage

    }
    fleet[4]->attack(fleet[7]);
/*   
    Name Titanic
    Type Battle ship
    Health: 0
    Location: (6 ,4)
    Torpedoes: 10

    Name 1000 Falcon X2
    Type Battle ship
    Health: 0
    Location: (2 ,2)
    Torpedoes: 10

    Name BoatyMcBoatFace
    Type Battle ship
    Health: 100
    Location: (4 ,4)
    Torpedoes: 0

    Name 1000 Falcon X3
    Type Battle ship
    Health: 90
    Location: (4 ,2)
    Torpedoes: 10
*/

    if (fleet[5]->getHealth() != 0 || fleet[5]->getX() != 6 || fleet[5]->getY() != 4 || fleet[5]->getRange() != 10 ||
        fleet[6]->getHealth() != 0 || fleet[6]->getX() != 2 || fleet[6]->getY() != 2 || fleet[6]->getRange() != 10 ||
        fleet[7]->getHealth() != 90 || fleet[7]->getX() != 4 || fleet[7]->getY() != 2 || fleet[7]->getRange() != 10 || fleet[4]->getAttackPower() != 10) {
        cout << "Battle ship of Unit Test 4 Failed." << endl;
        return false;
    }
    cout << "Battle Ship Testcases Passed " << endl;
    return true;

}

inline bool UnitTest::CruiserShip_UnitTest() const{
    Ship ** fleet;
    int numShip;
    numShip = 8;

    /* ========================== Cruiser Ship Unit Test 1 ========================== */
    // Move and attack within range with two Cruiser.
    fleet = new Ship *[numShip];
    fleet[0] = new Cruiser("Constitution", 2, 2, us);
    fleet[1] = new Cruiser("BoatyMcBoatFace", 4, 2, them);

    fleet[0]->move();
    fleet[1]->move();
    fleet[0]->attack(fleet[1]);
    fleet[1]->attack(fleet[0]);


/*
    Name Constitution
    Type Cruiser ship
    Health: 45
    Location: (3 ,4)

    Name BoatyMcBoatFace
    Type Cruiser ship
    Health: 45
    Location: (5 ,4)
*/

    if (fleet[0]->getHealth() != 45 || fleet[0]->getX() != 3 || fleet[0]->getY() != 4 || fleet[0]->getRange() != 50 ||
        fleet[1]->getHealth() != 45 || fleet[1]->getX() != 5 || fleet[1]->getY() != 4 || fleet[1]->getRange() != 50) {
        cout << "Cruiser of Unit Test 1 Failed." << endl;
        return false;
    }


    /* ========================== Cruiser Ship Unit Test 2 ========================== */
    // Move and attack out of range with two battleship.
    fleet[2] = new Cruiser("1000Falcon", 2, 2, us);
    fleet[3] = new Cruiser("DocMcStuffings", 53, 2, them);

    fleet[2]->move();
    fleet[3]->move();
    fleet[2]->attack(fleet[3]);
    fleet[3]->attack(fleet[2]);

/*
    Name 1000Falcon
    Type Cruiser ship
    Health: 50
    Location: (3 ,4)

    Name DocMcStuffings
    Type Cruiser ship
    Health: 50
    Location: (54 ,4)
*/

    if (fleet[2]->getHealth() != 50 || fleet[2]->getX() != 3 || fleet[2]->getY() != 4 || fleet[2]->getRange() != 50 ||
        fleet[3]->getHealth() != 50 || fleet[3]->getX() != 54 || fleet[3]->getY() != 4 || fleet[3]->getRange() != 50) {
        cout << "Cruiser of Unit Test 2 Failed." << endl;
        return false;
    }

    /* ========================== Cruiser Unit Test 3 ========================== */
    // BoatyMcBoatFace attack Titanic, Titanic attack allies and chaotic (cannot attack your allies and chaotic).
    fleet[4] = new Cruiser("BoatyMcBoatFace", 4, 4, chaotic);
    fleet[5] = new Cruiser("Titanic", 6, 4, us);
    fleet[6] = new Cruiser("1000 Falcon X2", 2, 2, us);

    fleet[4]->attack(fleet[5]);
    fleet[5]->attack(fleet[4]);
    fleet[5]->attack(fleet[6]);
/*
    Name BoatyMcBoatFace
    Type Cruiser ship
    Health: 50
    Location: (4 ,4)

    Name Titanic
    Type Cruiser ship
    Health: 45
    Location: (6 ,4)

    Name 1000 Falcon X2
    Type Cruiser ship
    Health: 50
    Location: (2 ,2)
*/
    if (fleet[4]->getHealth() != 50 || fleet[4]->getX() != 4 || fleet[4]->getY() != 4 || fleet[4]->getRange() != 50 ||
        fleet[5]->getHealth() != 45 || fleet[5]->getX() != 6 || fleet[5]->getY() != 4 || fleet[5]->getRange() != 50 ||
        fleet[6]->getHealth() != 50 || fleet[6]->getX() != 2 || fleet[6]->getY() != 2 || fleet[6]->getRange() != 50) {
        cout << "Cruiser of Unit Test 3 Failed." << endl;
        return false;
    }


    cout << "Cruiser Testcases Passed " << endl;
    return true;

}

inline bool UnitTest::CorvetteShip_UnitTest() const{
    Ship ** fleet;
    int numShip;
    numShip = 8;

    /* ========================== Corvette Unit Test 1 ========================== */
    // Move and attack within range with two Corvette 
    fleet = new Ship *[numShip];
    fleet[0] = new Corvette("Constitution", 2, 2, us);
    fleet[1] = new Corvette("BoatyMcBoatFace", 4, 2, them);

    fleet[0]->move();
    fleet[1]->move();
    fleet[0]->attack(fleet[1]);
    fleet[1]->attack(fleet[0]);


/*
    Name Constitution
    Type Corvette ship
    Health: 20
    Location: (7 ,7)

    Name BoatyMcBoatFace
    Type Corvette ship
    Health: 20
    Location: (9 ,7)
*/

    if (fleet[0]->getHealth() != 20 || fleet[0]->getX() != 7 || fleet[0]->getY() != 7 || fleet[0]->getRange() != 25 || fleet[0]->getAlign() != them ||
        fleet[1]->getHealth() != 20 || fleet[1]->getX() != 9 || fleet[1]->getY() != 7 || fleet[1]->getRange() != 25 || fleet[1]->getAlign() != us) {
        cout << "Corvette of Unit Test 1 Failed." << endl;
        return false;
    }

    /* ========================== Corvette Unit Test 2 ========================== */
    // Move and attack out of range with two Corvette.
    fleet[2] = new Corvette("1000Falcon", 2, 2, us);
    fleet[3] = new Corvette("DocMcStuffings", 28, 2, them);

    fleet[2]->move();
    fleet[3]->move();
    fleet[2]->attack(fleet[3]);
    fleet[3]->attack(fleet[2]);

/*
Name 1000Falcon
Type Corvette ship
Health: 20
Location: (7 ,7)

Name DocMcStuffings
Type Corvette ship
Health: 20
Location: (33 ,7)


*/

    if (fleet[2]->getHealth() != 20 || fleet[2]->getX() != 7 || fleet[2]->getY() != 7 || fleet[2]->getRange() != 25 || fleet[2]->getAlign() != us ||
        fleet[3]->getHealth() != 20 || fleet[3]->getX() != 33 || fleet[3]->getY() != 7 || fleet[3]->getRange() != 25 || fleet[3]->getAlign() != them) {
        cout << "Corvette of Unit Test 2 Failed." << endl;
        return false;
    }
    /* ========================== Corvette Unit Test 3 ========================== */
    // Titanic convert the BoatyMcBoatFace to us and BoatyMcBoatFace attack 1000 Falcon X2 (cannot attack your allies).
    fleet[4] = new Battle("BoatyMcBoatFace", 4, 4, us);
    fleet[5] = new Corvette("Titanic", 6, 4, them);
    fleet[6] = new Cruiser("1000 Falcon X2", 2, 2, them);

    fleet[5]->attack(fleet[4]);
    fleet[4]->attack(fleet[6]);
/*
Name 1000 Falcon X2
Type Cruiser ship
Health: 50
Location: (2 ,2)

Name BoatyMcBoatFace
Type Battle ship
Health: 100
Location: (4 ,4)
Torpedoes: 10
*/
    if (fleet[4]->getHealth() != 100 || fleet[4]->getX() != 4 || fleet[4]->getY() != 4 || fleet[4]->getRange() != 10 || fleet[4]->getAlign() != them ||
        fleet[6]->getHealth() != 50 || fleet[6]->getX() != 2 || fleet[6]->getY() != 2 || fleet[6]->getRange() != 50 || fleet[6]->getAlign() != them) {
        cout << "Corvette of Unit Test 3 Failed." << endl;
        return false;
    }


    cout << "Corvette Testcases Passed " << endl;
    return true;


}

inline bool UnitTest::RepairShip_UnitTest() const{
    Ship ** fleet;
    int numShip;
    numShip = 9;

    /* ========================== Repair Ship Unit Test 1 ========================== */
    // Constitution kills BoatyMcBoatFace and 1000Falcon heals BoatyMcBoatFace
    fleet = new Ship *[numShip];
    fleet[0] = new Battle("Constitution", 2, 2, us);
    fleet[1] = new Battle("BoatyMcBoatFace", 4, 2, them);
    fleet[2] = new Repair("1000Falcon", 3, 2, them);

    while (fleet[1]->getHealth() != 0) {    // 5 Torpedoes used until BoatyMcBoatFace dies

        fleet[0]->attack(fleet[1]);
    }

   

/*
    Name BoatyMcBoatFace
    Type Battle ship
    Health: 0
    Location: (4 ,2)
    Torpedoes: 10
*/

    if (fleet[1]->getHealth() != 0 || fleet[1]->getX() != 4 || fleet[1]->getY() != 2 || fleet[1]->getRange() != 10 || fleet[1]->getAlign() != them) {
        cout << "Repair ship of Unit Test 1 part 1 Failed." << endl;
        return false;
    }

    fleet[2]->attack(fleet[1]);

/*

    Name BoatyMcBoatFace
    Type Battle ship
    Health: 100
    Location: (4 ,2)
    Torpedoes: 10

*/

    if (fleet[1]->getHealth() != 100 || fleet[1]->getX() != 4 || fleet[1]->getY() != 2 || fleet[1]->getRange() != 10 || fleet[1]->getAlign() != them) {
        cout << "Repair ship of Unit Test 1 part 1 Failed." << endl;
        return false;
    }

    /* ========================== Repair ship Unit Test 2 ========================== */
    // Constitution kills BoatyMcBoatFace and 1000Falcon heals BoatyMcBoatFace but out of range :(
    fleet = new Ship *[numShip];
    fleet[0] = new Battle("Constitution", 2, 2, us);
    fleet[1] = new Battle("BoatyMcBoatFace", 4, 2, them);
    fleet[2] = new Repair("1000Falcon", 30, 2, them);

    while (fleet[1]->getHealth() != 0) {    // 5 Torpedoes used until BoatyMcBoatFace dies

        fleet[0]->attack(fleet[1]);
    }



    /*

    Name BoatyMcBoatFace
    Type Battle ship
    Health: 0
    Location: (4 ,2)
    Torpedoes: 10
    */

    if (fleet[1]->getHealth() != 0 || fleet[1]->getX() != 4 || fleet[1]->getY() != 2 || fleet[1]->getRange() != 10 || fleet[1]->getAlign() != them) {
        cout << "Repair ship of Unit Test 2 part 1 Failed." << endl;
        return false;
    }

    fleet[2]->attack(fleet[1]);

    /*
    Name BoatyMcBoatFace
    Type Battle ship
    Health: 0
    Location: (4 ,2)
    Torpedoes: 10

    */

    if (fleet[1]->getHealth() != 0 || fleet[1]->getX() != 4 || fleet[1]->getY() != 2 || fleet[1]->getRange() != 10 || fleet[1]->getAlign() != them) {
        cout << "Repair ship of Unit Test 2 part 2 Failed." << endl;
        return false;
    }


    /* ========================== Repair ship Unit Test 3 ========================== */
    // BoatyMcBoatFace kills Constitution and 1000Falcon heals Constitution but can't heal enemy ship
    fleet = new Ship *[numShip];
    fleet[0] = new Battle("Constitution", 2, 2, us);
    fleet[1] = new Battle("BoatyMcBoatFace", 4, 2, them);
    fleet[2] = new Repair("1000Falcon", 6, 2, them);

    while (fleet[0]->getHealth() != 0) {

        fleet[1]->attack(fleet[0]);
    }



    /*

    Name Constitution
    Type Battle ship
    Health: 0
    Location: (2 ,2)
    Torpedoes: 10

    */

    if (fleet[0]->getHealth() != 0 || fleet[0]->getX() != 2 || fleet[0]->getY() != 2 || fleet[0]->getRange() != 10 || fleet[0]->getAlign() != us) {
        cout << "Repair ship of Unit Test 3 part 1 Failed." << endl;
        return false;
    }

    fleet[2]->attack(fleet[0]);

    /*
    Name Constitution
    Type Battle ship
    Health: 0
    Location: (2 ,2)
    Torpedoes: 10

    */

    if (fleet[0]->getHealth() != 0 || fleet[0]->getX() != 2 || fleet[0]->getY() != 2 || fleet[0]->getRange() != 10 || fleet[0]->getAlign() != us) {
        cout << "Repair ship of Unit Test 3 part 2 Failed." << endl;
        return false;
    }


    cout << "Repair Testcases Passed " << endl;
    return true;

}
#endif // ! trekWars_hpp
