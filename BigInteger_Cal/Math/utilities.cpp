#include "Math.h"

size_t len(string s){
	size_t n = 0;
	while (s[n] != '\0')n++;
	return n;
}
string my_substr(string s, int l, int n){
	string new_s = "";
	int ln = len(s);
	if (ln - n - l < 0)n = ln-l;
	for (int i = l; i-l < n; i++)
		new_s += s[i];
	return new_s;
}
int my_atoi(string s){
	int n = 0;

	for (int i = len(s) - 1, exp = 1; i >= 0; i--, exp*=10){
		if (!('0' <= s[i] && s[i] <= '9'))return -1;
		n += (s[i] - '0') * exp;
	}
	return n;
}
bool isValid_num(string n){
	for (size_t i = 0; n[i] != '\0';i++)
		if (!('0' <= n[i] && n[i] <= '9'))if(!(i == 0 && n[i] == '-') || n.size() == 1)return false;
	return true;
}
int my_max(int a, int b){
	if (a > b)return a;
	return b;
}