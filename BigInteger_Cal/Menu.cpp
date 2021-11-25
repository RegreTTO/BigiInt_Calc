#include "Menu.h"

void print_math_help() {
	cout << BLUE << "Usage: num1 num2 math_sign(+,-,*)\nType \"exit\" to exit\n";
}

bool menu_handler() {
	return math_event_handler();
}