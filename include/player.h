#ifndef PLAYER_H
#define PLAYER_H

#include "../include/pokemon.h"
#include "../DB/Database.h"

#include <thread>
#include "Item.h"
#include <vector>
#include <string>
using namespace std;
// 좌표
struct coord {
    int x;
    int y;
};

class Player {

    protected:
        string name;//플레이어 이름
        coord pos; //좌표
        vector<CatchedPokemon*> pokemons;
        // change Pokemon* -> CatchedPokemon*
        bool playerType;  //  관장인지 아닌지 구별 (관장은 false)

    public:
        Player();
        Player(string name);
        ~Player();
        //플레이어 이름
        string GetName();
        void SetName(string newName);
        //좌표
        coord GetPos();
        void SetPos(coord c);
        //포켓몬
        CatchedPokemon*GetPokemon(int ind);
        void SetPokemon(string name);
        // 플레이어 타입
        bool GetPlayerType();
        void SetPlayerType(bool type);
        // change : add function
        void SetPokemon();
        void SetPokemon(CatchedPokemon* pokemonPtr, int ind);
        vector<CatchedPokemon*> getPokemonsVector();

};

// change add some class
class MyPlayer : public Player
{
private:
    std::vector<Item*> items;

public:
    MyPlayer();
    ~MyPlayer();

    std::vector<Item*> getItems();
    Item* getItem(int ix);

    void initItems();
};

class OtherPlayer : public Player
{
private:
      bool liveState;

public:
    OtherPlayer();
    void setLiveState(bool _liveState);
    bool getLiveState();
};
#endif
