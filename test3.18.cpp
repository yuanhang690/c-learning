#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//int main() {
//	//假设开辟10个整形的空间-10*sizeof(int)
//	//int a[10];//栈区
//	//动态内存开辟
//	int* p=(int*)malloc(10 * sizeof(int));
//	if (p == NULL) {
//		//printf  +strerror
//		perror("main");
//		return 0;
//	}
//	//使用
//	int i = 0;
//	for (i = 0; i < 10; i++) {
//		*(p + i) = i;
//
//	}
//	for (i = 0; i < 10; i++) {
//		printf("%d ", p[i]);//p[i]-->*(p+i)
//	}
//	//回收空间
//	free(p);
//	p = NULL;//手动把p置为空指针
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
// 使用
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
	//这里需要p的空间更大。20个int的空间
	//realloc调整空间
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
//	//类似calloc。直接在堆区开辟40个字节
//	return 0;
//}