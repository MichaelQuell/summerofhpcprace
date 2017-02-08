#include<stdio.h>

#define MY_PI 3.14159265358979323846
#define COUNT_OF(x) (sizeof(x)/sizeof(x[0]))

//naive implementation
double pi(unsigned int n){
	double ret=0;
	int i;
	for(i=0;i<n;i++){
		ret+=1.0/(1.0+((double) i-0.5)*(i-0.5)/n/n);
	}
	return 4.0/n*ret;
}
//optimized implementation
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

int main(int argc, char* argv[]){
	int i;
	unsigned int N[]={1,2,10,50,100,500,628478};
	for(i=0;i<COUNT_OF(N);i++){
		printf("pi(%d) =% 20.16e, err(%d) = % 20.16e\n",
					N[i],pi2(N[i]),N[i],pi2(N[i])-MY_PI);
	}
	return 0;
}
