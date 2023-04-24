#include <iostream>
#include "http_lib.h"


int main() {
	Site site("http://httpbin.org");

	std::string commands[6] = { "exit", "get", "post", "put", "delete", "patch" };
	std::string command = "no";
	int cmd;
	while (true) {
		cmd = -1;
		while (cmd<0) {
			std::cout << "Input new command:\n";
			std::cin >> command;
			cmd = -1;
			for (int i = 0; i < 6; ++i) {
				if (command == commands[i]) {
					cmd = i; break;
				}
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
		case 3:
			site.put();
			break;
		case 4:
			site.del();
			break;
		case 5:
			site.patch();
			break;
		default:
			command = "no";
			break;
		}
	}
	return 0;
};