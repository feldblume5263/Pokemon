#pragma once

#include <string>
#include <vector>

#include "Pokemon.h"

//class Move1
//{
//public:
//    std::string name;
//    std::string type;
//    int move_type;
//    int pp;
//    int max_pp;
//    int power;
//    int acc;
//
//    void fire_blast()
//    {
//        move_type = 0;
//        name = "fire_blast";
//        type = "fire";
//        pp = 5;
//        max_pp = 5;
//        power = 110;
//    int max_pp;
//        acc = 85;
//    }
//    void hydro_pump()
//    {
//        move_type = 0;
//        name = "hydro_pump";
//        type = "water";
//        power = 110;
//        pp = 5;
//        max_pp = 5;
//        acc = 80;
//    }
//    
//};
//
//class Pokemon1
//{
//public:
//    std::string name;
//	int maxHP;
//	int Attack;
//	int Defence;
//	int SpecialAttack;
//	int SpecialDefence;
//	int Speed;
//	// int IVs;
//    Move move[4];
//
//	std::string type1;
//	std::string type2;
//	std::string Nature;
//    
//    int HP;
//    bool liveState = true;
//
//	void gyarados()
//	{
//        name = "gyarados";
//        maxHP = 95;
//        HP = 95;
//		Attack = 125;
//		Defence = 79;
//		SpecialAttack = 60;
//		SpecialDefence = 100;
//		Speed = 81;
//
//        type1 = "water";
//        type2 = "fly";
//
//        move[0].hydro_pump();
//        move[1].hydro_pump();
//        move[2].hydro_pump();
//        move[3].hydro_pump();
//	}
//
//    void charizard()
//	{
//        name = "charizard";
//        
//        HP = 78;
//        maxHP = 78;
//		Attack = 84;
//		Defence = 78;
//		SpecialAttack = 109;
//		SpecialDefence = 85;
//		Speed = 100;
//
//        type1 = "fire";
//        type2 = "fly";
//
//        move[0].fire_blast();
//        move[1].fire_blast();
//        move[2].fire_blast();
//        move[3].fire_blast();
//	}
//
//    void setNature()
//    {
//
//    }
//};


class Player
{
public:
    Pokemon pokemon[6];
    std::vector<Pokemon*> pokemons;

    Player() {
    }

    void charizard()
    {
        int i = pokemons.size();
        pokemon[i].charizard();
        pokemons.push_back(&pokemon[i]);

    }
    void gyarados()
    {
        int i = pokemons.size();
        pokemon[i].gyarados();
        pokemons.push_back(&pokemon[i]);
    }
};

class Item
{
public:
    int item_type;
    int item_volume;
    std::string item_name;
    std::string item_description;
};

class HPRecoveryItem : public Item
{
public:
    int recovery_volume;
    
    void HyperPotion()
    {
        item_type = 0;
        item_volume = 2;
        item_name = "HyperPotion";
        item_description = "Spray-type wound drug. Restores 200 HP of 1 Pokemon.";
        recovery_volume = 200;
    }

    void MaxPotion()
    {
        item_type = 0;
        item_volume = 2;
        item_name = "MaxPotion";
        item_description = "Spray-type wound drug. Recover all HP of 1 Pokemon.";
        recovery_volume = 200;
    }

};

class MonsterBallItem : public Item
{
public:
    float chatchProbility;

    void HyperBall()
    {
        item_type = 1;
        item_volume = 2;
        item_name = "HyperBall";
        item_description = "A very high-performance ball that makes Pokemon easier to catch than a Super ball";
        chatchProbility = 99.0f;
    }
};

class MyPlayer : public Player
{
public:
    std::vector<Item*> items;

    MonsterBallItem MonsterBallItem;
    HPRecoveryItem HPRecoveryItem0;
    HPRecoveryItem HPRecoveryItem1;

    void setItems()
    {
        MonsterBallItem.HyperBall();
        items.push_back(&MonsterBallItem);

        HPRecoveryItem0.HyperPotion();
        items.push_back(&HPRecoveryItem0);

        HPRecoveryItem1.MaxPotion();
        items.push_back(&HPRecoveryItem1);
    }
};

class OtherPlayer : public Player
{
};






