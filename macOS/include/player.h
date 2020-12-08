#ifndef PLAYER_H
#define PLAYER_H

#include "pokemon.h"
#include "Database.h"

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
        void SetPos(int x, int y);
        //포켓몬
        CatchedPokemon*GetPokemon(int ind);
        void SetPokemon(string name);

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
      //bool liveState;

public:
    OtherPlayer();
    //void setLiveState(bool _liveState);
    //bool getLiveState();
};
#endif
