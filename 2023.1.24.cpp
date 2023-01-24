#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main() {
	int i = 0, j = 0, b[100], n, x;
	char arr[100][15];
	//定义arr和b，用于接受学生姓名和成绩
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", &arr[i]);//&arr[i]表示这行的地址，二维数组首元素为第一行，以%s输入时不会接收Space空格
		//，回车Enter，Tab键，空格后直接就是读入b
		scanf("%d", &b[i]);
	}
	//类似冒泡排序开循环
	for (i = 0; i < n - 1; i++) {//共n-1趟
		for (j = 0; j < n - 1 - i; j++) {//两两比较
			if (b[j] < b[j + 1]) {
				//交换名字
				char a[20];
				strcpy(a, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], a);
				//交换成绩
				x = b[j];
				b[j] = b[j + 1];
				b[j + 1] = x;
			}
		}
	}
	for (i = 0; i < n; i++) {//输出
		printf("%s ", arr[i]);
		printf("%d\n", b[i]);
	}

	return 0;
}