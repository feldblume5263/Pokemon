#include"pokemon.h"
#include<random>
#include<cmath>
#include<iostream>

Pokemon::Pokemon(){
	this->name = "Pikachu";
	this->base_health_point = 35;
	this->base_attack = 55;
	this->base_block = 40;
	this->base_contact = 50;
	this->base_defense = 50;
	this->base_speed = 90;
	this->type1 = Electric;
	this->type2 = None;
	SetIndiStat();
	SetEffStat();
	SetStat();
	this->remain_hp = this->health_point;
	for (int i = 0; i < 4; i++) {
		this->moves[i] = Skill();
	}
}
Pokemon::Pokemon(string name) {
//데이터 베이스에서 가져옴

}
Pokemon::~Pokemon() {}
void Pokemon::SetStat() {

	health_point = ceil((base_health_point * 2 + indi_health_point + eff_health_point / 4) / 2 + 10 + 50);
	//(종족값 * 2 + 개체값 + 노력치 / 4) / 2 + 10 + 50(레벨)
	attack = ceil((base_attack * 2 + indi_attack + eff_attack / 4) / 2 + 5);
	block = ((base_block * 2 + indi_block + eff_block / 4) / 2 + 5);
	contact = ceil((base_contact * 2 + indi_contact + eff_contact / 4) / 2 + 5);
	defense = ceil((base_defense * 2 + indi_defense + eff_defense / 4) / 2 + 5);
	speed = ceil((base_speed * 2 + indi_speed + eff_speed / 4) / 2 + 5);
	//{(종족값*2+개체값+노력치/4)/2+5}*(성격 보정)



}
void Pokemon::SetIndiStat(){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 31);
	this->indi_health_point = dis(gen);
	this->indi_attack = dis(gen);
	this->indi_block = dis(gen);
	this->indi_contact = dis(gen);
	this->indi_defense = dis(gen);
	this->indi_speed = dis(gen);
}
void Pokemon::SetEffStat() {
	this->eff_health_point = 0;
	this->eff_attack = 0;
	this->eff_block = 0;
	this->eff_contact = 0;
	this->eff_defense = 0;
	this->eff_speed = 0;
	
	
	int i = 0;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 6);
	for (i = 0; i < 510; i++) {
		int select = dis(gen);
		switch (select) {
		case 1:
			if (this->eff_health_point < 253) {
				this->eff_health_point++;
				
			}
			continue;

		case 2:
			if (this->eff_attack < 253) {
				this->eff_attack++;
				
			}
			continue;
		case 3:
			if (this->eff_block < 253) {
				this->eff_block++;
				

			}
			continue;
		case 4:
			if (this->eff_contact < 253) {
				this->eff_contact++;
				
			}
			continue;
		case 5:
			if (this->eff_defense < 253) {
				this->eff_defense++;
				
			}
			continue;

		
		case 6:
			if (this->eff_speed < 253) {
				this->eff_speed++;

			}
			continue;

	}
	}
}
bool Pokemon::Attack(Pokemon& target, Skill attack) {
	double attack_power;
	double defense_power;

	double rate;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);
	if (dis(gen) < attack.GetAccuracy()) {
		
		if (attack.GetDamageType() == Physical) {

			if (this->GetType1() == attack.GetType() || this->GetType2() == attack.GetType()) {
				attack_power = this->GetAttack() * attack.GetPower() * 1.5;
			}
			else {
				attack_power = this->GetAttack() * attack.GetPower();
			}
			defense_power = ceil(target.GetBlock() * target.GetRemainHp() / 0.411);
			rate = attack_power / defense_power * type_damage_rate[attack.GetType()][target.GetType1()] *
				type_damage_rate[attack.GetType()][target.GetType2()];
			target.SetRemainHp(rate);

		}
		else {

			if (this->GetType1() == attack.GetType() || this->GetType2() == attack.GetType()) {
				attack_power = this->GetContact() * attack.GetPower() * 1.5;
			}
			else {
				attack_power = this->GetContact() * attack.GetPower();
			}
			defense_power = ceil(target.GetDefense() * target.GetRemainHp() / 0.411);
			rate = attack_power / defense_power * type_damage_rate[attack.GetType()][target.GetType1()] *
				type_damage_rate[attack.GetType()][target.GetType2()];
			target.SetRemainHp(rate);

		}
		return true;
	}
	else {
		
		false;
	}



}
void Pokemon::SetAlive(bool life) {
	if (life) {
		this->alive = true;
	}
	else {
		this->alive = false;
	}
}
bool Pokemon::Alive() {
	return this->alive;
}
void Pokemon::SetRemainHp(double rate) {
	if (this->remain_hp - (int)ceil(this->remain_hp * rate) > 0) {
		this->remain_hp = (int)(this->remain_hp - ceil(this->remain_hp * rate));
	}
	else {
		this->remain_hp = 0;
		this->SetAlive(0);
	}

}
double Pokemon::GetRemainHp() {
	return this->remain_hp;
}
int Pokemon::GetHealthPoint() {
	return this->health_point;
}
int Pokemon::GetAttack() {
	return this->attack;
}
int Pokemon::GetBlock() {
	return this->block;
}
int Pokemon::GetContact() {
	return this->contact;
}
int Pokemon::GetDefense() {
	return this->defense;
}
int Pokemon::GetSpeed() {
	return this->speed;
}
Type Pokemon::GetType1() {
	return this->type1;
}
Type Pokemon::GetType2() {
	return this->type2;
}
void Pokemon::ShowInfo() {
	cout << this->name << endl;
	cout << "hp:" << this->remain_hp <<"/" << this->health_point << endl;

	cout << "attack:" << this->attack << endl;

	cout << "block:" << this->block << endl;

	cout << "contact:" << this->contact << endl;

	cout << "defense:" << this->defense << endl;

	cout << "speed:" << this->speed << endl;
	
	for (int i = 0; i < 4; i++) {
		this->moves[i].ShowInfo();
	}
}
Skill Pokemon::GetSkill1() {
	return this->moves[0];
}

Skill Pokemon::GetSkill2() {
	return this->moves[1];
}

Skill Pokemon::GetSkill3(){
	return this->moves[2];
}
Skill Pokemon::GetSkill4() {
	return this->moves[3];
}


int main() {
	Pokemon test = Pokemon();
	Pokemon test1 = Pokemon();
	test1.ShowInfo();
	test.Attack(test1,test.GetSkill1());
	test1.ShowInfo();
	return 0;
}