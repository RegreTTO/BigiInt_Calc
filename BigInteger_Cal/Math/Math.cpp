#include "Math.h"

string crutch_zero_fillup(int n){
	string crutch = "";
	int l = 0;
	while (l < 9){
		if (n != 0)crutch = char(n % 10 + '0') + crutch, n /= 10;
		else crutch = '0' + crutch;
		l++;
	}
	return crutch;

}

vector<string> read_str_array(){
	string s;
	getline(cin, s);
	vector<string> v = split(s);
	return v;

}

bigint convert_string_to_bigint(string s, bool negate = 0){
	bigint bn;
	size_t n = len(s);
	for (int i = n; i > 0; i -= 9){
		string tmp = "";
		if (i < 9)
			bn.push_back(my_atoi(my_substr(s, negate, i-negate)));
		else
		{
			if (i - 9 == 0)
				bn.push_back(my_atoi(my_substr(s, i - 9 + negate, 9)));
			else bn.push_back(my_atoi(my_substr(s, i - 9, 9)));
		}
	}
	while (bn.size() > 1 && bn[bn.size() - 1] == 0)
		bn.pop_back();
	return bn;
}

void print_bigint(bigint a, bool negate){


	if (a.size() == 0)
		cout << 0;
	else{
		if (negate && a[a.size()-1])cout << '-';
		cout << a[a.size() - 1];
	}

	for (int i = (int)a.size() - 2; i >= 0; i--)
		cout << crutch_zero_fillup(a[i]);
	cout << '\n';
}

bool math_event_handler(){
	vector<string> strings = read_str_array();
	for (int i = 0; i < strings.size(); i++)if (strings[i] == "exit") return 1;
	if (strings.size() != 3||!isValid_num(strings[0]) || !isValid_num(strings[1])){
		cout << RED << "RTFM!\n" << DEFAULT;
		return 0;
	}
	string action = strings[2];

	bigint a, b, res;
	bool a_negate = strings[0][0] == '-';
	bool b_negate = strings[1][0] == '-';
	bool res_negate = 0;
	a = convert_string_to_bigint(strings[0], a_negate);
	b = convert_string_to_bigint(strings[1], b_negate);
	
	parse(action, a, b, a_negate, b_negate);
	cout << '\n';
	return 0;
}
