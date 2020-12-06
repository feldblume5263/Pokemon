#pragma once

#include "pokemon.h"
#include "player.h"

#include <random>
#include <conio.h>
#include <vector>
#include <windows.h>

enum KeyboardKey
{
    UP = 119,
    DOWN = 115,
    LEFT = 97,
    RIGHT = 100,
    SPACEBAR = 32,
    ENTER = 13,
    ESC = 27
};

// deseperate UI and battle algorithms.
// when other player are gonna change pokemon, Ask to me wheter change pokemon.

class Battle
{
private:
    MyPlayer* my_player = nullptr;
    OtherPlayer* other_player = nullptr;

    CatchedPokemon* my_selected_pokemon = nullptr;
    CatchedPokemon* other_selected_pokemon = nullptr;

    // state
    bool  hitSpot = false;
    float typeCal = 1.0f;
    bool  priority = true;
    bool  endBattle = false;
    bool  my_win = false;
    int   arrowKey = 0; // 0123 UDLR
    std::mt19937 mersenne;

    // locatoin for drawing
    const int my_pokemon_state_x = 59;
    const int my_pokemon_state_y = 31;
    const int other_pokemon_state_x = 85;
    const int other_pokemon_state_y = 16;
    const int message_x = 70;
    const int message_y = 50;

    // for cout
    const std::string moveType[19] = { "Normal", "Fire", "Water", "Electric", "Grass", "Ice", "Fighting", "Poison", "Ground", "Flying", "Psychic", "Bug", "Rock", "Ghost", "Dragon", "Dark", "Steel", "Fairy", "None" };


public:
    Battle(MyPlayer* _my_player, OtherPlayer* _other_player);
    Battle(MyPlayer* _my_player, CatchedPokemon* _other_pokemon);
    Battle(MyPlayer* _my_player);
    Battle();

private:
    void startBattle();
    void startHunting();
    void display();
    void printHPbar(CatchedPokemon* pokemon);
    void drawPokemon_emoji(CatchedPokemon* pokemon, int place_x, int place_y);
    void pullPokemon();
    void selectAction();

    // fight
    void    selectMove();
    void    fight(CatchedPokemon* myPokemon, CatchedPokemon* otherPokemon, Skill* move);
    void    attack(CatchedPokemon* attakingPokemon, CatchedPokemon* defendingPokemon, Skill* move);
    int     setRandomMoveNumber();
    int     calculateDamage(CatchedPokemon* attakingPokemon, CatchedPokemon* defendingPokemon, Skill* move);
    float   checkSametypeAttackbonus(CatchedPokemon* attakingPokemon, Skill* move);
    float   calculateType(CatchedPokemon* defendingPokemon, Skill* move);
    float   checkHitSpot();
    int     getRandomNumber();
    void    checkAlive(CatchedPokemon* pokemon);
    bool    checkPokemons(Player* player);
    // change
    void    changePokemon(MyPlayer* player);
    void    changePokemon(OtherPlayer* player);
    int     selectPokemon();
    void    checkSpeed();
    // bag
    void    selectBag();
    void    useItem(int ix);
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
