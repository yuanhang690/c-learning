#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//结合笔记理解
//将数组arr1转存到arr2里，向右移dest位,前面补0（已初始化）
void copy_arr(int arr1[], int arr2[], int dest) {
	//b			temb		i-1
	int i = 0;
	for (i = 1; i <= arr1[0]; i++) {
		arr2[i + dest] = arr1[i];
	}
	arr2[0] = arr1[0] + dest;
}
//定义比较函数
//arr1[]>arr2[],返回1，相等返回0，小于返回-1；
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
//相减函数
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
	//a[]被除数  b[]除数	c[]商	temb[]临时数组，在b增长长度时，加上前导0；
	int a[3000], b[3000], c[3000] = { 0 }, temb[250], i = 0;
	scanf("%s%s", sa, sb);
	//为了方便，让数组下标为0的元素存储该数组有效长度
	a[0] = strlen(sa);
	b[0] = strlen(sb);
	c[0] = a[0] - b[0] + 1;
	//从a[1]开始对a，b初始化
	for (i = 1; i <= a[0]; i++) {
		a[i] = sa[i - 1] - '0';
	}
	for (i = 1; i <= b[0]; i++) {
		b[i] = sb[i - 1] - '0';
	}
	//模拟除法过程
	for (i = 1; i <= c[0]; i++) {
		memset(temb, 0, sizeof(temb));
		copy_arr(b, temb, i - 1);//将数组arr1转存到arr2里，向右移dest位,前面补0（已初始化）
		a[0] = temb[0];
		//定义一个函数比较临时数组temb和a的大小
		while (comp_arr(a, temb) >= 0) {
			sub_arr(a, temb);
			c[i]++;
		}

	}
	//打印商
	print_arr(c);
	//打印余数
	print_arr(a);
	return 0;
}