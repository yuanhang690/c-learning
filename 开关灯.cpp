#include <stdio.h>
//j=j+i 
int main(){
	//用0表示关闭，1表示打开
	//第一个人关闭所有，数组初始化为0，从2开始改变 
	int n, m, i , j ,k=0, a[6000] = { 0 };
	scanf("%d %d", &n, &m);
	//m人数；n灯数
	for(i=2;i<=m;i++){
		for(j=i;j<=n;j=j+i){//使其成倍数增长 
			a[j]=(a[j]==1?0:1);
		}
	} 
	
	for (i = 1; i <= n; i++) {
		if (a[i] == 0){
			if(k==0){//用k来判断第一个关闭的灯，后面加上“，” 
				printf("%d",i);
				k=1;
			}
			else
				printf(",%d",i);
		}
	}	
	return 0;

}
