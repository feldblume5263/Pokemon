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
    my_player = _my_player;
    other_selected_pokemon = _other_pokemon;
    my_selected_pokemon = my_player->pokemons[0];

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
    gotoxy(message_x, message_x);
    if (my_win == true)
        std::cout << "My Win" << std::endl;
    else
        std::cout << "My Loose" << std::endl;
}

inline void Battle::startHunting()
{
    // todo
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
        std::cout << my_selected_pokemon->GetName() << std::endl;
        gotoxy(my_pokemon_state_x, my_pokemon_state_y + 2);
        printHPbar(my_selected_pokemon);
        gotoxy(my_pokemon_state_x, my_pokemon_state_y + 4);
        std::cout << "HP : " << my_selected_pokemon->GetRemainHp() << " / " << my_selected_pokemon->GetHealthPoint() << std::endl;

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
        std::cout << other_selected_pokemon->GetName() << std::endl;
        gotoxy(other_pokemon_state_x, other_pokemon_state_y + 2);
        printHPbar(other_selected_pokemon);
        gotoxy(other_pokemon_state_x, other_pokemon_state_y + 4);
        std::cout << "HP : " << other_selected_pokemon->GetRemainHp() << " / " << other_selected_pokemon->GetHealthPoint() << std::endl;

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

void Battle::printHPbar(Pokemon* pokemon)
{
    int num = 0;
    int checkHP = 0;
    int standardHP = pokemon->GetHealthPoint() / 20;

    // max num is 10
    while (num < 20)
    {
        if (pokemon->GetRemainHp() > checkHP)
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

inline void Battle::drawPokemon_emoji(Pokemon* pokemon, int place_x, int place_y)
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

inline void Battle::drawPoekomon(Pokemon* pokemon, int place_x, int place_y)
{
    // todo
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
        std::cout << "| TYPE : " << my_selected_pokemon->GetSkill(i).GetType() << " | PP : " <<
            my_selected_pokemon->GetSkill(i).GetRemainPP() << " / " << my_selected_pokemon->GetSkill(i).GetPP() << " | " << my_selected_pokemon->GetSkill(i).GetName() << std::endl; // todo type
    }
    printArrow(x, y);

    // select move
    if (y == f_y)
        fight(my_selected_pokemon, other_selected_pokemon, my_selected_pokemon->GetSkill(0));
    else if (y == f_y + 3)
        fight(my_selected_pokemon, other_selected_pokemon, my_selected_pokemon->GetSkill(1));
    else if (y == f_y + 6)
        fight(my_selected_pokemon, other_selected_pokemon, my_selected_pokemon->GetSkill(2));
    else if (y == f_y + 9)
        fight(my_selected_pokemon, other_selected_pokemon, my_selected_pokemon->GetSkill(3));
}

void Battle::fight(Pokemon* myPokemon, Pokemon* otherPokemon, Skill& move)
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
            std::cout << otherPokemon->GetName() << " is fainted." << std::endl;
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
            std::cout << otherPokemon ->GetName() << " don`t have PP anymore.";
            gotoxy(message_x, message_y + 1);
            std::cout << "So Can not attack.";
            while (!getEnterSpacebar());
            return;
        }

        attack(otherPokemon, myPokemon, other_selected_pokemon->GetSkill(ix));
        if (myPokemon->Alive() == false)
        {
            display();
            gotoxy(message_x, message_y);
            std::cout << myPokemon->GetName() << " is fainted." << std::endl;
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
            std::cout << otherPokemon->GetName() << " don`t have PP anymore.";
            gotoxy(message_x, message_y + 1);
            std::cout << "So Can not attack.";
            while (!getEnterSpacebar());
            return;
        }

        attack(otherPokemon, myPokemon, other_selected_pokemon->GetSkill(ix));
        if (myPokemon->Alive() == false)
        {
            display();
            gotoxy(message_x, message_y);
            std::cout << myPokemon->GetName() << " is fainted." << std::endl;
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
            std::cout << otherPokemon->GetName() << " is fainted." << std::endl;
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

void Battle::attack(Pokemon* attakingPokemon, Pokemon* defendingPokemon, Skill& move)
{
    display();
    int x = 5, y = 15;
    //gotoxy(x, y);

    gotoxy(message_x, message_y);

    int damage = calculateDamage(attakingPokemon, defendingPokemon, move) * 0.1f;
    std::cout << attakingPokemon->GetName() << " Used " << move.GetName() << "." << std::endl;
    while (!getEnterSpacebar());

    display();
    gotoxy(message_x, message_y);
    //gotoxy(x, y);
    std::cout << attakingPokemon->GetName() << " Damaged to " << damage << " " << defendingPokemon->GetName() << std::endl;
    while (!getEnterSpacebar());


    // todo : hp bar will be diminished slowly
    //for (int i = 0; i < damage; ++i)
    //{
    //    defendingPokemon->HP = defendingPokemon->HP - 1;
    //    Sleep(100);
    //}
    
    defendingPokemon->SetRemainHp(defendingPokemon->GetRemainHp() - damage);
    move.SetRmainPP(move.GetPP() - 1);
    checkAlive(defendingPokemon);
}

int Battle::calculateDamage(Pokemon*  attakingPokemon, Pokemon*  defendingPokemon, Skill& move)
{
    float SametypeAttackbonus = checkSametypeAttackbonus(attakingPokemon, move);
    float Decision = 0.0f;
    // normal Attack
    if (move.GetDamageType() == Physical)
        Decision = attakingPokemon->GetAttack() * move.GetPower() * SametypeAttackbonus;
    // sepcial Attack
    else if (move.GetDamageType() == Special)
        Decision = attakingPokemon->GetSpecialAttack() * move.GetPower() * SametypeAttackbonus;

    // 0.411 is correction dimension
    float durability = 0.0f;
    durability = defendingPokemon->GetHealthPoint() * defendingPokemon->GetDefense() * 0.411;

    // Damage calculate
    float HitSpot = checkHitSpot();
    float Type1 = calculateType();
    float Type2 = calculateType();
    float damage = 0.0f;
    int RandomNumber = getRandomNumber();
    damage = Decision / durability * HitSpot * Type1 * Type2 * RandomNumber;

    return static_cast<int>(damage);
}

float Battle::checkSametypeAttackbonus(Pokemon* attakingPokemon, Skill& move)
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
    // 85 ~ 100. Not equial probility per number.
    float RN = 0.0f;
    RN = std::uniform_int_distribution<>(217, 255)(mersenne) * 100.0f / 255.0f;
    return static_cast<int>(RN);
}

void Battle::checkAlive(Pokemon* pokemon)
{
    if (pokemon->GetRemainHp() <= 0)
    {
        pokemon->SetRemainHp(0);
        pokemon->SetAlive(false);
    }
}

bool Battle::checkPokemons(Player* player)
{
    endBattle = true;

    for (auto pokemon : player->pokemons)
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
        if (other_selected_pokemon->GetSkill(i).GetRemainPP() > 0)
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

            if (other_selected_pokemon->GetSkill(ix).GetRemainPP() > 0)
                return ix;
        }
}

