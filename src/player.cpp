#include "../include/player.h"
#include "../DB/Database.h"

Player::Player() {
    this->name = "Me";
    this->pos.x = 0;
    this->pos.y = 0;
    SetPlayerType(true);
}
Player::Player(string name) {

}
Player::~Player() {}

string Player::GetName() {
    return this->name;
}

void Player::SetName(string newName) {
    this->name = newName;
}

coord Player::GetPos() {
    return this->pos;
}

void Player::SetPos(coord c) {
    this->pos.x = c.x;
    this->pos.y = c.y;
}
Pokemon* Player::GetPokemon(int ind) {
    Pokemon *pokemon = this->pokemons[ind];
    return pokemon;
}
void Player::SetPokemon(string name) {
    Pokemon *pokemon = new Pokemon(name);
    requestPokemon(pokemon, name);
    this->pokemons.push_back(pokemon);
}
/*
void Player::SetPokemon1(string name) {
    Pokemon pokemon = Pokemon(name);
    requestPokemon(pokemon, name);
    this->pokemons[0] = pokemon;
}
*/


bool Player::GetPlayerType() {
    return this->playerType;
}

void Player::SetPlayerType(bool type) {
    this->playerType = type;
}


