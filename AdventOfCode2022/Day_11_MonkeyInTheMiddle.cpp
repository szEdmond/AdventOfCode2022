#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

struct Monkey {
	int id;

	//items, = worry level
	std::vector<unsigned long long> items;
	//operation on item(worry level)
	std::string operation;

	int divider;
	int truThrowId;
	int falsThrowId;
	int counter = 0;


	// THIS SHOULD BE OPTIMISED
	void doOperation(unsigned long long& worrylevel) {
		std::string temp;
		int num;
		std::stringstream sstr;
		sstr << operation;
		if (operation == "* old") {
			worrylevel *= worrylevel;
			
		}
		else {
			while (!sstr.eof()) {
				sstr >> temp;
				if (std::stringstream(temp) >> num) {}
				temp = "";
			}
			if (operation[0] == '+') 
				worrylevel += num;
			else if (operation[0] == '*') 
				worrylevel *= num;
		}
	}

};

int main()
{
	std::ifstream f("input/day11.txt");
	std::string line;
	
	std::vector<Monkey*> monkeys;

	std::vector<std::string> monke;

	while (std::getline(f, line)) {
		monke.push_back(line);
		if (line == "") {
			// line 0
			Monkey* tempmonke = new Monkey();
			tempmonke->id = monke[0][7] - '0';

			//line 1
			std::stringstream ss;
			int tempitem;
			std::string tempstr;
			ss << monke[1];
			while (!ss.eof()) {
				ss >> tempstr;
				if (std::stringstream(tempstr) >> tempitem) {
					tempmonke->items.push_back(tempitem);
				}
				tempstr = "";
			}
			
			//line 2
			tempmonke->operation = monke[2].substr(23, monke[2].size());

			//line 3 divisible by
			ss.clear();
			ss << monke[3];
			while (!ss.eof()) {
				ss >> tempstr;
				if (std::stringstream(tempstr) >> tempitem)
					tempmonke->divider = tempitem;
			}
		
			//line 4-5
			tempmonke->truThrowId = stoi(monke[4].substr(monke[4].size() - 1, monke[4].size()));
			tempmonke->falsThrowId = stoi(monke[5].substr(monke[5].size() - 1, monke[5].size()));

			monkeys.push_back(tempmonke);
			monke.clear();
		}
	}
	f.close();

	// greatest common divisor
	int mod = 1;
	for (Monkey* monkey : monkeys) {
		mod *= monkey->divider;
	}
	
	int rounds = 10000;
	for (int i = 0; i < rounds; ++i) {
		for (Monkey* monkey : monkeys) {
			monkey->counter += monkey->items.size();
			for (unsigned long long& item : monkey->items) {
				monkey->doOperation(item);
				//item /= 3;
				item%= mod;
				if (item % monkey->divider == 0) {
					monkeys[monkey->truThrowId]->items.push_back(item);
				}
				else {
					monkeys[monkey->falsThrowId]->items.push_back(item); 
				}

			}
			monkey->items.clear();
		}
	}

	// find the 2 most active monkeys, calc level of monkey business
	std::vector<int> iv;

	for (Monkey* monkey : monkeys) {
		iv.push_back(monkey->counter);
		std::cout << monkey->counter << std::endl;
	}
	std::sort(iv.begin(), iv.end(), std::greater<>());
	std::cout << unsigned long long(iv[0]) * unsigned long long(iv[1]) << std::endl;


	for (auto p : monkeys)
		delete p;
	monkeys.clear();
}