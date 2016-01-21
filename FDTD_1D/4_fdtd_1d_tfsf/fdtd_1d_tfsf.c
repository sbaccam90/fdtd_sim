#include <stdio.h>
#include <math.h>

#define SIZE 200

int main()
{
	double ez[SIZE] = {0.}, hy[SIZE] = {0.}, imp0 = 377.0;
	int qTime, maxTime = 500, mm;

	char basename[80] = "sim", filename[100];
	int frame = 0;
	FILE *snapshot;

	/*
	 * do time stepping
	 */
	for (qTime = 0; qTime < maxTime; qTime++) {

		/*
		 * Absorbed bounded condition
		 */
		hy[SIZE-1] = hy[SIZE-2];

		/*
		 * update magnetic field
		 */
		for (mm = 0; mm < SIZE - 1; mm++)
			hy[mm] = hy[mm] + (ez[mm + 1] - ez[mm]) / imp0;

		/* correction for Hy adjacent to TFSF boundary */
		hy[49] -= exp(-(qTime - 30.) * (qTime - 30.) / 100.) / imp0;

		/*
		 * Absorbed bounded condition
		 */
		ez[0] = ez[1];

		/*
		 * update electric field
		 */
		for (mm = 1; mm < SIZE; mm++)
			ez[mm] = ez[mm] + (hy[mm] - hy[mm - 1]) * imp0;
		
		/* correction for Ez adjacent to TFSF boundary */
		ez[50] += exp(-(qTime + 0.5 - (-0.5) - 30.) * (qTime + 0.5 - (-0.5) - 30.) / 100.);

		/*
		 * write snapshot if time-step is a multiple of 10
		 */
		if (qTime % 10 == 0) {

			/*
			 * construct complete file name and increment frame counter
			 */
			sprintf(filename, "%s.%d", basename, frame++);

			/*
			 * open file
			 */
			snapshot = fopen(filename, "w");

			/*
			 * write data to file
			 */
			for (mm = 0; mm < SIZE; mm++)
				fprintf(snapshot, "%g\n", ez[mm]);

			/*
			 * close file
			 */
			fclose(snapshot);
		}
	}
	
	/*
	 * end of time-stepping
	 */
	return 0;
}
