// #include <windows.h>
// #include <conio.h>
#include <ctime>
#include <iostream>
//# include <termios.h>
# include <fstream>
# include <string>
//# include <unistd.h>
# include <cstdlib>
# include "../include/Battle.h"

// todo : make other pokemon attack, my pokemon attack function

Battle::Battle() {}

Battle::Battle(MyPlayer* _my_player)
{
    my_player = _my_player;
    my_selected_pokemon = my_player->GetPokemon(0);


    for (auto pokemon : my_player->getPokemonsVector())
    {
        pokemon->setAlive(true);
        pokemon->setRemainHp(pokemon->getHealthPoint());
        for (int i = 0; i < 4; ++i)
        {
            if (pokemon->getSkill(i) != nullptr)
                pokemon->getSkill(i)->resetPP();
        }
    }

    std::cout << "\a" << std::endl;
}

//int			noah_()
//{
//	struct	termios oldt;
//	struct	termios newt;
//	int		ch;
//
//	tcgetattr( STDIN_FILENO, &oldt);
//	newt = oldt;
//	newt.c_lflag &= ~( ICANON | ECHO);
//	tcsetattr( STDIN_FILENO, TCSANOW, &newt);
//	ch = getchar();
//	tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
//	return (ch);
//}

Battle::Battle(MyPlayer* _my_player, OtherPlayer* _other_player)
    :mersenne(static_cast<unsigned int>(std::time(nullptr)))
{

    my_player = _my_player;
    other_player = _other_player;
    //if (other_player->getLiveState() == false)
    //{
    //    std::cout << "\a" << std::endl;
    //    while (!getEnterSpacebar());
    //    return;
    //}
    startBattle();
}

Battle::Battle(MyPlayer* _my_player, CatchedPokemon* _other_pokemon)
{
    my_player = _my_player;
    other_selected_pokemon = _other_pokemon;
    my_selected_pokemon = my_player->GetPokemon(0);

    startHunting();
}

void Battle::startBattle()
{
    pullPokemon();

    while (endBattle == false)
    {
        selectAction();
    }

    // end battle
    display();
    gotoxy(message_x, message_y);
    if (my_win == true)
        std::cout << "My Win" << std::endl;
    else
        std::cout << "My Loose" << std::endl;

    //other_player->setLiveState(false);

    my_selected_pokemon = nullptr;
    other_selected_pokemon = nullptr;
    while (!getEnterSpacebar());
}

void Battle::startHunting()
{
    // todo delete
}

void Battle::display()
{
    system("cls");

    // draw dialog box
    gotoxy(5, 40);
    for (int i = 0; i < 160; ++i)
        std::cout << "-";
    gotoxy(5, 60);
    for (int i = 0; i < 160; ++i)
        std::cout << "-";
    gotoxy(0, 41);
    for (int i = 0; i < 20; ++i)
        std::cout << "     |\n";
    for (int i = 0; i < 20; ++i)
    {
        gotoxy(164, 41 + i);
        std::cout << "|";
    }

    // draw emoji of pokemons
    if (my_selected_pokemon != nullptr)
        drawPokemon_emoji(my_selected_pokemon, 8, 18);
    if (other_selected_pokemon != nullptr)
        drawPokemon_emoji(other_selected_pokemon, 120, 4);

    // draw neme and HP of pokemons
    {   // my pokemon
        gotoxy(my_pokemon_state_x, my_pokemon_state_y);
        std::cout << my_selected_pokemon->getName() << std::endl;
        gotoxy(my_pokemon_state_x, my_pokemon_state_y + 2);
        printHPbar(my_selected_pokemon);
        gotoxy(my_pokemon_state_x, my_pokemon_state_y + 4);
        std::cout << "HP : " << my_selected_pokemon->getRemainHp() << " / " << my_selected_pokemon->getHealthPoint() << std::endl;

        for (int i = 0; i < 30; ++i)
        {
            gotoxy(my_pokemon_state_x - 5 + i, my_pokemon_state_y - 2);
            std::cout << "-";
            gotoxy(my_pokemon_state_x - 5 + i, my_pokemon_state_y + 6);
            std::cout << "-";
        }
        for (int i = 0; i < 7; ++i)
        {
            gotoxy(my_pokemon_state_x - 5, my_pokemon_state_y - 1 + i);
            std::cout << "|";
            gotoxy(my_pokemon_state_x + 24, my_pokemon_state_y - 1 + i);
            std::cout << "|";
        }
    }
    {   // other pokemon
        gotoxy(other_pokemon_state_x, other_pokemon_state_y);
        std::cout << other_selected_pokemon->getName() << std::endl;
        gotoxy(other_pokemon_state_x, other_pokemon_state_y + 2);
        printHPbar(other_selected_pokemon);
        gotoxy(other_pokemon_state_x, other_pokemon_state_y + 4);
        std::cout << "HP : " << other_selected_pokemon->getRemainHp() << " / " << other_selected_pokemon->getHealthPoint() << std::endl;

        for (int i = 0; i < 30; ++i)
        {
            gotoxy(other_pokemon_state_x - 5 + i, other_pokemon_state_y - 2);
            std::cout << "-";
            gotoxy(other_pokemon_state_x - 5 + i, other_pokemon_state_y + 6);
            std::cout << "-";
        }
        for (int i = 0; i < 7; ++i)
        {
            gotoxy(other_pokemon_state_x - 5, other_pokemon_state_y - 1 + i);
            std::cout << "|";
            gotoxy(other_pokemon_state_x + 24, other_pokemon_state_y - 1 + i);
            std::cout << "|";
        }
    }
}

