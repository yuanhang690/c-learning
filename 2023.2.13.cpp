//#include <stdio.h>
//int main(){
//	int n;
//	double sum=0;
//	scanf("%d",&n);
//	if(n<=15){
//		sum=2.58*n;
//	}
//	else if(n>15&&n<=22){
//		sum=15*2.58+(n-15)*3.34;
//	}
//	else if(n>22){
//		sum=15*2.58+7*3.34+(n-22)*4.09;
//	}
//	double sum1=sum*100;
//	printf("%.0f",sum1);
//	return 0;
//}
//#include <stdio.h>
//int main(){
//	int m,n;
//	scanf("%d%d",&m,&n);
//	if((m>=60&&n<60)||(m<60&&n>=60))
//		printf("1");
//	else
//		printf("0");
//	return 0;
//}
//#include <stdio.h>
//int main(){
//	int n;
//	scanf("%d",&n);
//	if(n%2==1)
//		printf("odd");
//	else if(n%2==0)
//		printf("even");
//	else
//	
//	return 0;
//}
//#include <stdio.h>
//int main(){
//	int n,i=0;
//	double sum=0;
//	int a[1000];
//	scanf("%d",&n);
//	for(i=0;i<n;i++){
//		scanf("%d",&a[i]);
//	}
//	for(i=0;i<n;i++){
//		if(a[i]<=70)
//			sum+=0.1;
//		else{
//			sum=sum+(a[i]/70)*0.1;
//			if(a[i]%70!=0)
//				sum+=0.1;
//		} 
//	}
//	printf("%.1f",sum);
//	return 0;
//}
//���p1540�������� 
#include <stdio.h>
int main(){
	//count��ʾ���Ҵ��� 
	int m,n,word,i=0,num[1000],count=0,j=0,p=0;
	scanf("%d%d",&m,&n);
	//��num������ģ���ֵ� 
	for(i=0;i<m;i++){
		num[i]=-1;
	}
	for(i=0;i<n;i++){
		int tag=0;
		scanf("%d",&word);//���뵥�� 
		
		for(j=0;j<m;j++){
			if(num[j]==word){//tagΪ1����ʾ�ֵ����иõ��� 
				tag=1;
				break;
			}
			
		}
		if(tag==0){//û�иõ��ʾʹ����ֵ䣬���Ҵ���+1 
				num[p++]=word;
				count++;
			}
			if(p==m)
				p=0;
	}
	printf("%d",count);
	return 0;
}
