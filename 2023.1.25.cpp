#define _CRT_SECURE_NO_WARNINGS 1
//����һ��5X5�����������ҳ�������С��Ԫ�أ�������ڵ��кš��кź�Ԫ��ֵ�������кź��кŶ���0��ʼ��
#include <stdio.h>
int main() {
	int a[5][5], i = 0, j = 0,m,n,tem;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			scanf("%d", &a[i][j]);//��������
		}
	}
	int min = a[0][0];//�ٶ���һ�е�һ������Сֵ
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (a[i][j] < min) {
				//��֮��ÿһ���Ƚϣ���С���һ��������Ԫ��ֵ
				tem = min;
				min = a[i][j];
				a[i][j] = tem;
				//��m��n���洢��Сֵ�б���б�
				m = i;
				n = j;
			}
		}
	}
	printf("%d %d %d", m, n, min);
	return 0;
}
