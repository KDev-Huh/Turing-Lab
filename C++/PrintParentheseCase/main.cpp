#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

set<string> findParenthese(int n) {
	set<string> results;
	if (n == 1) return {"()"};

	for (int i = 0; i < n - 1; i++) {
		for (auto v : findParenthese(n - 1)) {
			string value1 = "", value2 = "", value3 = "";
			value1 += "()" + v;
			value2 += v + "()";
			value3 += "(" + v + ")";
			results.insert(value1);
			results.insert(value2);
			results.insert(value3);
		}
	}

	return results;
}

const char OP = '(';
const char CP = ')';

vector<string> genParentheses(int n);
void genParentheses(vector<string>& res, string stemp, int open, int close);

int main() {
	int n;

	cin >> n;

	for (auto s : findParenthese(n)) {
		cout << s << endl;
	}

	for (int i = 1; i < 3; i++) {
		vector<string> sres = genParentheses(i);
		cout << "n = " << i << ", count = " << sres.size() << endl;
		for (auto sparen : sres)
			cout << sparen << "\n";
		cout << "\n\n*********************************************\n";
	}


	return 0;
}

vector<string> genParentheses(int n) {
	vector<string> res;

	genParentheses(res, "", n, n);

	return res;
}

void genParentheses(vector<string>& res, string stemp, int open, int close) {

	// base case
	if (open == 0 && close == 0) {
		cout << "push" << endl;
		res.push_back(stemp);
		return;
	}

	// general case
	if (open > 0) {
		cout << "open" << endl;
		stemp.push_back(OP);
		genParentheses(res, stemp, open - 1, close);
		stemp.pop_back();
	}

	if (close > open) {
		cout << "close" << endl;
		stemp.push_back(CP);
		genParentheses(res, stemp, open, close - 1);
		stemp.pop_back();
	}
}