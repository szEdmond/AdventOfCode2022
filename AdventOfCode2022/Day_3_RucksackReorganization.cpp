#include <iostream>
#include <fstream>
#include <string>

// split string into 2 parts, Find the common char
// add the char value to answer
// a-z 1-26
// A-Z 27-52

int partOne() {
	std::ifstream f("input/day3.txt");

	int score = 0;
	std::string line;
	std::string secondHalf;

	while (std::getline(f, line)) {

		secondHalf = line.substr(line.size() / 2, line.size() / 2);
		bool found = false;

		for (int i = 0; i < line.size()/2 && !found; i++) {
			// if this char is in the second half
			if (secondHalf.find(line[i]) != std::string::npos) {
				if (islower(line[i])) {
					score += line[i] - 'a' + 1;
					found = true;
				}
				else {
					score += line[i] - 'A' + 27;
					found = true;
				}
			}
		}
	}
	f.close();
	return score;
}


int partTwo() {
	std::fstream f("input/day3.txt");

	std::string line;
	int ans = 0;

	int nthLine = 0;
	int freq[52];
	memset(freq, 0, sizeof(int) * 52);

	while (std::getline(f, line)) {
		for (int i = 0; i < line.size(); ++i) {
			if (islower(line[i])) {
				if (freq[line[i] - 'a'] == nthLine) {
					freq[line[i] - 'a']++;
				}
			}
			else {
				if (freq[line[i] - 'A'+26] == nthLine) {
					freq[line[i] - 'A'+26]++;
				}
			}
		}

		nthLine++;

		if (nthLine == 3) {
			//find pos where freq == 3;
			auto itr = std::find(freq, freq + sizeof(freq) / sizeof(int), 3);
			int c = std::distance(freq, itr);
			ans += c+1;

			memset(freq, 0, sizeof(int) * 52);
			nthLine = 0;
		}
	}
	f.close();
	return ans;
}



int main()
{
	std::cout << partOne() << std::endl;
	std::cout << partTwo() << std::endl;
}