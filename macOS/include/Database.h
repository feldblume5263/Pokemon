#ifndef DATABASE_H
#define DATABASE_H

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>


//#include "../include/cpprestsdk_x64-windows/include/cpprest/http_client.h"
//#include "../include/cpprestsdk_x64-windows/include/cpprest/filestream.h"

#include "skill.h"
#include "pokemon.h"
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

private:
	void requestTypes(Pokemon*, json::value&);
	void requestBaseStats(Pokemon*, json::value&);
	void requestSkills(Pokemon*, json::value&);
	void requestSkillURL(Pokemon*, string_t&, size_t&);

	const string URI = "https://pokeapi.co/api/v2/";
	mt19937 *gen;
};

#endif
