//输入11个整数，如果第1个数为1，则将其中的第2至11个数升序排列；如果第1个数为0，则降序排列。
#include <stdio.h>
#include <stdlib.h>
int cmp_int2(const void* e1, const void* e2) {
	return *(int*)e2 - *(int*)e1;//排降序的相邻两元素比较 
}
int cmp_int(const void* e1, const void* e2) {
	return *(int*)e1 - *(int*)e2;//排升序的相邻两元素比较
}
void print(int* arr,int sz) {//打印函数 
	int i = 0;
	for (i = 0; i <sz; i++) {
		printf("%d ", arr[i]);
	}
}
int main() {
	int a[10], i = 0;
	int sz = 0,k;
	scanf("%d", &k);
	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	sz = sizeof(a) / sizeof(a[0]);
	//bubble_sort(a, sz);
	if(k==1)
		qsort(a, sz, sizeof(a[0]), cmp_int);//使用qsort排序 
	else if(k==0)
		qsort(a, sz, sizeof(a[0]), cmp_int2);
	print(a,sz);
	return 0;
}

//解法2：
//#include <stdio.h>
//void bubble_sort(int* arr, int sz) {
//	int i = 0, j = 0, tem;
//	if (arr[0] == 1) {
//		for (i = 1; i <= sz - 1; i++) {//每一趟排序 
//			for (j = 1; j <= sz - 1 - i; j++) {
//				if (arr[j] > arr[j + 1]) {//每一趟中排到最终位置的两两元素比较大小并交换 
//					tem = arr[j];
//					arr[j] = arr[j + 1];
//					arr[j + 1] = tem;
//				}
//			}
//		}
//	}
//	else if (arr[0] == 0) {//每一趟中排到最终位置的两两元素比较大小并交换
//		for (i = 1; i <= sz - 1; i++) {
//			for (j = 1; j <= sz - 1 - i; j++) {
//				if (arr[j] < arr[j + 1]) {
//					tem = arr[j];
//					arr[j] = arr[j + 1];
//					arr[j + 1] = tem;
//				}
//			}
//		}
//	}
//	else {}
//}
//void print(int* arr,int sz) {
//	int i = 0;
//	for (i = 1; i < sz; i++) {
//		printf("%d ", arr[i]);
//	}
//}
//int main() {
//	int a[11], i = 0;
//	int sz = 0;
//	for (i = 0; i < 11; i++) {
//		scanf("%d", &a[i]);
//	}
//	sz = sizeof(a) / sizeof(a[0]);
//	bubble_sort(a, sz);//排序 
//	print(a,sz);//打印 
//	return 0;
//} 


