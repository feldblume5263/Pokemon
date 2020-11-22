#include"skill.h"
#include<iostream>
Skill::Skill(){
	this->name = "Thunderbolt";
	this->power = 90;
	this->accuracy=100;
	this->type = Electric;
	this->damage_type = Special;
}

Skill::Skill(string name) {
	
}
Skill::~Skill() {

}
string Skill::GetName() {
	return this->name;
}
int Skill::GetPower(){
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
void Skill::ShowInfo() {
	cout << this->name<<endl;
}