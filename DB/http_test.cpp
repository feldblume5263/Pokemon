#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <iostream>

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;
using namespace std;

int main()
{
	const string URI = "https://pokeapi.co/api/v2/";
	string queryParams = "pokemon/ditto";

	uri_builder builder(U("https://pokeapi.co/api/v2/pokemon/ditto"));
	wcout << builder.to_string() << "\n";
	uri u(builder.to_uri());
	http_client client(u);

	pplx::task<http_response> responseTask = client.request(methods::GET);
	http_response response = responseTask.get();
	utility::string_t str = response.extract_string().get();

	wcout << str.c_str() << endl;
	

	return 0;

}