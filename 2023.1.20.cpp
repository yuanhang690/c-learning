//����11�������������1����Ϊ1�������еĵ�2��11�����������У������1����Ϊ0���������С�
#include <stdio.h>
#include <stdlib.h>
int cmp_int2(const void* e1, const void* e2) {
	return *(int*)e2 - *(int*)e1;//�Ž����������Ԫ�رȽ� 
}
int cmp_int(const void* e1, const void* e2) {
	return *(int*)e1 - *(int*)e2;//�������������Ԫ�رȽ�
}
void print(int* arr,int sz) {//��ӡ���� 
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
		qsort(a, sz, sizeof(a[0]), cmp_int);//ʹ��qsort���� 
	else if(k==0)
		qsort(a, sz, sizeof(a[0]), cmp_int2);
	print(a,sz);
	return 0;
}

//�ⷨ2��
//#include <stdio.h>
//void bubble_sort(int* arr, int sz) {
//	int i = 0, j = 0, tem;
//	if (arr[0] == 1) {
//		for (i = 1; i <= sz - 1; i++) {//ÿһ������ 
//			for (j = 1; j <= sz - 1 - i; j++) {
//				if (arr[j] > arr[j + 1]) {//ÿһ�����ŵ�����λ�õ�����Ԫ�رȽϴ�С������ 
//					tem = arr[j];
//					arr[j] = arr[j + 1];
//					arr[j + 1] = tem;
//				}
//			}
//		}
//	}
//	else if (arr[0] == 0) {//ÿһ�����ŵ�����λ�õ�����Ԫ�رȽϴ�С������
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
//	bubble_sort(a, sz);//���� 
//	print(a,sz);//��ӡ 
//	return 0;
//} 


