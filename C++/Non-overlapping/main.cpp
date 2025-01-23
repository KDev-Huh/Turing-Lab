#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
int main() {
	std::string s;
	std::deque<char> d;
	
	std::cin >> s;

	int max = 0;

	for (int i = 0; i < s.length(); i++) {
		if (std::find(d.begin(), d.end(), s[i]) != d.end()) {
			while (d.front() != s[i]) {
				d.pop_front();
			}
			d.pop_front();
			d.push_back(s[i]);
		}
		else
			d.push_back(s[i]);
		if (max < d.size())
			max = d.size();
	}

	std::cout << max;

	return 0;
}