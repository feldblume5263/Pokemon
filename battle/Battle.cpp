#include "Battle.h"

Battle::Battle(MyPlayer* _my_player, OtherPlayer* _other_player)
    :mersenne(static_cast<unsigned int>(std::time(nullptr)))
{

    my_player = _my_player;
    other_player = _other_player;

    startBattle();
}

Battle::Battle(MyPlayer* _my_player, Pokemon* _other_pokemon)
{
   // todo
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
    if (my_win == true)
    {
        display();
        gotoxy(5, 15);
        std::cout << "My Win" << std::endl;
    }
    else
    {
        display();
        gotoxy(5, 15);
        std::cout << "My Loose" << std::endl;
    }
}

inline void Battle::startHunting()
{
}

void Battle::display()
{
    system("cls");

    gotoxy(5, 12);
    std::cout << my_selected_pokemon->name << std::endl;
    gotoxy(5, 12 + 1);
    printHPbar(my_selected_pokemon);
    gotoxy(5, 12 + 1 + 1);
    std::cout << "HP : " << my_selected_pokemon->HP << " / " << my_selected_pokemon->maxHP << std::endl;

    gotoxy(40, 2);
    std::cout << other_selected_pokemon->name << std::endl;
    gotoxy(40, 2 + 1);
    printHPbar(other_selected_pokemon);
    gotoxy(40, 2 + 1 + 1);
    std::cout << "HP : " << other_selected_pokemon->HP << " / " << other_selected_pokemon->maxHP << std::endl;
}

void Battle::printHPbar(Pokemon* pokemon)
{
    int num = 0;
    int checkHP = 0;
    int standardHP = pokemon->maxHP / 10;

    // max num is 10
    while (num < 10)
    {
        if (pokemon->HP > checkHP)
        {
            num += 1;
            checkHP += standardHP;
        }
        else
            break;
    }
    

    for (int i = 0; i < num; ++i)
    {
        std::cout << "O";
        //std::cout << i;
    }
    std::cout << std::endl;

}

void Battle::pullPokemon()
{
    // first pokemon
    if (my_selected_pokemon == nullptr && other_selected_pokemon == nullptr)
    {
        my_selected_pokemon = my_player->pokemons[0];
        other_selected_pokemon = other_player->pokemons[0];
    }
    checkSpeed();
}

void Battle::selectAction()
{
    display();

    int x = 7; int y = 15;

    gotoxy(x, y);
    std::cout << "FIGHT" << std::endl;
    gotoxy(x, ++y);
    std::cout << "BAG" << std::endl;
    gotoxy(x, ++y);
    std::cout << "POKEMON" << std::endl;
    gotoxy(x, ++y);
    std::cout << "RUN" << std::endl;

    // todo : delete Overlapping code
    y -= 3;
    gotoxy(x - 2, y);
    std::cout << ">\b";
    while (getArrowkey(x, y) == false)
    {
        gotoxy(x - 2, y);
        std::cout << ">\b";
    }

    // select
    if (y == 15)
        selectMove();
    else if (y == 16)
        selectBag();
    else if (y == 17)
        changePokemon(my_player);
    else if (y == 18)
        selectRun();
}

// Attack
void Battle::selectMove()
{
    display();

    int x = 5, y = 14;
    gotoxy(x, y);
    std::cout << "     __MOVES__" << std::endl;
    for (int i = 0; i < 4; ++i)
        std::cout << "        | TYPE : " << my_selected_pokemon->move[i].type << " | PP : " << 
            my_selected_pokemon->move[i].pp << " |" << my_selected_pokemon->move[i].name << std::endl;;

    gotoxy(x, ++y);
    std::cout << ">\b";
    while (getArrowkey(x, y) == false)
    {
        gotoxy(x, y);
        std::cout << ">\b";
    }

    if (y == 15)
        fight(my_selected_pokemon, other_selected_pokemon, my_selected_pokemon->move[0]);
    else if (y == 16)
        fight(my_selected_pokemon, other_selected_pokemon, my_selected_pokemon->move[1]);
    else if (y == 17)
        fight(my_selected_pokemon, other_selected_pokemon, my_selected_pokemon->move[2]);
    else if (y == 18)
        fight(my_selected_pokemon, other_selected_pokemon, my_selected_pokemon->move[3]);
}

