#define _CRT_SECURE_NO_WARNINGS 1
//һ���ĳһ�߶�h����(��λ�ף�n��1,000,000)��ÿ����غ�����ԭ���߶ȵ�һ�룬�����¡�
//��̼��������ڵ�10�����ʱ��������������? ��10�η�����ߣ�
//����������У���1�У������10�����ʱ��һ����������������2�У���10�ε����ĸ߶ȡ�

//����������С�����4λ��
#include <stdio.h>
#include <math.h>
#include <math.h>
int main() {
	double h;
	int i = 0;
	scanf("%lf", &h);
	double sum = h, tem = h;//sum=hĬ�ϰѵ�һ����ؾ�����h���ϣ����Դ�2��ʼѭ��
	for (i = 2; i <= 10; i++) {
		sum += tem;
		tem *= 0.5;
	}
	printf("%.4f\n", sum);
	printf("%.4f", h / pow(2, 10));
	return 0;
}
