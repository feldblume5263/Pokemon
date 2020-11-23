#pragma once
#include <string>
#include <vector>

class Move
{
public:
    std::string name;
    std::string type;
    int move_type;
    int pp;
    int power;
    int acc;

    void fire_blast()
    {
        move_type = 0;
        name = "fire_blast";
        type = "fire";
        pp = 5;
        power = 110;
        acc = 85;
    }
    void hydro_pump()
    {
        move_type = 0;
        name = "hydro_pump";
        type = "water";
        power = 110;
        pp = 5;
        acc = 80;
    }
    
};

class Pokemon
{
public:
    std::string name;
	int HP;
	int Attack;
	int Defence;
	int SpecialAttack;
	int SpecialDefence;
	int Speed;
	// int IVs;
    Move move;

	std::string type1;
	std::string type2;
	std::string Nature;

    bool liveState = true;

	void gyarados()
	{
        name = "gyarados";
		HP = 95;
		Attack = 125;
		Defence = 79;
		SpecialAttack = 60;
		SpecialDefence = 100;
		Speed = 81;

        type1 = "water";
        type2 = "fly";

        move.hydro_pump();
	}

    void charizard()
	{
        name = "charizard";
        HP = 78;
		Attack = 84;
		Defence = 78;
		SpecialAttack = 109;
		SpecialDefence = 85;
		Speed = 100;

        type1 = "fire";
        type2 = "fly";

        move.fire_blast();
	}

    void setNature()
    {

    }
};

class Player
{
public:
    std::vector<Pokemon*> pokemons;
    int test = 3;

    Player()
    {
        
    }

    void charizard()
    {
        Pokemon pokemon1;
        pokemon1.charizard();
        pokemons.push_back(&pokemon1);
    }
    void gyarados()
    {
        Pokemon pokemon1;
        pokemon1.gyarados();
        pokemons.push_back(&pokemon1);
    }
};




class Test
{
public:

    Test(int& i1, int& i2)
    {
        doSomething(i1, i2);
    }

    void doSomething(int& i1, int& i2)
    {
        i1 += 100;
        i2 += 100;
    }


};

