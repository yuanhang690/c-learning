#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main() {
	int i = 0, j = 0, b[100], n, x;
	char arr[100][15];
	//����arr��b�����ڽ���ѧ�������ͳɼ�
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", &arr[i]);//&arr[i]��ʾ���еĵ�ַ����ά������Ԫ��Ϊ��һ�У���%s����ʱ�������Space�ո�
		//���س�Enter��Tab�����ո��ֱ�Ӿ��Ƕ���b
		scanf("%d", &b[i]);
	}
	//����ð������ѭ��
	for (i = 0; i < n - 1; i++) {//��n-1��
		for (j = 0; j < n - 1 - i; j++) {//�����Ƚ�
			if (b[j] < b[j + 1]) {
				//��������
				char a[20];
				strcpy(a, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], a);
				//�����ɼ�
				x = b[j];
				b[j] = b[j + 1];
				b[j + 1] = x;
			}
		}
	}
	for (i = 0; i < n; i++) {//���
		printf("%s ", arr[i]);
		printf("%d\n", b[i]);
	}

	return 0;
}