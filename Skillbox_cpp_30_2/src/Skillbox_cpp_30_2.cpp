#include <iostream>
#include "http_lib.h"


int main() {
	Site site("httpbin.org");
	site.Header_print();
	return 0;
};