#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string simplifyPath(string path) {
	stringstream directories(path);

	string buffer;
	string result = "/";
	vector<string> paths;
	while (getline(directories, buffer, '/')) {
		if (!buffer.size() || buffer == "." || buffer == "..") {
			if (buffer == ".." && paths.size() > 0)
				paths.pop_back();
			continue;
		}
		
		paths.push_back(buffer);
	}

	for (auto p : paths) {
		result += p + "/";
	}

	if (!(result.size() == 1)) result.pop_back();

	return result;
}

int main() {
	vector<string> paths{
		"/home/", "/home//foo/", "/home/user/Documents/../Pictures", "/../", "/.../a/../b/c/../d/./"
	};

	for (auto p : paths) {
		cout << simplifyPath(p) << endl;
	}

	return 0;
}