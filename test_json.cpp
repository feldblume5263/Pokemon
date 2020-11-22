#pragma comment (lib, "lib_json.lib")

#include <iostream>
#include <fstream>
#include "json/json.h"

using namespace std;
using namespace Json;

int main()
{
	ofstream json_file;
	json_file.open("JSON_DATA.json");

	Value Computer;
	Computer["CPU"] = "17";
	Computer["RAM"] = "16G";

	Value Language;
	Language["C++"] = "Visual Studio";
	Language["Python"] = "IDLE";

	Computer["Program"] = Language;
	Computer["HDD"] = "2TB";

	StreamWriterBuilder builder;
	builder["commentStyle"] = "None";
	builder["identation"] = "	";
	unique_ptr<StreamWriter> writer(builder.newStreamWriter());

	writer->write(Computer, &cout);
	writer->write(Computer, &json_file);
	cout << endl;

	json_file.close();
	return 0;
}