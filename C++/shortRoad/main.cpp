#include <iostream>
#include <vector>
#include <queue>
#include <print>

int main() {
	int row = 5, col = 6;
	std::vector<std::vector<int>> map{
		{1, 1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 1},
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
	};

	const std::vector<std::pair<int, int>> move{
		{-1, 0}, {0, 1}, {1, 0}, {0, -1}
	};

	std::queue<std::pair<int, int>> squeue;


	squeue.push({ 0, 0 });

	while (!squeue.empty())
	{
		auto [r, c] = squeue.front();	// 구조분해 할당
		squeue.pop();

		for (auto [dr, dc] : move)
		{
			if (r + dr >= 0 and r + dr < row and c + dc >= 0 and c + dc < col and map[r + dr][c + dc] == 1 and ( r + dr != 0 or c + dc != 0))
			{
				map[r + dr][c + dc] = map[r][c] + 1;
				squeue.push({ r + dr, c + dc });
			}
		}
	}

	for (auto line : map)
	{
		for (auto c : line)
			std::print("{:2d}", c);
		std::cout << std::endl;
	}


	return 0;
}