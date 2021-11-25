#include "Math.h"
bigint subscription(bigint a, bigint b){
	bool carry = 0;
	for (size_t i = 0; i < b.size() || carry; i++){
		int tmp = 0;
		if (i < b.size())tmp = b[i];
		a[i] -= carry + tmp;
		carry = a[i] < 0;
		if (carry)
			a[i] += base;
	}

	//delete leading zeros
	while (a.size() > 1 && a[a.size() - 1] == 0){
		a.pop_back();
	}
	return a;
}