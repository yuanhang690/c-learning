#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//struct S {
//	int n;//4
//	int arr[];//大小未知
//};
////柔性数组使用
//int main() {
//	//期望arr大小是10个整形
//	//开辟空间由ps管理
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
//	ps->n = 10;
//	int i = 0;
//	for (i = 0; i < 10; i++) {
//		ps->arr[i] = i;
//	}
//	//增加
//	struct S* ptr = (struct S*)realloc(ps->arr, sizeof(struct S) + 20 * sizeof(int));
//	if (ptr != NULL) {
//		ps = ptr;
//	}
//	//释放
//	free(ps);
//	ps = NULL;
//	return 0;
//}
//struct S
//{
//	int n;
//	int* arr;
//};
////第二种
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//	if (ps == NULL)
//		return 1;
//	ps->n = 10;
//	ps->arr = (int*)malloc(10*sizeof(int));
//	if (ps->arr == NULL)
//		return 1;
//	
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	//增加
//	int*ptr =(int*) realloc(ps->arr, 20 * sizeof(int));
//	if (ptr != NULL)
//	{
//		ps->arr = ptr;
//	}
//	//使用
//	
//	//释放
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}


//有序序列插入一个数
//有一个有序数字序列，从小到大排序，将一个新输入的数插入到序列中
//，保证插入新数后，序列仍然是升序。
int main() {
	//输入n
	int n = 0;
	scanf("%d", &n);
	//输入整数
	int a[51] = { 0 };
	int i = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	//插入要插入的数据
	int m;
	scanf("%d", &m);
	//插入数据
	for (i = n - 1; i >= 0; i--) {
		//从最后一个开始，如果比m大，就将其往后挪一位，一直往前
		//到比m小的那个数时，复制到他前面
		if (m < a[i]) {
			a[i + 1] = a[i];
		}
		else {
			a[i + 1] = m;
			break;
		}
		
	}
	if (i < 0) {
		//如果到a[0]也没有找到说明m要放到最前
		//即将a[0]变成m；
		//如果没有会出现如
		//1  6  8  9  22  31要插入0时
		//会出现：1  1  6  8  9  22  31
		a[i + 1] = m;
	}
	for (i = 0; i < n + 1; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}