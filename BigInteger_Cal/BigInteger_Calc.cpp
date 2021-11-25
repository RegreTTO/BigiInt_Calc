#include "Includes.h"
int main() {
	bool END = false;
	while (!END){
		print_math_help();
		END = menu_handler();

	}
}
