#pragma once
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include "include/pokemon.h"
#include <iostream>
#include <random>
#include <chrono>

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
	void requestStats(Pokemon*, json::value&);
	void requestSkills(Pokemon*, json::value&);

private:
	const string URI = "https://pokeapi.co/api/v2/";
	random_device *rd;
	mt19937 *gen;
	
};

