#include "Database.h"

Database::Database() {
	rd = new random_device();
	gen = new mt19937(rd);
}

Database::~Database() {
	delete rd;
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
			requestStats(pokemon, v);
			requestSkills(pokemon, v);
			}).wait();
		}).wait();

		
}

// TODO: setType1, setType2 만들어주세요!
void Database::requestTypes(Pokemon* pokemon, json::value& val) {
	cout << "requestTypes 호출." << endl;

	json::value type1, type2;
	auto types = val.at(L"types");
	json::array type_array = types.as_array();
	size_t type_num = type_array.size();

	// if requested json data have only one type
	if (type_num == 1) {
		// then only Type1 is set
		type1 = type_array.at(0);
		pokemon->setType1(type1.at(L"type").at(L"name").as_string());
	}
	else if (type_num == 2) {
		type1 = type_array.at(0);
		type2 = type_array.at(1);
		string_t type1_w = type1.at(L"type").at(L"name").as_string();
		string_t type2_w = type2.at(L"type").at(L"name").as_string();
		string type1_str, type2_str;

		type1_str.assign(type1_w.begin(), type1_w.end());
		type2_str.assign(type2_w.begin(), type2_w.end());
		pokemon->setType1(type1_str);
		pokemon->setType2(type2_str);
	}
	else if (type_num > 2) {
		// Use random type index for more than two types
		uniform_int_distribution<int> dis(0, type_num - 1);
		int type1_idx = dis(gen);
		int type2_idx = dis(gen);
		
		while (type1_idx == type2_idx) type2_idx = dis(gen);

		type1 = type_array.at(type1_idx);
		type2 = type_array.at(type2_idx);
		string_t type1_w = type1.at(L"type").at(L"name").as_string();
		string_t type2_w = type2.at(L"type").at(L"name").as_string();
		string type1_str, type2_str;

		type1_str.assign(type1_w.begin(), type1_w.end());
		type2_str.assign(type2_w.begin(), type2_w.end());
		pokemon->setType1(type1_str);
		pokemon->setType2(type2_str);
	}

	cout << "requestTypes 완료됨." << endl;
}

void Database::requestStats(Pokemon* pokemon, json::value& val) {

}

void Database::requestStats(Pokemon* pokemon, json::value& val) {

}