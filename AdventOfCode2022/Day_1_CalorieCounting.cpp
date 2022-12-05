#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

int main()
{
    std::ifstream inputtext;
    inputtext.open("input/day1.txt");

    std::string line;
    int max = 0;
    int currSum = 0;
    std::vector<int> calories;

    while (std::getline(inputtext, line)) {
        if (line != "") {
            currSum += stoi(line);
        }
        else {
            max = std::max(max, currSum);
            calories.push_back(currSum);
            currSum = 0;
        }
    }
    std::sort(calories.begin(), calories.end(), std::greater<>());
    
    int ans = 0;
    for (int i = 0; i < 3; i++)
        ans += calories[i];
    
    std::cout << ans << std::endl;
    std::cout << max;
    
    return 0;
}

