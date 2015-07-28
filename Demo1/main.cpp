
#include "config.h"

#ifdef USE_MYMATH
#include <MathFunctions.h>
#else
#include <cmath>
#endif // USE_MYMATH

#include <cstdlib> // atof atoi
#include <iostream>
using namespace std;


int main(int argc, char* argv[]){
	if (argc < 3)
	{
		cout << "Usage: " << argv[0] << " base exponent." << endl; 
		return 1;
	}
	double base = atof(argv[1]);
	int exponent = atoi(argv[2]);
#ifdef USE_MYMATH
	cout << "Now we use our own Math library.";
	double result = power(base, exponent);
#else
	cout << "Now we use the standard library.";
	double result = pow(base, exponent);
#endif // USE_MYMATH
	cout << base << " ^ " << exponent << " is " << result << endl;
	return 0;
}
