#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//��ϱʼ����
//������arr1ת�浽arr2�������destλ,ǰ�油0���ѳ�ʼ����
void copy_arr(int arr1[], int arr2[], int dest) {
	//b			temb		i-1
	int i = 0;
	for (i = 1; i <= arr1[0]; i++) {
		arr2[i + dest] = arr1[i];
	}
	arr2[0] = arr1[0] + dest;
}
//����ȽϺ���
//arr1[]>arr2[],����1����ȷ���0��С�ڷ���-1��
int comp_arr(int arr1[], int arr2[]) {
	int i = 0;
	/*if (arr1[0] > arr2[0])
		return 1;
	if (arr1[0] < arr2[0])
		return -1;*/
	for (i = 1; i <= arr1[0]; i++) {
		if (arr1[i] > arr2[i])
			return 1;
		if (arr1[i] < arr2[i])
			return -1;
	}
	return 0;
}
//�������
void sub_arr(int arr1[], int arr2[]) {
	int i = 0;
	for (i = arr1[0]; i >= 1; i--) {
		if (arr1[i] < arr2[i]) {
			arr1[i - 1]--;
			arr1[i] += 10;
		}
		arr1[i] -= arr2[i];
	}
}
void print_arr(int arr[]) {
	int i = 0, flag = 0;
	for (i = 1; i <= arr[0]; i++) {
		if (!flag && !arr[i])
			continue;
		flag = 1;
		printf("%d", arr[i]);
	}
	if (!flag)
		printf("0");
	printf("\n");
}
int main() {
	char sa[2500], sb[2500];
	//a[]������  b[]����	c[]��	temb[]��ʱ���飬��b��������ʱ������ǰ��0��
	int a[3000], b[3000], c[3000] = { 0 }, temb[250], i = 0;
	scanf("%s%s", sa, sb);
	//Ϊ�˷��㣬�������±�Ϊ0��Ԫ�ش洢��������Ч����
	a[0] = strlen(sa);
	b[0] = strlen(sb);
	c[0] = a[0] - b[0] + 1;
	//��a[1]��ʼ��a��b��ʼ��
	for (i = 1; i <= a[0]; i++) {
		a[i] = sa[i - 1] - '0';
	}
	for (i = 1; i <= b[0]; i++) {
		b[i] = sb[i - 1] - '0';
	}
	//ģ���������
	for (i = 1; i <= c[0]; i++) {
		memset(temb, 0, sizeof(temb));
		copy_arr(b, temb, i - 1);//������arr1ת�浽arr2�������destλ,ǰ�油0���ѳ�ʼ����
		a[0] = temb[0];
		//����һ�������Ƚ���ʱ����temb��a�Ĵ�С
		while (comp_arr(a, temb) >= 0) {
			sub_arr(a, temb);
			c[i]++;
		}

	}
	//��ӡ��
	print_arr(c);
	//��ӡ����
	print_arr(a);
	return 0;
}