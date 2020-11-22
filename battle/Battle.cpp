#include "Battle.h"

Battle::Battle(Player* _my_player, Player* _other_player)
{
    my_player = _my_player;
    other_player = _other_player;

    // player class가 복사되지 말고 주소값이 들어와야한다.
    // 포켓몬의 바뀐 값들을 내보내야하니까.
    // 포인터로 받으면 해결되곘지만, c++에서 포인터 쓰기 싫은데..
}

void Battle::startBattle()
{
    pullPokemon();

    while (endBattle == false)
    {
        // pokemon can not fight or change pokemon
        while (my_selected_pokemon->liveState == true || other_selected_pokemon->liveState == true
            || changeState == false)
        {
            selectAction();
        }

        // todo : check all pokemon can not fight
        changePokemon();
    }
    
    
}

void Battle::display()
{
    // 앞, 뒷모습 사진을 각각 구해야한다.
    // console은 길어야 79 24 길이이다.
    // 근데 그ascii로 바꾸는 사이트 최소 길이가 40이다.
    // 턱없이 부족하다.
    gotoxy(5, 12);
    std::cout << my_selected_pokemon->name << std::endl;
    gotoxy(5, 12 + 1);
    std::cout << "HP : " << my_selected_pokemon->HP << std::endl;

    gotoxy(40, 2);
    std::cout << other_selected_pokemon->name << std::endl;
    gotoxy(40, 2 + 1);
    std::cout << "HP : " << other_selected_pokemon->HP << std::endl;
}

void Battle::pullPokemon()
{
    // first pokemon
    if (my_selected_pokemon == nullptr && other_selected_pokemon == nullptr)
    {
        my_selected_pokemon = &(my_player->pokemons[0]);
        other_selected_pokemon = &(other_player->pokemons[0]);
    }

    if (my_selected_pokemon->Speed > other_selected_pokemon->Speed)
        priority = true;
    else if (my_selected_pokemon->Speed < other_selected_pokemon->Speed)
        priority = false;
    else if (my_selected_pokemon->Speed == other_selected_pokemon->Speed)
    {
        std::cout << "NOTHING";
    }
    // todo : random
}

void Battle::selectAction()
{
    display();

    int x = 5; int y = 15;

    gotoxy(x, y);
    std::cout << "__ FIGHT" << std::endl;
    std::cout << "     __ BAG" << std::endl;
    std::cout << "     __ POKEMON" << std::endl;
    std::cout << "     __ RUN" << std::endl;

    gotoxy(x, y);
    // todo : delete Overlapping code
    std::cout << "O\b";
    while (1)
    {
        if (getArrowkey(x, y) == true)
            break;
        gotoxy(x, y);
        std::cout << "O\b";
    }

    // FIGHT
    if (y == 15)
        selectMove();
    else if (y == 16)
        selectPokemon();
}


// change
void Battle::selectPokemon()
{
    changeState = true;
}

void Battle::changePokemon()
{
    ;
    // change pokemon
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
        std::cout << "__";
        y1 -= 1;
        break;
        // DOWN
    case 80:
        std::cout << "_";
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

void Battle::selectMove()
{
    int x = 5, y = 15;
    system("cls");
    display();

    gotoxy(x, y);
    std::cout << "__MOVES__" << std::endl;
    std::cout << "     __ " << my_selected_pokemon->move.name << std::endl;;
    gotoxy(x, y + 1);
    std::cout << "O\b";

    if (getArrowkey(x, y))
    {
        Attack(*my_selected_pokemon, *other_selected_pokemon, my_selected_pokemon->move);
    }
}

void Battle::Attack(Pokemon& attakingPokemon, Pokemon& defendingPokemon, Move& move)
{
    system("cls");
    display();
    int x = 5, y = 15;
    gotoxy(x, y);
    int damage = calculateDamage(attakingPokemon, defendingPokemon, move);
    std::cout << "Damage : "<< damage << std::endl;
}

int Battle::calculateDamage(const Pokemon& attakingPokemon, Pokemon& defendingPokemon, const Move& move)
{
    float SametypeAttackbonus = 0.0f;
    if (checkSametypeAttackbonus() == true)
        SametypeAttackbonus = 1.5f;
    else
        SametypeAttackbonus = 1.0f;

    float Decision = 0.0f;
    // normal Attack
    if (move.move_type == 0)
    {
        Decision = attakingPokemon.Attack * move.power * SametypeAttackbonus;
    }
    // sepcial Attack
    else if (move.move_type == 1)
    {
        Decision = attakingPokemon.SpecialAttack * move.power * SametypeAttackbonus;
    }

    // 0.411 is correction dimension
    float durability = 0.0f;
    durability = defendingPokemon.HP * defendingPokemon.Defence * 0.411;

    // Damage calculate
    calculateType();
    calculateType();
    getRanmdomNumber();
    checkHitSpot();

    float damage = 0.0f;
    float HitSpot = 1.0f, Type1 = 1.0f, Type2 = 1.0f, RandomNumber = 85.0f;
    damage = Decision / durability * HitSpot * Type1 * Type2 * RandomNumber;

    return static_cast<int>(damage);
}

bool Battle::checkSametypeAttackbonus()
{
    return true;
}

float Battle::calculateType()
{
    return 0.5f;
}

bool Battle::checkHitSpot()
{
    // 6.25%
    return true;
}

int Battle::getRanmdomNumber()
{
    float RN = 85.0f;
    //(217 ~255) * 100 / 255
    return static_cast<int>(RN);
}
