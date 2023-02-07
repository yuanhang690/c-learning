#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main() {
	char s1[5010];
	long long b, c[5010], i = 0, la, lc = 1, a[5010], x = 0;
	scanf("%s", s1);
	la = strlen(s1);
	scanf("%lld", &b);
	//将被除数每一位存入数组
	//注意：改变后首元素是a[1]不是a[0]
	for (i = 0; i < la; i++) {
		a[i + 1] = s1[i] - '0';
	}
	//核心算法，借助笔记理解
	for (i = 1; i <= la; i++) {
		c[i] = (x * 10 + a[i]) / b;
		x = (x * 10 + a[i]) % b;
	}
	while (c[lc] == 0 && lc < la)
		lc++;
	for (i = lc; i <= la; i++) {
		printf("%d", c[i]);
	}
	return 0;
}