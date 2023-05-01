#pragma once

#include <string>
#include <iostream>
#include <map>

#include "cpr/cpr.h"



class Site {
protected:
	cpr::Header headerc ;
	std::string name;
	cpr::Url urlc;
	std::vector<cpr::Pair> parameters;
	cpr::Parameters* params;
	cpr::Payload* payload;
	cpr::Session session;
	void print(cpr::Response responce);
	void add_param(std::string _key, std::string _value);
	void update_params();
	void update_payload();
public:
	explicit Site(std::string _url);
	void get();
	void post();
	bool check_param(std::string & _key, std::string &_value);
};

