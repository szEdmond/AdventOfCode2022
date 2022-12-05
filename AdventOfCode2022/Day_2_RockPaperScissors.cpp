#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

int main() 
{
	std::ifstream f("input/day2.txt");
	std::string line;

	int score = 0;
	char elf;
	char me;

	//score 1 for Rock(X)     2 for Paper(Y)      3 Scissor(Z)
	// Lost-0   Draw-3 Won-6
	//WinCases A-Y
	//         B-Z
	//         C-X

	while (getline(f, line)) {
		elf = line[0];
		me = line[2];

		if (elf == 'A') {
			// need to Lose
			if (me == 'X') {
				// Z
				score += 3;
			}
			//need to Draw
			else if (me == 'Y') {
				// X
				score += 4;
			}
			//need to Win
			else {
				score += 8;
			}
		}
		if (elf == 'B') {
			// need to Lose
			if (me == 'X') {
				// X
				score += 1;
			}
			//need to Draw
			else if (me == 'Y') {
				// Y
				score += 5;
			}
			//need to Win
			else {
				score += 9;
			}
		}
		if (elf == 'C') {
			// need to Lose
			if (me == 'X') {
				// Y
				score += 2;
			}
			//need to Draw
			else if (me == 'Y') {
				// Z
				score += 6;
			}
			//need to Win
			else {
				score += 7;
			}
		}



		//if (elf == 'A') {
		//	//draw
		//	if (me == 'X') {
		//		score += 4;
		//	}
		//	//win
		//	else if (me == 'Y') {
		//		score += 8;
		//	}
		//	//lose
		//	else {
		//		score += 3;
		//	}
		//}
		//if (elf == 'B') {
		//	//draw
		//	if (me == 'Y') {
		//		score += 5;
		//	}
		//	//win
		//	else if (me == 'Z') {
		//		score += 9;
		//	}
		//	//lose
		//	else {
		//		score += 1;
		//	}
		//}
		//if (elf == 'C') {
		//	//draw
		//	if (me == 'Z') {
		//		score += 6;
		//	}
		//	//win
		//	else if (me == 'X') {
		//		score += 7;
		//	}
		//	//lose
		//	else {
		//		score += 2;
		//	}
		//}
	}
	std::cout << score << std::endl;
}