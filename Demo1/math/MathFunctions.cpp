#include "MathFunctions.h"

double power(double base, int exponent){
	double result = base;
	for (int i = 1; i < exponent; ++i)
		result *= base;
	return result;
}