void Battle::printHPbar(CatchedPokemon* pokemon)
{
    int num = 0;
    int checkHP = 0;
    int standardHP = pokemon->getHealthPoint() / 20;

    // max num is 10
    while (num < 20)
    {
        if (pokemon->getRemainHp() > checkHP)
        {
            num += 1;
            checkHP += standardHP;
        }
        else
            break;
    }


    for (int i = 0; i < num; ++i)
    {
        std::cout << "@";
    }
    std::cout << std::endl;

}

void Battle::drawPokemon_emoji(CatchedPokemon* pokemon, int place_x, int place_y)
{
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 40; ++j)
        {
            gotoxy(place_x + j, place_y + i);
            char c = pokemon->emoji[j + i * 40];
            if (c == 'M')
                std::cout << ' ';
            else if (c == ' ')
                std::cout << ' /b';
            else
                std::cout << c;
        }
        std::cout << std::endl;
    }
}

void Battle::pullPokemon()
{
    // first pokemon
    if (my_selected_pokemon == nullptr && other_selected_pokemon == nullptr)
    {
        my_selected_pokemon = my_player->GetPokemon(0);
        other_selected_pokemon = other_player->GetPokemon(0);
    }
    checkSpeed();
}

void Battle::selectAction()
{
    display();

    // print actions
    int x = 30; int y = 45; const int f_y = y;
    gotoxy(x, y);
    std::cout << "FIGHT" << std::endl;
    gotoxy(x, y + 3);
    std::cout << "BAG" << std::endl;
    gotoxy(x, y + 6);
    std::cout << "POKEMON" << std::endl;
    gotoxy(x, y + 9);
    std::cout << "RUN" << std::endl;


    printArrow(x, y);

    // select
    if (y == f_y)
        selectMove();
    else if (y == f_y + 3)
        selectBag();
    else if (y == f_y + 6)
        changePokemon(my_player);
    else if (y == f_y + 9)
        selectRun();
}

// Attack
void Battle::selectMove()
{
    display();


    // print moves
    int x = 30; int y = 45; const int f_y = y;
    gotoxy(x, y - 2);
    std::cout << "---MOVES---" << std::endl;
    for (int i = 0; i < 4; ++i) {
        gotoxy(x, y + 3 * i);
        if (my_selected_pokemon->getSkill(i) != nullptr)
        {
            std::cout << "| TYPE : " << moveType[my_selected_pokemon->getSkill(i)->getType()] << " | PP : " <<
                my_selected_pokemon->getSkill(i)->getRemainPP() << " / " << my_selected_pokemon->getSkill(i)->getPP() << " | " << my_selected_pokemon->getSkill(i)->getName() << std::endl;
        }
        else if (my_selected_pokemon->getSkill(i) == nullptr)
        {
            std::cout << "| TYPE : " << "  --  " << " | PP : " <<
                "  --  "  << " | " << "  --  " << std::endl;
        }

    }
    printArrow(x, y);

    // select move
    if (y == f_y)
        fight(my_selected_pokemon, other_selected_pokemon, my_selected_pokemon->getSkill(0));
    else if (y == f_y + 3)
        fight(my_selected_pokemon, other_selected_pokemon, my_selected_pokemon->getSkill(1));
    else if (y == f_y + 6)
        fight(my_selected_pokemon, other_selected_pokemon, my_selected_pokemon->getSkill(2));
    else if (y == f_y + 9)
        fight(my_selected_pokemon, other_selected_pokemon, my_selected_pokemon->getSkill(3));
}

