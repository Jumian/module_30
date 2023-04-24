#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "cpr/cpr.h"



class Site {
protected:
	cpr::Header headerc = cpr::Header({ {"User-Agent","Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/110.0.0.0 YaBrowser/23.3.2.806 Yowser/2.5 Safari/537.36"}});
	std::string name;
	cpr::Url urlc = cpr::Url("http://httpbin.org");
	void print(cpr::Response responce);
public:
	explicit Site(std::string _url) { urlc = cpr::Url(_url); }
	void get();
	void post();
	void put();
	void del();
	void patch();
};

