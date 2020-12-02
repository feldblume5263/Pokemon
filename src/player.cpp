#include "../include/player.h"
//#include "../DB/Database.h"

Player::Player() {

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
CatchedPokemon* Player::GetPokemon(int ind) {
    CatchedPokemon *pokemon = this->pokemons[ind];
    return pokemon;
}
void Player::SetPokemon(string name) {
    CatchedPokemon*pokemon = new CatchedPokemon(name);
    //requestPokemon(pokemon, name);
    this->pokemons.push_back(pokemon);
}

void Player::SetPokemon() {
    CatchedPokemon* pokemon = new CatchedPokemon();
    this->pokemons.push_back(pokemon);
}
void Player::SetPokemon(CatchedPokemon* pokemonPtr, int ind)
{
    pokemons[ind] = pokemonPtr;
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

// change : add function
vector<CatchedPokemon*> Player::getPokemonsVector()
{
    return pokemons;
}


