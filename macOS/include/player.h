#ifndef PLAYER_H
#define PLAYER_H

#include "../include/pokemon.h"
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
    MyPlayer()
    {
        this->name = "Me";
        this->pos.x = 0;
        this->pos.y = 0;
        SetPlayerType(true);

        initItems();
    }

    ~MyPlayer()
    {
        // todo : delete
    }

    std::vector<Item*> getItems()
    {
        return items;
    }

    Item* getItem(int ix)
    {
        return items[ix];
    }

    void initItems()
    {
        Item* monsterball = new Item("HyperBall");
        this->items.push_back(monsterball);

        Item* hppotion1 = new Item("HyperPotion");
        this->items.push_back(hppotion1);

        Item* hppotion2 = new Item("MaxPotion");
        this->items.push_back(hppotion2);

        //MonsterBallItem* monsterball = new MonsterBallItem("HyperBall");
        //this->items.push_back(monsterball);

        //HPRecoveryItem* hppotion1 = new HPRecoveryItem("HyperPotion");
        //this->items.push_back(hppotion1);

        //HPRecoveryItem* hppotion2 = new HPRecoveryItem("MaxPotion");
        //this->items.push_back(hppotion2);
    }
};

class OtherPlayer : public Player
{
private:
      bool liveState;

public:
    OtherPlayer()
    {
        this->name = "ROSA";
        //this->pos.x = 0;
        //this->pos.y = 0;
        SetPlayerType(false);
        setLiveState(true);
    }
    void setLiveState(bool _liveState);
    bool getLiveState();
};

#endif
