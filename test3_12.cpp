#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//struct S {
//	char c1;
//	int i;
//	char c2;
//}s;
//默认对齐数是8

//将其改为2
//#pragma pack(2)
//struct S
//{
//	char c1;//0
//	int i;//
//	char c2;//
//};
#pragma pack()//将设置的默认对齐数还原为默认
 //C语言位段
struct A
{
	//4个字节 - 32bit
	int _a : 2;//_a 成员占2个bit位
	int _b : 5;//_b 成员占5个bit位
	int _c : 10;//_c 成员占10个bit位
	//15
	//4个字节 - 32bit
	int _d : 30;//_b 成员占30个bit位
	//不能超过最大的位（32）
};
//结构体传参传地址更好，节省时间空间
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
	//计算某个元素的偏移量
	print1(s);
	print2(&s);

	return 0;
}


