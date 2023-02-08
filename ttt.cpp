#include <stdio.h>
#include <math.h>
int main(){
	double a,b,c,det,x1,x2;
	scanf("%lf%lf%lf",&a,&b,&c);
	det=b*b-4*a*c;
	
	if(det>0){
	x1=(-b+sqrt(det))/(2*a);
	x2=(-b-sqrt(det))/(2*a);
		if(x1>x2){
		double t=x1;
			x1=x2;
			x2=t;
		}
		printf("x1=%.5f;x2=%.5f",x1,x2);
	}
	else if(det<0)
		printf("No answer!");
	else
		printf("x1=x2=%.5f",(-1.0*b-sqrt(det))/(2*a));
	return 0;
}
