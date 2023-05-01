#include "http_lib.h"

void Site::Header_print(){
	std::string dlmtr1("<h1>"), dlmtr2("</h1>");
	headerc = { 
		{"User-Agent","Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/110.0.0.0 YaBrowser/23.3.2.806 Yowser/2.5 Safari/537.36"},
		{"accept", "text/html"} };
	url=cpr::Url("http://httpbin.org/html");
	cpr::Response res = cpr::Get(url, headerc);
	auto start = res.text.find(dlmtr1) + dlmtr1.size();
	auto end = res.text.find(dlmtr2,start);
	std::cout << res.text.substr(start, end - start);
}

