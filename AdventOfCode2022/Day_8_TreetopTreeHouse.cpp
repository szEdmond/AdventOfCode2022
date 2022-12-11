#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void checkTop(int pos, std::vector<std::string>& grid, std::vector<std::vector<int>>& visible) {
	int max = INT_MIN;

	for (int i = 0; i < grid.size(); ++i) {
		if (grid[i][pos] - '0' > max) {
			max = grid[i][pos] - '0';
			visible[i][pos]++;
		}
	}
}

void checkBottom(int pos, std::vector<std::string>& grid, std::vector<std::vector<int>>& visible) {
	int max = INT_MIN;

	for (int i = grid.size()-1; i >= 0; --i) {
		if (grid[i][pos] - '0' > max) {
			max = grid[i][pos] - '0';
			visible[i][pos]++;
		}
	}
}

void checkLeft(int pos, std::vector<std::string>& grid, std::vector<std::vector<int>>& visible) {
	int max = INT_MIN;

	for (int i = 0; i < grid.size(); ++i) {
		if (grid[pos][i] - '0' > max) {
			max = grid[pos][i] - '0';
			visible[pos][i]++;
		}
	}
}

void checkRight(int pos, std::vector<std::string>& grid, std::vector<std::vector<int>>& visible) {
	int max = INT_MIN;

	for (int i = grid.size()-1; i >=0; --i) {
		if (grid[pos][i] - '0' > max) {
			max = grid[pos][i] - '0';
			visible[pos][i]++;
		}
	}
}

// ---------------- part 2 -----------------

int calcTop(int x, int y, std::vector<std::string>& grid) {
	int max = grid[x][y]-'0';
	int result = 0;
	--x;
	while (x >= 0) {
		if (max > grid[x][y] - '0')
			result++;
		else
			return result+1;
		--x;
	}
	return result;
}

int calcBottom(int x, int y, std::vector<std::string>& grid) {
	int max = grid[x][y]-'0';
	int result = 0;
	++x;
	while (x < grid.size()) {
		if (max > grid[x][y] - '0')
			result++;
		else
			return result+1;
		++x;
	}
	return result;
}

int calcLeft(int x, int y, std::vector<std::string>& grid) {
	int max = grid[x][y]-'0';
	int result = 0;
	--y;
	while (y >= 0) {
		if (max > grid[x][y] - '0')
			result++;
		else
			return result+1;
		--y;
	}
	return result;
}

int calcRight(int x, int y, std::vector<std::string>& grid) {
	int max = grid[x][y]-'0';
	int result = 0;
	++y;
	while (y < grid.size()) {
		if (max > grid[x][y] - '0')
			result++;
		else
			return result+1;
		++y;
	}
	return result;
}

void part1();
void part2();

int main()
{
	part1();
	part2();
}

void part2() {
	std::fstream f("input/day8.txt");

	std::vector<std::string>grid;
	std::string line;

	while (std::getline(f, line)) {
		grid.push_back(line);
	}
	f.close();

	int ans;
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[0].size(); ++j) {
			ans = std::max(ans, calcTop(i, j, grid)* calcBottom(i, j, grid)* calcLeft(i, j, grid)* calcRight(i, j, grid));
		}
	}
	std::cout << ans << std::endl;
}


void part1() {
	std::fstream f("input/day8.txt");
	
	std::vector<std::string> grid;
	std::vector<std::vector<int>> visible;
	std::string line;

	while (std::getline(f, line)) {
		grid.push_back(line);

		std::vector<int> v(line.size(), 0);
		visible.push_back(v);
	}

	int counter = 0;

	for (int i = 0; i < grid.size(); i++)
	{
		checkTop(i, grid, visible);
		checkBottom(i, grid, visible);
		checkLeft(i, grid, visible);
		checkRight(i, grid, visible);
	}

	int ans = 0;
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[0].size(); ++j) {
			if (visible[i][j])
				++ans;
		}
	}
	std::cout << ans << std::endl;
	f.close();
}