#ifndef PLAYER_H
#define PLAYER_H

#include"../include/pokemon.h"
#include <vector>

// 좌표
struct coord {
    int x;
    int y;
};

class Player {

    private:
        string name;//플레이어 이름
        coord pos; //좌표
        vector<Pokemon> pokemons;
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
        Pokemon *GetPokemon(int ind);
        void SetPokemon(int ind, string name);
        // 플레이어 타입 
        bool GetPlayerType();
        void SetPlayerType(bool type);
};

#endif
