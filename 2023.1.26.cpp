#define _CRT_SECURE_NO_WARNINGS 1
//一球从某一高度h落下(单位米，n≤1,000,000)，每次落地后反跳回原来高度的一半，再落下。
//编程计算气球在第10次落地时，共经过多少米? 第10次反弹多高？
//输出包含两行，第1行：到球第10次落地时，一共经过的米数。第2行：第10次弹跳的高度。

//输出结果保留小数点后4位。
#include <stdio.h>
#include <math.h>
#include <math.h>
int main() {
	double h;
	int i = 0;
	scanf("%lf", &h);
	double sum = h, tem = h;//sum=h默认把第一次落地经过的h算上，所以从2开始循环
	for (i = 2; i <= 10; i++) {
		sum += tem;
		tem *= 0.5;
	}
	printf("%.4f\n", sum);
	printf("%.4f", h / pow(2, 10));
	return 0;
}
