#include"../include/skill.h"
#include<iostream>
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
int Skill::GetPP() {
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