void Battle::fight(CatchedPokemon* myPokemon, CatchedPokemon* otherPokemon, Skill* move)
{
    // my pokemon will bi atack at first.
    if (priority == true)
    {
        attack(myPokemon, otherPokemon, move);
        // other pokemon can not fight
        if (otherPokemon->Alive() == false)
        {
            display();
            gotoxy(message_x, message_y);
            std::cout << otherPokemon->getName() << " is fainted." << std::endl;
            while (!getEnterSpacebar());

            // other player has another pokemon
            if (checkPokemons(other_player) == true)
            {
                changePokemon(other_player);
                return;
            }
            // end battle
            else {
                my_win = true;
                return;
            }
        }

        // setMove by random.
        int ix = setRandomMoveNumber();
        if (ix < 0)
        {
            display();
            gotoxy(message_x, message_y);
            std::cout << otherPokemon ->getName() << " don`t have PP anymore.";
            gotoxy(message_x, message_y + 1);
            std::cout << "So Can not attack.";
            while (!getEnterSpacebar());
            return;
        }

        attack(otherPokemon, myPokemon, other_selected_pokemon->getSkill(ix));
        if (myPokemon->Alive() == false)
        {
            display();
            gotoxy(message_x, message_y);
            std::cout << myPokemon->getName() << " is fainted." << std::endl;
            while (!getEnterSpacebar());

            if (checkPokemons(my_player) == true)
            {
                changePokemon(my_player);
                return;
            }
            else {
                my_win = false;
                return;
            }
        }
    }

    // other pokemon will bi atack at first.
    else if (priority == false)
    {
        int ix = setRandomMoveNumber();
        if (ix < 0)
        {
            display();
            gotoxy(message_x, message_y);
            std::cout << otherPokemon->getName() << " don`t have PP anymore.";
            gotoxy(message_x, message_y + 1);
            std::cout << "So Can not attack.";
            while (!getEnterSpacebar());
            return;
        }

        attack(otherPokemon, myPokemon, other_selected_pokemon->getSkill(ix));
        if (myPokemon->Alive() == false)
        {
            display();
            gotoxy(message_x, message_y);
            std::cout << myPokemon->getName() << " is fainted." << std::endl;
            while (!getEnterSpacebar());

            if (checkPokemons(my_player) == true)
            {
                changePokemon(my_player);
                return;
            }
            else {
                my_win = false;
                return;
            }
        }

        attack(myPokemon, otherPokemon, move);
        if (otherPokemon->Alive() == false)
        {
            display();
            gotoxy(message_x, message_y);
            std::cout << otherPokemon->getName() << " is fainted." << std::endl;
            while (!getEnterSpacebar());

            if (checkPokemons(other_player) == true)
            {
                changePokemon(other_player);
                return;
            }
            else {
                my_win = true; return;
            }
        }
    }
}

