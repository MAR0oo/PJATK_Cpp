#ifndef INC_2223Z_WIN_PJC_S24671_MONSTER_H
#define INC_2223Z_WIN_PJC_S24671_MONSTER_H
#include <iostream>
#include <vector>
using namespace std;

class Monster {
protected:
    string name;
    int power;
    int cunning;
    int hp;
    string specialPowerName;
    int specialPower;
    int timesSpecialPowerCanBeUsed;
    int specialPowerWasUsed=0;
    int XP;
    int XPToLvlUp;
    int expAfterDeath;
    int skillLvl;
    double influenceRatio;
    string type;
public:
    void attackPower(Monster& monster);

    // Funckja ustala sile z jaka zostanie uderzony potwor podany w parametrze i odejmuje te sile od jego punktow zycia
    //@param monster - potwor ktory ma zostac uderzony

    void tryToAttack(Monster& monster);

    // Funckja sprawdza czy uda nam sie uderzyc potwora przeciwnika (moze zrobic unik, dzieki swojej zrecznosci)
    //@param monster - potwor ktory ma zostac uderzony

    void specialAttack(Monster& monster);
    void tryToSpecialAttack(Monster& monster);
    bool tryToUseSpecialPower();

    //Funckja sprawdza czy gracz moze uzyc specjalnego ataku czy zostal on juz wykorzystany
    //@return jesli nie wykorzystalismy wszystkich atakow specjalnych zwraca true ,wpp false

    string getName();
    int getHp();
    void setHp(const int x);
    void setSpecialPowerWasUsed(const int x);
    bool isTeamAlive(vector<Monster> monster);

    //Sprawdza czy wektor potworow podany jako parametr jeszcze zyje
    //@param monster - sprawdzany wektor
    //@return jesli ktorykolwiek z potworow w wektorze zyje to zwraca true, wpp false

    vector<Monster> deleteMonster(vector<Monster> Vector, const int x);

    //Usuwa potwora z wektora pod indeksem podanym jako parametr
    //@param Vector - wektor z ktorego usuwamy potwora
    //@param x - indeks z ktorego usuwamy
    //@return - zwraca zmodyfikowany wektor (bez usunietego potwora)

    void levelUp();
    void chooseLevelUp();

    //Daje zapytanie do gracza ktory atrybut chce ewoluowac w potworze

    bool levelUpIsAvailable();
    void increaseExpValue(Monster& monster);

    //Sprawdza ile potwor podany jako parametr oddaje XP po smierci a nastepnie dodaje to wartosc
    // do obecnej ilosci XP dla potwora na ktorym zostala wykonana
    //@param monster - potwor z ktorego pobiera wartosc XP po smierci

    void hpBoost(const double x);

    //Funckja zwieksza wartosc hp potwora, jesli jest ono ponizej 50
    //@param x - wspolczynnik ktory definiuje ile hp powinno zostac dodane do potwora

    void setInfluenceRatio(const Monster& monster);

    //funckja ustawia jak poszczegolne potwory na siebie oddzialuja
    //@param monster - potwor na ktorego bedzie chcial oddzialywac potwor na ktorym wywolujemy funckje

    friend ostream& operator<<(ostream& o, const Monster &monster);
    friend ostream& operator>>(ostream& o, const Monster &monster);

};

class Yoder : public Monster {
public:
    Yoder(){
        this->name="Yoder";
        this->power=31;
        this->cunning=33;
        this->hp=160;
        this->specialPowerName="trzesienie ziemii";
        this->specialPower=75;
        this->timesSpecialPowerCanBeUsed=2;
        this->XP=0;
        this->XPToLvlUp=200;
        this->expAfterDeath=250;
        this->skillLvl=1;
        this->type="land";
    }
};

class Ochoa : public Monster{
public:
    Ochoa(){
        this->name="Ochoa";
        this->power=66;
        this->cunning=18;
        this->hp=160;
        this->specialPowerName="ognisko smierci";
        this->specialPower=96;
        this->timesSpecialPowerCanBeUsed=1;
        this->XP=0;
        this->XPToLvlUp=250;
        this->expAfterDeath=400;
        this->skillLvl=1;
        this->type="fire";
    }
};

class Colon : public Monster{
public:
    Colon(){
        this->name="Colon";
        this->power=56;
        this->cunning=28;
        this->hp=170;
        this->specialPowerName="wystrzal z lopaty";
        this->specialPower=89;
        this->timesSpecialPowerCanBeUsed=1;
        this->XP=0;
        this->XPToLvlUp=150;
        this->expAfterDeath=250;
        this->skillLvl=1;
        this->type="steel";
    }
};

class Enzo : public Monster{
public:
    Enzo(){
        this->name="Enzo";
        this->power=90;
        this->cunning=69;
        this->hp=120;
        this->specialPowerName="kula lodowa";
        this->specialPower=95;
        this->timesSpecialPowerCanBeUsed=3;
        this->XP=0;
        this->XPToLvlUp=300;
        this->expAfterDeath=600;
        this->skillLvl=1;
        this->type="ice";
    }
};

