#ifndef PLAYER_H
#define PLAYER_H

#include"../include/pokemon.h"
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
public:
    MyPlayer()
    {
        this->name = "Me";
        this->pos.x = 0;
        this->pos.y = 0;
        SetPlayerType(true);
    }
    //std::vector<Item*> items;

    //MonsterBallItem MonsterBallItem;
    //HPRecoveryItem HPRecoveryItem0;
    //HPRecoveryItem HPRecoveryItem1;

    //void setItems()
    //{
    //    MonsterBallItem.HyperBall();
    //    items.push_back(&MonsterBallItem);

    //    HPRecoveryItem0.HyperPotion();
    //    items.push_back(&HPRecoveryItem0);

    //    HPRecoveryItem1.MaxPotion();
    //    items.push_back(&HPRecoveryItem1);
    //}
};

class OtherPlayer : public Player
{
public:
    OtherPlayer()
    {
        this->name = "ROSA";
        //this->pos.x = 0;
        //this->pos.y = 0;
        SetPlayerType(false);
    }
};

#endif
