#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//struct S {
//	int n;//4
//	int arr[];//��Сδ֪
//};
////��������ʹ��
//int main() {
//	//����arr��С��10������
//	//���ٿռ���ps����
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
//	ps->n = 10;
//	int i = 0;
//	for (i = 0; i < 10; i++) {
//		ps->arr[i] = i;
//	}
//	//����
//	struct S* ptr = (struct S*)realloc(ps->arr, sizeof(struct S) + 20 * sizeof(int));
//	if (ptr != NULL) {
//		ps = ptr;
//	}
//	//�ͷ�
//	free(ps);
//	ps = NULL;
//	return 0;
//}
//struct S
//{
//	int n;
//	int* arr;
//};
////�ڶ���
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
//	//����
//	int*ptr =(int*) realloc(ps->arr, 20 * sizeof(int));
//	if (ptr != NULL)
//	{
//		ps->arr = ptr;
//	}
//	//ʹ��
//	
//	//�ͷ�
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}


//�������в���һ����
//��һ�������������У���С�������򣬽�һ��������������뵽������
//����֤����������������Ȼ������
int main() {
	//����n
	int n = 0;
	scanf("%d", &n);
	//��������
	int a[51] = { 0 };
	int i = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	//����Ҫ���������
	int m;
	scanf("%d", &m);
	//��������
	for (i = n - 1; i >= 0; i--) {
		//�����һ����ʼ�������m�󣬾ͽ�������Ųһλ��һֱ��ǰ
		//����mС���Ǹ���ʱ�����Ƶ���ǰ��
		if (m < a[i]) {
			a[i + 1] = a[i];
		}
		else {
			a[i + 1] = m;
			break;
		}
		
	}
	if (i < 0) {
		//�����a[0]Ҳû���ҵ�˵��mҪ�ŵ���ǰ
		//����a[0]���m��
		//���û�л������
		//1  6  8  9  22  31Ҫ����0ʱ
		//����֣�1  1  6  8  9  22  31
		a[i + 1] = m;
	}
	for (i = 0; i < n + 1; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}