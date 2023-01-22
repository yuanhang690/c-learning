#include <stdio.h>
double dg(double x, double n){
	if(n==1)
	return x/(1+x);
	else
	return x/(n+dg(x,n-1));
}
int main(){
	double x,n,result;
	scanf("%lf%lf",&x,&n);
	result=dg(x,n);
	printf("%f",result);
}
