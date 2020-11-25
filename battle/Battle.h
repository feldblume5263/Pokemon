#pragma once

//#include <iostream>
#include <windows.h>
#include <conio.h> 
//#include <random>
#include <ctime>

#include "test.h"

#include "pokemon.h"

//enum KeyboardKey
//{
//    UP = 27,
//    DOWN = 80,
//    LEFT = 75,
//    RIGHT = 77,
//    SPACEBAR = 32,
//    ENTER = 13
//};


class Battle
{
private:
    MyPlayer* my_player = nullptr;
    OtherPlayer* other_player = nullptr;

    Pokemon* my_selected_pokemon = nullptr;
    Pokemon* other_selected_pokemon = nullptr;

    bool priority = true;
    bool endBattle = false;
    bool my_win = false;
    int  arrowKey = 0; // 0123 UDLR
    std::mt19937 mersenne;

    // locatoin for drawing
    const int my_pokemon_state_x = 59;
    const int my_pokemon_state_y = 31;
    const int other_pokemon_state_x = 85;
    const int other_pokemon_state_y = 16;
    const int message_x = 70;
    const int message_y = 50;



public:
    Battle(MyPlayer* _my_player, OtherPlayer* _other_player);
    Battle(MyPlayer* _my_player, Pokemon* _other_pokemon);

private:
    void startBattle();
    void startHunting();
    void display();
    void printHPbar(Pokemon* pokemon);
    void drawPokemon_emoji(Pokemon* pokemon, int place_x, int place_y);
    void drawPoekomon(Pokemon* pokemon, int place_x, int place_y);
    void pullPokemon();
    void selectAction();

    // fight
    void    selectMove();
    void    fight(Pokemon* myPokemon, Pokemon* otherPokemon, Skill& move);
    void    attack(Pokemon* attakingPokemon, Pokemon* defendingPokemon, Skill& move);
    int     setRandomMoveNumber();
    int     calculateDamage(Pokemon* attakingPokemon, Pokemon* defendingPokemon, Skill& move);
    float   checkSametypeAttackbonus(Pokemon* attakingPokemon, Skill& move);
    float   calculateType();
    float   checkHitSpot();
    int     getRandomNumber();
    void    checkAlive(Pokemon* pokemon);
    bool    checkPokemons(Player* player);
    // change
    void    changePokemon(MyPlayer* player);
    void    changePokemon(OtherPlayer* player);
    int     selectPokemon();
    void    checkSpeed();
    // bag
    void    selectBag();
    void    useItme(int ix);
    // run
    void    selectRun();


    // tool
    void gotoxy(int column, int line);
    bool getArrowkey(int& x1, int& y1);
    bool getEnterSpacebar();
    void printArrow(int& x, int& y);
    void printArrow_change(int& x, int& y);
    // 27ESC, 72Up 80Down 75Left 77Right  32Spacebar

};