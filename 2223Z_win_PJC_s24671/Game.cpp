#include "Game.h"
#include "iostream"
#include "Monster.h"
#include <algorithm>
using namespace std;


void Game::chooseLvl() {
    cout << "Wybierz poziom trudnosci (latwy/sredni/trudny)" << endl;
    string decyzja;
    cin >> decyzja;
    if(decyzja=="latwy"){
        hpBoostRatio=1.1;
        opponents=3;
        opponentsMonsters=3;
    } else if(decyzja=="sredni"){
        hpBoostRatio=1;
        opponents=4;
        opponentsMonsters=4;
    } else if(decyzja=="trudny"){
        hpBoostRatio=0.9;
        opponents=5;
        opponentsMonsters=5;
    }
    cout << "Wybrano poziom trudnosci : " << decyzja << endl;
    cout << endl;
}

void Game::startGame() {

    chooseLvl();
    cout << "Gra rozpoczeta, wybierz 6 postaci do swojej druzyny"<< endl;
    pickPlayersTeam();

    for (int i = 1; i <= rounds; ++i) {
        cout << "Runda : " << i << endl;
        for (int j = 1; j <= opponents; ++j) {
            cout << endl;
            if(i!=1 || j!=1){
                cout << "Gratuluje! Pokonales przeciwnika. Zostalo dodane " << 100*hpBoostRatio << "hp do kazdej twojej postaci ktora miala ponizej 50 puntkow zycia";
            }
            pickOpponentsTeam();
            cout << "Przeciwnik : " << j << endl;
            fight();
            if (!x.isTeamAlive(*playersTeam)) {
                j=opponents+1;
                i=rounds+1;
                cout << "PRZEGRALES! Twoja druzyna nie zyje." << endl;
            } else if(i==rounds && j==opponents){
                cout << "BITWA WYGRANA!, Pokonales wszystkich przeciwnikow!" << endl;
            }
        }
    }

}

int Game::findID(vector<Monster> monster, string decyzja) {
    vector<string> pomoc{};
    for (int i = 0; i < monster.size(); ++i) {
        pomoc.push_back(monster.at(i).getName());
    }
    auto it=find(pomoc.begin(),pomoc.end(),decyzja);
    int index=it-pomoc.begin();
    return index;
}

void Game::pickPlayersTeam() {
    Monster add;
    showInteractions();
    cout << endl;
    showAllMonsters();
    for (int i = 0; i < 6; ++i) {
        string decyzja;
        cout << "Wybierz postac numer " << i+1 << ": " << endl;
        cin >> decyzja;
        int index= findID(characterPool,decyzja);
        add=characterPool.at(index);
        playersTeam->push_back(add);
    }
    printYourTeam();
}

void Game::showInteractions() {
    cout << "Oddzialywanie miedzy typami potworow" << endl;
    cout << endl;
    cout << "Atakujacy  fire   water   ice   air   steel   land" << endl;
    cout << "water      good   bad     med   med   med     good " << endl;
    cout << "land       good   med     good  bad   good    med " << endl;
    cout << "air        med    med     good  med   bad     bad " << endl;
    cout << "fire       med    bad     good  med   good    bad " << endl;
    cout << "ice        bad    bad     bad   med   med     good " << endl;
    cout << "steel      bad    good    med   good  bad     med " << endl;

}

void Game::pickOpponentsTeam() {
    Monster add;
    int x;
    srand(time(NULL));
    for (int i = 0; i < opponentsMonsters; ++i) {
        x=rand()%characterPool.size();
        opponentsTeam->push_back(characterPool.at(x));
    }
    printOpponentsTeam();
}

void Game::printYourTeam() {
    cout << "Twoj sklad: " << endl;
    for (int i = 0; i < playersTeam->size(); ++i) {
        cout << playersTeam->at(i) << endl;
    }
    cout << endl;
}

void Game::printOpponentsTeam() {
    cout << endl;
    cout << "Sklad twojego przeciwnika: " << endl;
    for (int i = 0; i < opponentsTeam->size(); ++i) {
        cout << opponentsTeam->at(i) << endl;
    }
    cout << endl;
}

