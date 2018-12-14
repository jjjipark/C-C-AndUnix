#include <stdio.h>

double power(double a, double b){
	double i, k;
	k = a;

	for(i=0; i<b; i++){
		k = k*a;
	}
	return k;
}
