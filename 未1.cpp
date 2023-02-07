//#include <stdio.h>
//int main(){
//	double a[10]={28.9,32.7,45.6,78,35,86.2,27.8,43,56,65},c[10],sum=0;
//	int b[10],i=0;
//	for(i=0;i<10;i++){
//		scanf("%d",&b[i]);
//	}
//	for(i=0;i<10;i++){
//		c[i]=a[i]*(double)b[i];
//		sum+=c[i];
//	}
//	printf("%.1f",sum);
//	return 0;
//}
//#include <stdio.h>
//int main(){
//	int n,i=0,a[100],m=0,count=0;
//	scanf("%d",&n);
//	for(i=0;i<n;i++){
//		scanf("%d",&a[i]);
//	}
//	scanf("%d",&m);
//	for(i=0;i<n;i++){
//		if(a[i]==m)
//		count++;
//	}
//	printf("%d",count);
//	return 0;
//}
#include <stdio.h>
int main(){
	int n=0,a[1000],max=0,i=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>max)
		max=a[i];
	}
	int min=a[0];
	for(i=1;i<n;i++){
		if(a[i]<min)
		min=a[i];
	}
	printf("%d %d",max,min);

	return 0;
}
