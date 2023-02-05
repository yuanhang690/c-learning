#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int max(int x, int y) {
	if (x == y)
		return x;
	int m = (x > y) ? x : y;
	return m;
}
double compare(char* arr1, char* arr2) {
	int u = strlen(arr1), v = strlen(arr2);
	int j = 0;
	if (u != v)
		return u > v;
	for (j = 0; j < u; j++) {
		if (arr1[j] != arr2[j])
			return arr1[j] > arr2[j];
	}
	return 1;
}
int main() {
	char s1[10090], s2[10090], s3[10090];
	int a[10090], b[10090] = { 0 }, i = 0, flag = 0;//这里b要初始化
	scanf("%s", s1);
	scanf("%s", s2);
	if (!compare(s1, s2)) {//如果返回0，s1<s2,交换两字符串
		//如果s1<s2,结果是负数，让flag==1，后面输出符号
		//比如s1==234	s2==1234
		//交换后是1234-234结果为1000
		//再加个符号就好
		flag = 1;
		strcpy(s3, s1);
		strcpy(s1, s2);
		strcpy(s2, s3);
		//b未初始化：1234
		//			  234（千位上的数将不确定，所以要让他为0）
	}
	int la = strlen(s1), lb = strlen(s2);
	for (i = 0; i < la; i++) {
		a[la - i] = s1[i] - '0';
	}
	for (i = 0; i < lb; i++) {
		b[lb - i] = s2[i] - '0';
	}
	int lc = max(la, lb);
	//核心算法
	for (i = 1; i <= lc; i++) {
		if (a[i] < b[i]) {
			a[i] += 10;
			a[i + 1]--;
		}
		a[i] -= b[i];
	}
	//将结果头部0去掉
	while (a[lc] == 0 && lc > 1)
		lc--;
	if (flag == 1)
		printf("-");
	for (i = lc; i > 0; i--) {
		printf("%d", a[i]);
	}//从高位输出
	return 0;
}