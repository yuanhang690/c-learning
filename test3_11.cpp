#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
////struct S {
////	char c1;
////	int i;
////	char c2;
////}s;
////Ĭ�϶�������8
//
////�����Ϊ2
////#pragma pack(2)
////struct S
////{
////	char c1;//0
////	int i;//
////	char c2;//
////};
//#pragma pack()//�����õ�Ĭ�϶�������ԭΪĬ��
// //C����λ��
//struct A
//{
//	//4���ֽ� - 32bit
//	int _a : 2;//_a ��Առ2��bitλ
//	int _b : 5;//_b ��Առ5��bitλ
//	int _c : 10;//_c ��Առ10��bitλ
//	//15
//	//4���ֽ� - 32bit
//	int _d : 30;//_b ��Առ30��bitλ
//	//���ܳ�������λ��32��
//};
////�ṹ�崫�δ���ַ���ã���ʡʱ��ռ�
//struct S
//{
//	int data[1000];
//	int num;
//};
//struct S s = { {1,2,3,4}, 1000 };
//void print1(struct S s) {
//	printf("%d\n", s.num);
//}
//void print2(struct S* ps) {
//	printf("%d\n", ps->num);
//}
////offsetof
//\
////��������������
//union Un {
//	char c;
//	int i;
//};
////û���������жϴ�С��
//int check_sys()
//{
//	int a = 1;
//	if ((*(char*)&a) == 1)
//	{
//		return 1;//С��
//	}
//	else
//	{
//		return 0;//���
//	}
//}
////ʹ��������
//int check_u() {
//	union Un{
//	char j;
//	int i;
//	}un;
//	un.i = 1;
//	return un.j;
//}
//#include <stddef.h>
//int main() {
//	/*printf("%d\n", sizeof(S));
//	printf("%d\n", offsetof(struct S, c1));
//	printf("%d\n", offsetof(struct S, i));*/
//	//����ĳ��Ԫ�ص�ƫ����
//	/*print1(s);
//	print2(&s);*/
//
//	//��������
//	union Un u = { 10 };
//	printf("%d\n", u);
//	printf("%d", u.i);
//	if (check_u ()== 1) {
//		printf("С��");
//	}
//	else {
//		printf("���");
//	}
//	return 0;
//}
//��������
#include <stdio.h>
#include <string.h>
#define maxn 20
int a[maxn][maxn];
int main() {
	int n, x, y,flg=0;
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	flg = a[x = 0][y=n - 1] = 1;
	while (flg < n * n) {
		while (x + 1 < n && !a[x + 1][y]) {
			a[++x][y] = ++flg;
		}
		while (y - 1 >= 0 && !a[x][y - 1]) {
			a[x][--y] = ++flg;
		}
		while (x - 1 >= 0 && !a[x - 1][y]) {
			a[--x][y] = ++flg;
		}
		while (y + 1 < n && !a[x][y + 1]) {
			a[x][++y] = ++flg;
		}
	}
	for (x = 0; x < n; x++) {
		for (y = 0; y < n; y++) {
			printf("%3d", a[x][y]);
			
		}
		printf("\n");
	}
	return 0;
}