void Battle::fight(Pokemon* myPokemon, Pokemon* otherPokemon, Move& move)
{
    display();

    // my pokemon will bi atack at first.
    if (priority == true)
    {
        attack(myPokemon, otherPokemon, move);
        // other pokemon can not fight
        if (otherPokemon->liveState == false)
        {
            std::cout << "otherPokemon->liveState == false" << std::endl;
            // other player has another pokemon
            if (checkPokemons(other_player) == true)
            {
                std::cout << "checkPokemons(other_player) == true" << std::endl;

                while(!getEnterSpacebar());
                
                changePokemon(other_player);
                return;
            }
            // end battle
            else {
                my_win = true; return;
            }
        }

        // setMove by random.
        int ix = setRandomMoveNumber();
        attack(otherPokemon, myPokemon, other_selected_pokemon->move[ix]);
        if (myPokemon->liveState == false)
        {
            if (checkPokemons(my_player) == true)
            {
                changePokemon(my_player);
                return;
            }
            else {
                my_win = false; return;
            }
        }
    }
    // other pokemon will bi atack at first.
    else if (priority == false)
    {
        int ix = setRandomMoveNumber();
        attack(otherPokemon, myPokemon, other_selected_pokemon->move[ix]);
        if (myPokemon->liveState == false)
        {
            if (checkPokemons(my_player) == true)
            {
                changePokemon(my_player);
                return;
            }
            else {
                my_win = false; return;
            }
        }


        attack(myPokemon, otherPokemon, move);
        if (otherPokemon->liveState == false)
        {
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

void Battle::attack(Pokemon* attakingPokemon, Pokemon* defendingPokemon, Move& move)
{
    display();
    int x = 5, y = 15;
    gotoxy(x, y);
    int damage = calculateDamage(attakingPokemon, defendingPokemon, move) * 0.1f;
    std::cout << attakingPokemon->name << " Used " << move.name << "." << std::endl;
    while (!getEnterSpacebar());

    display();
    gotoxy(x, y);
    std::cout << attakingPokemon->name << " Damaged " << damage << " " << defendingPokemon->name << std::endl;
    while (!getEnterSpacebar());


    // todo : hp bar will be diminished slowly
    //for (int i = 0; i < damage; ++i)
    //{
    //    defendingPokemon->HP = defendingPokemon->HP - 1;
    //    Sleep(100);
    //}

    defendingPokemon->HP = defendingPokemon->HP - damage;
    move.pp -= 1;
    checkAlive(defendingPokemon);

}

int Battle::calculateDamage(const Pokemon* const attakingPokemon, const Pokemon* const defendingPokemon, const Move& move)
{
    float SametypeAttackbonus = checkSametypeAttackbonus(attakingPokemon, move);
 
    float Decision = 0.0f;
    // normal Attack
    if (move.move_type == 0)
        Decision = attakingPokemon->Attack * move.power * SametypeAttackbonus;
    // sepcial Attack
    else if (move.move_type == 1)
        Decision = attakingPokemon->SpecialAttack * move.power * SametypeAttackbonus;

    // 0.411 is correction dimension
    float durability = 0.0f;
    durability = defendingPokemon->HP * defendingPokemon->Defence * 0.411;

    // Damage calculate

    float HitSpot = checkHitSpot();
    float Type1 = calculateType();
    float Type2 = calculateType();

    float damage = 0.0f;
    int RandomNumber = getRandomNumber();
    damage = Decision / durability * HitSpot * Type1 * Type2 * RandomNumber;

    return static_cast<int>(damage);
}

float Battle::checkSametypeAttackbonus(const Pokemon* const attakingPokemon, const Move& move)
{
    // todo
    return 1.0f;
}

float Battle::calculateType()
{
    // todo
    return 1.0f;
}

float Battle::checkHitSpot()
{
    // 6.25%
    int RN = 0;
    RN = std::uniform_int_distribution<>(1, 16)(mersenne);
    if (RN == 16)
        return 2.0f;
    else
        return 1.0f;
}

int Battle::getRandomNumber()
{
    float RN = 0.0f;
    RN = std::uniform_int_distribution<>(217, 255)(mersenne) * 100.0f / 255.0f;
    return static_cast<int>(RN);
}

void Battle::checkAlive(Pokemon* pokemon)
{
    if (pokemon->HP <= 0)
    {
        pokemon->HP = 0;
        pokemon->liveState = false;
    }
}

bool Battle::checkPokemons(const Player* const player)
{
    endBattle = true;

    for (auto pokemon : player->pokemons)
    {
        // at least one of pokemons is alive
        if (pokemon->liveState == true)
        {
            endBattle = false;
            return true;
        }
    }
    // battle end
    return false;
}

// todo : more efficient
int Battle::setRandomMoveNumber()
{
    for (int i = 0; i < 4; ++i)
    {
        // at least one move have a pp
        if (other_selected_pokemon->move[i].pp > 0)
        {
            while (1)
            {
                int ix = std::uniform_int_distribution<>(0, 3)(mersenne);
                if (other_selected_pokemon->move[ix].pp > 0)
                    return ix;
            }
        }
    }

    // Can not use move sice don`t have pp
    // todo
    return 5;
}

// change
int Battle::selectPokemon()
{
    // todo : show pokemon`s emoji
    display();
    for (int i = 0; i < my_player->pokemons.size(); ++i)
    {
        gotoxy(5, 17 + 3 * i);
        std::cout << "  " << my_player->pokemons[i]->name << std::endl;
        gotoxy(5, 17 + 3 * i + 1);
        std::cout << "  HP : " << my_player->pokemons[i]->HP << " / " << my_player->pokemons[i]->maxHP << std::endl;
    }

    // todo : delete Overlapping code
    gotoxy(5, 17);
    int x = 5, y = 17;
    std::cout << ">\b";
    while (1)
    {
        // todo : set interval
        gotoxy(x , y);
        std::cout << ">\b";
        if (getArrowkey(x, y) == true)
        {
            // todo : HP > 0
            if (y == 17)
            {
                display();
                gotoxy(5, 15);
                std::cout << "Can`t swap" << std::endl;
                while (!getEnterSpacebar());
                display();

                for (int i = 0; i < my_player->pokemons.size(); ++i)
                {
                    gotoxy(5, 17 + 3 * i);
                    std::cout << "  " << my_player->pokemons[i]->name << std::endl;
                    gotoxy(5, 17 + 3 * i + 1);
                    std::cout << "  HP : " << my_player->pokemons[i]->HP << " / " << my_player->pokemons[i]->maxHP << std::endl;
                }

                continue;
            }
            else
                // todo
                return 1;

        }
    }
}

void Battle::changePokemon(MyPlayer* player)
{
    int ix = selectPokemon();

    display();
    gotoxy(5, 15);
    std::swap(player->pokemons[0], player->pokemons[ix]);
    std::cout << "IN " << player->pokemons[ix]->name << std::endl;
    while (!getEnterSpacebar());

    gotoxy(5, 15);
    std::cout << "OUT " << player->pokemons[0]->name << std::endl;
    while (!getEnterSpacebar());

    // change current pokemon
    my_selected_pokemon = player->pokemons[0];
    display();
    while (!getEnterSpacebar());

}
void Battle::changePokemon(OtherPlayer* player)
{
    int ix = 0;
    while (1)
    {
        ix = std::uniform_int_distribution<>(1, player->pokemons.size() - 1)(mersenne);
        if (player->pokemons[ix]->HP > 0)
            break;
    }

    display();
    gotoxy(5, 15);
    std::swap(player->pokemons[0], player->pokemons[ix]);
    std::cout << "IN " << player->pokemons[ix]->name << std::endl;
    while (!getEnterSpacebar());

    gotoxy(5, 15);
    std::cout << "OUT " << player->pokemons[0]->name << std::endl;
    while (!getEnterSpacebar());

    // change current pokemon
    other_selected_pokemon = player->pokemons[0];
    display();
    while (!getEnterSpacebar());
}

void Battle::checkSpeed()
{
    if (my_selected_pokemon->Speed > other_selected_pokemon->Speed)
        priority = true;
    else if (my_selected_pokemon->Speed < other_selected_pokemon->Speed)
        priority = false;
    else if (my_selected_pokemon->Speed == other_selected_pokemon->Speed)
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
    int x = 5, y = 16;
    gotoxy(x, y);

    std::cout << "Quanity    Name            Description" << std::endl;
    for (int i = 0; i < my_player->items.size(); ++i)
    {
        gotoxy(x, y + 1 + i);
        std::cout << "  X" << my_player->items[i]->item_volume << "     |" <<
            my_player->items[i]->item_name << "\t|" << my_player->items[i]->item_description <<  std::endl;
    }

    gotoxy(x, ++y);
    std::cout << ">\b";
    while (getArrowkey(x, y) == false)
    {
        gotoxy(x, y);
        std::cout << ">\b";
    }

    // select
    if (y == 17)
        useItme(0);
    else if (y == 18)
        useItme(1);
    else if (y == 19)
        useItme(2);

    // todo delete when volume = 0
    // other pokemon will atacky by priority

    while (!getEnterSpacebar()) return;

}

inline void Battle::useItme(int ix)
{
    display();
    gotoxy(5, 15);

    // using monster ball, when battle with other player.
    if (my_player->items[ix]->item_type == 1 && other_player != nullptr)
    {
        std::cout << "Can`t use MonsterBall" << std::endl;
        while (!getEnterSpacebar()) return;

        return;
    }

    if (my_player->items[ix]->item_type == 0)
    {
        std::cout << "Use " << my_player->items[ix]->item_name << std::endl;
        // todo..
        //std::cout << "Recover " << my_selected_pokemon->name << "`s HP about  " <<  my_player->items[ix]->recovery_volume << std::endl;
        my_player->items[ix]->item_volume -= 1;
    }



}

// run
void Battle::selectRun()
{
    system("cls");
    display();
    gotoxy(5, 15);
    std::cout << "NO! There`s no running from a Trainer battle!" << std::endl;
    while (!getEnterSpacebar());
}



// tool
// 27ESC, 72Up 80Down 75Left 77Right  32Spacebar

void Battle::gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool Battle::getArrowkey(int& x1, int& y1)
{
    int c = 0;
    switch ((c = getch()))
    {
        // UP
    case 72:
        std::cout << " ";
        y1 -= 1;
        break;
        // DOWN
    case 80:
        std::cout << " ";
        y1 += 1;
        break;
        // ENTER
    case 13:
        return true;
    case 32:
        return true;
    default:
        break;
    }
    return false;
}

bool Battle::getEnterSpacebar()
{
    int c = 0;
    switch ((c = getch()))
    {
    case 13:
        return true;
    case 32:
        return true;
    default:
        break;
    }
    return false;
}