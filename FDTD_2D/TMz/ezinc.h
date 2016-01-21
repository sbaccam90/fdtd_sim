/* Header file to accompany ezinc3.c. */
#ifndef _EZINC_H
#define _EZINC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "fdtd-alloc1.h"
#include "fdtd-macro-tmz.h"
#include "fdtd-proto1.h"


/* Type of source */
#define RICKER//GAUSSIAN_PULSE //HARMONIC //

#define PI 3.14159265

void ezIncInit(Grid *g);
double ezInc(double time, double location);

#endif
/* matches #ifndef _EZINC_H */
