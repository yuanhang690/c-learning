#define _CRT_SECURE_NO_WARNINGS 1
////һ��ֻ��Сд��ĸ��ɵ��ַ���s,���������ַ���ִ��
////k�β���,��ÿ�β����������ASCII����С����ĸ��s��ɾ�����뷵��k�β���֮����ַ���x.
////���磺����"caabeefa",2	�����"ceef"
//#include <stdio.h>
//#include <string.h>
//int main() {
//	int i = 0,k=0,count=0;
//	char arr[100];//�����ַ�����
//	char* p = arr + 1;//����ָ��pָ��arr�ڶ���Ԫ�أ���Ϊ��һ��arr[0]�� " ���Բ��ù�
//	while (1) {
//		scanf("%c ", &arr[i]);
//		count++;//��¼������ַ���'�� '��','���ܳ���
//		if (arr[i] == ',') {
//			break;
//		}
//		i++;
//	}
//	scanf("%d", &k);//����k
//	int min = arr[1];//�ٶ���СֵminΪ��һ����ĸ
//	for (i = 2; i < count - 2; i++) {//count���ܳ�����Ҫȥ�����,��"���ַ�
//		if (arr[i] < min) {//���������ҵ�ASCll��С����ĸ������min
//			int m = min;
//			min = arr[i];
//			arr[i] = m;
//		}
//	}
//	for (i = 0; i < k; i++) {
//		int j = 1;
//		while (*p != ',') {//�ӵ�һ����ʼֱ������������С����ĸ��ʹ����*����������
//			if (arr[j] == min) {
//				*p = '*';
//			}
//			j++;
//			p++;//ÿӰ����ָ�������
//		}
//		//һ������ɵڶ�С��ĸ�����жϣ�������Ҫ��ָ������ָ��arr��1��
//		min++;
//		p = arr + 1;
//		
//	}
//	for (i = 0; i < count-1; i++) {
//		if (arr[i] != '*') {
//			printf("%c", arr[i]);
//		}
//	}
//
//	return 0;
//}
//#include <stdio.h>
//int main() {
//	int m, n, sum = 0,  i = 0;
//	scanf("%d%d", &m, &n);
//	for (i = m; i <= n; i++) {
//		if (i % 2 != 0)
//			sum += i;
//	}
//	printf("%d", sum);
//	return 0;
//}
//#include <stdio.h>
//a^b��ĩ3λ���Ƕ��٣�
//����������a��b;�Ӹ�λ����λ����ݵ�ĩ��λ����
//int main() {
//	
//	int a, b,i,k=1;
//	scanf("%d%d", &a, &b);
//	for (i = 1; i <= b; i++) {
//		k *= a;
//		k %= 1000;
//	}
//	if (k < 10)
//		printf("00%d", k);
//	else if (k >= 10 && k <= 100)
//		printf("0%d", k);
//	else
//		printf("%d", k);
//
//	return 0;
//
//}
//int main() {
//	printf("%d", 1/0);
//	return 0;
//}
#include <stdio.h>
int main() {
	 int arr[100][100] = { 0 }, len[10000], wid[10000], a[10000], b[10000];
	int i = 0, j = 0, k = 0, n, x, y;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a[i], &b[i], &len[i], &wid[i]);
	}
	scanf("%d%d", &x, &y);
	for (i = 0; i < n; i++) {
		for (j = a[i]; j <= len[i]; j++) {
			for (k = b[i]; k <= wid[i]; k++) {
				arr[j][k]++;
			}
		}
	}
	if (arr[x][y] == 0)
		printf("-1");
	else
		printf("%d", arr[x][y]);
	return 0;
}