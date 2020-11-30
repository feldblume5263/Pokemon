#include "../include/player.h"

Player::Player() {
    this->name = "Me";
    this->pos.x = 0;
    this->pos.y = 0;
    SetPlayerType(true);
    //SetPokemons();
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
Pokemon Player::GetPokemon1() {
    return this->pokemons[0];
}
Pokemon Player::GetPokemon2() {
    return this->pokemons[1];
}
Pokemon Player::GetPokemon3() {
    return this->pokemons[2];
}
Pokemon Player::GetPokemon4() {
    return this->pokemons[3];
}
/*
Pokemon Player::SetPokemons() {

}
*/

bool Player::GetPlayerType() {
    return this->playerType;
}

void Player::SetPlayerType(bool type) {
    this->playerType = type;
}
