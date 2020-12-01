#ifndef PLAYER_H
#define PLAYER_H

#include"../include/pokemon.h"

// 좌표
struct coord {
    int x;
    int y;
};

class Player {

    private:
        string name;//플레이어 이름
        coord pos; //좌표
        Pokemon pokemons[4]; //포켓몬 4개
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
        //Pokemon GetPokemons()  배열 전체를 반환
        //포켓몬 하나씩 반환
        Pokemon GetPokemon(int ind);
        //test
        void SetPokemon1(string name);
        void SetPokemon2(string name);
        void SetPokemon3(string name);
        void SetPokemon4(string name);
        // 플레이어 타입 
        bool GetPlayerType();
        void SetPlayerType(bool type);
};

#endif
