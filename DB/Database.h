#pragma once
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include "include/skill.h"
#include "include/pokemon.h"
#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace std;

class Database
{
public:
	Database();
	~Database();
	void requestPokemon(Pokemon*, string);
	void requestTypes(Pokemon*, json::value&);
	void requestBaseStats(Pokemon*, json::value&);
	void requestSkills(Pokemon*, json::value&);
	void requestSkillURL(Pokemon*, string_t&, size_t&);

private:
	const string URI = "https://pokeapi.co/api/v2/";
	random_device *rd;
	mt19937 *gen;
};

/*
	this->name = "Thunderbolt";
	this->power = 90;
	this->accuracy = 100;
	this->type = Electric;
	this->damage_type = Special;
	this->pp = 20;
*/