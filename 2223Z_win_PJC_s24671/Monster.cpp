#include "Monster.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Monster::attackPower(Monster& monster) {
    this->setInfluenceRatio(monster);
    int attack= this->power * influenceRatio;
    monster.hp-=attack;
}

void Monster::tryToAttack(Monster &monster) {
    srand(time(NULL));
    int random=rand()%100;
    if(random>monster.cunning){
        this->attackPower(monster);
        cout << "Uderzono potwora" << endl;
    } else
        cout << "Potwor zrobil unik" << endl;
}

void Monster::specialAttack(Monster &monster) {
    this->setInfluenceRatio(monster);
    int attack=this->specialPower*influenceRatio;
    monster.hp-=attack;
}

bool Monster::tryToUseSpecialPower() {
    return this->specialPowerWasUsed < this->timesSpecialPowerCanBeUsed;
}

void Monster::tryToSpecialAttack(Monster &monster) {
    this->specialPowerWasUsed++;
    srand(time(NULL));
    int random=rand()%100;
    if(random>monster.cunning){
        this->specialAttack(monster);
        cout << "Uderzono potwora za pomoca specjalnego ataku : " << this->specialPowerName << endl;
    } else
        cout << "Potwor zrobil unik" << endl;
}

void Monster::setSpecialPowerWasUsed(const int x) {
    this->specialPowerWasUsed=x;
}

string Monster::getName() {
    return this->name;
}

int Monster::getHp() {
    return this->hp;
}

void Monster::setHp(const int x) {
    this->hp=x;
}


bool Monster::isTeamAlive(vector<Monster> monster) {
    bool alive=false;
    for (int i = 0; i < monster.size(); ++i) {
        if(monster.at(i).getHp()>0)
            alive=true;
    }
    return alive;
}

vector<Monster> Monster::deleteMonster(vector<Monster> Vector, const int x) {
    Vector.erase(Vector.begin()+x);
    return Vector;
}

void Monster::chooseLevelUp() {
    string decyzja;
    cout << "[AS] - atak specjalny , [A] - atak , [Z] - zrecznosc , [H] - hp" << endl;
    for (int i = 0; i < 2; ++i) {
        cin >> decyzja;
        if(decyzja=="AS"){
            this->specialPower*=1.5;
        }
        if(decyzja=="A"){
            this->power*=1.5;
        }
        if(decyzja=="Z"){
            this->cunning*=1.5;
        }
        if(decyzja=="H"){
            this->hp*=1.5;
        }
    }
}

void Monster::levelUp() {
    this->skillLvl+=1;
    this->XP-=XPToLvlUp;
}

bool Monster::levelUpIsAvailable() {
    return this->XP > this->XPToLvlUp;
}

void Monster::increaseExpValue(Monster &monster) {
    this->XP+=monster.expAfterDeath;
}

ostream& operator<<(ostream& o, const Monster &monster){
    return o << monster.name << ": " << monster.hp << " hp, " << monster.skillLvl << " skillLvl" << ", special power : " << monster.specialPowerWasUsed << "/" << monster.timesSpecialPowerCanBeUsed << ", typ : " << monster.type;
}

ostream& operator>>(ostream& o, const Monster &monster){
    return o << setw(8) << monster.name << setw(5) << monster.power << setw(11) << monster.specialPower << setw(13) << monster.cunning
             << setw(8) << monster.hp << setw(12) << monster.type << endl;
}


void Monster::hpBoost(const double x) {
    double ratio=100*x;
    if(this->hp<50)
        this->hp+=ratio;
}

void Monster::setInfluenceRatio(const Monster& monster) {
    influenceRatio=1;
    if(this->type=="water"){

        if(monster.type=="water")
            influenceRatio=0.75;
        if(monster.type=="land")
            influenceRatio=1.25;
        if(monster.type=="fire")
            influenceRatio=1.25;

    } else if(this->type=="land"){

        if(monster.type=="air")
            influenceRatio=0.75;
        if(monster.type=="fire")
            influenceRatio=1.25;
        if(monster.type=="ice")
            influenceRatio=1.25;
        if(monster.type=="steel")
            influenceRatio=1.25;

    } else if(this->type=="air"){

        if(monster.type=="land")
            influenceRatio=0.75;
        if(monster.type=="ice")
            influenceRatio=1.5;
        if(monster.type=="steel")
            influenceRatio=0.75;

    } else if(this->type=="fire"){

        if(monster.type=="water")
            influenceRatio=0.75;
        if(monster.type=="land")
            influenceRatio=0.75;
        if(monster.type=="ice")
            influenceRatio=1.25;
        if(monster.type=="steel")
            influenceRatio=1.25;

    } else if(this->type=="ice") {

        if (monster.type == "water")
            influenceRatio = 0.75;
        if (monster.type == "land")
            influenceRatio = 1.25;
        if (monster.type == "fire")
            influenceRatio = 0.75;
        if (monster.type == "ice")
            influenceRatio = 0.75;

    } else if(this->type=="steel") {

        if (monster.type == "water")
            influenceRatio = 1.25;
        if (monster.type == "air")
            influenceRatio = 1.25;
        if (monster.type == "fire")
            influenceRatio = 0.75;
        if (monster.type == "steel")
            influenceRatio = 0.75;

    }

}
