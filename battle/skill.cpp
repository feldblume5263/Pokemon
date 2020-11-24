#include "skill.h"

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
int Skill::GetRemainPP() {
	return this->remain_pp;
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










// GETPP -> GetRemainPP
int Skill::GetPP()
{
	return pp;
}

void Skill::SetRmainPP(int _remina_pp)
{
	this->remain_pp = _remina_pp;
}

void Skill::fire_blast()
{
	damage_type = Physical;
	name = "fire_blast";
	type = Fire;
	pp = 5;
	remain_pp = 5;
	power = 110;
	int max_pp;
	accuracy = 85;
}

void Skill::hydro_pump()
{
	damage_type = Physical;
	name = "hydro_pump";
	type = Water;
	power = 110;
	pp = 5;
	remain_pp = 5;
	accuracy = 80;
}