void Battle::attack(CatchedPokemon* attakingPokemon, CatchedPokemon* defendingPokemon, Skill* move)
{
    display();
    int x = 5, y = 15;
    //gotoxy(x, y);

    gotoxy(message_x, message_y);

    int damage = calculateDamage(attakingPokemon, defendingPokemon, move);
    std::cout << attakingPokemon->getName() << " Used " << move->getName() << "." << std::endl;
    while (!getEnterSpacebar());

    // when critical hit
    if (hitSpot == true)
    {
        gotoxy(message_x, message_y);
        std::cout << "A critical Hit!" << std::endl;
        while (!getEnterSpacebar());
    }

    // type attack message
    if (typeCal == 1.0f)
    {
        ;
    }
    else if (typeCal == 0.5f)
    {
        gotoxy(message_x, message_y);
        std::cout << "It`s not very effective..." << std::endl;
        while (!getEnterSpacebar());
    }
    else if (typeCal == 2.0f)
    {
        gotoxy(message_x, message_y);
        std::cout << "It`s super effective!" << std::endl;
        while (!getEnterSpacebar());
    }
    else if (typeCal == 4.0f)
    {
        gotoxy(message_x, message_y);
        std::cout << "It`s super super effective!!!" << std::endl;
        while (!getEnterSpacebar());
    }
    else if (typeCal == 0.25f)
    {
        gotoxy(message_x, message_y);
        std::cout << "It`s not very very effective..." << std::endl;
        while (!getEnterSpacebar());
    }
    else if (typeCal == 0.0f)
    {
        gotoxy(message_x, message_y);
        std::cout << "It`s no effective..." << std::endl;
        while (!getEnterSpacebar());
    }

    display();
    gotoxy(message_x, message_y);
    std::cout << attakingPokemon->getName() << " Damaged to " << damage << " " << defendingPokemon-> getName() << std::endl;
    while (!getEnterSpacebar());

    int tempHP = defendingPokemon->getRemainHp();
    hitSpot = false;
    typeCal = 1.0f;

    defendingPokemon->setRemainHp(defendingPokemon->getRemainHp() - damage);
    move->reducePP();
    checkAlive(defendingPokemon);

    // hp bar will be diminished slowly (need to check on mac)
    //for (int i = 0; i < damage; ++i)
    //{
    //    defendingPokemon->setRemainHp(--tempHP);
    //    Sleep(3);
    //    display();
    //    if (tempHP == 0) break;
    //}
}

int Battle::calculateDamage(CatchedPokemon*  attakingPokemon, CatchedPokemon*  defendingPokemon, Skill* move)
{
    float SametypeAttackbonus = checkSametypeAttackbonus(attakingPokemon, move);
    float Decision = 0.0f;
    float durability = 0.0f;

    // normal Attack
    if (move->getDamageType() == Physical)
    {
        Decision = attakingPokemon->getAttack() * move->getPower() * SametypeAttackbonus;
        // 0.411 is correction dimension
        durability = static_cast<float>(defendingPokemon->getHealthPoint()) * static_cast<float>(defendingPokemon->getDefense()) / 0.411f;
    }
    // sepcial Attack
    else if (move->getDamageType() == Special)
    {
        Decision = attakingPokemon->getSpecialAttack() * move->getPower() * SametypeAttackbonus;
        durability = static_cast<float>(defendingPokemon->getHealthPoint()) * static_cast<float>(defendingPokemon->getSpecialDefense()) / 0.411f;
    }

    // Damage calculate
    float HitSpot = checkHitSpot();
    float Type = calculateType(defendingPokemon, move);
    float damage = 0.0f;
    int RandomNumber = getRandomNumber();
    damage = Decision / durability * HitSpot * Type * RandomNumber;

    return static_cast<int>(damage);
}

float Battle::checkSametypeAttackbonus(CatchedPokemon* attakingPokemon, Skill* move)
{
    if (attakingPokemon->getType1() == move->getType() || attakingPokemon->getType2() == move->getType())
        return 1.5f;
    else
        return 1.0f;
}

float Battle::calculateType(CatchedPokemon* defendingPokemon, Skill* move)
{
    typeCal = type_damage_rate[move->getType()][defendingPokemon->getType1()] * type_damage_rate[move->getType()][defendingPokemon->getType2()];
    return typeCal;
}

float Battle::checkHitSpot()
{
    // 6.25%
    int RN = 0;
    RN = std::uniform_int_distribution<>(1, 16)(mersenne);
    if (RN == 16)
    {
        return 2.0f;
        hitSpot = true;
    }
    else
    {
        return 1.0f;
        hitSpot = false;
    }
}

int Battle::getRandomNumber()
{
    // 85 ~ 100. Not equial probility per number.
    float RN = 0.0f;
    RN = std::uniform_int_distribution<>(217, 255)(mersenne) * 100.0f / 255.0f;
    return static_cast<int>(RN);
}

void Battle::checkAlive(CatchedPokemon* pokemon)
{
    if (pokemon->getRemainHp() <= 0)
    {
        pokemon->setRemainHp(0);
        pokemon->setAlive(false);
    }
}

bool Battle::checkPokemons(Player* player)
{
    endBattle = true;

    for (auto pokemon : player->getPokemonsVector())
    {
        // at least one of pokemons is alive
        if (pokemon->Alive())
        {
            endBattle = false;
            return true;
        }
    }
    // battle end
    return false;
}

