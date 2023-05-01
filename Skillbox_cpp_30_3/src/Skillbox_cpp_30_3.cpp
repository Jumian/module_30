#include <iostream>
#include "http_lib.h"


int main() {
	Site site("http://httpbin.org");
	std::string commands[3] = { "exit", "get", "post" };
	std::string command = "";
	int cmd;
	std::string key,value;
	while (true) {
		cmd = -1;
		key = value = "";
		
			std::cout << "Input new parameter key or command:\n";
			std::cin >> command;
			cmd = -1;
			for (int i = 0; i < 6; ++i) {
				if (command == commands[i]) {
					cmd = i; 
					break;
				}
			}
		
		switch (cmd) {
		case 0: 
			return 0;
		case 1:
			site.get();
			break;
		case 2:
			site.post();
			break;
		case -1:
		default:
			key = command;
			std::cout << "Input Value:\n";
			std::cin >> value;
			command = "";
			if (site.check_param(key, value)) {
				std::cout << "parameter ACCEPTED: key = \"" << key << "\", value = \""<< value<<"\"" << std::endl;
			}
			else {
				std::cout << "parameter REJECTED: key = \"" << key << "\", value = \"" << value << "\"" << std::endl;
			}
			break;
		}
	}
	return 0;
};