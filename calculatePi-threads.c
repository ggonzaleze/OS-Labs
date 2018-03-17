#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
//Graph : https://drive.google.com/file/d/1YMD5hfsVWXVovnDV2XubpEKw0guKatD6/view?usp=sharing
int numThreads = 4;
int npoints = 100000;
int circle_count = 0;

void *quarterCircle(){
       for(int j = 0; j < npoints/numThreads; j++){
               float xcoordinate = (double) rand() / (double) RAND_MAX;
                float ycoordinate = (double) rand() / (double) RAND_MAX;
                float xsquared = pow(xcoordinate,2);
                float ysquared = pow(ycoordinate,2);
                float hipotenuse = sqrt(xsquared + ysquared);
                if(hipotenuse < 1){
                        circle_count = circle_count + 1;
                }
       }
       pthread_exit(NULL);
}

int main(){
       pthread_t threads[numThreads];
       int rc;
       for(int t = 0; t < numThreads; t++){
               rc = pthread_create(&threads[t],NULL,quarterCircle,NULL);
       }
       for(int i = 0; i < numThreads; i++){
               pthread_join(threads[i],NULL);
       }
       float pi = (4.0 * circle_count) / npoints;
        printf("pi: %f calculated with %d threads \n", pi,numThreads);
       return 0;
}
