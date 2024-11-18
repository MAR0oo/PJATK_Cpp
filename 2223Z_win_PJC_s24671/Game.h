#ifndef INC_2223Z_WIN_PJC_S24671_GAME_H
#define INC_2223Z_WIN_PJC_S24671_GAME_H
#include <vector>
#include "Monster.h"


class Game {
private:
    vector<Monster> characterPool{Yoder(),Ochoa(),Colon(),Enzo(),Marianne(),Zoet(),Allen(),Ingram(),
                                  Oneal(),Ortiz(),Castro(),Gibbs(),Mccarty(),Atkinson(),Glover()};

    //lokowanie wektora w pamieci
    vector<Monster> *playersTeam=new vector<Monster>;
    vector<Monster> *opponentsTeam=new vector<Monster>;

    Monster x;
    int rounds=4;
    int opponents;
    int opponentsMonsters;
    double hpBoostRatio;

public:
    Game(){
        try {
            startGame();
        } catch(...) {
            cout << endl;
            cout << "WYSTAPIL BLAD! , WPROWADZILES NIEPOPRAWNE DANE" << endl;
        }
    }
    void startGame();

    //Funckja ktora jest odpowiedzialna za cala rozgrywke

    void pickPlayersTeam();

    //Funkcja dzieki ktorej gracz moze wybrac swoja druzyne potworow

    void pickOpponentsTeam();

    //Funkcja losowo wybiera druzyne przeciwnika

    void fight();

    //Funckja odpowiada za przebieg walki miedzy graczem a przeciwnikiem

    void printYourTeam();

    //Funkcja wypisuje na konsoli druzyne gracza

    void printOpponentsTeam();

    //Funkcja wypisuje na konsoli druzyne przeciwnika

    void setSpecialPowerUsedToZero();

    //Funkcja ustawia ilosc uzytych specjalnych atakow na 0 (po skonczonej walce)

    void boostHP();

    //Funckja ktora podwyzsza hp wszystkim potworom ( ktore spelniaja warunek w funckji hpBoost w Monster) w druzynie gracza

    void chooseLvl();

    //Funkcja odpowiedzialna za wybor poziomu trudnosci przez gracza

    void showAllMonsters();

    //Funckja pokazujace dostepne potwory na poczatku gry

    int findID(vector<Monster> monster, string decyzja);

    //Funckja szuka indeksu postaci ktorej nazwa jest przekazana w parametrze
    //@param monster - wektor w ktorym funkcja szuka imiona postaci
    //@param decyzja - imie szukanej postaci
    //return zwraca indeks postaci

    void showInteractions();

    //Funckja pokazuje oddzialywania miedzy typami potworow

};

#endif //INC_2223Z_WIN_PJC_S24671_GAME_H
