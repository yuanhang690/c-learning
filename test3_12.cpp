#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//struct S {
//	char c1;
//	int i;
//	char c2;
//}s;
//Ĭ�϶�������8

//�����Ϊ2
//#pragma pack(2)
//struct S
//{
//	char c1;//0
//	int i;//
//	char c2;//
//};
#pragma pack()//�����õ�Ĭ�϶�������ԭΪĬ��
 //C����λ��
struct A
{
	//4���ֽ� - 32bit
	int _a : 2;//_a ��Առ2��bitλ
	int _b : 5;//_b ��Առ5��bitλ
	int _c : 10;//_c ��Առ10��bitλ
	//15
	//4���ֽ� - 32bit
	int _d : 30;//_b ��Առ30��bitλ
	//���ܳ�������λ��32��
};
//�ṹ�崫�δ���ַ���ã���ʡʱ��ռ�
struct S
{
	int data[1000];
	int num;
};
struct S s = { {1,2,3,4}, 1000 };
void print1(struct S s) {
	printf("%d\n", s.num);
}
void print2(struct S* ps) {
	printf("%d\n", ps->num);
}
//offsetof
#include <stddef.h>
int main() {
	/*printf("%d\n", sizeof(S));
	printf("%d\n", offsetof(struct S, c1));
	printf("%d\n", offsetof(struct S, i));*/
	//����ĳ��Ԫ�ص�ƫ����
	print1(s);
	print2(&s);

	return 0;
}