int Battle::setRandomMoveNumber()
{

    bool have_pp = false;
    for (int i = 0; i < 4; ++i)
    {
        // at least one move have a pp
        if (other_selected_pokemon->getSkill(i)->getRemainPP() > 0)
        {
            have_pp = true;
            break;
        }
    }

    // Don`t have pp among all the skill
    if (have_pp == false)
        return -1;
    else
        while (1)
        {
            int ix = std::uniform_int_distribution<>(0, 3)(mersenne);

            if (other_selected_pokemon->getSkill(ix)->getRemainPP() > 0)
                return ix;
        }
}

// change
int Battle::selectPokemon()
{
    display();

    int num_pokemons = my_player->getPokemonsVector().size();

    // print pokemons
    int x = 30; int y = 45; const int f_y = y; const int f_x = x - 3;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i * 3 + j < num_pokemons)
            {
                gotoxy(x + i * 40, y + 3 * j);
                std::cout << "  " << my_player->GetPokemon(i * 3 + j)->getName() << std::endl;
                gotoxy(x + i * 40, y + 3 * j + 1);
                std::cout << "  HP : " << my_player->GetPokemon(i * 3 + j)->getRemainHp() << " / " << my_player->GetPokemon(i * 3 + j)->getHealthPoint() << std::endl;
            }
            else
            {
                gotoxy(x + i * 40, y + 3 * j);
                std::cout << "___";
            }
        }
    }

    while (1)
    {
        printArrow_change(x, y);

        if (x == f_x && y == f_y)
        {
            return -1;
        }
        else if(x == f_x && y == f_y + 3)
        {
            if (num_pokemons > 1 || my_player->GetPokemon(1)->getRemainHp() == 0)
                return 1;
            else return -1;
        }
        else if (x == f_x && y == f_y + 6)
        {
            if (num_pokemons > 2 || my_player->GetPokemon(2)->getRemainHp() == 0)
                return 2;
            else return -1;
        }
        else if (x == f_x + 40 && y == f_y)
        {
            if (num_pokemons > 3 || my_player->GetPokemon(3)->getRemainHp() == 0)
                return 3;
            else return -1;
        }
        else if (x == f_x + 40 && y == f_y + 3)
        {
            if (num_pokemons > 4 || my_player->GetPokemon(4)->getRemainHp() == 0)
                return 4;
            else return -1;
        }
        else if (x == f_x + 40 && y == f_y + 6)
        {
            if (num_pokemons > 5 || my_player->GetPokemon(5)->getRemainHp() == 0)
                return 5;
            else return -1;
        }
    }
}

void Battle::changePokemon(MyPlayer* player)
{
    int ix = selectPokemon();
    if (ix < 0)
    {
        display();
        gotoxy(message_x, message_y);
        std::cout << "Can`t swap" << std::endl;
        while (!getEnterSpacebar());

        changePokemon(player);
        return;
    }

    CatchedPokemon* tempPtr = player->GetPokemon(0);
    player->SetPokemon(player->GetPokemon(ix), 0);
    player->SetPokemon(tempPtr, ix);

    display();
    gotoxy(message_x, message_y);
    std::cout << "IN " << player->GetPokemon(ix)->getName() << std::endl;
    while (!getEnterSpacebar());

    gotoxy(message_x, message_y);
    std::cout << "OUT " << player->GetPokemon(0)->getName() << std::endl;
    while (!getEnterSpacebar());

    // change current pokemon
    my_selected_pokemon = player->GetPokemon(0);

    display();

    // other pokemon attack
    int idx = setRandomMoveNumber();
    if (idx < 0)
    {
        display();
        gotoxy(message_x, message_y);
        std::cout << other_selected_pokemon->getName() << " don`t have PP anymore.";
        gotoxy(message_x, message_y + 1);
        std::cout << "So Can not attack.";
        while (!getEnterSpacebar());
        return;
    }
    attack(other_selected_pokemon, my_selected_pokemon, other_selected_pokemon->getSkill(idx));
    if (my_selected_pokemon->Alive() == false)
    {
        display();
        gotoxy(message_x, message_y);
        std::cout << my_selected_pokemon->getName() << " is fainted." << std::endl;
        while (!getEnterSpacebar());

        if (checkPokemons(my_player) == true)
        {
            changePokemon(my_player);
            return;
        }
        else {
            my_win = false;
            return;
        }
    }
}
void Battle::changePokemon(OtherPlayer* player)
{
    int ix = 0;
    while (1)
    {
        ix = std::uniform_int_distribution<>(1, player->getPokemonsVector().size() - 1)(mersenne);
        if (player->GetPokemon(ix)->getRemainHp() > 0)
            break;
    }

    CatchedPokemon* tempPtr = player->GetPokemon(0);
    player->SetPokemon(player->GetPokemon(ix), 0);
    player->SetPokemon(tempPtr, ix);


    display();
    gotoxy(message_x, message_y);
    std::cout << "IN " << player->GetPokemon(ix)->getName() << std::endl;
    while (!getEnterSpacebar());

    gotoxy(message_x, message_y);
    std::cout << "OUT " << player->GetPokemon(0)->getName() << std::endl;
    while (!getEnterSpacebar());

    // change current pokemon
    other_selected_pokemon = player->GetPokemon(0);
}