void Game::setSpecialPowerUsedToZero() {
    for (int i = 0; i < playersTeam->size(); ++i) {
        playersTeam->at(i).setSpecialPowerWasUsed(0);
    }
}

void Game::boostHP() {
    for (int i = 0; i < playersTeam->size(); ++i) {
        playersTeam->at(i).hpBoost(hpBoostRatio);
    }
}

void Game::showAllMonsters() {
    cout << "Lista potworow ktore mozesz wybrac do druzyny to : " << endl;
    cout << "   Nazwa  Sila  AtakSpecjalny  Zrecznosc  HP      TypPostaci" << endl;
    for (int i = 0; i < characterPool.size(); ++i) {
        cout >> characterPool.at(i);
    }
}

void Game::fight() {
    bool running=true;
    int index;
    string decyzja;
    boostHP();
    cout << "Wybierz index twojej postaci " << endl;
    cin >> index;
    setSpecialPowerUsedToZero();
    Monster playersMonster=playersTeam->at(index-1);
    int x=rand()%opponentsTeam->size();
    Monster opponentsMonster=opponentsTeam->at(x);

    while(running){

        if(playersMonster.getHp()<=0 && decyzja!="C"){
            playersMonster.setHp(0);
            playersTeam->at(index-1)=playersMonster;
            cout << "Twoja postac nie zyje, trzeba ja zmienic" << endl;
            decyzja="Z";
        } else {
            cout << "[AS] - atak specjalny , [A] - atak , [Z] - zmiana postaci , [E] - ewolucja postaci" << endl;
            cout << "Twoj ruch : ";
            cin >> decyzja;
            if(decyzja=="AS" && !playersMonster.tryToUseSpecialPower()){
                decyzja="A";
                cout << "Uzyto zwyklego ataku, wykorzystales limit atakow specjalnych tej postaci w tej walce" << endl;
            }
        }

        if(decyzja=="E" || decyzja=="e"){
            if(playersMonster.levelUpIsAvailable()) {
                playersMonster.levelUp();
                playersMonster.chooseLevelUp();
                cout << "[AS] - atak specjalny , [A] - atak , [Z] - zmiana postaci , [E] - ewolucja postaci" << endl;
                cout << "Twoj ruch : ";
            } else {
                cout << "Nie mozna ewoluowac postaci, wybierz inna opcje" << endl;
                cin >> decyzja;
            }
        }  if(decyzja=="AS" || decyzja=="as"){
            playersMonster.tryToSpecialAttack(opponentsMonster);
        }  if(decyzja=="Z" || decyzja=="z"){
            cout << "Wprowadz index postaci na ktora chcesz sie zmienic: " << endl;
            cin >> index;
            playersMonster=playersTeam->at(index-1);
            cout << "Zmieniono sie na: " << playersMonster << endl;
        }  if(decyzja=="A" || decyzja=="a"){
            playersMonster.tryToAttack(opponentsMonster);
        }
//        if(decyzja=="help" || decyzja=="HELP"){
//            cout << ""
//        }

        cout << "Postac przeciwnika to: " << opponentsMonster << endl;

        if(opponentsMonster.getHp()<=0 && opponentsTeam->size()!=1){
            playersMonster.increaseExpValue(opponentsMonster);
            *opponentsTeam=opponentsMonster.deleteMonster(*opponentsTeam,x);
            x=rand()%opponentsTeam->size();
            opponentsMonster=opponentsTeam->at(x);
            cout << "Przeciwnik zmienil postac na: " << opponentsMonster << endl;
        } else if(opponentsMonster.getHp()>0){
            opponentsMonster.tryToAttack(playersMonster);
        } else if(opponentsMonster.getHp()<=0 && opponentsTeam->size()==1){
            *opponentsTeam=opponentsMonster.deleteMonster(*opponentsTeam,x);
        }

        playersTeam->at(index-1)=playersMonster;
        if(!opponentsTeam->empty()){
            opponentsTeam->at(x)=opponentsMonster;
        }

        printYourTeam();

        if(opponentsTeam->empty()){
            running=false;
            cout << "Druzyna twojego przeciwnika nie zyje, wygrales" << endl;
        }

        if(!playersMonster.isTeamAlive(*playersTeam)){
            running=false;
        }


    }
}
