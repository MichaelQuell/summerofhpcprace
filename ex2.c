#include<stdio.h>
#include<math.h>

#define MY_PI 3.14159265358979323846

double pi2(unsigned int n){
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
	for(i=1;i>0;i++){
		double err=fabs(pi2(i)-MY_PI);
		//printf("%10d %20.16e\n",i,err);
		if(err<tol){
			return i;
		}
	}
	return 0;
}

int main(int argc, char* argv[]){
	double tol=1e-6;
	unsigned int i=c_nmin(tol);
	if(i==0){
		printf("No N_min found!\n");
	}else{
		printf("N_min = %d\n",i);
	}
	return 0;
}