class Oneal : public Monster{
public:
    Oneal(){
        this->name="Oneal";
        this->power=60;
        this->cunning=32;
        this->hp=145;
        this->specialPowerName="tornado";
        this->specialPower=98;
        this->timesSpecialPowerCanBeUsed=1;
        this->XP=0;
        this->XPToLvlUp=200;
        this->expAfterDeath=300;
        this->skillLvl=1;
        this->type="air";
    }
};

class Atkinson : public Monster{
public:
    Atkinson(){
        this->name="Atkinson";
        this->power=63;
        this->cunning=28;
        this->hp=150;
        this->specialPowerName="wir wodny";
        this->specialPower=90;
        this->timesSpecialPowerCanBeUsed=1;
        this->XP=0;
        this->XPToLvlUp=200;
        this->expAfterDeath=150;
        this->skillLvl=1;
        this->type="water";
    }
};

class Ortiz : public Monster{
public:
    Ortiz(){
        this->name="Ortiz";
        this->power=34;
        this->cunning=28;
        this->hp=190;
        this->specialPowerName="ogniowy miecz";
        this->specialPower=75;
        this->timesSpecialPowerCanBeUsed=2;
        this->XP=0;
        this->XPToLvlUp=350;
        this->expAfterDeath=300;
        this->skillLvl=1;
        this->type="fire";
    }
};

class Ingram : public Monster{
public:
    Ingram(){
        this->name="Ingram";
        this->power=41;
        this->cunning=17;
        this->hp=185;
        this->specialPowerName="ostry pret";
        this->specialPower=80;
        this->timesSpecialPowerCanBeUsed=2;
        this->XP=0;
        this->XPToLvlUp=200;
        this->expAfterDeath=300;
        this->skillLvl=1;
        this->type="steel";
    }
};

class Mccarty : public Monster{
public:
    Mccarty(){
        this->name="Mccarty";
        this->power=57;
        this->cunning=24;
        this->hp=160;
        this->specialPowerName="ruchome piaski";
        this->specialPower=95;
        this->timesSpecialPowerCanBeUsed=1;
        this->XP=0;
        this->XPToLvlUp=150;
        this->expAfterDeath=200;
        this->skillLvl=1;
        this->type="land";
    }
};

class Marianne : public Monster{
public:
    Marianne(){
        this->name="Marianne";
        this->power=60;
        this->cunning=32;
        this->hp=110;
        this->specialPowerName="morozacy oddech";
        this->specialPower=96;
        this->timesSpecialPowerCanBeUsed=1;
        this->XP=0;
        this->XPToLvlUp=100;
        this->expAfterDeath=300;
        this->skillLvl=1;
        this->type="ice";
    }
};

class Gibbs : public Monster{
public:
    Gibbs(){
        this->name="Gibbs";
        this->power=64;
        this->cunning=21;
        this->hp=160;
        this->specialPowerName="tsunami";
        this->specialPower=88;
        this->timesSpecialPowerCanBeUsed=2;
        this->XP=0;
        this->XPToLvlUp=200;
        this->expAfterDeath=150;
        this->skillLvl=1;
        this->type="water";
    }
};

class Zoet : public Monster{
public:
    Zoet(){
        this->name="Zoet";
        this->power=55;
        this->cunning=27;
        this->hp=185;
        this->specialPowerName="stalowy mlotek";
        this->specialPower=80;
        this->timesSpecialPowerCanBeUsed=2;
        this->XP=0;
        this->XPToLvlUp=300;
        this->expAfterDeath=400;
        this->skillLvl=1;
        this->type="steel";
    }
};

class Glover : public Monster{
public:
    Glover(){
        this->name="Glover";
        this->power=46;
        this->cunning=22;
        this->hp=190;
        this->specialPowerName="miecz z lawy";
        this->specialPower=70;
        this->timesSpecialPowerCanBeUsed=3;
        this->XP=0;
        this->XPToLvlUp=200;
        this->expAfterDeath=350;
        this->skillLvl=1;
        this->type="fire";
    }
};

class Castro : public Monster{
public:
    Castro(){
        this->name="Castro";
        this->power=50;
        this->cunning=19;
        this->hp=175;
        this->specialPowerName="chmura grawitacyjna";
        this->specialPower=85;
        this->timesSpecialPowerCanBeUsed=2;
        this->XP=0;
        this->XPToLvlUp=350;
        this->expAfterDeath=150;
        this->skillLvl=1;
        this->type="air";
    }
};

class Allen : public Monster{
public:
    Allen(){
        this->name="Allen";
        this->power=68;
        this->cunning=21;
        this->hp=145;
        this->specialPowerName="spadajace sople lodu";
        this->specialPower=95;
        this->timesSpecialPowerCanBeUsed=1;
        this->XP=0;
        this->XPToLvlUp=300;
        this->expAfterDeath=150;
        this->skillLvl=1;
        this->type="ice";
    }
};


#endif //INC_2223Z_WIN_PJC_S24671_MONSTER_H
