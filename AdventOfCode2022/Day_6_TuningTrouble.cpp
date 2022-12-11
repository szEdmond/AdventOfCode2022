#include <iostream>
#include <string>
#include <fstream>

bool checkSignal(const std::string& s);

int main()
{
	std::ifstream f("input/day6.txt");
	std::string line;
	f >> line;
	std::string signal;
	
	int markLength = 14;
	int ans = 0;

	// make markLength size substr and check for same characters
	for (int i = 0; i < line.size() - markLength; ++i) {
		signal = line.substr(i, markLength);
		if (checkSignal(signal)) {
			ans = i + markLength;
			break;
		}
	}

	std::cout << ans;
}

bool checkSignal(const std::string& s) {
	for (int i = 0; i < s.size() - 1; ++i){
		for (int j = i + 1; j < s.size(); ++j) {
			if (s[i] == s[j])
				return false;
		}
	}
	return true;
}
