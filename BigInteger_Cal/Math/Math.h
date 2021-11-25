#pragma once
#include "../Includes.h"
#include <string>
#include <vector>
using namespace std;

typedef vector<int> bigint;

extern const int base;

int my_atoi(string);
size_t len(string s);
string my_substr(string s, int l, int n);
bool isValid_num(string);
int my_max(int, int);
vector<string> split(string s);

bool math_event_handler();

void print_bigint(bigint a, bool negate);
bigint addition(bigint a, bigint b);
bigint subscription(bigint a, bigint b);
bigint multiplication(bigint a, bigint b);

// comparators:
bool gt(bigint, bigint);
bool lt(bigint, bigint);
bool eq(bigint, bigint);

void parse(string action, bigint a, bigint b, bool a_negate, bool b_negate);
