#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//int main() {
//	//���迪��10�����εĿռ�-10*sizeof(int)
//	//int a[10];//ջ��
//	//��̬�ڴ濪��
//	int* p=(int*)malloc(10 * sizeof(int));
//	if (p == NULL) {
//		//printf  +strerror
//		perror("main");
//		return 0;
//	}
//	//ʹ��
//	int i = 0;
//	for (i = 0; i < 10; i++) {
//		*(p + i) = i;
//
//	}
//	for (i = 0; i < 10; i++) {
//		printf("%d ", p[i]);//p[i]-->*(p+i)
//	}
//	//���տռ�
//	free(p);
//	p = NULL;//�ֶ���p��Ϊ��ָ��
//	return 0;
//}
//
//call0c
//int main() {
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL) {
//		perror("main");
//		return 1;
//	}
// ʹ��
//	int i = 0;
//	for (i = 0; i < 10; i++) {
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
int main() {
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL) {
		perror("main");
		return 1;
	}
	int i = 0;
	for (i = 0; i < 10; i++) {
		*(p + i) = 5;
	}
	//������Ҫp�Ŀռ����20��int�Ŀռ�
	//realloc�����ռ�
	int* ptr = (int*)realloc(p, 20 * sizeof(int));
	if (ptr != NULL) {
		p = ptr;
	}
	free(p);
	p = NULL;
	return 0;
}
//int main() {
//	int* ptr = (int*)realloc(NULL, 40 * sizeof(int));
//	//����calloc��ֱ���ڶ�������40���ֽ�
//	return 0;
//}