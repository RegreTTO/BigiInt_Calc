#include "Math.h"

#define args action, a, b, a_negate, b_negate
#define arguments string action, bigint a, bigint b, bool a_negate, bool b_negate

void parse_plus(arguments){
	bool res_negate = 0;
	bigint res;

	if (!(a_negate ^ b_negate)){
		res_negate = a_negate;
		res = addition(a, b);
	}
	else{
		if (lt(a, b)){
			bigint tmp = a;
			a = b, b = tmp;
		}
		if (a_negate){

			res_negate = 1;
			res = subscription(a, b);
		}
		else{
			res = subscription(a, b);
			if (!a_negate && b_negate)res_negate = 1;
		}
	}
	print_bigint(res, res_negate);
}
void parse_minus(arguments){
	bool res_negate = 0;
	bigint res;
	if (!(a_negate ^ b_negate)){
		if (!a_negate){
			if (lt(a, b)){
				bigint tmp = a;
				a = b, b = tmp;
				res_negate = 1;
			}
			else
				res_negate = 0;
			res = subscription(a, b);
		}
		else
			res_negate = 1, res = addition(a, b);
	}
	else{
		if (!a_negate && b_negate)res = addition(a, b), res_negate = 0;
		if (a_negate && !b_negate)res = addition(a, b), res_negate = 1;
	}
	print_bigint(res, res_negate);
}
void parse_multiplication(arguments){
	bool res_negate = 0;
	bigint res;
	if (!(a_negate ^ b_negate)){
		res = multiplication(a, b);
	}
	else{
		res_negate = 1;
		res = multiplication(a, b);
	}
	print_bigint(res, res_negate);
}
void parse(string action,bigint a, bigint b, bool a_negate, bool b_negate){
	if (action[0] == '+')
		parse_plus(args);
	else if (action[0] == '-')
		parse_minus(args);
	else if (action[0] == '*')
		parse_multiplication(args);
	else
		cout << RED << "RTFM!\n" << DEFAULT;


}