// change
int Battle::selectPokemon()
{
    display();

    int num_pokemons = my_player->pokemons.size();

    // print pokemons
    int x = 30; int y = 45; const int f_y = y; const int f_x = x - 3;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i * 3 + j < num_pokemons)
            {
                gotoxy(x + i * 40, y + 3 * j);
                std::cout << "  " << my_player->pokemons[i * 3 + j]->GetName() << std::endl;
                gotoxy(x + i * 40, y + 3 * j + 1);
                std::cout << "  HP : " << my_player->pokemons[i * 3 + j]->GetRemainHp() << " / " << my_player->pokemons[i * 3 + j]->GetHealthPoint() << std::endl;
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
            if (num_pokemons > 1 || my_player->pokemons[1]->GetRemainHp() == 0)
                return 1;
            else return -1;
        }
        else if (x == f_x && y == f_y + 6)
        {
            if (num_pokemons > 2 || my_player->pokemons[2]->GetRemainHp() == 0)
                return 2;
            else return -1;
        }
        else if (x == f_x + 40 && y == f_y)
        {
            if (num_pokemons > 3 || my_player->pokemons[3]->GetRemainHp() == 0)
                return 3;
            else return -1;
        }
        else if (x == f_x + 40 && y == f_y + 3)
        {
            if (num_pokemons > 4 || my_player->pokemons[4]->GetRemainHp() == 0)
                return 4;
            else return -1;
        }
        else if (x == f_x + 40 && y == f_y + 6)
        {
            if (num_pokemons > 5 || my_player->pokemons[5]->GetRemainHp() == 0)
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

    std::swap(player->pokemons[0], player->pokemons[ix]);

    display();
    gotoxy(message_x, message_y);
    std::cout << "IN " << player->pokemons[ix]->GetName() << std::endl;
    while (!getEnterSpacebar());

    gotoxy(message_x, message_y);
    std::cout << "OUT " << player->pokemons[0]->GetName() << std::endl;
    while (!getEnterSpacebar());

    // change current pokemon
    my_selected_pokemon = player->pokemons[0];
}
void Battle::changePokemon(OtherPlayer* player)
{
    int ix = 0;
    while (1)
    {
        ix = std::uniform_int_distribution<>(1, player->pokemons.size() - 1)(mersenne);
        if (player->pokemons[ix]->GetRemainHp() > 0)
            break;
    }

    std::swap(player->pokemons[0], player->pokemons[ix]);

    display();
    gotoxy(message_x, message_y);
    std::cout << "IN " << player->pokemons[ix]->GetName() << std::endl;
    while (!getEnterSpacebar());

    gotoxy(message_x, message_y);
    std::cout << "OUT " << player->pokemons[0]->GetName() << std::endl;
    while (!getEnterSpacebar());

    // change current pokemon
    other_selected_pokemon = player->pokemons[0];
}

void Battle::checkSpeed()
{
    if (my_selected_pokemon->GetSpeed() > other_selected_pokemon->GetSpeed())
        priority = true;
    else if (my_selected_pokemon->GetSpeed() < other_selected_pokemon->GetSpeed())
        priority = false;
    else if (my_selected_pokemon->GetSpeed() == other_selected_pokemon->GetSpeed())
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
    // if 걸어서, bag누를때마다 갯수 확인하고 0보다 작거나 같으면 delete

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
    gotoxy(message_x, message_y);
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
        arrowKey = 0;
        break;
        // DOWN
    case 80:
        std::cout << " ";
        arrowKey = 1;
        break;
        // LEFT
    case 75:
        arrowKey = 2;
        break;
        // RIGHT
    case 77:
        arrowKey = 3;
        break;
        // ENTER
    case 13:
        return true;
    case 32:
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
    case 13:
        return true;
    case 32:
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
