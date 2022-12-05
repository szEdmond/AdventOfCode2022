#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>

std::string CrateMover9000(std::vector<std::stack<char>> stacks);
std::string CrateMover9001(std::vector<std::stack<char>> stacks);

int main()
{
	// ---------------------- Read Stacks ---------------------------
	std::fstream f("input/day5_stack.txt");
	std::string line;
	// store the input so we can create stack array with correct size
	std::vector<std::string> in;

	while (std::getline(f, line)) {
		in.push_back(line);
	}
	
	std::vector<std::stack<char>> stacks(line.size()/4 + 1);

	for (int i = in.size()-1; i >= 0; --i) {
		// nth stack track
		int stackNo = 0;

		for (int j = 1; j < in[0].size(); j += 4) {
			if (in[i][j] == ' ') {
				++stackNo;
				continue;
			}
			else {
				stacks[stackNo].push(in[i][j]);
			}
			++stackNo;
		}
	}
	f.close();
	
	std::cout << CrateMover9000(stacks) << std::endl;
	std::cout << CrateMover9001(stacks) << std::endl;

}

std::string CrateMover9000(std::vector<std::stack<char>> stacks) {
	// ------------------ Read Commands -----------------------------
	std::ifstream f("input/day5_instructions.txt");
	
	std::string useless;
	int amount, from, to;
	while (f>> useless >> amount >> useless >> from >> useless >> to) {
		for (int i = 0; i < amount; i++) {
			char current = stacks[from - 1].top();
			stacks[from - 1].pop();
			stacks[to - 1].push(current);
		}
	}
	f.close();

	std::string ans;
	// return top of stacks
	for (const auto& i : stacks) {
		if (!i.empty()) 
			ans+= i.top();
		else 
			ans+= ' ';
	}
	
	return ans;
}

std::string CrateMover9001(std::vector<std::stack<char>> stacks) {
	std::ifstream f("input/day5_instructions.txt");
	
	std::string useless;
	int amount, from, to;
	while (f>> useless >> amount >> useless >> from >> useless >> to) {
		// store picked up elements
		std::stack<char>moving;
		for (int i = 0; i < amount; i++) {
			char current = stacks[from - 1].top();
			// remove picked up crates
			stacks[from - 1].pop();
			moving.push(current);
		}
		// place them in their new position
		for (int i = 0; i < amount; i++) {
			char current = moving.top();
			moving.pop();
			stacks[to - 1].push(current);
		}
	}
	f.close();
	
	std::string ans;
	// return top of stacks
	for (const auto& i : stacks) {
		if (!i.empty()) 
			ans+= i.top();
		else 
			ans+= ' ';
	}

	return ans;
	

}
