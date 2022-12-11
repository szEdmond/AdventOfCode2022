#include <iostream> 
#include <fstream>
#include <string>
#include <vector>

void part1() {
	std::ifstream f("input/day10.txt");
	std::string line;
	std::string cmd;

	//program:  addx - 2 steps, first step doesnt affect
	//			else - 1 step no effect
	//this way we get every nth step
	std::vector<int> program;
	while (std::getline(f, line)) 
	{
		cmd = line.substr(0, 4);
		if (cmd == "addx") {
			program.push_back(0);
			program.push_back(stoi(line.substr(5, line.size())));
		}
		else {
			program.push_back(0);
		}
	}
	f.close();

	int registerValue = 1;
	int signalStr = 0;

	int sum = 0;
	
	// 20th step is xRegisterValue * signalStrength(20)
	for (int i = 0; i < program.size(); ++i) {
		signalStr++;

		// every 40th move begining at 20
		if (signalStr % 40 == 20) {
			sum += registerValue * signalStr;
			std::cout << signalStr << ": " << registerValue*signalStr << std::endl;
		}
		registerValue += program[i];
	}

	std::cout << sum;

}

void part2() {
	std::ifstream f("input/day10.txt");
	std::string line;
	std::string cmd;

	std::vector<int> program;
	while (std::getline(f, line)) {
		cmd = line.substr(0, 4);
		if (cmd == "addx") {
			program.push_back(0);
			program.push_back(stoi(line.substr(5,line.size())));
		}
		else {
			program.push_back(0);
		}
	}
	f.close();

	int registerValue = 1;
	std::string row(40,' ');

	/*
	If the pixel's current position is over the sprite, light the pixel up.
	The sprite is 3 pixels wide, and is centered over the position equal
	to the value of the register.
	*/
	int signalStr = 0;
	for (int i = 0; i < program.size(); ++i) {
		int pixel = i % 40;

		if (pixel >= registerValue - 1 && pixel <= registerValue + 1) {
			row[pixel] = '#';
		}

		signalStr++;
		// every 40 cycle we fill a row
		if (signalStr % 40 == 0) {
			std::cout << row << std::endl;
			row = std::string(40, ' ');
		}

		registerValue += program[i];
	}
}
int main()
{
	part2();
}