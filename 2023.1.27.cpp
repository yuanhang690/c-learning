#define _CRT_SECURE_NO_WARNINGS 1
//һ��ֻ��Сд��ĸ��ɵ��ַ���s,���������ַ���ִ��
//k�β���,��ÿ�β����������ASCII����С����ĸ��s��ɾ�����뷵��k�β���֮����ַ���x.
//���磺����"caabeefa",2	�����"ceef"
#include <stdio.h>
#include <string.h>
int main() {
	int i = 0, k = 0, count = 0;
	char arr[100];//�����ַ�����
	char* p = arr + 1;//����ָ��pָ��arr�ڶ���Ԫ�أ���Ϊ��һ��arr[0]�� " ���Բ��ù�
	while (1) {
		scanf("%c ", &arr[i]);
		count++;//��¼������ַ���'�� '��','���ܳ���
		if (arr[i] == ',') {
			break;
		}
		i++;
	}
	scanf("%d", &k);//����k
	int min = arr[1];//�ٶ���СֵminΪ��һ����ĸ
	for (i = 2; i < count - 2; i++) {//count���ܳ�����Ҫȥ�����,��"���ַ�
		if (arr[i] < min) {//���������ҵ�ASCll��С����ĸ������min
			int m = min;
			min = arr[i];
			arr[i] = m;
		}
	}
	for (i = 0; i < k; i++) {
		int j = 1;
		while (*p != ',') {//�ӵ�һ����ʼֱ������������С����ĸ��ʹ����*����������
			if (arr[j] == min) {
				*p = '*';
			}
			j++;
			p++;//ÿӰ����ָ�������
		}
		//һ������ɵڶ�С��ĸ�����жϣ�������Ҫ��ָ������ָ��arr��1��
		min++;
		p = arr + 1;

	}
	for (i = 0; i < count - 1; i++) {
		if (arr[i] != '*') {
			printf("%c", arr[i]);
		}
	}

	return 0;
}