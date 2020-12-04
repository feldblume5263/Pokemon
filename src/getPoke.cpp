//#include<iostream>
//#include<string>
//#include <vector>
//#include <random>
//using namespace std;
//
//void printPokemon() {
//	cout << "--------------------------------" << endl;
//	cout << "Pokemon List" << endl;
//	cout << "--------------------------------" << endl;
//	cout << "1.venusaur		(이상해꽃)" << endl;
//	cout << "2.charizard		(리자몽)" << endl;
//	cout << "3.blastoise		(거북왕)" << endl;
//	cout << "4.butterfree		(버터플)" << endl;
//	cout << "5.pidgeot		(피죤투)" << endl;
//	cout << "6.pikachu		(피카츄)" << endl;
//	cout << "7.alakazam		(후딘)" << endl;
//	cout << "8.scyther		(스라크)" << endl;
//	cout << "9.gyarados		(갸라도스)" << endl;
//	cout << "10.lapras		(라프라스)" << endl;
//	cout << "11.vaporeon		(샤미드)" << endl;
//	cout << "12.jolteon		(쥬피썬더)" << endl;
//	cout << "13.flareon		(부스터)" << endl;
//	cout << "14.snorlax		(잠만보)" << endl;
//	cout << "--------------------------------" << endl;
//}
//
//bool validPokemon(string poke_name) {
//
//
//	if (poke_name == "venusaur") return true;
//	if (poke_name == "charizard") return true;
//	if (poke_name == "blastoise") return true;
//	if (poke_name == "butterfree") return true;
//	if (poke_name == "pidgeot") return true;
//	if (poke_name == "pikachu") return true;
//	if (poke_name == "alakazam") return true;
//	if (poke_name == "scyther") return true;
//	if (poke_name == "gyarados") return true;
//	if (poke_name == "lapras") return true;
//	if (poke_name == "vaporeon") return true;
//	if (poke_name == "jolteon") return true;
//	if (poke_name == "flareon") return true;
//	if (poke_name == "snorlax") return true;
//	cout << "Invalide Pokemon Name" << endl;
//	return false;
//
//}
//
//vector<string> getRandomPokemon() {
//	string list[14] = { "venusaur","charizard","blastoise","butterfree","pidgeot","pikachu",
//		"alakazam","scyther","gyarados","lapras","vaporeon","jolteon","flareon","snorlax" };
//	vector<string> ret;
//	random_device rd;
//	mt19937 gen(rd());
//	uniform_int_distribution<int> dis(0, 13);
//	bool check[14] = { false, };
//	int idx;
//	for (int i = 0; i < 3;) {
//		idx = dis(gen);
//		if (!check[idx]) {
//			ret.push_back(list[idx]);
//			check[idx] = true;
//			i++;
//		}
//
//	}
//	return ret;
//}
//
//vector<string> selectPokemon() {
//	
//	vector<string> ret;
//	printPokemon();
//	cout << "You can choose 3 pokemons" << endl;
//	for (int i = 0; i < 3;) {
//		string temp;
//		cout << "Enter name of pokemon in English:";
//		cin >> temp;
//		if (validPokemon(temp)) {
//			ret.push_back(temp);
//			cout << "Pokemon added"<<endl;
//			i++;
//		}
//
//	}
//	return ret;
//
//
//}
//string getImoji(string poke_name) {
//	string ret;
//	if (poke_name == "venusaur") 
//	if (poke_name == "charizard") 
//	if (poke_name == "blastoise") 
//	if (poke_name == "butterfree") 
//	if (poke_name == "pidgeot") 
//	if (poke_name == "pikachu") 
//	if (poke_name == "alakazam") 
//	if (poke_name == "scyther") 
//	if (poke_name == "gyarados") 
//	if (poke_name == "lapras") 
//	if (poke_name == "vaporeon") 
//	if (poke_name == "jolteon") 
//	if (poke_name == "flareon") 
//	if (poke_name == "snorlax") 
//                             
//	return ret;
//
//}
//
//// int main() {
//	
//
//	// //vector<string> pokemons = selectPokemon();
//	// /*vector<string> random = getRandomPokemon();
//	// for (int i = 0; i < 3; i++) {
//		// cout << random[i] << endl;;
//	// }*/
//	// return 0;
//
//// }