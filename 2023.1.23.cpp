//����n��1��n��100����ѧ���������ͳɼ������ճɼ��Ӹߵ������������ѧ�������������ظ���
//����гɼ���ͬ�ģ���ԭ���������п�ǰ��ͬѧ��Ȼ������ǰ�档
//��һ������n����ʾ������ѧ������������n��ѧ�������֣��ɼ����ÿո�ָ���ÿ����һ���˺��� 
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main() {
	char arr[20];
	int i = 0, n = 0,count=0,j=0,x;
	struct student {
		char name[20];
		int score;
	};
	struct student stu[50];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s%d", stu[i].name, &stu[i].score);
	}
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (stu[j].score < stu[j + 1].score) {
				strcpy(arr, stu[j].name);
				strcpy(stu[j].name, stu[j + 1].name);
				strcpy(stu[j + 1].name, arr);
				x = stu[j].score;
				stu[j].score = stu[j + 1].score;
				stu[j + 1].score = x;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%s ", stu[i].name);
		printf("%d\n", stu[i].score);
	}
	
	
	return 0;
}
