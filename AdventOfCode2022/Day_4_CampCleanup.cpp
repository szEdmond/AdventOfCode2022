#include<iostream>
#include<string>
#include<fstream>
#include <vector>

int main()
{
	std::ifstream f("input/day4.txt");
	std::string line;

	char symbol;
	int a, b, c, d;
	
	int fullyContain = 0;
	int overlap = 0;

	//14-50,14-50
	while (f >> a >> symbol >> b >> symbol >> c >> symbol >>d) {
		if (a >= c && b <= d || c >= a && d <= b) fullyContain++;
		if (a >= c && a <= d || b<=d && b>=c || c >= a && c <= b || d<=b && d>=a) overlap++;
	}

	std::cout << fullyContain << std::endl;
	std::cout << overlap;
}