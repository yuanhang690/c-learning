#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>
//ָ������������
//һά����
//�ص�֪ʶ��1.sizeof(������)����������������������ʱ������������������С����λ���ֽ�
//			2.&������--ȡ��������������ĵ�ַ
//������������������������������ֱ�ʾ������Ԫ�ص�ַ
//		����strlen������������ܵ���Ҫ�ǵ�ַ������һ��Ϊchar*������Ϊ��Ļᱨ��
//ע����������ǵ�ַ��С��4/8�����ǵ�ַ��Ԫ�صĴ�С
int main() {
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));//��������-->16
	printf("%d\n", sizeof(a + 0));//a+0���㵥�����֣���������Ԫ�ص�ַ��ַ-->Ϊ4��32λ��/8��64λ��
	printf("%d\n", sizeof(*a));//����������������Ԫ�ؽ�����-->4��4���ֽڣ�
	printf("%d\n", sizeof(a + 1));//ͬ2�У�4/8
	printf("%d\n", sizeof(a[1]));//4(�ڶ���Ԫ�ش�С)
	printf("%d\n", sizeof(&a));//4/8-->(�����������ַ)
	printf("%d\n", sizeof(*&a));//16-->��������������С
	printf("%d\n", sizeof(&a + 1));//4/8-->�������������һ���ռ�ĵ�ַ
	printf("%d\n", sizeof(&a[0]));//4/8
	printf("%d\n", sizeof(&a[0] + 1));//4/8-->Ҳ�ǵ�ַ


	//�ַ�����
	char arr[] = { 'a','b','c','d','e','f' };//ע�⣺���ʼ����û��'\0'��
	printf("%d\n", sizeof(arr));//6-->���������С��1Ԫ��һ�ֽڣ�
	printf("%d\n", sizeof(arr + 0));//4/8-->��Ԫ�ص�ַ
	printf("%d\n", sizeof(*arr));//1-->��Ԫ�ص�ַ�����þ��ǡ�a����ռ��С
	printf("%d\n", sizeof(arr[1]));//1��ͬ�ϣ�
	printf("%d\n", sizeof(&arr));//4/8
	printf("%d\n", sizeof(&arr + 1));//4/8
	printf("%d\n", sizeof(&arr[0] + 1));//4/8��������Ϊ��ַ��



	printf("%d\n", strlen(arr));//���ֵ-->strlenֹͣ�ı�־���ҵ�'\0'������û�еģ���������
	printf("%d\n", strlen(arr + 0));//ͬ��
	printf("%d\n", strlen(*arr));//error	���ݵ���ֵ�����ǵ�ַ������
	printf("%d\n", strlen(arr[1]));//ͬ��
	printf("%d\n", strlen(&arr));//���ֵ		һֱ���ֱ���ҵ�0Ϊֹ
	printf("%d\n", strlen(&arr + 1));//���ֵ-6		���������ַ��1�������һ�������飨6Ԫ�أ�
	printf("%d\n", strlen(&arr[0] + 1));//���ֵ-1	ͬ��



	char arr[] = "abcdef";//ע�⣺�����ĳ�ʼ����'\0'˼����������
	printf("%d\n", sizeof(arr));//7-->����ѡ�\0��Ҳ��ͽ�����
	printf("%d\n", sizeof(arr + 0));//4/8	��ַ
	printf("%d\n", sizeof(*arr));//1	��Ԫ�ش�С
	printf("%d\n", sizeof(arr[1]));//1	ͬ��
	printf("%d\n", sizeof(&arr));//4/8
	printf("%d\n", sizeof(&arr + 1));//4/8
	printf("%d\n", sizeof(&arr[0] + 1));//4/8
	printf("%d\n", strlen(arr));//6-->�ҵ��ˡ�\0��
	printf("%d\n", strlen(arr + 0));//6
	printf("%d\n", strlen(*arr));//error		���ǵ�ַ
	printf("%d\n", strlen(arr[1]));//error
	printf("%d\n", strlen(&arr));//6
	printf("%d\n", strlen(&arr + 1));//���ֵ��������������
	printf("%d\n", strlen(&arr[0] + 1));//5		��b��ʼ

	char* p = "abcdef";
	printf("%d\n", sizeof(p));//4/8
	printf("%d\n", sizeof(p + 1));//4/8
	printf("%d\n", sizeof(*p));//1		��Ԫ�ش�С
	printf("%d\n", sizeof(p[0]));//1	��������ͬp[0]== *(p+0)
	printf("%d\n", sizeof(&p));//4/8
	printf("%d\n", sizeof(&p + 1));//4/8
	printf("%d\n", sizeof(&p[0] + 1));//4/8


	printf("%d\n", strlen(p));//6	��Ԫ�ص�ַ		
	printf("%d\n", strlen(p + 1));//5	
	printf("%d\n", strlen(*p));//error
	printf("%d\n", strlen(p[0]));//error
	printf("%d\n", strlen(&p));//���ֵ		������p�Լ�����ӵ�еĵ�ַ��֪���Ƿ���'\0'
	printf("%d\n", strlen(&p + 1));//���ֵ
	printf("%d\n", strlen(&p[0] + 1));//5
	return 0;
}