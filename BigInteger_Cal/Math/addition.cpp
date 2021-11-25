#include "Math.h"

bigint addition(bigint a, bigint b){
	bool carry = 0;
	for (size_t i = 0; i < my_max(a.size(), b.size()) || carry; i++){
		if (i == a.size())
			a.push_back(0);
		int tmp = 0;
		if (i < b.size())tmp = b[i];
		a[i] += carry + tmp;
		carry = a[i] >= base;
		if (carry)
			a[i] -= base;
	}
	return a;

}