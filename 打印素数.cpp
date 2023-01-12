#include <stdio.h>
#include <math.h>
int panduan(int x){
	int j;
	if(x<2){ 
	return 0;} 
	for(j=2;j<sqrt(x);j++){
		if(x%j==0)
		return 0;
	}
	return 1;
} 
int main(){
	int i=0;
	for(i=1;i<=200;i++){//1µ½200 
		if(panduan(i)){
			printf("%d\n",i);
		}
		
	}
	return 0;
}
//打印1到200的素数
