#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <string.h>
int max(int x, int y) {
	if (x == y)
		return x;
	int m = (x > y) ? x : y;
	return m;
}
int main() {
	char s1[999], s2[999];
	int i = 0, la, lb, a[999] = { 0 }, b[999] = { 0 }, c[999] = { 0 };
	scanf("%s", s1);
	scanf("%s", s2);
	la = strlen(s1);
	lb = strlen(s2);
	for (i = 0; i < la; i++) {
		a[la - i] = s1[i] - '0';//���ַ�ת�������֣�������洢�����飬���ڼ��㣬��Ϊ����ʱ�Ӹ�λ��ʼ��
	}//����laΪ4��ôs1[0]==a[4],s1[1]==a[3],s1[2]==a[2],s1[3]==a[1]
	//
	for (i = 0; i < lb; i++) {
		b[lb - i] = s2[i] - '0';
	}
	int lc = max(la, lb) + 1;
	int k = 0;//k����¼��λ
	for (i = 1; i <= lc; i++) {
		c[i] = a[i] + b[i] + k;
		k = c[i] / 10;
		c[i] = c[i] % 10;
	}
	if (c[lc] == 0 && lc > 0)//�ж����λ�ǲ���0����lcΪ0ʱ�ر���
		lc--;
	for (i = lc; i > 0; i--) {//��Ϊ��������������������������

		printf("%d", c[i]);
	}

	return 0;
}