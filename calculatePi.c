#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int npoints = 100000;
	int circle_count = 0;
	for(int j = 0; j < npoints; j+= 1){
		float xcoordinate = (double) rand() / (double) RAND_MAX;
		float ycoordinate = (double) rand() / (double) RAND_MAX;
		float xsquared = pow(xcoordinate,2);
		float ysquared = pow(ycoordinate,2);
		float hipotenuse = sqrt(xsquared + ysquared);
		if(hipotenuse < 1){
			circle_count = circle_count + 1;
		}
	}
	float pi = (4.0 * circle_count) / npoints;
        printf("pi: %f\n", pi);
	return 0;
}
