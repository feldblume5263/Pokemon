#include"../include/skill.h"
#include<iostream>

Type SearchType(string type) {

	if (type == "") return Normal;
	if (type == "") return Fire;
	if (type == "") return Water;
	if (type == "") return Electric;
	if (type == "") return Grass;
	if (type == "") return Ice;
	if (type == "") return Fighting;
	if (type == "") return Poison;
	if (type == "") return Ground;
	if (type == "") return Flying;
	if (type == "") return Psychic;
	if (type == "") return Bug;
	if (type == "") return Rock;
	if (type == "") return Ghost;
	if (type == "") return Dragon;
	if (type == "") return Dark;
	if (type == "") return Steel;
	if (type == "") return Fairy;
	if (type == "") return None;

}
DamageType SearchDamageType(string damage_type) {
	if (damage_type == "") return Physical;
	if (damage_type == "") return Special;

}
Skill::Skill() {
	////from database/////////
	//this->name = "Thunderbolt";
	//this->power = 90;
	//this->accuracy=100;
	//this->type = Electric;
	//this->damage_type = Special;
	//this->pp = 20;
	//////////////////////////
	//this->remain_pp = this->pp;
}

Skill::Skill(string name) {

}
Skill::~Skill() {

}
string Skill::GetName() {
	return this->name;
}
int Skill::GetPower() {
	return this->power;
}
double Skill::GetAccuracy() {
	return this->accuracy;
}
Type Skill::GetType() {
	return this->type;
}
DamageType Skill::GetDamageType() {
	return this->damage_type;
}
int Skill::GetPP() {
	return this->remain_pp;
}
void Skill::SetName(wstring name) {
	string poke_name;
	poke_name.assign(name.begin(), name.end());
	this->name = poke_name;
}
void Skill::SetPower(int power) {
	this->power = power;

}
void Skill::SetAccuracy(double accuracy) {

	this->accuracy = accuracy;
}
void Skill::SetType(wstring type_name) {
	string name;
	name.assign(type_name.begin(), type_name.end());
	this->type = SearchType(name);
}
void Skill::SetDamageType(wstring damage_type_name) {
	string name;
	name.assign(damage_type_name.begin(), damage_type_name.end());
	this->type = SearchType(name);
}
void Skill::SetPP(int pp) {
	this->pp = pp;
}
void Skill::ShowInfo() {
	cout << this->name << endl;
}
void  Skill::ResetPP() {
	this->remain_pp = this->pp;
}
void Skill::ReducePP() {
	this->remain_pp--;
}
bool Skill::NoPP() {
	if (this->remain_pp == 0) {
		return true;
	}
	else {
		false;
	}

}