#include "../include/player.h"


OtherPlayer::OtherPlayer()
{
    this->name = "ROSA";
    this->pos.x = 0;
    this->pos.y = 0;
    SetPlayerType(false);
    setLiveState(true);
}

void OtherPlayer::setLiveState(bool _liveState)
{
    liveState = _liveState;
}
bool OtherPlayer::getLiveState()
{
    return (liveState);
}

Player::Player()
{

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

void Player::SetPos(int x, int y)
{
    this->pos.x = x;
    this->pos.y = y;
}

void Player::SetPos(coord c) {
    this->pos.x = c.x;
    this->pos.y = c.y;
}
CatchedPokemon* Player::GetPokemon(int ind) {
    CatchedPokemon *pokemon = this->pokemons[ind];
    return pokemon;
}
// 메인 쓰레드가  requestPokemon()이 끝날때까지 기다려줌
void Player::SetPokemon(string name) {
    CatchedPokemon*pokemon = new CatchedPokemon(name);
    //Database database();

    Database database = Database();
    database.requestPokemon(pokemon, name);
    //std::thread thr1(database.requestPokemon, pokemon, name);
    //thr1.join();

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

MyPlayer::MyPlayer()
{
    this->name = "Me";
    this->pos.x = 0;
    this->pos.y = 0;
    SetPlayerType(true);

    initItems();
}

MyPlayer::~MyPlayer()
{
}

std::vector<Item*> MyPlayer::getItems()
{
    return items;
}

Item* MyPlayer::getItem(int ix)
{
    return items[ix];
}

void MyPlayer::initItems()
{
    Item* monsterball = new Item("HyperBall");
    this->items.push_back(monsterball);

    Item* hppotion1 = new Item("HyperPotion");
    this->items.push_back(hppotion1);

    Item* hppotion2 = new Item("MaxPotion");
    this->items.push_back(hppotion2);

    //MonsterBallItem* monsterball = new MonsterBallItem("HyperBall");
    //this->items.push_back(monsterball);

    //HPRecoveryItem* hppotion1 = new HPRecoveryItem("HyperPotion");
    //this->items.push_back(hppotion1);

    //HPRecoveryItem* hppotion2 = new HPRecoveryItem("MaxPotion");
    //this->items.push_back(hppotion2);
}