void Battle::checkSpeed()
{
    if (my_selected_pokemon->getSpeed() > other_selected_pokemon->getSpeed())
        priority = true;
    else if (my_selected_pokemon->getSpeed() < other_selected_pokemon->getSpeed())
        priority = false;
    else if (my_selected_pokemon->getSpeed() == other_selected_pokemon->getSpeed())
    {
        // half probilitiy
        int i = std::uniform_int_distribution<>(1, 2)(mersenne);
        if (i == 1)
            priority = true;
        else
            priority = false;
    }
}

// bag
void Battle::selectBag()
{
    display();
    int num_items = my_player->getItems().size();
    int x = 30; int y = 45; const int f_y = y + 1; const int f_x = x - 3;

    gotoxy(x, y);
    std::cout << "Quanity    Name            Description" << std::endl;
    for (int i = 0; i < num_items; ++i)
    {
        gotoxy(x, y + 1 + i);
        std::cout << "  X" << my_player->getItem(i)->getItemVolume() << "     |" <<
            my_player->getItem(i)->getItemName() << "\t|" << my_player->getItem(i)->getItemDesc() <<  std::endl;
    }

    x = x - 2; y = y + 1;
    gotoxy(x, y);
    std::cout << ">\b";
    while (getArrowkey(x, y) == false)
    {
        if (arrowKey == 0)
        {
            if (y <= f_y)
            {
                std::cout << "\b>\b";
                continue;
            }
            y = y - 1;
            gotoxy(x, y);
        }
        else if (arrowKey == 1)
        {
            if (y >= f_y + num_items - 1)
            {
                std::cout << "\b>\b";
                continue;
            }
            y = y + 1;
            gotoxy(x, y);
        }
        std::cout << ">\b";
    }

    // select
    int ix = y - f_y;
    std::cout << ix;

    // using monster ball, when battle with other player.
    if (my_player->getItem(ix)->getItemType() == MonsterBall_Item && other_player != nullptr)
    {
        gotoxy(message_x, message_y);
        std::cout << "Can`t use MonsterBall In Pokemon Battle!" << std::endl;
        while (!getEnterSpacebar()) return;
    }

    useItem(ix);

    // other pokemon attack
    int idx = setRandomMoveNumber();
    if (idx < 0)
    {
        display();
        gotoxy(message_x, message_y);
        std::cout << other_selected_pokemon->getName() << " don`t have PP anymore.";
        gotoxy(message_x, message_y + 1);
        std::cout << "So Can not attack.";
        while (!getEnterSpacebar());
        return;
    }
    attack(other_selected_pokemon, my_selected_pokemon, other_selected_pokemon->getSkill(idx));
    if (my_selected_pokemon->Alive() == false)
    {
        display();
        gotoxy(message_x, message_y);
        std::cout << my_selected_pokemon->getName() << " is fainted." << std::endl;
        while (!getEnterSpacebar());

        if (checkPokemons(my_player) == true)
        {
            changePokemon(my_player);
            return;
        }
        else {
            my_win = false;
            return;
        }
    }
}

