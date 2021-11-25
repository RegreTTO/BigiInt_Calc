#include "Math.h"
bigint multiplication(bigint a, bigint b){
	bigint c(a.size() + b.size());
	for (size_t i = 0; i < a.size(); i++){
		for (int j = 0, carry = 0; j < b.size() || carry; j++){
			int cur_mult = 0;

			if (j < b.size())
				cur_mult = b[j];

			long long block = c[i + j] + (long long)a[i] * cur_mult + carry;
			c[i + j] = (int)(block % base);
			carry = (int)(block / base);
		}
	}
	//fixing situatuions where c.size not actual a.size + b.size
	while (c.size() > 1 && c.back() == 0)
		c.pop_back();

	return c;
}
