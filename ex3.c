#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<math.h>

#define MY_PI (3.14159265358979323846)
#define MAX(a,b) (((a)>(b))?(a):(b))
#define NN (10000)



double pi2(int n){
	double nn=(double)n;
	double ret=0;
	unsigned int i;
	nn*=nn;
	for(i=n;i>0;i--){
		ret+=1.0/(double)(4.0*nn+(4.0*((double)i)-4.0)*((double)i)+1.0);
	}
	return 16.0*n*ret;
}

unsigned int c_nmin(double tol){
	unsigned int i;
	for(i=1;i<UINT_MAX;i++){
		if(pi2(i)-MY_PI<tol){
			return i;
		}
	}
	return 0;
}

unsigned int c_nmin_faster(double tol);

int main(int argc, char* argv[]){
	int k;
	double tol=1.e-6;
	unsigned int i;
	unsigned int j;
	//measure new
	clock_t start = clock();
	for(k=0;k<NN;k++){
		i=c_nmin_faster(tol);
	}
	clock_t end = clock() ;
	double elapsed_time = (end-start)/(double)CLOCKS_PER_SEC;
	
	start = clock();
	for(k=0;k<NN;k++){
		j=c_nmin(tol);
	}
	end = clock() ;
	double elapsed_time2 = (end-start)/(double)CLOCKS_PER_SEC;
	if(i!=j){printf("%d %d\n",i,j);}//return -1;}
	printf("N_min = %d Improved: %5.4es Naive: %5.4es Speedup: %6.3f err(N_min) = %20.16e\n",i,elapsed_time/NN,elapsed_time2/NN,elapsed_time2/elapsed_time,pi2(i)-MY_PI);
	//printf("EX=%d\n",c_nmin(tol));
	return 0;
}

unsigned int c_nmin_faster(double tol){//main problem err(n) is not monoton
	unsigned int i=1;
	if(tol>=1e-10){
		i=MAX(floor(0.2885/sqrt(tol)),1);//used aproximate convergence rate
		//should always be lower than correct i;
		//needs up to ~20 calculations of pi2 
		while(tol<fabs(pi2(i)-MY_PI)){
			i++;
		}
	}else{ //or you could generate a look up table, but to keep it simple
		i=c_nmin(tol);
	}
	return i;
}
