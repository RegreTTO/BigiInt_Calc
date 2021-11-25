#include "Math.h"
bool gt(bigint a, bigint b){
	int n = my_max(a.size(), b.size());
	if (a.size() > b.size())return true;
	else if (a.size() < b.size())return false;
	for (int i = n-1; i >= 0; i--){
		if (a[i] < b[i])return false;
		if (a[i] > b[i])return true;
	}
	return false;
}
bool lt(bigint a, bigint b){
	int n = my_max(a.size(), b.size());
	if (a.size() < b.size())return true;
	else if (a.size() > b.size())return false;
	for (int i = n-1; i >= 0; i--){
		if (a[i] > b[i])return false;
		if (a[i] < b[i])return true;
	}
	return false;
}
bool eq(bigint a, bigint b){
	return !gt(a, b) && !lt(a, b);
}