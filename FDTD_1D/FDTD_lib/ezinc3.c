/* Functions to calculate the source function (i.e., the incident
* field). */
#include "ezinc3.h"

/* global variables -- but private to this file */
static double cdtds;

#ifdef GAUSSIAN_PULSE
static double delay, width = 0;
#endif

#ifdef HARMONIC
static double nlambda;
#endif

#ifdef RICKER
static double nlambda_peak, multiple_delay;
#endif

/* prompt user for source-function width and delay. */
void ezIncInit(Grid *g){
	cdtds = Cdtds;

#ifdef GAUSSIAN_PULSE
	printf("Enter delay: ");
	scanf(" %lf", &delay);
	printf("Enter width: ");
	scanf(" %lf", &width);
#endif

#ifdef HARMONIC
	printf("Enter number of spacial steps for lambda: ");
	scanf(" %lf", &nlambda);
#endif

#ifdef RICKER
	printf("Enter number of spacial steps for lambda of peak frequency: ");
	scanf(" %lf", &nlambda_peak);
	printf("Enter delay multiple: ");
	scanf(" %lf", &multiple_delay);
#endif
	return;
}

/* calculate source function at given time and location */
double ezInc(double time, double location) {

#ifdef GAUSSIAN_PULSE
	if (width <= 0) {
		fprintf(stderr,"ezInc: must call ezIncInit before ezInc.\n""Width must be positive.\n");
		exit(-1);
	}


	return exp(-pow((time - delay - location / cdtds), 2)/ width);
#endif

#ifdef HARMONIC
	if (nlambda <= 0) {
		fprintf(stderr,"ezInc: must call ezIncInit before ezInc.\n""nlambda must be positive.\n");
		exit(-1);
	}


	return sin(2*PI*(cdtds*time - location)/nlambda);
#endif

#ifdef RICKER
	if (nlambda_peak <= 0) {
		fprintf(stderr,"ezInc: must call ezIncInit before ezInc.\n""nlambda must be positive.\n");
		exit(-1);
	}


	return (1 -2*pow(PI*((cdtds*time - location)/nlambda_peak - multiple_delay),2))*exp(-pow(PI*((cdtds*time - location)/nlambda_peak - multiple_delay),2));
#endif
}
