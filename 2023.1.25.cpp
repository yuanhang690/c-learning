#define _CRT_SECURE_NO_WARNINGS 1
//给定一个5X5的整数矩阵，找出其中最小的元素，输出所在的行号、列号和元素值，其中行号和列号都从0开始。
#include <stdio.h>
int main() {
	int a[5][5], i = 0, j = 0,m,n,tem;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			scanf("%d", &a[i][j]);//读入数据
		}
	}
	int min = a[0][0];//假定第一行第一个是最小值
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (a[i][j] < min) {
				//与之后每一个比较，若小与第一个交换两元素值
				tem = min;
				min = a[i][j];
				a[i][j] = tem;
				//用m，n来存储最小值行标和列标
				m = i;
				n = j;
			}
		}
	}
	printf("%d %d %d", m, n, min);
	return 0;
}
