#include <stdio.h>
int main(){

long long int i,j,bx,by,mx,my,f[30][30]={0},horse[30][30]={0};//f[][]���̣� 
scanf("%lld%lld%lld%lld",&bx,&by,&mx,&my);
bx+=2;by+=2;mx+=2;my+=2;//�Ӷ���ֹԽ�� 
//����Ƶĵ� 
horse[mx][my]=1;
horse[mx-2][my-1]=1;
horse[mx-2][my+1]=1;
horse[mx-1][my-2]=1;
horse[mx-1][my+2]=1;
horse[mx+1][my-2]=1;
horse[mx+1][my+2]=1;
horse[mx+2][my-1]=1;
horse[mx+2][my+1]=1;
f[2][1]=1;
for(i=2;i<=bx;i++){
	for(j=2;j<=by;j++){
		if(horse[i][j]==1)
		continue;
		f[i][j]=f[i-1][j]+f[i][j-1];//����ʽ 
	}
}
printf("%lld",f[bx][by]);
return 0;
}