void Battle::useItem(int ix)
{
    display();

    if (my_player->getItem(ix)->getItemType() == MonsterBall_Item && other_player == nullptr)
    {
        ;
    }

    if (my_player->getItem(ix)->getItemType() == HPRecovery_Item)
    {
        gotoxy(message_x, message_y);
        std::cout << "Use " << my_player->getItem(ix)->getItemName() << std::endl;
        while (!getEnterSpacebar()) return;

        // recover
        my_selected_pokemon->setRemainHp(my_selected_pokemon->getRemainHp() + my_player->getItem(ix)->getRecoveryVolume());
        if (my_selected_pokemon->getRemainHp() >= my_selected_pokemon->getHealthPoint())
            my_selected_pokemon->setRemainHp(my_selected_pokemon->getHealthPoint());
        // reduce volume
        my_player->getItem(ix)->setVolume(my_player->getItem(ix)->getItemVolume() - 1);

        //// todo
        //if (my_player->getItem(ix)->getItemVolume() == 0)
        //{
        //    std::cout << my_player->getItems().size() << std::endl;
        //    my_player->getItems().erase(my_player->getItems().begin() + ix);
        //    std::cout << my_player->getItems().size() << std::endl;
        //}

        display();
        gotoxy(message_x, message_y);
        std::cout << "Recover " << my_selected_pokemon->getName() << "`s HP about " << my_player->getItem(ix)->getRecoveryVolume() << std::endl;
        while (!getEnterSpacebar()) return;
    }


}

// run
void Battle::selectRun()
{
    system("cls");
    display();
    gotoxy(message_x, message_y);
    std::cout << "NO! There`s no running from a Trainer battle!" << std::endl;
    while (!getEnterSpacebar());
}



// tool
 void Battle::gotoxy(int column, int line)
 {
     COORD coord;
     coord.X = column;
     coord.Y = line;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
 }

//void Battle::gotoxy(int x,int y)
//{
//    printf("%c[%d;%df",0x1B,y,x);
//}

bool Battle::getArrowkey(int& x1, int& y1)
{
    int c = 0;
    switch ((c = getch()))
    {
    case UP:
        std::cout << " ";
        arrowKey = 0;
        break;
    case DOWN:
        std::cout << " ";
        arrowKey = 1;
        break;
    case LEFT:
        arrowKey = 2;
        break;
    case RIGHT:
        arrowKey = 3;
        break;
    case ENTER:
        return true;
    case SPACEBAR:
        return true;
    default:
        arrowKey = -1;
        break;
    }
    return false;
}

bool Battle::getEnterSpacebar()
{
    int c = 0;
    switch ((c = getch()))
    {
    case ENTER:
        return true;
    case SPACEBAR:
        return true;
    default:
        break;
    }
    return false;
}

void Battle::printArrow(int& x, int& y)
{
    x = x - 3;
    gotoxy(x, y);
    std::cout << ">\b";
    while (getArrowkey(x, y) == false)
    {
        if (arrowKey == 0)
        {
            if (y <= 45)
            {
                std::cout << "\b>\b";
                continue;
            }
            y = y - 3;
            gotoxy(x, y);
        }
        else if (arrowKey == 1)
        {
            if (y >= 45 + 9)
            {
                std::cout << "\b>\b";
                continue;
            }
            y = y + 3;
            gotoxy(x, y);
        }
        std::cout << ">\b";
    }
}

void Battle::printArrow_change(int& x, int& y)
{
    x = x - 3;
    gotoxy(x, y);
    std::cout << ">\b";
    while (getArrowkey(x, y) == false)
    {
        if (arrowKey == 0)
        {
            if (y <= 45)
            {
                std::cout << "\b>\b";
                continue;
            }
            y = y - 3;
            gotoxy(x, y);
        }
        else if (arrowKey == 1)
        {
            if (y >= 45 + 6)
            {
                std::cout << "\b>\b";
                continue;
            }
            y = y + 3;
            gotoxy(x, y);
        }
        else if (arrowKey == 2)
        {
            if (x == 30 - 3)
            {
                std::cout << ">\b";
                continue;
            }
            std::cout << " ";
            x = x - 40;
            gotoxy(x, y);
        }
        else if (arrowKey == 3)
        {
            if (x == 30 - 3 + 40)
            {
                std::cout << ">\b";
                continue;
            }
            std::cout << " ";
            x = x + 40;
            gotoxy(x, y);
        }
        std::cout << ">\b";
    }
}
