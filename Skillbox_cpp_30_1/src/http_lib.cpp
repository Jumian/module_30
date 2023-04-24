#include "http_lib.h"

void Site::get(){
	cpr::Header header = headerc;
	cpr::Url url = urlc + "/get";
	cpr::Response res = cpr::Get(url, header);
	print(res);
}
void Site::post()
{
	cpr::Header header = headerc;
	cpr::Url url = urlc + "/post";
	cpr::Response res = cpr::Post(url, header);
	print(res);
}
void Site::put()
{
	cpr::Url url = urlc + "/put";
	cpr::Header header = headerc;
	cpr::Response res = cpr::Put(url, headerc);
	print(res);
}
void Site::del()
{
	cpr::Header header = headerc;
	header.insert({ {"accept","application/json"} });
	cpr::Url url = urlc + "/delete";
	cpr::Response res = cpr::Delete(url,header);
	print(res);
}
void Site::patch()
{
	cpr::Header header = headerc;
	cpr::Url url = urlc + "/patch";
	cpr::Response res = cpr::Patch(url, header);
	print(res);
}

void Site::print(cpr::Response responce)
{
	std::cout << responce.text << std::endl;
}

