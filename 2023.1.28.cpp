#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//a^b的末3位数是多少？
//两个正整数a，b;从高位到低位输出幂的末三位数字
int main() {

	int a, b, i, k = 1;
	scanf("%d%d", &a, &b);
	for (i = 1; i <= b; i++) {
		k *= a;
		k %= 1000;
	}
	if (k < 10)
		printf("00%d", k);
	else if (k >= 10 && k <= 100)
		printf("0%d", k);
	else
		printf("%d", k);

	return 0;

}