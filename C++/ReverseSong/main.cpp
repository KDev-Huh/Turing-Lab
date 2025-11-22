#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	locale::global(locale(""));
	wstring song = L"산토끼 토끼야 어디를 가느냐 깡총깡총 뛰면서 어디를 가느냐";

	/*wstring s = L"";
	for (auto w : song) {
		if (w == ' ') {
			reverse(s.begin(), s.end());
			wcout << s << L" ";
			s = L"";
		}
		else s += w;
	}

	wcout << s;*/

	wistringstream so(song);

	wstring word;
	while (so >> word) {
		reverse(word.begin(), word.end());
		wcout << word << " ";
	}

	return 0;
}