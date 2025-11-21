#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
	locale::global(locale(""));
	// 28, 44032 / 44060
	wstring s;

	wcin >> s;

	if (!((s.back() - L'가') % 28)) wcout << s << L"는 맛있어.";
	else wcout << s << L"은 맛있어.";

	return 0;
}

    