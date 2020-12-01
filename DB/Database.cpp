#include "Database.h"

Database::Database() {
	random_device rd;
	gen = new mt19937(rd());
}

Database::~Database() {
	delete gen;
}

void Database::requestPokemon(Pokemon* pokemon, string name) {
	string queryParams = "pokemon/" + name;
	string fullURI = URI + queryParams;
	string_t wfullURI;

	wfullURI.assign(fullURI.begin(), fullURI.end());
	uri_builder builder(wfullURI);

	uri resource(builder.to_uri());
	http_client client(resource);

	http_request req(methods::GET);
	client.request(req).then([=](http_response r) {
		wcout << U("STATUS : ") << r.status_code() << endl;
		wcout << "Content-Type : " << r.headers().content_type() << endl;
		r.extract_json(true).then([&](web::json::value v) {
			requestTypes(pokemon, v);
			requestBaseStats(pokemon, v);
			requestSkills(pokemon, v);
			}).wait();
		}).wait();

		
}

void Database::requestTypes(Pokemon* pokemon, json::value& val) {

	json::value type1, type2;
	auto types = val.at(L"types");
	json::array type_array = types.as_array();
	size_t type_num = type_array.size();

	// if requested json data have only one type
	if (type_num == 1) {
		// then only Type1 is set
		type1 = type_array.at(0);
		string_t type1_w = type1.at(L"type").at(L"name").as_string();
		string type1_str(type1_w.begin(), type1_w.end());
		
		pokemon->setType1(type1_str);
		pokemon->setType2("none");
	}
	else if (type_num == 2) {
		type1 = type_array.at(0);
		type2 = type_array.at(1);
		string_t type1_w = type1.at(L"type").at(L"name").as_string();
		string_t type2_w = type2.at(L"type").at(L"name").as_string();
		string type1_str(type1_w.begin(), type1_w.end());
		string type2_str(type2_w.begin(), type2_w.end());

		pokemon->setType1(type1_str);
		pokemon->setType2(type2_str);
	}
	else if (type_num > 2) {
		// Use random type index for more than two types
		uniform_int_distribution<int> dis(0, type_num - 1);
		int type1_idx = dis(*gen);
		int type2_idx = dis(*gen);
		
		while (type1_idx == type2_idx) type2_idx = dis(*gen);

		type1 = type_array.at(type1_idx);
		type2 = type_array.at(type2_idx);
		string_t type1_w = type1.at(L"type").at(L"name").as_string();
		string_t type2_w = type2.at(L"type").at(L"name").as_string();
		string type1_str(type1_w.begin(), type1_w.end());
		string type2_str(type2_w.begin(), type2_w.end());

		pokemon->setType1(type1_str);
		pokemon->setType2(type2_str);
	}

}
// hp, attack, defense, special-attack, special-defense, speed

void Database::requestBaseStats(Pokemon* pokemon, json::value& val) {
	auto stats = val.at(L"stats");

	json::array stats_array = stats.as_array();
	for (auto it = stats_array.cbegin(); it != stats_array.cend(); it++) {
		int base_stat = it->at(L"base_stat").as_integer();
		string_t wstat_name = it->at(L"stat").at(L"name").as_string();
		string stat_name;

		stat_name.assign(wstat_name.begin(), wstat_name.end());
		pokemon->setBaseStat(stat_name, base_stat);
	}
}

void Database::requestSkills(Pokemon* pokemon, json::value& val) {
	auto moves = val.at(L"moves");

	json::array moves_array = moves.as_array();
	size_t num_of_moves = moves_array.size();
	vector<bool> is_used_move;

	uniform_int_distribution<int> dis(0, num_of_moves - 1);
	size_t num_of_available_moves = num_of_moves;
	size_t move_setting_idx = 0;
	is_used_move.assign(num_of_moves, false);

	while (num_of_available_moves != 0) {
		int move_idx = dis(*gen);
		if (!is_used_move[move_idx]) {
			auto move = moves_array.at(size_t(move_idx));
			string_t url = move.at(L"move").at(L"url").as_string();
			is_used_move[move_idx] = true;
			num_of_available_moves -= 1;
			
			requestSkillURL(pokemon, url, move_setting_idx);
			if (move_setting_idx == 4) return;
		}
	}
}

void Database::requestSkillURL(Pokemon* pokemon, string_t& url, size_t& move_setting_idx) {
	uri_builder builder(url);

	uri resource(builder.to_uri());
	http_client client(resource);

	http_request req(methods::GET);

	client.request(req).then([pokemon, &move_setting_idx](http_response r) {
		
		r.extract_json(true).then([pokemon, &move_setting_idx](web::json::value v) {
			if (v.at(L"power").is_null()) {
				return;
			}
			else {
				Skill* added_skill = new Skill();
				string_t wname = v.at(L"name").as_string();
				string_t wdamage_type = v.at(L"damage_class").at(L"name").as_string();
				string_t wtype = v.at(L"type").at(L"name").as_string();
				int power = v.at(L"power").as_integer();
				int accuracy = v.at(L"accuracy").as_integer();
				int pp = v.at(L"pp").as_integer();

				string name(wname.begin(), wname.end());
				string damage_type(wdamage_type.begin(), wdamage_type.end());
				string type(wtype.begin(), wtype.end());

				added_skill->setName(name);
				added_skill->setDamageType(damage_type);
				added_skill->setType(type);
				added_skill->setPower(power);
				added_skill->setAccuracy(accuracy);
				added_skill->setPP(pp);

				pokemon->setSkill(move_setting_idx, added_skill);
				move_setting_idx += 1;
			}

			}).wait();
		}).wait();
}