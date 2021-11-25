#include "Math.h"
vector<string> split(string s) {
	vector<string> strings;
	string new_s = "";
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ')new_s += s[i];
		else {
			strings.push_back(new_s);
			new_s = "";
		}
	}
	if (new_s != "")strings.push_back(new_s);
	return strings;
}