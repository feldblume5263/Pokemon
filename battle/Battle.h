#pragma once
#include <iostream>
#include <windows.h>
#include "test.h"
#include <conio.h> // for kbhit
#include <random>
#include <ctime>


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

    int my_dialog_location[2] = { 5, 12 };
    int other_dialog_location[2] = { 40, 2 };

    int temp_x = 5;
    int temp_y = 15;

    std::mt19937 mersenne;

public:
    Battle(MyPlayer* _my_player, OtherPlayer* _other_player);
    Battle(MyPlayer* _my_player, Pokemon* _other_pokemon);

private:
    void startBattle();
    void startHunting();
    void display();
    void printHPbar(Pokemon* pokemon);
    void pullPokemon();
    void selectAction();

    // fight
    void    selectMove();
    void    fight(Pokemon* myPokemon, Pokemon* otherPokemon, Move& move);
    void    attack(Pokemon* attakingPokemon, Pokemon* defendingPokemon, Move& move);
    int     setRandomMoveNumber();
    int     calculateDamage(const Pokemon* const attakingPokemon, const Pokemon* const defendingPokemon, const Move& move);
    float   checkSametypeAttackbonus(const Pokemon* const attakingPokemon, const Move& move);
    float   calculateType();
    float   checkHitSpot();
    int     getRandomNumber();
    void    checkAlive(Pokemon* pokemon);
    bool    checkPokemons(const Player* const player);
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
    // 27ESC, 72Up 80Down 75Left 77Right  32Spacebar

};