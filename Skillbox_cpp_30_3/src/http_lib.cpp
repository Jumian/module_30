#include "http_lib.h"

Site::Site(std::string _url) { 
	urlc = cpr::Url(_url);
	headerc = cpr::Header({
		{"User-Agent","Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/110.0.0.0 YaBrowser/23.3.2.806 Yowser/2.5 Safari/537.36"},
		{"Accept","text/html"}
		});
	parameters.clear();
	params = nullptr;
	payload = nullptr;
	session.SetHeader(headerc);
	
}

Site::~Site() {
	delete params;
	delete payload;
}

void Site::get(){
	update_params();
	cpr::Url url = urlc + "/get";
	session.SetUrl(url);
	session.SetParameters(*params);
	cpr::Response res = session.Get();
	print(res);
}

void Site::post()
{
	update_payload();
	cpr::Url url = urlc + "/post";
	session.SetUrl(url);
	session.SetPayload(*payload);
	cpr::Response res = session.Post();
	print(res);
	
}
void Site::update_params() {
	delete params;
	
	params = nullptr;
	params = new cpr::Parameters;
	for (auto it = parameters.begin(); it != parameters.end(); it++) {
		std::string key = it._Ptr->key; std::string value = it._Ptr->value;
		params->Add({ {key,value} });
	}
	parameters.clear();
}

void Site::update_payload()
{
	delete payload;
	payload = nullptr;
	payload = new cpr::Payload(parameters.begin(),parameters.end());
	parameters.clear();
}

bool Site::check_param(std::string& _key, std::string& _value)
{
	if (_key.size() <= 0 || _value.size() <= 0) {
		return false;
	}
	std::pair<std::string,std::string> pair(_key, _value);
	add_param(pair.first,pair.second);
	return true;
}

void Site::add_param(std::string _key, std::string _value)
{
	parameters.push_back(cpr::Pair(_key, _value));
}



void Site::print(cpr::Response responce)
{
	std::cout << responce.text << std::endl;
}

