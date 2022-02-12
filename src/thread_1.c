#include <stdio.h> // Including packages
#include <math.h>
#include <stdlib.h>
#include <pthread.h>


struct thread_args { //struct for passing the arguments into the functions
	int a; 
	int b;
	int l;
	int m;
};

double z1,z2;

void *printz1 (void* arg) { // *printz1 for the first equation: a*(x1^5)+b*(x1^2)

	int x1;
	struct thread_args *arguments = arg; 
    	int d = arguments->a;
    	int e = arguments->b;
	printf("\n THREAD 1 RUNNING... \n Z1 = a*(x1^5)+b*(x1^2)");
	for(x1=1; x1<=100; x1++){
		z1=d*pow(x1,5)+e*pow(x1, 2);//1st equation 
		printf("\n for x1= %d | Z1 = %lf ", x1, z1);
	}
	return NULL;   
}


void *printz2 (void* arg) { // *printz2 for the second equation: l*(x2^5)+m*(x2^3)  
	int x2;
	struct thread_args *arguments = arg;
	int f = arguments->l;
	int g = arguments->m;
	printf("\n THREAD 2 RUNNING... \n Z2 = l*(x2^5)+m*(x2^3)");
	for(x2=1; x2<=100; x2++) {
		z2=f*pow(x2,5)+g*pow(x2,3);// 2nd equation 
		printf("\n for x2= %d | Z2 = %lf \t ", x2, z2);
	}
	return NULL;   
}

int  main() {

	printf("This program runs 2 equations and gives the result for diffrent values of x.\n");
	struct thread_args *arguments = malloc(sizeof *arguments);
	printf("Please enter a number for a! \n");
	scanf("%d", &(arguments -> a));
	printf("Please enter a number for b! \n");
	scanf("%d", &(arguments -> b));
	printf("Please enter a number for l! \n");
	scanf("%d", &(arguments -> l));
	printf("Please enter a number for m! \n");
	scanf("%d", &(arguments -> m));

	pthread_t t1, t2;
    
	printf("\n---Creating threads---\n");
	pthread_create(&t1, NULL, printz1, arguments) ;
	pthread_create(&t2, NULL, printz2, arguments);

	printf("\n---Joining Threads---\n");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("\n The program will now successfully exit. \n ");
	return 0;

}




