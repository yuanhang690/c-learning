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
//	//	//sprintf ��һ����ʽ�������ݣ�ת�����ַ���
//	sprintf(buf, "%s %d %f", s.arr, s.num, s.f);
//	printf("%s\n", buf);
//	//	//��buf�ַ����л�ԭ��һ���ṹ������
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
//	//��ȡ�ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//a
//
//	//�����ļ�ָ��
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
//	//���ļ�ָ��ص���ʵλ��
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c\n", ch);//a
//
//	//�ر��ļ�
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
	//д�ļ�
	fwrite(&a, sizeof(int), 1, pf);
	//10 27 00 00���ļ��У�
	// 10000
	// 0010 0111 0001 0000�������ƣ�
	// 0000 0000 0000 0000 0010 0111 0001 0000
	// ת��Ϊ16���Ʋ���С�˴��
	// ÿ�ĸ�ռһ��
	// 00 00 27 10
	// 10 27 00 00
	//�ر�
	fclose(pf);
	pf = NULL;

	return 0;
}