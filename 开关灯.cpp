#include <stdio.h>
//j=j+i 
int main(){
	//��0��ʾ�رգ�1��ʾ��
	//��һ���˹ر����У������ʼ��Ϊ0����2��ʼ�ı� 
	int n, m, i , j ,k=0, a[6000] = { 0 };
	scanf("%d %d", &n, &m);
	//m������n����
	for(i=2;i<=m;i++){
		for(j=i;j<=n;j=j+i){//ʹ��ɱ������� 
			a[j]=(a[j]==1?0:1);
		}
	} 
	
	for (i = 1; i <= n; i++) {
		if (a[i] == 0){
			if(k==0){//��k���жϵ�һ���رյĵƣ�������ϡ����� 
				printf("%d",i);
				k=1;
			}
			else
				printf(",%d",i);
		}
	}	
	return 0;

}
