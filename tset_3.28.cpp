#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
struct S {
	char arr[10];
	int num;
	float f;

};
//int main() {
//	struct S s = { "hello", 20, 5.5f };
//	struct S tmp = { 0 };
//	char buf[100] = { 0 };
//	//	//sprintf 把一个格式化的数据，转换成字符串
//	sprintf(buf, "%s %d %f", s.arr, s.num, s.f);
//	printf("%s\n", buf);
//	//	//从buf字符串中还原出一个结构体数据
//	sscanf(buf, "%s %d %f", tmp.arr, &(tmp.num), &(tmp.f));
//	printf("%s %d %f\n", tmp.arr, tmp.num, tmp.f);
//	return 0;
//}
//int main() {
//		FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读取文件
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//a
//
//	//调整文件指针
//	fseek(pf, -2, SEEK_END);
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);//e
//	ch = fgetc(pf);
//	printf("%c\n", ch);//f
//
//	int ret = ftell(pf);
//	printf("%d\n", ret);
//
//	//让文件指针回到其实位置
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c\n", ch);//a
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
int main() {
	FILE* pf=fopen("test.txt", "w");
	if (pf == NULL) {
		perror("fopen");
		return 1;
	}
	int a = 10000;
	//写文件
	fwrite(&a, sizeof(int), 1, pf);
	//10 27 00 00（文件中）
	// 10000
	// 0010 0111 0001 0000（二进制）
	// 0000 0000 0000 0000 0010 0111 0001 0000
	// 转换为16进制并按小端存放
	// 每四个占一个
	// 00 00 27 10
	// 10 27 00 00
	//关闭
	fclose(pf);
	pf = NULL;

	return 0;
}