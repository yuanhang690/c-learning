#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//�Ϸ�c��ʶ��������һ���ַ����ж��Ƿ�Ϊ�Ϸ�c��ʶ��
//int compare(char* arr) {
//	int i = 0,len=strlen(arr);
//	if (arr[0] >= '0' && arr[0] <= '9')
//		return 0;
//	for (i = 0; i < len; i++) {
//		 if (!(arr[i] >= 'A' && arr[i] <= 'Z' || arr[i] >= 'a' && arr[i] <= 'z' || arr[i] == '_'||arr[i]>='0'&&arr[i]<='9'))
//			return 0;
//	}
//	return 1;
//}
//int main() {
//	char arr[21];
//	scanf("%s", arr);
//	if (compare(arr) == 1)
//		printf("yes");
//	else
//		printf("no");
//	return 0;
//
//}
//�߾��ȳ˷�
int main() {
	char s1[3003], s2[3003];
	int a[3003] = { 0 }, b[3003] = { 0 }, c[3003] = { 0 }, i = 0, j = 0;
	scanf("%s", s1);
	scanf("%s", s2);
	//�������
	int la = strlen(s1), lb = strlen(s2);
	int lc = la + lb;
	//�����ŷ������㣬��������������
	for (i = 0; i < la; i++) {
		a[la - i] = s1[i] - '0';
	}
	for (i = 0; i < lb; i++) {
		b[lb - i] = s2[i] - '0';
	}
	int k = 0;
	//�����㷨�������ʼ�ȥ������
	for (i = 1; i <= la; i++) {
		for (j = 1; j <= lb; j++) {
			c[i + j - 1] = c[i + j - 1] + a[i] * b[j];
			c[i + j] = c[i + j] + c[i + j - 1] / 10;
			c[i + j - 1] %= 10;
		}
	}
	//ȥ��ǰ��0�������ж��0����Ҫ��ѭ��
	//����100*0�����ӵĻ���������0
	while (lc > 1) {
		if (c[lc] == 0)
			lc--;
		if (c[lc] != 0)
			break;
	}
	//���򣬴Ӹ�λ���
	for (i = lc; i > 0; i--) {
		printf("%d", c[i]);
	}
	return 0;
}