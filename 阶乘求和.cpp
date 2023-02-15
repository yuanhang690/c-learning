#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int n, a[1001] = { 0 }, b[1001] = { 0 }, i = 0, j = 0;
	scanf("%d", &n);
	a[0] = 1;
	b[0] = 1;
	for (i = 2; i <= n; i++) {
		//高精乘法
		for (j = 0; j < 100; j++) {
			a[j] *= i;
		}
		for (j = 0; j < 100; j++) {

			if (a[j] > 9) {
				a[j + 1] += a[j] / 10;
				a[j] %= 10;
			}
		}
		//高精加法
		for (j = 0; j < 100; j++) {
			b[j] += a[j];
			//进位处理
			if (b[j] > 9) {
				b[j + 1] += b[j] / 10;
				b[j] %= 10;
			}
		}
	}
	//从最高位找到不为零的位（去掉前导0）
	for (i = 100; i >= 0 && b[i] == 0; i--);
	for (j = i; j >= 0; j--) {//从高位开始输出
		printf("%d", b[j]);
	}
	return 0;
}
