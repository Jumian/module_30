#pragma once


#include <string>
#include <iostream>
#include <vector>
#include "cpr/cpr.h"



class Site {
protected:
	const static std::string ur;
	cpr::Header headerc;
	cpr::Url url;
public:

	explicit Site(std::string _url) { url = cpr::Url(_url); }
	void Header_print();

};

