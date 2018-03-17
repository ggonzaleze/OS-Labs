#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int milkAvailable = 20;
sem_t semaphore;

void *sellMilk(){
	while(milkAvailable > 0){
		int sold = 1 + rand() % 4;
		sem_wait(&semaphore);
        	if (sold > milkAvailable){
                	printf("Sorry! Can't sell %d milks, only %d left :( \n",sold,milkAvailable);
			sem_post(&semaphore);
        	}
        	else{
                	milkAvailable -= sold;
                	printf("Sold %d number of milks. \n",sold);
			sem_post(&semaphore);
        	}
	}
	pthread_exit(NULL);
}

int main(){
	int numSellers = 4;
	sem_init(&semaphore,0,1);
	pthread_t threads[numSellers];
	int rc;

	for(int t = 0; t < numSellers; t++){
		rc = pthread_create(&threads[t],NULL,sellMilk,NULL);
	}
	for(int i = 0; i < numSellers; i++){
		pthread_join(threads[i],NULL);
	}
	printf("All milks sold! \n");
	return 0;
}
