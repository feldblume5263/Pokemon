#include"../include/skill.h"
#include<iostream>

Type searchType(string type) {

	if (type == "normal") return Normal;
	if (type == "fire") return Fire;
	if (type == "water") return Water;
	if (type == "electric") return Electric;
	if (type == "grass") return Grass;
	if (type == "ice") return Ice;
	if (type == "fighting") return Fighting;
	if (type == "poison") return Poison;
	if (type == "ground") return Ground;
	if (type == "flying") return Flying;
	if (type == "psychic") return Psychic;
	if (type == "bug") return Bug;
	if (type == "rock") return Rock;
	if (type == "ghost") return Ghost;
	if (type == "dragon") return Dragon;
	if (type == "dark") return Dark;
	if (type == "steel") return Steel;
	if (type == "fairy") return Fairy;
	if (type == "none") return None;

}
DamageType searchDamageType(string damage_type) {
	if (damage_type == "") return Physical;
	if (damage_type == "") return Special;

}
Skill::Skill() {
	//from database/////////
	this->name = "Thunderbolt";
	this->power = 90;
	this->accuracy = 100;
	this->type = Electric;
	this->damage_type = Special;
	this->pp = 20;
	////////////////////////
	this->remain_pp = this->pp;
}

Skill::Skill(string name) {

}
Skill::~Skill() {

}
string Skill::getName() {
	return this->name;
}
int Skill::getPower() {
	return this->power;
}
double Skill::getAccuracy() {
	return this->accuracy;
}
Type Skill::getType() {
	return this->type;
}
DamageType Skill::getDamageType() {
	return this->damage_type;
}
int Skill::getPP() {
	return this->remain_pp;
}
void Skill::setName(string name) {
	string poke_name;
	poke_name.assign(name.begin(), name.end());
	this->name = poke_name;
}
void Skill::setPower(int power) {
	this->power = power;

}
void Skill::setAccuracy(int accuracy) {

	this->accuracy = accuracy;
}
void Skill::setType(string type_name) {

	this->type = searchType(type_name);
}
void Skill::setDamageType(string damage_type_name) {
	string name;
	name.assign(damage_type_name.begin(), damage_type_name.end());
	this->type = searchType(name);
}
void Skill::setPP(int pp) {
	this->pp = pp;
}
int Skill::GetRemainPP() {
	return this->remain_pp;
}
void Skill::setRemainPP(int remain_pp) {
	this->remain_pp = remain_pp;
}
int Skill::GetPP()
{
	return this->pp;
}
void Skill::showInfo() {
	cout << this->name << endl;
}
void  Skill::resetPP() {
	this->remain_pp = this->pp;
}
void Skill::reducePP() {
	this->remain_pp--;
}
bool Skill::noPP() {
	if (this->remain_pp == 0) {
		return true;
	}
	else {
		false;
	}

}