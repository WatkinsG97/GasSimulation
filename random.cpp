/*
 *  Created on: 29 Jan 2014
 *      Author: Jon
 */


#include <cmath>
#include <cstdlib>

#include "random.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace Random {
double randomNorm(double mu, double sigma)
{
// use the Box and Muller method
	// Annals of Mathematical Statistics 20, 2 610-611(1958)
	double r1 = 0.;
	double r2 = 0.;
	while(r1<0.0000001) { // avoid r1==0 which will give NaN
	r1 = double(rand())/RAND_MAX; // uniform number between 0 and 1
	r2 = double(rand())/RAND_MAX; // uniform number between 0 and 1
	}
	double x = std::sqrt(-2.*log(r1))*std::cos(2.*M_PI*r2);
	// this give something with mean 0 and width 1
	// so scale to width = sigma
	// and shift to mean = mu;
	x*=sigma;
	x+=mu;
	return x;

}
};
